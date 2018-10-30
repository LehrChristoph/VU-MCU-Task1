/*
 * sound.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include "application/sound.h"

#include <avr/io.h>
#include <stdbool.h>
#include <util/atomic.h>

#include "modules/Tasker.h"

#include "application/mp3.h"
#include "application/spi.h"
#include "application/sdcard.h"

uint8_t sound_buffer[BLOCK_SIZE];
uint32_t start_address = 0;
uint32_t current_address = 0;
uint32_t end_address = 0;

uint8_t volume = 0;
uint8_t volume_buffer[SOUND_VOLUME_BUFFER_SIZE];
uint8_t volume_index = 0;

buffer_state_t buffer_state = BUFFER_EMPTY;
mp3_state_t mp3_state = REQUEST_DATA;

// Tetris
#define THEME_ADDRESS 6778144
#define THEME_LENGTH 281808

// dt_bossdrum
#define STATRTUP_SOUND_ADDRESS 4030368
#define STATRTUP_SOUND_LENGTH 330048

// z2cave
#define GAME_OVER_SOUND_ADDRESS 7148256
#define GAME_OVER_SOUND_LENGH 121968

uint8_t task_id_volume_task =-1;

void sound_mp3_callback(void);

void sound_init(void)
{
    spiInit();

    error_t error_code = sdcardInit();

    if(error_code != SUCCESS)
    {
        // TODO: handle errors
    }

    mp3Init(&sound_mp3_callback);

    while(mp3Busy() == true);

    mp3SetVolume(0xF5);


    task_id_volume_task =  Tasker_add_task(0x11, sound_set_volume, 0);
    if(Tasker_pause_task(task_id_volume_task) == TASKER_ERROR)
    {
        //TODO add error handling
    }

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
            Tasker_resume_task(task_id_volume_task, 1);
        }

        volume_index=0;
    }
}

void sound_set_volume(void)
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        if(mp3Busy() == false)
        {
            mp3SetVolume(volume);
            Tasker_pause_task(task_id_volume_task);
        }
        else
        {
            Tasker_resume_task(task_id_volume_task, 1);
        }
    }
}

void sound_read_data()
{
    if (buffer_state == BUFFER_FULL)
    {
        return;
    }

    error_t error_code = sdcardReadBlock(current_address, sound_buffer);

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
    sound_read_data();
}

void sound_play_game_over(void)
{
    current_address = start_address = GAME_OVER_SOUND_ADDRESS;
    end_address = GAME_OVER_SOUND_ADDRESS + GAME_OVER_SOUND_LENGH;
    buffer_state = BUFFER_EMPTY;
    sound_read_data();
}
