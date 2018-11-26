/*
 * sound.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include "application/sound.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/atomic.h>

#include "modules/Tasker.h"
#include "application/field.h"
#include "application/mp3.h"
#include "application/spi.h"
#include "application/sdcard.h"

static uint8_t sound_buffer[BLOCK_SIZE];
static uint32_t start_address = 0;
static uint32_t current_address = 0;
static uint32_t end_address = 0;

static uint8_t volume = 0;
static uint8_t volume_buffer[SOUND_VOLUME_BUFFER_SIZE];
static uint8_t volume_index = 0;

static buffer_state_t buffer_state = BUFFER_EMPTY;
static mp3_state_t mp3_state = REQUEST_DATA;

// Tetris
#define THEME_ADDRESS 6778144
#define THEME_LENGTH 281808

// dt_bossdrum
#define STATRTUP_SOUND_ADDRESS 4030368
#define STATRTUP_SOUND_LENGTH 330048

// z2cave
#define GAME_OVER_SOUND_ADDRESS 7148256
#define GAME_OVER_SOUND_LENGH 121968

static uint8_t sound_task_id_volume_task =-1;
static uint8_t sound_task_id_cyclic_task =-1;
static uint8_t sound_volume_changed=0;

void sound_mp3_callback(void);
void sound_cyclic_task(void);

void sound_init(void)
{
    spiInit();

    error_t error_code = sdcardInit();

    if(error_code != SUCCESS)
    {

        if(error_code == E_TIMEOUT)
        {
            field_display_error(ERROR_SD_TIMEOUT);
        }
        else if(error_code == E_NOCARD)
        {
            field_display_error(ERROR_NO_CARD);
        }
        else if(error_code == E_UNKNOWN_CARD)
        {
            field_display_error(ERROR_UNKNOWN_CARD);
        }
        else
        {
            field_display_error(ERROR_SD_GENERAL);
        }
    }

    mp3Init(&sound_mp3_callback);

    mp3SetVolume(0);

    sound_task_id_cyclic_task =  Tasker_add_task(0x12, sound_cyclic_task, 7);
    sound_task_id_volume_task =  Tasker_add_task(0x11, sound_set_volume, 100);

    sound_volume_changed = 0x00;

}

void sound_cyclic_task(void)
{
    sound_read_data();
    sound_send_data();
}


void sound_mp3_callback(void)
{
    mp3_state = REQUEST_DATA;
}


void sound_send_data(void)
{
    if(mp3_state == REQUEST_DATA)
    {
        mp3SendMusic(sound_buffer);
        buffer_state = BUFFER_EMPTY;
    }
}

void sound_add_volume_val(uint8_t sound_input)
{
    volume_buffer[volume_index] = sound_input;
    if(++volume_index == SOUND_VOLUME_BUFFER_SIZE)
    {
        for(uint8_t i =1; i < SOUND_VOLUME_BUFFER_SIZE-1; ++i)
        {
            for(uint8_t j =0; j < SOUND_VOLUME_BUFFER_SIZE-1; ++j)
            {
                if(volume_buffer[j] > volume_buffer[j+1])
                {
                    uint8_t temp = volume_buffer[j+1];
                    volume_buffer[j+1] = volume_buffer[j];
                    volume_buffer[j] = temp;
                }
            }
        }
        if(volume_buffer[SOUND_VOLUME_BUFFER_SIZE/2] != volume)
        {
            volume = volume_buffer[SOUND_VOLUME_BUFFER_SIZE/2];
            sound_volume_changed = 0xFF;
        }

        volume_index=0;
    }
}

void sound_set_volume(void)
{
    if(mp3Busy() == false && sound_volume_changed)
    {
        sound_volume_changed = 0x00;

        uint16_t calc_volume = 0xFF;

        ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
        {
            calc_volume -= volume;
        }

        calc_volume *= calc_volume;
        calc_volume >>= 8;
        calc_volume *= calc_volume;
        calc_volume >>= 8;

        // invert scale
        calc_volume = 0xFF-calc_volume;

        mp3SetVolume(calc_volume);

    }
}

void sound_read_data()
{

    if (buffer_state == BUFFER_FULL)
    {
        return;
    }

    error_t error_code = sdcardReadBlock(current_address, sound_buffer);

    if(error_code != SUCCESS)
    {

        if(error_code == E_TIMEOUT)
        {
            field_display_error(ERROR_SD_TIMEOUT);
        }
        else if(error_code == E_NOCARD)
        {
            field_display_error(ERROR_NO_CARD);
        }
        else if(error_code == E_UNKNOWN_CARD)
        {
            field_display_error(ERROR_UNKNOWN_CARD);
        }
        else
        {
            field_display_error(ERROR_SD_GENERAL);
        }
    }

    current_address+=32;

    if( current_address >= end_address)
    {
        current_address = start_address;
    }

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        buffer_state = BUFFER_FULL;

        if(mp3Busy() == false)
        {
            mp3_state = REQUEST_DATA;
        }
        else
        {
            mp3_state = MP3_FULL;
        }
    }

}

void sound_start_playing_startup(void)
{
     current_address = start_address = STATRTUP_SOUND_ADDRESS;
     end_address = STATRTUP_SOUND_ADDRESS + STATRTUP_SOUND_LENGTH;
     buffer_state = BUFFER_EMPTY;
     sound_read_data();
}

void sound_start_playing_theme(void)
{
    current_address = start_address = THEME_ADDRESS;
    end_address = THEME_ADDRESS + THEME_LENGTH;
    buffer_state = BUFFER_EMPTY;
}

void sound_play_game_over(void)
{
    current_address = start_address = GAME_OVER_SOUND_ADDRESS;
    end_address = GAME_OVER_SOUND_ADDRESS + GAME_OVER_SOUND_LENGH;
    buffer_state = BUFFER_EMPTY;
}
