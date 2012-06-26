#ifndef AT_TIMER_H
#define AT_TIMER_H

#include <avr/io.h>


#if defined (__AVR_ATtiny13__)
#include "at_timer_tiny13.h"
#elif defined (__AVR_ATtiny26__)
#include "at_timer_attiny26.h"
#elif defined (__AVR_ATtiny261__)
#include "at_timer_attiny261.h"
#elif defined (__AVR_ATmega16__)
#include "at_timer_atmega16.h"
#else
#error Controller not supported by at_timer.h
#endif


#endif /* AT_TIMER_H */
