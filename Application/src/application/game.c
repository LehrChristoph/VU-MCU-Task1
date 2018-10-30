/*
 * game.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include "application/game.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "avr_libs/basics/ADC.h"
#include "avr_libs/basics/Timer3.h"
#include "avr_libs/modules/rand.h"

#include "application/sound.h"

adc_mode_t current_adc_mode = ADC_MODE_VOLUME;

void game_ADC_callback(uint16_t adc_val);
void game_timer_callback(void);

uint8_t counter =0;

void game_init(void)
{

    sound_init();

    //setup ADC
    // ADC_select_channel(ADC_CHANNEL_ADC0);
    // ADC_select_prescaler(ADC_PRESCALER_128);
    // ADC_select_voltage_referance(ADC_REF_VCC);
    // ADC_adjust_right();
    // ADC_set_callback(&game_ADC_callback);
    // ADC_enable_interrupt();
    // ADC_enable();


    // configure a 5ms timer
    // timer3_set_waveform_generation_mode(TIMER3_CTC_MODE_TOP_OCR3A);
    // timer3_set_prescaler(TIMER3_PRESCALER_8);
    // timer3_set_output_compare_A(50);
    // timer3_enable_output_compare_interrupt_A(&game_timer_callback);
    // timer3_activate_output_A(TIMER3_CTC_NO_PORT_OPERATION);
    // timer3_reset_counter();

}

void game_timer_callback(void)
{

    // ADC_enable();
    // ADC_start_conversion();
    // PORTL = counter++;
    // sound_read_data();
}

void game_ADC_callback(uint16_t adc_val)
{

    // if(current_adc_mode == ADC_MODE_VOLUME)
    // {
    //     current_adc_mode = ADC_MODE_LFSR;
    //     ADC_select_channel(ADC_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_200X);
    //     uint8_t temp = (adc_val >> 2);
    //     // shift out lowest 2 bit, not relevant
    //     // sound_add_volume_val(temp);
    // }
    // else
    // {
    //     current_adc_mode = ADC_MODE_VOLUME;
    //     ADC_select_channel(ADC_CHANNEL_ADC0);
    //     uint8_t temp = adc_val & 0xFF;
    //     // not interested in shifted out bit
    //     (void) rand_shift(temp);
    //
    // }
    // ADC_disable();
}

void game_start(void)
{
    // display start screen

    // play startup theme
    sound_start_playing_startup();
}

void game_cyclic_check(void)
{
    // load new data if necessary
    sound_read_data();
    sound_send_data();
}
