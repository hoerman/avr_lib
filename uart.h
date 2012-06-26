#ifndef UART_H
#define UART_H

#if defined (__AVR_ATmega32__)
#include "uart_atmega32.h"
#elif defined (__AVR_ATmega1281__) || defined (__AVR_ATmega1284P__)
#include "uart_atmega1281.h"
#else
#error Controller not supported by uart.h
#endif


#endif /* UART_H */
