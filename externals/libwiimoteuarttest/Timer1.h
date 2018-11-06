/*
 * Timer1.h
 *
 *  Created on: 5 Oct 2018
 *      Author: christoph
 */

#ifndef AVR_LIBS_TIMER1_H_
#define AVR_LIBS_TIMER1_H_

#define TIMER1_DISCONNECT 0
#define TIMER1_NO_PRESCALER 1
#define TIMER1_PRESCALER_8 2
#define TIMER1_PRESCALER_64 3
#define TIMER1_PRESCALER_256 4
#define TIMER1_PRESCALER_1024 5
#define TIMER1_PRESCALER_EXTERNAL_CLOCK_FALLING_EDGE 6
#define TIMER1_PRESCALER_EXTERNAL_CLOCK_RISING_EDGE 7

#define TIMER1_NORMAL_MODE 0
#define TIMER1_PWM_MODE_PHASE_CORRECT_8_BIT 1
#define TIMER1_PWM_MODE_PHASE_CORRECT_9_BIT 2
#define TIMER1_PWM_MODE_PHASE_CORRECT_10_BIT 3
#define TIMER1_CTC_MODE_TOP_OCR1A 4
#define TIMER1_PWM_FAST_MODE_8_BIT 5
#define TIMER1_PWM_FAST_MODE_9_BIT 6
#define TIMER1_PWM_FAST_MODE_10_BIT 7
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1 8
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_TOP_OCR1A 9
#define TIMER1_PHASE_CORRECT_16_BIT_TOP_ICR1 10
#define TIMER1_PHASE_CORRECT_16_BIT_TOP_OCR1A 11
#define TIMER1_CTC_MODE_TOP_ICR1 12
#define TIMER1_PWM_FAST_MODE_16_BIT_TOP_ICR1 14
#define TIMER1_PWM_FAST_MODE_16_BIT_TOP_OCR1A 15

#define TIMER1_CTC_NO_PORT_OPERATION 0
#define TIMER1_CTC_TOGGLE_PORT_ON_COMPARE_MATCH 1
#define TIMER1_CTC_CLEAR_PORT_ON_COMPARE_MATCH 2
#define TIMER1_CTC_SET_PORT_ON_COMPARE_MATCH 3

#define TIMER1_PWM_NO_PORT_OPERATION 0
#define TIMER1_PWM_TOGGLE_OC1A 1
#define TIMER1_PWM_NON_INVERTING_MODE 2
#define TIMER1_PWM_INVERTING_MODE 3

#include <avr/io.h>

/*! \fn void timer1_set_prescaler(uint8_t prescaler)
    \brief Sets the prescaler for Timer0.
    \param prescaler
    	0	turn off timer 1
    	1 	for no prescaler
    	2   for f/8
    	3   for f/64
    	4   for f/256
    	5   for f/1024
    	6 	use external clock, clock on falling edge
    	7 	use external clock, clock on rising edge
*/
void timer1_set_prescaler(uint8_t prescaler);

/*! \fn void timer1_set_waveform_generation_mode(uint8_t mode)
    \brief Sets the mode of the waveform generator
    \param mode
    	0   normal mode
    	1   activates Phase-Correct 8-bit PWM
        2   activates Phase-Correct 9-bit PWM
        3   activates Phase-Correct 10-bit PWM
    	4   activates CTC Mode, using OCR1A as TOP
    	5   activates Fast PWM 8-bit
        6   activates Fast PWM 9-bit
        7   activates Fast PWM 10-bit
        8   activate Phase and Frequency-Correct PWM, using ICR1 as TOP
        9   activate Phase and Frequency-Correct PWM, using OCR1A as TOP
        10  activates Phase-Correct 10-bit PWM, using ICR1 as TOP
        11  activates Phase-Correct 10-bit PWM, using OCR1A as TOP
        12  activates CTC Mode, using ICR1 as TOP
        13  reserved
        14  activates Fast PWM 16-bit, using ICR1 as TOP
        15  activates Fast PWM 16-bit, using OCR1A as TOP
*/
void timer1_set_waveform_generation_mode(uint8_t mode);

/*! \fn void timer1_set_waveform_generation_mode_A(uint8_t mode)
    \brief Sets the output mode of the non inverting output PB1 and inverting output PB0
    \param mode
    	In CTC mode:
    		0   no port operation
    		1   toggle pin on compare match
    		2   clear pin on compare match
    		3   set pin on compare match
		In a PWM mode:
    		0   no port operation
    		1   toggle OCR1A pin on compare match
    		2   activates non inverting mode at output (PB1)
    		3   activates inverting mode at output (PB1)
*/
void timer1_activate_output_A(uint8_t mode);

/*! \fn void timer1_set_waveform_generation_mode_B(uint8_t mode)
    \brief Sets the output mode of the non inverting output PB4 and inverting output PB3
    \param mode
    	In CTC mode:
    		0   no port operation
    		1   toggle pin on compare match
    		2   clear pin on compare match
    		3   set pin on compare match
		In a PWM mode:
    		0   no port operation
    		2   activates non inverting mode at output (PB4)
    		3   activates inverting mode at output (PB4)
*/
void timer1_activate_output_B(uint8_t mode);

/*! \fn void timer1_set_waveform_generation_mode_B(uint8_t mode)
    \brief Sets the output mode of the non inverting output PB4 and inverting output PB3
    \param mode
    	In CTC mode:
    		0   no port operation
    		1   toggle pin on compare match
    		2   clear pin on compare match
    		3   set pin on compare match
		In a PWM mode:
    		0   no port operation
    		2   activates non inverting mode at output (PB4)
    		3   activates inverting mode at output (PB4)
*/
void timer1_activate_output_C(uint8_t mode);


/*! \fn void timer1_enable_overflow_interrupt(void (*callback)(void))
    \brief Enables the timer overflow interrupt and sets the callback function
    \param callback The callback function which gets called when the interrupt occurs.
    	CAUTION: interrupt is blocking
*/
void timer1_enable_overflow_interrupt(void (*callback)(void));

/*! \fn void timer1_disable_overflow_interrupt(void)
    \brief Disables the timer overflow interrupt
*/
void timer1_disable_overflow_interrupt(void);

/*! \fn void timer1_enable_output_compare_interrupt_A(void (*callback)(void))
    \brief Enables the timer compare match for output A
    \param callback The callback function which gets called when the interrupt occurs.
    	CAUTION: interrupt is blocking
*/
void timer1_enable_output_compare_interrupt_A(void (*callback)(void));

/*! \fn void timer1_disable_output_compare_interrupt_A(void)
    \brief Disables the output compare interrupt A
*/
void timer1_disable_output_compare_interrupt_A(void);

/*! \fn void timer1_enable_output_compare_interrupt_B(void (*callback)(void))
    \brief Enables the timer compare match for output B
    \param callback The callback function which gets called when the interrupt occurs.
    	CAUTION: interrupt is blocking
*/
void timer1_enable_output_compare_interrupt_B(void (*callback)(void));

/*! \fn void timer1_disable_output_compare_interrupt_B(void)
    \brief Disables the output compare interrupt B
*/
void timer1_disable_output_compare_interrupt_B(void);

/*! \fn void timer1_enable_output_compare_interrupt_C(void (*callback)(void))
    \brief Enables the timer compare match for output C
    \param callback The callback function which gets called when the interrupt occurs.
    	CAUTION: interrupt is blocking
*/
void timer1_enable_output_compare_interrupt_C(void (*callback)(void));

/*! \fn void timer1_disable_output_compare_interrupt_C(void)
    \brief Disables the output compare interrupt C
*/
void timer1_disable_output_compare_interrupt_C(void);

/*! \fn void timer1_set_output_compare_A(uint8_t value);
    \brief Sets the value of the output compare register for output A/PB0
    \param value New value of the output compare register
*/
void timer1_set_output_compare_A(uint16_t value);

/*! \fn void timer1_increase_output_compare_A(uint16_t value);
    \brief Increases the value of the output compare register for output A/PB0
    \param value The value to increase the current value of the output compare register
*/
void timer1_increase_output_compare_A(uint16_t value);

/*! \fn void timer1_decrease_output_compare_A(uint16_t value);
    \brief Decreases the value of the output compare register for output A/PB0
    \param value The value to decrease the current value of the output compare register
*/
void timer1_decrease_output_compare_A(uint16_t value);

/*! \fn uint16_t timer1_get_output_compare_A(void);
    \brief Returns the value of the current output compare register A
    \return The current value of the output compare register A
*/
uint16_t timer1_get_output_compare_A(void);



/*! \fn void timer1_set_output_compare_B(uint16_t value);
    \brief Sets the value of the output compare register for output B/PB1
    \param value New value of the output compare register
*/
void timer1_set_output_compare_B(uint16_t value);

/*! \fn void timer1_increase_output_compare_B(uint16_t value);
    \brief Increases the value of the output compare register for output B/PB1
    \param value The value to increase the current value of the output compare register
*/
void timer1_increase_output_compare_B(uint16_t value);

/*! \fn void timer1_decrease_output_compare_B(uint16_t value);
    \brief Decreases the value of the output compare register for output B/PB1
    \param value The value to decrease the current value of the output compare register
*/
void timer1_decrease_output_compare_B(uint16_t value);

/*! \fn uint16_t timer1_get_output_compare_B(void);
    \brief Returns the value of the current output compare register B
    \return The current value of the output compare register B
*/
uint16_t timer1_get_output_compare_B(void);



/*! \fn void timer1_set_output_compare_C(uint16_t value);
    \brief Sets the value of the output compare register OCR1C
    \param value New value of the output compare register
*/
void timer1_set_output_compare_C(uint16_t value);

/*! \fn void timer1_increase_output_compare_C(uint16_t value);
    \brief Increases the value of the output compare register OCR1C
    \param value The value to increase the current value of the output compare register
*/
void timer1_increase_output_compare_C(uint16_t value);

/*! \fn void timer1_decrease_output_compare_B(uint16_t value);
    \brief Decreases the value of the output compare register OCR1C
    \param value The value to decrease the current value of the output compare register
*/
void timer1_decrease_output_compare_C(uint16_t value);

/*! \fn uint16_t timer1_get_output_compare_C(void);
    \brief Returns the value of the current output compare register C
    \return The current value of the output compare register C
*/
uint16_t timer1_get_output_compare_C(void);

/*! \fn void timer1_reset_counter(void);
    \brief Resets the counter of Timer 1 
*/
void timer1_reset_counter(void);

/*! \fn void timer1_enable_input_capture_interrupt(void);
    \brief Enables the Input capture interrupt for timer 1
*/
void timer1_enable_input_capture_interrupt(void);

/*! \fn void timer1_disable_input_capture_interrupt(void);
    \brief Disables the Input capture interrupt for timer 1
*/
void timer1_disable_input_capture_interrupt(void);

#endif /* AVR_LIBS_TIMER1_H_ */
