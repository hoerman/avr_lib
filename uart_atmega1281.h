#ifndef UART_ATMEGA1281_H
#define UART_ATMEGA1281_H

#include <avr/io.h>
#include "avr_clock.h"

#if AVR_CLOCK == 8000000
#define UART_BR_2400   207
#define UART_BR_4800   103
#define UART_BR_9600   51
#define UART_BR_14400  34
#define UART_BR_19200  25
#define UART_BR_28800  16
#define UART_BR_38400  12
#define UART_BR_57600  8
#define UART_BR_76800  6
#define UART_BR_115200 3
#else
#warning no baudrates defined for selected cpu clock
#endif

#define UART_8N1 (UART_PM_DIS | UART_CSC_8) /** UART settings for 8N1 mode. */

/** Control and Status Register A, UCSRA. */
#define UART_RX_COMP   0x80 /** Received Byte available. */
#define UART_TX_COMP   0x40 /** Byte send completly. */
#define UART_TX_EMPTY  0x20 /** Ready to write new data to TX Register. */
#define UART_RX_FERR   0x10 /** Frame Error Flag (Stopbit was zero), cleared
			     *  after reading UDR! */
#define UART_RX_DOR    0x08 /** Data Overrun Flag, cleared after reading
			     *  UDR! */
#define UART_RX_PAR    0x04 /** Parity error Flag,  cleared after reading
			     *  UDR! */
#define UART_U2X       0x02 /** Double UART Speed. */
#define UART_MPCM      0x01 /** Multiprocessor Communication Mode. */

/** Control and Status Register B, UCSRB. */
#define UART_RX_CIE    0x80 /** RX Complete Interrupt Enable. */
#define UART_TX_CIE    0x40 /** TX Complete Interrupt Enable. */
#define UART_TX_UDRIE  0x20 /** TX Empty Interrupt Enable. */
#define UART_RX_EN     0x10 /** Enable UART Receiver. */
#define UART_TX_EN     0x08 /** Enable UART Transmitter. */
#define UART_UCSZ2     0x04 /** UART Character Size.
			     *  Only needed for 9bit Charactersize. */
#define UART_RXB8      0x02 /** Received 9th bit. */
#define UART_TXB8      0x01 /** 9th bit to transmit. */

/** Control and Status Register C, UCSRC. */
#define UART_URSEL     0x80 /** Register Select. Reads as one when reading
			     *  UCSRC, must be set to one when writing
			     *  UCSRC, to zero when writing UBRRH.
			     */
#define UART_MSEL      0x40 /** UART Mode select. 0 => async, 1 => sync. */
#define UART_PM        0x30 /** UART Parity Mode mask. */
#define UART_STOPBITS  0x08 /** Set for two Stopbits, reset for one. */
#define UART_CHARSIZEM 0x06 /** UART Character Size Mask. */
#define UART_CPOL      0x01 /** Clock Polarity, 0 for async mode. */

/** Parity Modes. */
#define UART_PM_SHIFT 4        /** Position of Paritymode bits in UCSRC. */
#define UART_PM_DIS   (0x00 << UART_PM_SHIFT) /** Disable Parity Mode. */
#define UART_PM_EVEN  (0x02 << UART_PM_SHIFT) /** Even Parity. */
#define UART_PM_ODD   (0x03 << UART_PM_SHIFT) /** Odd Parity. */

/** Character Size. Only for 6 to 8 bit Charactersize, for 9 bit 
 *  UART_UCSZ2 must be set in UCSRB too!
 */
#define UART_CSC_SHIFT 1       /** Position of Charactersize bits in UCSRC. */
#define UART_CSC_5 (0 << UART_CSC_SHIFT) /** 5 bit charactes size. */
#define UART_CSC_6 (1 << UART_CSC_SHIFT) /** 6 bit charactes size. */
#define UART_CSC_7 (2 << UART_CSC_SHIFT) /** 7 bit charactes size. */
#define UART_CSC_8 (3 << UART_CSC_SHIFT) /** 8 bit charactes size. */

/** Mask for UART recv. errors. */
#define UART_RX_ERR_MASK (UART_RX_FERR | UART_RX_DOR | UART_RX_PAR)

static inline void init_uart(unsigned char baudrate, unsigned char mode) {
  /* set baudrate, data mode */
  UBRR0H = (baudrate >> 8);
  UBRR0L = (baudrate & 0xff);

  /* set UART mode */
  UCSR0A = 0;
  UCSR0C = mode;

  /* enable UART (and disable 9bit UART mode!) */
  UCSR0B = UART_RX_EN | UART_TX_EN;
}


static inline void uart_send(unsigned char data) {
  UDR0 = data;
}

static inline unsigned char uart_recv(void) {
  return UDR0;
}

static inline char uart_rts(void) {
  return UCSR0A & UART_TX_EMPTY;
}

static inline char uart_txc(void) {
  return UCSR0A & UART_TX_COMP;
}

static inline void uart_reset_txc(void) {
  UCSR0A = UART_TX_COMP;
}

static inline char uart_data_received(void) {
  return UCSR0A & UART_RX_COMP;
}

static inline unsigned char uart_err(void) {
  return UCSR0A & UART_RX_ERR_MASK;
}


static inline void enable_tx_empty_intr(void) {
  UCSR0B |= UART_TX_UDRIE;
}

static inline void disable_tx_empty_intr(void) {
  UCSR0B &= ~UART_TX_UDRIE;
}

static inline void enable_tx_complete_intr(void) {
  UCSR0B |= UART_TX_CIE;
}

static inline void disable_tx_complete_intr(void) {
  UCSR0B &= ~UART_TX_CIE;
}

static inline void enable_rx_complete_intr(void) {
  UCSR0B |= UART_RX_CIE;
}

static inline void disable_rx_complete_intr(void) {
  UCSR0B &= ~UART_RX_CIE;
}


#endif /* UART_ATMEGA1281_H */
