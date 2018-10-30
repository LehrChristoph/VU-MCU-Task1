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
#include "modules/Tasker.h"

// #include "application/sound.h"
// #include "application/spi.h"
// #include "application/mp3.h"
// #include "application/sdcard.h"

void main_send_music(void);


int main(int argc, char const *argv[])
{
    uint8_t counter =0;
    Tasker_init();
    game_init();
    sei();
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    game_start();


    while(1)
    {
        sleep_cpu();
        // while(mp3Busy() == true);
        // game_cyclic_check();
        Task_dispatch_tasks();
    }

}
