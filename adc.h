#ifndef ADC_H
#define ADC_H

#include <avr/io.h>
#include "types.h"

#if defined (__AVR_ATtiny13__)
#include "adc_attiny13.h"
#elif defined (__AVR_ATtiny26__)
#include "adc_attiny26.h"
#elif defined (__AVR_ATtiny261__)
#include "adc_attiny261.h"
#elif defined (__AVR_ATmega16__)
#include "adc_atmega16.h"
#else
#error Controller not supported by adc.h
#endif


#endif /* ADC_H */
