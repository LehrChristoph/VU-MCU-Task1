/*
 * sound.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include "application/sound.h"

#include <avr/io.h>
#include <stdbool.h>

#include "modules/QueuedExecuter.h"

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

// Tetris
#define THEME_ADDRESS 6778144
#define THEME_LENGTH 281808

// dt_bossdrum
#define STATRTUP_SOUND_ADDRESS 4030368
#define STATRTUP_SOUND_LENGTH 330048

// z2cave
#define GAME_OVER_SOUND_ADDRESS 7148256
#define GAME_OVER_SOUND_LENGH 121968

void sound_init(void)
{
    spiInit();
    // TODO: handle errors
    error_t error_code = sdcardInit();
    mp3Init(&sound_send_data);
}

void sound_send_data(void)
{
    mp3SendMusic(sound_buffer);
    QueuedExecuter_add_function_call(&sound_read_data);
}

void sound_add_volume_val(uint8_t sound_input)
{
    volume_buffer[volume_index] = sound_input;
    if(++volume_index == SOUND_VOLUME_BUFFER_SIZE)
    {
        QueuedExecuter_add_function_call(&sound_set_volume);
        volume_index=0;
    }
}

void sound_set_volume(void)
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
        mp3SetVolume(volume);
    }
}

void sound_read_data()
{
     error_t error_code = sdcardReadBlock(current_address, sound_buffer);

     // unable to read data, reschedule sd card access
     if(error_code != SUCCESS)
     {
         QueuedExecuter_add_function_call(&sound_read_data);
     }

     current_address+=32;

     if( current_address >= end_address)
     {
         current_address = start_address;
     }

     if(mp3Busy() == false)
     {
         sound_send_data();
     }
}

void sound_start_playing_startup(void)
{
     current_address = start_address = STATRTUP_SOUND_ADDRESS;
     end_address = STATRTUP_SOUND_ADDRESS + STATRTUP_SOUND_LENGTH;
     sound_read_data();
}

void sound_start_playing_theme(void)
{
    current_address = start_address = THEME_ADDRESS;
    end_address = THEME_ADDRESS + THEME_LENGTH;
    sound_read_data();
}

void sound_play_game_over(void)
{
    current_address = start_address = GAME_OVER_SOUND_ADDRESS;
    end_address = GAME_OVER_SOUND_ADDRESS + GAME_OVER_SOUND_LENGH;
    sound_read_data();
}
