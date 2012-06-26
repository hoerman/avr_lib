#ifndef IO_MCU_TYPES_H
#define IO_MCU_TYPES_H

#if defined (__AVR_ATtiny13__)
#define IO_HAS_PORT_B
#elif defined (__AVR_ATtiny26__)
#define IO_HAS_PORT_A
#define IO_HAS_PORT_B
#elif defined (__AVR_ATtiny261__)
#define IO_HAS_PORT_A
#define IO_HAS_PORT_B
#elif defined (__AVR_ATmega16__)
#define IO_HAS_PORT_A
#define IO_HAS_PORT_B
#define IO_HAS_PORT_C
#define IO_HAS_PORT_D
#elif defined (__AVR_ATmega1281__)
#define IO_HAS_PORT_A
#define IO_HAS_PORT_B
#define IO_HAS_PORT_C
#define IO_HAS_PORT_D
#define IO_HAS_PORT_E
#define IO_HAS_PORT_F
#define IO_HAS_PORT_G
#elif defined (__AVR_ATmega1284P__) 
#define IO_HAS_PORT_A
#define IO_HAS_PORT_B
#define IO_HAS_PORT_C
#define IO_HAS_PORT_D
#else
#error Controller not supported by io.h
#endif

#endif /* IO_MCU_TYPES_H */
