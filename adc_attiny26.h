#ifndef ADC_ATTINY26_H
#define ADC_ATTINY26_H


#define ADC_REF_AVCC   (0x00 << 6)  /**< Use AVCC as reference input. */
#define ADC_REF_AREF   (0x01 << 6)  /**< Use external reference input. */
#define ADC_REF_INT256 (0x02 << 6)  /**< Use internal 2.56V as reference. */
#define ADC_REF_INT256_AREF (0x03 << 6)  /**< Use internal 2.56V with external
					  *   capacitor at AREF as reference.
					  */

#define ADC_REF_MASK   (0x03 << 6)  /**< Mask for reference bits. */

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
#define ADC_IN_118  (0x1e) /**< Use internal 1.18V as input. */
#define ADC_IN_GND  (0x1f) /**< Use ground as input. */
#define ADC_IN_MASK (0x1f) /**< Mask for input bits. */

#define ADC_ENABLE (0x80) /**< Bit to enable adc. */
#define ADC_START  (0x40) /**< Bit to trigger start of conversion. */
#define ADC_FR_MODE  (0x20) /**< Bit to set ADC to free running mode. */
#define ADC_CONV_ACTIVE (0x40) /**< Flag marking an active conversion. */
#define ADC_ENABLE_IRQ (0x08) /**< Enable ADC Interrupt. */

#define ADC_CLOCK_2   (0x01) /**< Set ADC clock divisor to 2. */
#define ADC_CLOCK_4   (0x02) /**< Set ADC clock divisor to 4. */
#define ADC_CLOCK_8   (0x03) /**< Set ADC clock divisor to 8. */
#define ADC_CLOCK_16  (0x04) /**< Set ADC clock divisor to 16. */
#define ADC_CLOCK_32  (0x05) /**< Set ADC clock divisor to 32. */
#define ADC_CLOCK_64  (0x06) /**< Set ADC clock divisor to 64. */
#define ADC_CLOCK_128 (0x07) /**< Set ADC clock divisor to 128. */


static inline void adc_enable(void) {
  ADCSR = ADCSR | ADC_ENABLE;
}

static inline void adc_disable(void) {
  ADCSR = ADCSR & ~ADC_ENABLE;
}

static inline void adc_set_leftadjust(void) {
  ADMUX |= ADC_LEFT_ADJUST;
}

static inline void adc_set_rightadjust(void) {
  ADMUX &= ~ADC_LEFT_ADJUST;
}

static inline void adc_select_reference(unsigned char ref) {
  ADMUX = (ADMUX & ~ADC_REF_MASK) | (ref & ADC_REF_MASK);
}

static inline void adc_select_channel(unsigned char channel) {
  ADMUX = (ADMUX & ~ADC_IN_MASK) | (channel & ADC_IN_MASK);
}

static inline void adc_start_conversion(void) {
  ADCSR = ADCSR | ADC_START;
}

static inline char adc_conversion_done(void) {
  return ! (ADCSR & ADC_CONV_ACTIVE);
}

static inline _U8 adc_get_result(void) {
  return ADCH;
/*   return ADCL | (ADCH << 8); */
}

static inline _U16 adc_get_result_16(void) {
  return ADCL | (ADCH << 8);
}


static inline void adc_init(unsigned char adc_clock) {
  ADCSR = adc_clock;
  adc_select_reference(ADC_REF_AVCC);
  adc_select_channel(ADC_IN_ADC0);
}



#endif /* ADC_ATTINY26_H */
