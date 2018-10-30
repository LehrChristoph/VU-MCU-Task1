/*
 * main.c
 *
 *  Created on: 23 Oct 2018
 *      Author: christoph
 */

#include <avr/io.h>

#include <avr/interrupt.h>
#include <avr/sleep.h>

#include "application/game.h"
#include "avr_libs/modules/QueuedExecuter.h"

#include "application/sound.h"
// #include "application/spi.h"
#include "application/mp3.h"
// #include "application/sdcard.h"

void init_application(void);
void main_send_music(void);

// sdcard_block_t  sound_buffer_main;

int main(int argc, char const *argv[])
{
    uint8_t counter =0;

    game_init();
    sei();
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    game_start();

    // uint32_t start_address = 6778144;
    // uint32_t current_address = 6778144;
    // uint32_t end_address = start_address + 281808;
    //
    // PORTH = 0x00;
    // DDRH = 0xFF;
    // current_address = start_address;
    // spiInit();
    // error_t error_code = sdcardInit();
    //
    // mp3Init(&main_send_music);
    // mp3SetVolume(0xFF);
    //
    while(1)
    {
        // sleep_cpu();
        // while(mp3Busy() == true);
        game_cyclic_check();
    }

    // game_init();

    // game_start();
    // while(1)
    // {
    //     // if(QueuedExecuter_get_queue_lenght() == 0)
    //     // {
    //     //     PORTH = 0xFF;
    //     //     sleep_cpu();
    //     // }
    //     // QueuedExecuter_execute_queued_functions();
    //     sleep_cpu();
    // }
}

// void main_send_music(void)
// {
//     mp3SendMusic(sound_buffer_main);
// }
