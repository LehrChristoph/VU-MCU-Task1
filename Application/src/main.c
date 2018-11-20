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

int main(int argc, char const *argv[])
{

    Tasker_init();
    game_init();
    sei();
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
    game_start();

    while(1)
    {
        sleep_cpu();

        Task_dispatch_tasks();

    }

}
