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

#include "application/controls.h"

void main_send_music(void);


int main(int argc, char const *argv[])
{

    PORTH = 0x00;
    DDRH = 0xFF;

    PORTK = 0x00;
    DDRK = 0xFF;

    PORTL = 0x00;
    DDRL = 0xFF;

    Tasker_init();
    game_init();
    sei();
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    game_start();

    uint16_t counter;
    uint8_t counter_out;
    while(1)
    {
        // sleep_cpu();
        // while(mp3Busy() == true);
        // game_cyclic_check();
        PORTH ^= (1 << PORTH0);
        Task_dispatch_tasks();
        PORTH ^= (1 << PORTH1);
        counter++;
        if(counter > 1000)
        {
            counter_out++;
            counter=0;
            PORTL = counter_out;
        }
    }

    // sei();
    // controls_init();
    // while(1);

}
