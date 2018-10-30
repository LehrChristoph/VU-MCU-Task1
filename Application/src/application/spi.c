/*
 * SPI.c
 *
 *  Created on: 22 OCtober 2018
 *      Author: christoph
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "spi.h"

void spiInit(void)
{
    uint8_t temp = PORTB;
    PORTB =  (temp | 1 << PB3);
    temp = DDRB & 0xF0;
    DDRB = (temp | 1 << PB1 | 1 << PB2);

    temp = SPCR;
    temp |=  (1 << MSTR | 1 << SPE);
    temp &= ~(1 << DORD | 1 << CPOL | 1 << CPHA);
    SPCR = temp;
}

void spiSend(uint8_t data)
{
    // send data
    SPDR = data;
    SPCR |=  (1 << MSTR );
    // wait until transfer is completed
    while((SPSR & (1<<SPIF)) == 0);

}

uint8_t spiReceive(void)
{
    // send dummy byte
    SPDR = 0xFF;
    // wait until transfer is completed
    while(!(SPSR & (1<<SPIF) ));
    // return received data
    return SPDR;
}

void spiSetPrescaler(spi_prescaler_t prescaler)
{

    switch (prescaler)
    {
        case SPI_PRESCALER_128:
            SPCR |=  (1 << SPR1 | 1 << SPR0);
            SPSR &= ~(1 << SPI2X);
            break;
    	case SPI_PRESCALER_4:
            SPCR &= ~(1 << SPR1 | 1 << SPR0);
            SPSR &= ~(1 << SPI2X);
            break;
    }
}
