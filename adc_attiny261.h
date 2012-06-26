#ifndef ADC_ATTINY261_H
#define ADC_ATTINY261_H

#warning "todo: functions to set trigger mode"
#warning "todo: functions to digital input registers"

#define ADC_REF_AVCC   (0x00)  /**< Use AVCC as reference input. */
#define ADC_REF_AREF   (0x01)  /**< Use external reference input. */
#define ADC_REF_INT110 (0x02)  /**< Use internal 1.1V as reference. */
#define ADC_REF_INT256 (0x06)  /**< Use internal 2.56V as reference. */
#define ADC_REF_INT256_AREF (0x07)  /**< Use internal 2.56V with external
					  *   capacitor at AREF as reference.
					  */

#define ADC_REF_MASK     (0x03 << 6)  /**< Mask for reference bits in ADMUX. */
#define ADC_REF_MASK_B   (0x10)       /**< Mask for reference bits in ACSRB. */

#define ADC_LEFT_ADJUST (0x01 << 5) /**< Flag to left adjust result, so that
				     *   the high 8 Bits are all in high
				     *   result register.
				     */

#define ADC_IN_ADC0 (0x00) /**< Use ADC0 as input. */
#define ADC_IN_ADC1 (0x01) /**< Use ADC1 as input. */
#define ADC_IN_ADC2 (0x02) /**< Use ADC2 as input. */
#define ADC_IN_ADC3 (0x03) /**< Use ADC3 as input. */
#define ADC_IN_ADC4 (0x04) /**< Use ADC4 as input. */
#define ADC_IN_ADC5 (0x05) /**< Use ADC5 as input. */
#define ADC_IN_ADC6 (0x06) /**< Use ADC6 as input. */
#define ADC_IN_ADC7 (0x07) /**< Use ADC7 as input. */
#define ADC_IN_ADC8 (0x08) /**< Use ADC8 as input. */
#define ADC_IN_ADC9 (0x09) /**< Use ADC9 as input. */
#define ADC_IN_ADC10 (0x0a) /**< Use ADC10 as input. */
#define ADC_IN_ADC0_ADC1_20 (0x0b) /**< Differential ADC0-ADC1 Gain 20 */
#define ADC_IN_ADC0_ADC1    (0x0c) /**< Differential ADC0-ADC1 Gain 1 */
#define ADC_IN_ADC1_ADC1_20 (0x0d) /**< Differential ADC1-ADC1 Gain 20 */
#define ADC_IN_ADC2_ADC1_20 (0x0e) /**< Differential ADC2-ADC1 Gain 20 */
#define ADC_IN_ADC2_ADC1    (0x0f) /**< Differential ADC2-ADC1 Gain 1 */
#define ADC_IN_ADC2_ADC3    (0x10) /**< Differential ADC2-ADC3 Gain 1 */
#define ADC_IN_ADC3_ADC3_20 (0x11) /**< Differential ADC3-ADC3 Gain 20 */
#define ADC_IN_ADC4_ADC3_20 (0x12) /**< Differential ADC4-ADC3 Gain 20 */
#define ADC_IN_ADC4_ADC3    (0x13) /**< Differential ADC4-ADC3 Gain 1 */
#define ADC_IN_ADC4_ADC5_20 (0x14) /**< Differential ADC4-ADC5 Gain 20 */
#define ADC_IN_ADC4_ADC5    (0x15) /**< Differential ADC4-ADC5 Gain 1 */
#define ADC_IN_ADC5_ADC5_20 (0x16) /**< Differential ADC5-ADC5 Gain 20 */
#define ADC_IN_ADC6_ADC5_20 (0x17) /**< Differential ADC6-ADC5 Gain 20 */
#define ADC_IN_ADC6_ADC5    (0x18) /**< Differential ADC6-ADC5 Gain 1 */
#define ADC_IN_ADC8_ADC9_20 (0x19) /**< Differential ADC8-ADC9 Gain 20 */
#define ADC_IN_ADC8_ADC9    (0x1a) /**< Differential ADC8-ADC9 Gain 1 */
#define ADC_IN_ADC9_ADC9_20 (0x1b) /**< Differential ADC9-ADC9 Gain 20 */
#define ADC_IN_ADC10_ADC9_20 (0x1c) /**<Differential ADC10-ADC9 Gain 20*/
#define ADC_IN_ADC10_ADC9   (0x1d) /**< Differential ADC10-ADC9 Gain 1 */
#define ADC_IN_110  (0x1e) /**< Use internal 1.10V as input. */
#define ADC_IN_GND  (0x1f) /**< Use ground as input. */

/* #define ADC_IN_ADC0_ADC1_20 (0x20) /\**< Differential ADC0-ADC1 Gain 20 *\/ */
#define ADC_IN_ADC0_ADC1_32 (0x60) /**< Differential ADC0-ADC1 Gain 32 */
#define ADC_IN_ADC0_ADC1_1  (0x21) /**< Differential ADC0-ADC1 Gain 1 */
#define ADC_IN_ADC0_ADC1_8  (0x61) /**< Differential ADC0-ADC1 Gain 8 */
#define ADC_IN_ADC1_ADC0_20 (0x22) /**< Differential ADC1-ADC0 Gain 20 */
#define ADC_IN_ADC1_ADC0_32 (0x62) /**< Differential ADC1-ADC0 Gain 32 */
#define ADC_IN_ADC1_ADC0_1  (0x23) /**< Differential ADC1-ADC0 Gain 1 */
#define ADC_IN_ADC1_ADC0_8  (0x63) /**< Differential ADC1-ADC0 Gain 8 */

#define ADC_IN_ADC1_ADC2_20 (0x24) /**< Differential ADC1-ADC2 Gain 20 */
#define ADC_IN_ADC1_ADC2_32 (0x64) /**< Differential ADC1-ADC2 Gain 32 */
#define ADC_IN_ADC1_ADC2_1  (0x25) /**< Differential ADC1-ADC2 Gain 1 */
#define ADC_IN_ADC1_ADC2_8  (0x65) /**< Differential ADC1-ADC2 Gain 8 */
/* #define ADC_IN_ADC2_ADC1_20 (0x26) /\**< Differential ADC2-ADC1 Gain 20 *\/ */
#define ADC_IN_ADC2_ADC1_32 (0x66) /**< Differential ADC2-ADC1 Gain 32 */
#define ADC_IN_ADC2_ADC1_1  (0x27) /**< Differential ADC2-ADC1 Gain 1 */
#define ADC_IN_ADC2_ADC1_8  (0x67) /**< Differential ADC2-ADC1 Gain 8 */

#define ADC_IN_ADC2_ADC0_20 (0x28) /**< Differential ADC2-ADC0 Gain 20 */
#define ADC_IN_ADC2_ADC0_32 (0x68) /**< Differential ADC2-ADC0 Gain 32 */
#define ADC_IN_ADC2_ADC0_1  (0x29) /**< Differential ADC2-ADC0 Gain 1 */
#define ADC_IN_ADC2_ADC0_8  (0x69) /**< Differential ADC2-ADC0 Gain 8 */
#define ADC_IN_ADC0_ADC2_20 (0x2a) /**< Differential ADC0-ADC2 Gain 20 */
#define ADC_IN_ADC0_ADC2_32 (0x6a) /**< Differential ADC0-ADC2 Gain 32 */
#define ADC_IN_ADC0_ADC2_1  (0x2b) /**< Differential ADC0-ADC2 Gain 1 */
#define ADC_IN_ADC0_ADC2_8  (0x6b) /**< Differential ADC0-ADC2 Gain 8 */

/* #define ADC_IN_ADC4_ADC5_20 (0x2c) /\**< Differential ADC4-ADC5 Gain 20 *\/ */
#define ADC_IN_ADC4_ADC5_32 (0x6c) /**< Differential ADC4-ADC5 Gain 32 */
#define ADC_IN_ADC4_ADC5_1  (0x2d) /**< Differential ADC4-ADC5 Gain 1 */
#define ADC_IN_ADC4_ADC5_8  (0x6d) /**< Differential ADC4-ADC5 Gain 8 */
#define ADC_IN_ADC5_ADC4_20 (0x2e) /**< Differential ADC5-ADC4 Gain 20 */
#define ADC_IN_ADC5_ADC4_32 (0x6e) /**< Differential ADC5-ADC4 Gain 32 */
#define ADC_IN_ADC5_ADC4_1  (0x2f) /**< Differential ADC5-ADC4 Gain 1 */
#define ADC_IN_ADC5_ADC4_8  (0x6f) /**< Differential ADC5-ADC4 Gain 8 */

#define ADC_IN_ADC5_ADC6_20 (0x34) /**< Differential ADC5-ADC6 Gain 20 */
#define ADC_IN_ADC5_ADC6_32 (0x74) /**< Differential ADC5-ADC6 Gain 32 */
#define ADC_IN_ADC5_ADC6_1  (0x35) /**< Differential ADC5-ADC6 Gain 1 */
#define ADC_IN_ADC5_ADC6_8  (0x75) /**< Differential ADC5-ADC6 Gain 8 */
/* #define ADC_IN_ADC6_ADC5_20 (0x36) /\**< Differential ADC6-ADC5 Gain 20 *\/ */
#define ADC_IN_ADC6_ADC5_32 (0x76) /**< Differential ADC6-ADC5 Gain 32 */
#define ADC_IN_ADC6_ADC5_1  (0x37) /**< Differential ADC6-ADC5 Gain 1 */
#define ADC_IN_ADC6_ADC5_8  (0x77) /**< Differential ADC6-ADC5 Gain 8 */

#define ADC_IN_ADC0_ADC0_20 (0x30) /**< Differential ADC0-ADC0 Gain 20 */
#define ADC_IN_ADC0_ADC0_32 (0x70) /**< Differential ADC0-ADC0 Gain 32 */
#define ADC_IN_ADC0_ADC0_1  (0x31) /**< Differential ADC0-ADC0 Gain 1 */
#define ADC_IN_ADC0_ADC0_8  (0x71) /**< Differential ADC0-ADC0 Gain 8 */
/* #define ADC_IN_ADC1_ADC1_20 (0x32) /\**< Differential ADC1-ADC1 Gain 20 *\/ */
#define ADC_IN_ADC1_ADC1_32 (0x72) /**< Differential ADC1-ADC1 Gain 32 */
#define ADC_IN_ADC2_ADC2_20 (0x33) /**< Differential ADC2-ADC2 Gain 20 */
#define ADC_IN_ADC2_ADC2_32 (0x73) /**< Differential ADC2-ADC2 Gain 32 */

#define ADC_IN_ADC4_ADC4_20 (0x30) /**< Differential ADC4-ADC4 Gain 20 */
#define ADC_IN_ADC4_ADC4_32 (0x70) /**< Differential ADC4-ADC4 Gain 32 */
/* #define ADC_IN_ADC5_ADC5_20 (0x31) /\**< Differential ADC5-ADC5 Gain 20 *\/ */
#define ADC_IN_ADC5_ADC5_32 (0x71) /**< Differential ADC5-ADC5 Gain 32 */
#define ADC_IN_ADC6_ADC6_20 (0x32) /**< Differential ADC6-ADC6 Gain 20 */
#define ADC_IN_ADC6_ADC6_32 (0x72) /**< Differential ADC6-ADC6 Gain 32 */
#define ADC_IN_ADC11        (0x3f) /**< Use ADC11 (internal temp. sensor) */
#define ADC_IN_TEMP         (0x3f) /**< Use ADC11 (internal temp. sensor) */

#define ADC_IN_MASK_MUX    (0x1f) /**< Mask for input channel bits in ADMUX. */
#define ADC_IN_MASK_ADCSRB (0x48) /**< Mask for input channel bits in ADCSRB. */


#define ADC_ENABLE (0x80) /**< Bit to enable adc. */
#define ADC_START  (0x40) /**< Bit to trigger start of conversion. */
#define ADC_AUTO_TRIGGER  (0x20) /**< Bit to set ADC to auto trigger mode. */
#define ADC_CONV_ACTIVE (0x40) /**< Flag marking an active conversion. */
#define ADC_INTR_FLAG  (0x10) /**< Interrupt flag, set after conversion end. */
#define ADC_ENABLE_IRQ (0x08) /**< Enable ADC Interrupt. */

#define ADC_CLOCK_2   (0x01) /**< Set ADC clock divisor to 2. */
#define ADC_CLOCK_4   (0x02) /**< Set ADC clock divisor to 4. */
#define ADC_CLOCK_8   (0x03) /**< Set ADC clock divisor to 8. */
#define ADC_CLOCK_16  (0x04) /**< Set ADC clock divisor to 16. */
#define ADC_CLOCK_32  (0x05) /**< Set ADC clock divisor to 32. */
#define ADC_CLOCK_64  (0x06) /**< Set ADC clock divisor to 64. */
#define ADC_CLOCK_128 (0x07) /**< Set ADC clock divisor to 128. */

#define ADC_CLOCK_MASK (0x07)

#define ADC_BIPOLAR_MODE (0x80) /**< Flag to set bipolar mode. */

#define ADC_TRIGGER_FR   (0x00)   /**< Free running mode. */
#define ADC_TRIGGER_AC   (0x01)   /**< Use analog comparator as trigger. */
#define ADC_TRIGGER_EI   (0x02)   /**< Use external intterupt as trigger. */
#define ADC_TRIGGER_TC0A (0x03)   /**< Use timer 0 compare match A as trigger.*/
#define ADC_TRIGGER_TO0  (0x04)   /**< Use timer 0 overflow as trigger.*/
#define ADC_TRIGGER_TC0B (0x05)   /**< Use timer 0 compare match B as trigger.*/
#define ADC_TRIGGER_TO1  (0x06)   /**< Use timer 1 overflow as trigger.*/
#define ADC_TRIGGER_WDI  (0x07)   /**< Use watchdog interrupt as trigger.*/


static inline void adc_enable(void) {
  ADCSRA = ADCSRA | ADC_ENABLE;
}

static inline void adc_disable(void) {
  ADCSRA = ADCSRA & ~ADC_ENABLE;
}

static inline void adc_enable_intr(void) {
  ADCSRA = ADCSRA | ADC_INTR_FLAG;
}

static inline void adc_disable_intr(void) {
  ADCSRA = ADCSRA & ~(ADC_INTR_FLAG);
}

static inline void adc_enable_bipolar_mode(void) {
  ADCSRB |= ADC_BIPOLAR_MODE;
}

static inline void adc_disable_bipolar_mode(void) {
  ADCSRB &= ~(ADC_BIPOLAR_MODE);
}


static inline void adc_set_leftadjust(void) {
  ADMUX |= ADC_LEFT_ADJUST;
}

static inline void adc_set_rightadjust(void) {
  ADMUX &= ~ADC_LEFT_ADJUST;
}

static inline void adc_select_reference(unsigned char ref) {
  ADMUX = (ADMUX & ~ADC_REF_MASK) | ((ref << 6) & ADC_REF_MASK);
  ADCSRB = (ADCSRB & ~ADC_REF_MASK_B) | ((ref << 2)  & ADC_REF_MASK_B);
}

static inline void adc_select_channel(unsigned char channel) {
  ADMUX = (ADMUX & ~ADC_IN_MASK_MUX) | (channel & ADC_IN_MASK_MUX);
  ADCSRB = (ADCSRB &~ADC_IN_MASK_ADCSRB) | ((channel & 0x20) >> 2)
    | (channel & 0x40);
}

static inline void adc_start_conversion(void) {
  ADCSRA = ADCSRA | ADC_START;
}

static inline char adc_conversion_done(void) {
  return ! (ADCSRA & ADC_CONV_ACTIVE);
}

static inline char adc_get_intr_flag(void) {
  return ADCSRA & ADC_INTR_FLAG;
}

static inline _U8 adc_get_result(void) {
  return ADCH;
/*   return ADCL | (ADCH << 8); */
}

static inline _U16 adc_get_result_16(void) {
  return ADCL | (ADCH << 8);
}


static inline void adc_init(unsigned char adc_clock) {
  ADCSRA = adc_clock;
  adc_select_reference(ADC_REF_AVCC);
  adc_select_channel(ADC_IN_ADC0);
}

static inline void adc_set_clock(unsigned char adc_clock) {
  ADCSRA = (ADCSRA & ~ADC_CLOCK_MASK) | adc_clock;
}



#endif /* ADC_ATTINY261_H */
