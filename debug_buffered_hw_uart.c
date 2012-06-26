#include "debug_buffered_hw_uart.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include <uart.h>

static char _debug_buffer[DEBUG_BUFFER_SIZE];
static volatile unsigned char _debug_buffer_first_used = 0;
static volatile unsigned char _debug_buffer_next_free = 0;

void _debug_buffer_send_next_char(void) {
  /* disable interrupts to avoid data corruption */
  cli();

  if ((_debug_buffer_first_used != _debug_buffer_next_free) &&
      uart_rts()) {
    uart_send(_debug_buffer[_debug_buffer_first_used]);
    _debug_buffer_first_used =
      (_debug_buffer_first_used + 1) % DEBUG_BUFFER_SIZE;
  }

  sei();
}

ISR(USART0_UDRE_vect) {
  _debug_buffer_send_next_char();
}  

void su_send(unsigned char data) {
  /* we hopefully don't need any interrupt locking here... */
  /* wait for free space in ring buffer */
  while ((_debug_buffer_next_free + 1) % DEBUG_BUFFER_SIZE ==
	 _debug_buffer_first_used) {
    _debug_buffer_send_next_char();
  };

  _debug_buffer[_debug_buffer_next_free] = data;

  _debug_buffer_next_free = (_debug_buffer_next_free + 1) % DEBUG_BUFFER_SIZE;

  _debug_buffer_send_next_char();
}

