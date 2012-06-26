#ifndef AT_TIMER_TINY26_H
#define AT_TIMER_TINY26_H


#define TIMER0_CLK_SRC_DISABLED (0x00) /**< Disable timer module. */
#define TIMER0_CLK_SRC_CLKIO    (0x01) /**< Use IO clock as timer clock. */
#define TIMER0_CLK_SRC_CLKIO_8  (0x02) /**< Use IO clock divided by 8 as
					*   timer clock.
					*/
#define TIMER0_CLK_SRC_CLKIO_64  (0x03)/**< Use IO clock divided by 64 as
					*   timer clock.
					*/
#define TIMER0_CLK_SRC_CLKIO_256 (0x04) /**< Use IO clock divided by 256 as
					 *   timer clock.
					 */
#define TIMER0_CLK_SRC_CLKIO_1024 (0x05) /**< Use IO clock divided by 1024 as
					  *   timer clock.
					  */
#define TIMER0_CLK_SRC_EXT_FALLING (0x06) /**< Use falling edge of external T0
					   *   pin as timer clock.
					   */
#define TIMER0_CLK_SRC_EXT_RISING  (0x07) /**< Use rising edge of external T0
					   *   pin as timer clock.
					   */
#define TIMER0_CLK_MASK (0x07) /**< Mask for setting clocksource. */


#define TIMER0_OVERFLOW_INT (0x02) /**< Flag to enable/check interrupt on
				    *   timer0 overflow.
				    */


#define TIMER1_CLK_SRC_DISABLED (0x00) /**< Disable timer module. */
#define TIMER1_CLK_SRC_CLKIO    (0x01) /**< Use IO clock as timer clock. */
#define TIMER1_CLK_SRC_CLKIO_2  (0x02) /**< Use IO clock divided by 2 as
					*   timer clock.
					*/
#define TIMER1_CLK_SRC_CLKIO_4  (0x03)/**< Use IO clock divided by 4 as
				       *   timer clock.
				       */
#define TIMER1_CLK_SRC_CLKIO_8 (0x04) /**< Use IO clock divided by 8 as
				       *   timer clock.
				       */
#define TIMER1_CLK_SRC_CLKIO_16 (0x05) /**< Use IO clock divided by 16 as
					*   timer clock.
					*/
#define TIMER1_CLK_SRC_CLKIO_32  (0x06) /**< Use IO clock divided by 32 as
					 *   timer clock.
					 */
#define TIMER1_CLK_SRC_CLKIO_64  (0x07)/**< Use IO clock divided by 64 as
					*   timer clock.
					*/
#define TIMER1_CLK_SRC_CLKIO_128 (0x08) /**< Use IO clock divided by 128 as
					 *   timer clock.
					 */
#define TIMER1_CLK_SRC_CLKIO_256 (0x09) /**< Use IO clock divided by 256 as
					 *   timer clock.
					 */
#define TIMER1_CLK_SRC_CLKIO_512  (0x0a) /**< Use IO clock divided by 512 as
					  *   timer clock.
					  */
#define TIMER1_CLK_SRC_CLKIO_1024  (0x0b)/**< Use IO clock divided by 1024 as
					  *   timer clock.
					  */
#define TIMER1_CLK_SRC_CLKIO_2048 (0x0c) /**< Use IO clock divided by 2048 as
					  *   timer clock.
					  */
#define TIMER1_CLK_SRC_CLKIO_4096 (0x0d) /**< Use IO clock divided by 4096 as
					  *   timer clock.
					  */
#define TIMER1_CLK_SRC_CLKIO_8192 (0x0e) /**< Use IO clock divided by 8192 as
					  *   timer clock.
					  */
#define TIMER1_CLK_SRC_CLKIO_16384 (0x0f) /**< Use IO clock divided by 16384 as
					   *   timer clock.
					   */

#define TIMER1_CLK_MASK (0x0f) /**< Mask for setting clocksource. */



#define TIMER1_PWM_OCA1_DIS (0x00) /**< Disable output of PWM signal A. */
#define TIMER1_PWM_OCA1_COCM_BOTH (0x40) /**< Clear PWM signal on compare match,
					  *   enable normal and negated output.
					  */
#define TIMER1_PWM_OCA1_COCM (0x80) /**< Clear PWM signal on compare match,
				     *   enable ony normal output.
				     */
#define TIMER1_PWM_OCA1_SOCM (0xc0) /**< Set PWM signal on compare match,
				     *   enable ony normal output.
				     */

#define TIMER1_PWMA_ENABLE (0x02)  /**< Enables PWM mode for comparator A. */
#define TIMER1_PWMA_DISABLE (0x00) /**< Disable PWM mode for comparator A. */

#define TIMER1_PWM_OCA1_MASK ((unsigned char) ~(0xc2))

#define TIMER1_PWM_OCB1_DIS (0x00) /**< Disable output of PWM signal B. */
#define TIMER1_PWM_OCB1_COCM_BOTH (0x10) /**< Clear PWM signal on compare match,
					  *   enable normal and negated output.
					  */
#define TIMER1_PWM_OCB1_COCM (0x20) /**< Clear PWM signal on compare match,
				     *   enable ony normal output.
				     */
#define TIMER1_PWM_OCB1_SOCM (0x30) /**< Set PWM signal on compare match,
				     *   enable ony normal output.
				     */
#define TIMER1_PWMB_ENABLE (0x01)  /**< Enables PWM mode for comparator B. */
#define TIMER1_PWMB_DISABLE (0x00) /**< Disable PWM mode for comparator B. */

#define TIMER1_PWM_OCB1_MASK ((unsigned char) ~0x31)


#define TIMER1_MATCH_A_INT (0x40) /**< Flag to enable/check interrupt on match
				  *    to compare register OCR1A.
				  */
#define TIMER1_MATCH_B_INT (0x20) /**< Flag to enable/check interrupt on match
				  *    to compare register 0CR1B.
				  */
#define TIMER1_OVERFLOW_INT (0x04) /**< Flag to enable/check interrupt on
				    *   timerß overflow.
				    */
#define TIMER1_CCM_MODE (0x80) /**< Clear timer1 on compare match with
				*   OCR1C
				*/
#define TIMER1_CRM_MODE (0x00) /**< Don't clear timer1 on compare match with
				*   OCR1C
				*/


static inline void set_timer1_oca1_pwm_mode(unsigned char mode) {
  assert((mode & TIMER1_PWM_OCA1_MASK) == 0);

  TCCR1A = (TCCR1A & TIMER1_PWM_OCA1_MASK) | mode;
}

static inline void set_timer1_ocb1_pwm_mode(unsigned char mode) {
  assert((mode & TIMER1_PWM_OCB1_MASK) == 0);

  TCCR1A = (TCCR1A & TIMER1_PWM_OCB1_MASK) | mode;
}


static inline void set_timer1_clk_source(unsigned char src) {
  assert((src & (unsigned char) ~TIMER1_CLK_MASK) == 0);

  TCCR1B = src;
}

static inline void set_timer1_mode(unsigned char mode) {
  TCCR1B = (TCCR1B & ~TIMER1_CCM_MODE) | (mode & TIMER1_CCM_MODE);
}

static inline void set_timer1(unsigned char val) {
  TCNT1 = val;
}

static inline unsigned char get_timer1(void) {
  return TCNT1;
}

static inline void set_timer1_compare_a(unsigned char val) {
  OCR1A = val;
}

static inline void set_timer1_compare_b(unsigned char val) {
  OCR1B = val;
}

static inline void set_timer1_compare_c(unsigned char val) {
  OCR1C = val;
}

static inline void set_timer0_clk_source(unsigned char src) {
  assert((src & (unsigned char) ~TIMER0_CLK_MASK) == 0);

  TCCR0 = src;
}

static inline void set_timer_interrupts(unsigned char intr) {
  TIMSK = intr;
}

static inline unsigned char get_timer_interrupt_state(unsigned char intr) {
  return TIFR & intr;
}

static inline void reset_timer_interrupt_state(unsigned char intr) {
  TIFR = intr;
}

#endif /* AT_TIMER_TINY26_H */
