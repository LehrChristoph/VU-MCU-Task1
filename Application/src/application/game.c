/*
 * game.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */
 
#include "application/game.h"

#include <avr/io.h>

#include "avr_libs/basics/ADC.h"
#include "avr_libs/basics/Timer1.h"
#include "avr_libs/modules/rand.h"

#include "application/sound.h"

adc_mode_t current_adc_mode = ADC_MODE_VOLUME;

void game_ADC_callback(uint8_t adc_val);
void game_timer_callback(void);

void game_init(void)
{
    sound_init();

    // setup ADC
    ADC_select_channel(ADC_CHANNEL_ADC0);
    ADC_select_channel(ADC_PRESCALER_16);
    ADC_adjust_right();
    ADC_enable();

    // configure a 5ms timer
    timer1_set_waveform_generation_mode(TIMER1_CTC_MODE_TOP_OCR1A);
    timer1_set_prescaler(TIMER1_PRESCALER_64);
    timer1_set_output_compare_A(1250);
    timer1_enable_output_compare_interrupt_A(&game_timer_callback);
    timer1_activate_output_A(TIMER1_CTC_NO_PORT_OPERATION);

}

void game_timer_callback(void)
{
    ADC_start_conversion();
}

void game_ADC_callback(uint16_t adc_val)
{
    if(current_adc_mode == ADC_MODE_VOLUME)
    {
        current_adc_mode = ADC_MODE_LFSR;
        ADC_select_channel(ADC_PRESCALER_128);
        ADC_select_channel(ADC_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_200X);
        uint8_t temp = (adc_val >> 2) & 0xFF;
        // shift out lowest 2 bit, not relevant
        sound_add_volume_val(temp);
    }
    else
    {
        current_adc_mode = ADC_MODE_VOLUME;
        ADC_select_channel(ADC_CHANNEL_ADC0);
        ADC_select_channel(ADC_PRESCALER_16);
        uint8_t temp = adc_val & 0xFF;
        // not interested in shifted out bit
        (void) rand_shift(temp);
    }
}

void game_start(void)
{
    // display start screen

    // play startup theme
    sound_start_playing_startup();
}
