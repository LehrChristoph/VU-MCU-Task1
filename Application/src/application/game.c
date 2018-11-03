/*
 * game.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include "application/game.h"

#include <avr/io.h>
#include <avr/interrupt.h>

#include "basics/ADC.h"
#include "modules/rand.h"
#include "modules/Tasker.h"

#include "application/field.h"
#include "application/sound.h"

adc_mode_t current_adc_mode = ADC_MODE_VOLUME;

void game_ADC_callback(uint16_t adc_val);
void game_start_adc(void);
void game_cyclic_check(void);

uint8_t counter =0;
uint8_t task_id_cyclic_task =-1;
uint8_t task_id_adc_task =-1;


void game_init(void)
{
    sound_init();
    field_init();

    //setup ADC
    ADC_select_channel(ADC_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_200X);
    ADC_select_prescaler(ADC_PRESCALER_128);
    ADC_select_voltage_referance(ADC_REF_VCC);
    ADC_adjust_right();
    ADC_set_callback(&game_ADC_callback);
    ADC_enable_interrupt();

    game_task_id_adc_task =  Tasker_add_task(0x01, game_start_adc, 10);

}

void game_start_adc(void)
{

    ADC_enable();
    ADC_start_conversion();
}

void game_ADC_callback(uint16_t adc_val)
{

    if( current_adc_mode == ADC_MODE_INIT_LFSR)
    {
        current_adc_mode = ADC_MODE_NEXT_VOLUME;
        ADC_select_channel(ADC_CHANNEL_ADC0);

        rand_init(adc_val);
    }
    // throw away first conversion for volume
    else if(current_adc_mode == ADC_MODE_NEXT_VOLUME)
    {
        current_adc_mode = ADC_MODE_VOLUME;
        ADC_start_conversion();
    }
    else if(current_adc_mode == ADC_MODE_VOLUME)
    {
        current_adc_mode = ADC_MODE_NEXT_LFSR;
        ADC_select_channel(ADC_CHANNEL_DIFFERENTIAL_ADC3_ADC2_GAIN_200X);
        // shift out lowest 2 bit, not relevant
        uint8_t temp = (adc_val >> 2);
        sound_add_volume_val(temp);
        ADC_disable();
    }
    // throw away first conversion for lfrs
    else if(current_adc_mode == ADC_MODE_NEXT_LFSR)
    {
        current_adc_mode = ADC_MODE_LFSR;
        ADC_start_conversion();
    }
    else
    {
        current_adc_mode = ADC_MODE_NEXT_VOLUME;
        ADC_select_channel(ADC_CHANNEL_ADC0);
        uint8_t temp = adc_val & 0xFF;
        // not interested in shifted out bit
        (void) rand_shift(temp);
        ADC_disable();
    }

}

void game_start(void)
{
    // display start screen

    // play startup theme
    sound_start_playing_startup();
}

void game_cyclic_check(void)
{
    sound_read_data();
    sound_send_data();
}
