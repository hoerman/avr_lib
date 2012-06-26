#ifndef ADC_ATMEGA16_H
#define ADC_ATMEGA16_H


#define ADC_REF_AREF   (0x00 << 6)  /**< Use external reference input. */
#define ADC_REF_AVCC   (0x01 << 6)  /**< Use AVCC as reference input. */
#define ADC_REF_INT256 (0x03 << 6)  /**< Use internal 2.56V as reference. */
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
#define ADC_IN_130  (0x0e) /**< Use internal 1.30V as input. */
#define ADC_IN_GND  (0x0f) /**< Use ground as input. */
#define ADC_IN_MASK (0x1f) /**< Mask for input bits. */

#define ADC_ENABLE (0x80) /**< Bit to enable adc. */
#define ADC_START  (0x40) /**< Bit to trigger start of conversion. */
#define ADC_CONV_ACTIVE (0x40) /**< Flag marking an conversion is active. */

static inline void adc_init(void);

static inline void adc_enable(void) {
  ADCSRA = ADCSRA | ADC_ENABLE;
}

static inline void adc_disable(void) {
  ADCSRA = ADCSRA & ~ADC_ENABLE;
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
  ADCSRA = ADCSRA | ADC_START;
}

static inline char adc_conversion_done(void) {
  return ! (ADCSRA & ADC_CONV_ACTIVE);
}

static inline _U16 adc_get_result(void) {
  return ADCH;
/*   return ADCL | (ADCH << 8); */
}

static inline _U16 adc_get_result_16(void) {
  return ADCL | (ADCH << 8);
}


static inline void adc_init(void) {
  ADCSRA = 0;
  adc_select_reference(ADC_REF_AVCC);
  adc_select_channel(ADC_IN_ADC0);
}



#endif /* ADC_ATMEGA16_H */
