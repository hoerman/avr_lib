#ifndef AT_TIMER_MEGA16_H
#define AT_TIMER_MEGA16_H

#define PWM_PC_OC0A_INVERTED (0x20) /**< Set OC0A pwm output to inverted
				     *   mode.
				     */
#define PWM_PC_OC0A_NORMAL   (0x30) /**< Set OC0A pwm output to normal
				     *    mode.
				     */
#define PWM_PC_MODE          (0x40)      /**< Flag to set phase correct pwm
					  *   mode.
					  */
#define PWM_MODE_MASK (0x48 | 0x30)      /**< Bitmask for setting timer mode. */

#define TIMER_CLK_SRC_DISABLED (0x00) /**< Disable timer module. */
#define TIMER_CLK_SRC_CLKIO    (0x01) /**< Use IO clock as timer clock. */
#define TIMER_CLK_SRC_CLKIO_8  (0x02) /**< Use IO clock divided by 8 as
				       *   timer clock.
				       */
#define TIMER_CLK_SRC_CLKIO_64  (0x03)/**< Use IO clock divided by 64 as
				       *   timer clock.
				       */
#define TIMER_CLK_SRC_CLKIO_256 (0x04) /**< Use IO clock divided by 256 as
					*   timer clock.
					*/
#define TIMER_CLK_SRC_CLKIO_1024 (0x05) /**< Use IO clock divided by 1024 as
					 *   timer clock.
					 */
#define TIMER_CLK_SRC_EXT_FALLING (0x06) /**< Use falling edge of external T0
					  *   pin as timer clock.
					  */
#define TIMER_CLK_SRC_EXT_RISING  (0x07) /**< Use rising edge of external T0
					  *   pin as timer clock.
					  */
#define TIMER_CLK_MASK (0x07) /**< Mask for setting clocksource. */

#define TIMER_MATCH_A_INT (0x04) /**< Flag to enable/check interrupt on match to
				  *   compare register 0a.
				  */
#define TIMER_MATCH_B_INT (0x08) /**< Flag to enable/check interrupt on match to
				  *   compare register 0b.
				  */
#define TIMER_OVERFLOW_INT (0x02) /**< Flag to enable/check interrupt on
				   *   timer overflow.
				   */



static inline void set_timer_mode(unsigned char mode) {
  TCCR0 = (TCCR0 & ~PWM_MODE_MASK) | (mode & PWM_MODE_MASK);
}

static inline void set_timer_clk_source(unsigned char src) {
  TCCR0 = (TCCR0 & ~TIMER_CLK_MASK) | (src & TIMER_CLK_MASK);
}

static inline void set_timer_compare_0a(unsigned char val) {
  OCR0 = val;
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

#endif /* AT_TIMER_MEGA16_H */
