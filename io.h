#ifndef IO_H
#define IO_H

#include <avr/io.h>
#include <stdlib.h>
#include <assert.h>
#include "io_mcu_types.h"

#define P0_DIR_OUTPUT 0x01
#define P1_DIR_OUTPUT 0x02
#define P2_DIR_OUTPUT 0x04
#define P3_DIR_OUTPUT 0x08
#define P4_DIR_OUTPUT 0x10
#define P5_DIR_OUTPUT 0x20
#define P6_DIR_OUTPUT 0x40
#define P7_DIR_OUTPUT 0x80
#define P_ALL_OUTPUT  0xff

#define P0_DIR_INPUT 0x00
#define P1_DIR_INPUT 0x00
#define P2_DIR_INPUT 0x00
#define P3_DIR_INPUT 0x00
#define P4_DIR_INPUT 0x00
#define P5_DIR_INPUT 0x00
#define P6_DIR_INPUT 0x00
#define P7_DIR_INPUT 0x00
#define P_ALL_INPUT  0x00

#define P0_PULLUP (0x01)
#define P1_PULLUP (0x02)
#define P2_PULLUP (0x04)
#define P3_PULLUP (0x08)
#define P4_PULLUP (0x10)
#define P5_PULLUP (0x20)
#define P6_PULLUP (0x40)
#define P7_PULLUP (0x80)
#define P_ALL_PULLUP (0xff)

static inline void init_port_a_direction(unsigned char dir) {
#ifdef IO_HAS_PORT_A
  DDRA = dir;
#else
  assert(0);
#endif
}

static inline void init_port_b_direction(unsigned char dir) {
#ifdef IO_HAS_PORT_B
  DDRB = dir;
#else
  assert(0);
#endif
}

static inline void init_port_c_direction(unsigned char dir) {
#ifdef IO_HAS_PORT_C
  DDRC = dir;
#else
  assert(0);
#endif
}

static inline void init_port_d_direction(unsigned char dir) {
#ifdef IO_HAS_PORT_D
  DDRD = dir;
#else
  assert(0);
#endif
}

static inline void write_port_a(unsigned char data) {
#ifdef IO_HAS_PORT_A
  PORTA = data;
#else
  assert(0);
#endif
}

static inline void write_port_b(unsigned char data) {
#ifdef IO_HAS_PORT_B
  PORTB = data;
#else
  assert(0);
#endif
}

static inline void write_port_c(unsigned char data) {
#ifdef IO_HAS_PORT_C
  PORTC = data;
#else
  assert(0);
#endif
}

static inline void write_port_d(unsigned char data) {
#ifdef IO_HAS_PORT_D
  PORTD = data;
#else
  assert(0);
#endif
}

static inline void set_port_a_pullup(unsigned char pullup) {
#ifdef IO_HAS_PORT_A
  PORTA = pullup;
#else
  assert(0);
#endif
}

static inline void set_port_b_pullup(unsigned char pullup) {
#ifdef IO_HAS_PORT_B
  PORTB = pullup;
#else
  assert(0);
#endif
}

static inline void set_port_c_pullup(unsigned char pullup) {
#ifdef IO_HAS_PORT_C
  PORTC = pullup;
#else
  assert(0);
#endif
}

static inline void set_port_d_pullup(unsigned char pullup) {
#ifdef IO_HAS_PORT_D
  PORTD = pullup;
#else
  assert(0);
#endif
}

static inline unsigned char read_port_a(void) {
#ifdef IO_HAS_PORT_A
  return PINA;
#else
  assert(0);
#endif
}

static inline unsigned char read_port_b(void) {
#ifdef IO_HAS_PORT_B
  return PINB;
#else
  assert(0);
#endif
}

static inline unsigned char read_port_c(void) {
#ifdef IO_HAS_PORT_C
  return PINC;
#else
  assert(0);
#endif
}

static inline unsigned char read_port_d(void) {
#ifdef IO_HAS_PORT_D
  return PIND;
#else
  assert(0);
#endif
}


#endif /* IO_H */
