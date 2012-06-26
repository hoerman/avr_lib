#ifndef AT_TIMER_TINY261_H
#define AT_TIMER_TINY261_H


#warning incomplete implementation...

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


#define TIMER0_16BIT_WIDTH (0x80) /**< Flag to set timer to 16bit width mode.
				   *   Use set_timer0_mode to set this flag.
				   */
#define TIMER0_IC_MODE (0x40) /**< Flag to set timer to input capture mode.
			       *   Use set_timer0_mode to set this flag.
			       */
#define TIMER0_IC_NOISE_CANCELER (0x20) /**< Flag to enable noise canceler for
					 *   input canceler mode.
					 *   Use set_timer0_mode to set this
					 *   flag.
					 */
#define TIMER0_IC_FALLING_EDGE (0x00) /**< Flag to select input capture on
				       *   falling edge.
				       *
				       *   Use set_timer0_mode or 
				       *   set_timer0_ic_edge to set this
				       *   flag.
				       */
#define TIMER0_IC_RISING_EDGE (0x10) /**< Flag to select input capture on
				       *   falling edge.
				       *
				       *   Use set_timer0_mode or 
				       *   set_timer0_ic_edge to set this
				       *   flag.
				       */
#define TIMER0_IC_ANALOG_COMPARATOR (0x08) /**< Flag to use analog comparator
					    *   for input capture.
					    *
					    *   Use set_timer0_mode to set this
					    *   flag.
					    */
#define TIMER0_NORMAL_MODE (0x00) /**< Set timer0 to normal mode.
				   *
				   *   Use set_timer0_mode to set this
				   *   flag.
				   */
#define TIMER0_CCM_MODE (0x01)    /**< Set timer0 to clear on compare match
				   *   mode.
				   *
				   *   Use set_timer0_mode to set this
				   *   flag.
				   */
#define TIMER0_MODE_MASK ((unsigned char) ~0x06) /**< Internaly used to check
						  *   parameters given to
						  *   set_timer0_mode().
						  */
#define TIMER0_MATCH_A_INT (0x10) /**< Flag to enable/check interrupt on match
				  *    to compare register OCR0A.
				  */
#define TIMER0_MATCH_B_INT (0x08) /**< Flag to enable/check interrupt on match
				  *    to compare register 0CR0B.
				  */
#define TIMER0_OVERFLOW_INT (0x02) /**< Flag to enable/check interrupt on
				    *   timerß overflow.
				    */
#define TIMER0_IC_INT (0x02) /**< Flag to enable/check interrupt on
			      *   timer0 input compare match.
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


/** comments of this section are wrong for normal mode!!! */
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

#define TIMER1_PWM_OCD1_DIS (0x00) /**< Disable output of PWM signal D. */
#define TIMER1_PWM_OCD1_COCM_BOTH (0x04) /**< Clear PWM signal on compare match,
					  *   enable normal and negated output.
					  */
#define TIMER1_PWM_OCD1_COCM (0x08) /**< Clear PWM signal on compare match,
				     *   enable ony normal output.
				     */
#define TIMER1_PWM_OCD1_SOCM (0x0c) /**< Set PWM signal on compare match,
				     *   enable ony normal output.
				     */
#define TIMER1_PWMD_ENABLE (0x01)  /**< Enables PWM mode for comparator D. */
#define TIMER1_PWMD_DISABLE (0x00) /**< Disable PWM mode for comparator D. */

#define TIMER1_PWM_OCD1_MASK ((unsigned char) ~0xc1)

#define TIMER1_MODE_FAST_PWM (0x00) /**< Set timer1 to fast pwm mode. */
#define TIMER1_MODE_PFC_PWM (0x01)  /**< Set timer1 to phase and frequency
				     *   correct pwm mode. */

#define TIMER1_MATCH_A_INT (0x40) /**< Flag to enable/check interrupt on match
				  *    to compare register OCR1A.
				  */
#define TIMER1_MATCH_B_INT (0x20) /**< Flag to enable/check interrupt on match
				  *    to compare register 0CR1B.
				  */
#define TIMER1_MATCH_D_INT (0x80) /**< Flag to enable/check interrupt on match
				  *    to compare register 0CR1D.
				  */
#define TIMER1_OVERFLOW_INT (0x04) /**< Flag to enable/check interrupt on
				    *   timerß overflow.
				    */

#define TIMER1_NORMAL_MODE (0x00) /**< Set timer1 to normal mode.
				   *
				   *   Use set_timer1_mode to set this
				   *   flag.
				   */

static inline void set_timer1_oca1_pwm_mode(unsigned char mode) {
  assert((mode & TIMER1_PWM_OCA1_MASK) == 0);

  TCCR1A = (TCCR1A & TIMER1_PWM_OCA1_MASK) | mode;
}

static inline void set_timer1_ocb1_pwm_mode(unsigned char mode) {
  assert((mode & TIMER1_PWM_OCB1_MASK) == 0);

  TCCR1A = (TCCR1A & TIMER1_PWM_OCB1_MASK) | mode;
}

static inline void set_timer1_ocd1_pwm_mode(unsigned char mode) {
  assert((mode & TIMER1_PWM_OCD1_MASK) == 0);

  TCCR1C = (TCCR1C & TIMER1_PWM_OCB1_MASK) | mode;
}

static inline void set_timer1_clk_source(unsigned char src) {
  assert((src & (unsigned char) ~TIMER1_CLK_MASK) == 0);

  TCCR1B = src;
}

static inline void set_timer1_mode(unsigned char mode) {
  TCCR1D = mode;
}

static inline void set_timer1_8(unsigned char val) {
  TCNT1 = val;
}

static inline unsigned char get_timer1_8(void) {
  return TCNT1;
}



static inline void set_timer1_compare_a_8(unsigned char val) {
  OCR1A = val;
}

static inline void set_timer1_compare_b_8(unsigned char val) {
  OCR1B = val;
}

static inline void set_timer1_compare_c_8(unsigned char val) {
  OCR1C = val;
}

static inline void set_timer1_compare_d_8(unsigned char val) {
  OCR1D = val;
}

static inline void set_timer1_compare_a(unsigned char val) {
  set_timer1_compare_a_8(val);
}

static inline void set_timer1_compare_b(unsigned char val) {
  set_timer1_compare_b_8(val);
}

static inline void set_timer1_compare_c(unsigned char val) {
  set_timer1_compare_c_8(val);
}

static inline void set_timer1_compare_d(unsigned char val) {
  set_timer1_compare_d_8(val);
}

static inline void set_timer0_mode(unsigned char mode) {
  assert((mode & ((unsigned char) ~TIMER0_MODE_MASK)) == 0);

  TCCR0A = mode;
}

static inline void set_timer0_ic_edge(unsigned char mode) {
  assert(mode == TIMER0_IC_RISING_EDGE ||
	 mode == TIMER0_IC_FALLING_EDGE);

  if (mode == TIMER0_IC_RISING_EDGE) {
    TCCR0A = TCCR0A | TIMER0_IC_RISING_EDGE;
  } else {
    TCCR0A = TCCR0A & ((unsigned char) ~TIMER0_IC_RISING_EDGE);
  }
}  

static inline void set_timer0_16(unsigned int val) {
  unsigned char sreg = SREG;
  _CLI();
  TCNT0H = (unsigned char) (val >> 8);
  TCNT0L = (unsigned char) val;
  SREG = sreg;
}

static inline void set_timer0_8(unsigned char val) {
  TCNT0L = val;
}

static inline unsigned int get_timer0_16(void) {
  unsigned int ret;
  unsigned char sreg = SREG;
  _CLI();

  ret = TCNT0L;
  ret |= ((unsigned int) TCNT0H << 8);

  SREG = sreg;

  return ret;
}

static inline unsigned char get_timer0_8(void) {
  return TCNT0L;
}

static inline void set_timer0_compare_a(unsigned char val) {
  OCR0A = val;
}

static inline void set_timer0_compare_b(unsigned char val) {
  OCR0B = val;
}

static inline void set_timer0_compare_16(unsigned int val) {
  unsigned char sreg = SREG;
  _CLI();
  OCR0B = (unsigned char) (val >> 8);
  OCR0A = (unsigned char) val;
  SREG = sreg;
}

static inline void set_timer0_clk_source(unsigned char src) {
  assert((src & (unsigned char) ~TIMER0_CLK_MASK) == 0);

  TCCR0B = src;
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

#endif /* AT_TIMER_TINY261_H */
