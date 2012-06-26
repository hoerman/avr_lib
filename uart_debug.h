#ifndef UART_DEBUG_H
#define UART_DEBUG_H

#if defined DEBUG_SU
#include "soft_uart.h"
#define UART_DEBUG_DO_DEBUG
#elif defined DEBUG_HW_BUFFERED
#include "debug_buffered_hw_uart.h"
#define UART_DEBUG_DO_DEBUG
#endif

static inline void debug_byte(const char *str, unsigned char by);
static inline void debug_byte_hex(const char *str, unsigned char by);
static inline void debug_ptr(const char *str, void *ptr);
static inline void debug_uart(const char *str);

void su_send_byte(unsigned char by);
void su_send_byte_hex(unsigned char by);
void su_send_string(const char *str);



/*********************************************/
/* implementation of static inline functions */
/*********************************************/

static inline void debug_byte(const char *str, unsigned char by) {
#ifdef UART_DEBUG_DO_DEBUG
  su_send_string(str);
  su_send(' ');
  su_send_byte(by);
  su_send(13);
  su_send(10);
#endif
}

static inline void debug_byte_hex(const char *str, unsigned char by) {
#ifdef UART_DEBUG_DO_DEBUG
  su_send(' ');
  su_send_string(str);
  su_send(' ');
  su_send_byte_hex(by);
  su_send(13);
  su_send(10);
#endif
}

static inline void debug_bytes(const char *str, const unsigned char *data,
			       unsigned char count) {
#ifdef UART_DEBUG_DO_DEBUG
  unsigned char i;

  su_send_string(str);
  su_send(' ');
  
  for (i = 0; i < count; i++) {
    su_send_byte_hex(*data);
    data++;
  }
  su_send(13);
  su_send(10);
#endif
}


static inline void debug_word(unsigned char code, unsigned int val) {
#ifdef UART_DEBUG_DO_DEBUG
  su_send_byte_hex(code);
  su_send(' ');
  su_send_byte_hex(val >> 8);
  su_send_byte_hex(val);
  su_send(13);
  su_send(10);
#endif
}

static inline void debug_word_s(const char *str, unsigned int val) {
#ifdef UART_DEBUG_DO_DEBUG
  su_send_string(str);
  su_send(' ');
  su_send_byte_hex(val >> 8);
  su_send_byte_hex(val);
  su_send(13);
  su_send(10);
#endif
}

static inline void debug_ptr(const char *str, void *ptr) {
#ifdef UART_DEBUG_DO_DEBUG
  su_send_string(str);
  su_send(' ');
  su_send_byte(((unsigned int) ptr) >> 8);
  su_send(' ');
  su_send_byte((unsigned int) ptr);
  su_send(13);
  su_send(10);
#endif
}

static inline void debug_uart(const char *str) {
#ifdef UART_DEBUG_DO_DEBUG
  su_send_string(str);
  su_send(13);
  su_send(10);
#endif
}



#endif /* UART_DEBUG_H */
