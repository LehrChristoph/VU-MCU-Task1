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
    SPCR |=  (1 << SPE | 1 << MSTR );
    SPCR &= ~(1 << DORD | 1 << CPOL | 1 << CPHA);
}

void spiSend(uint8_t data)
{
    // check if transfer is currently active
    while(!(SPSR & (1<<SPIF) ));
    // send data
    SPDR = data;
    // wait until transfer is completed
    while(!(SPSR & (1<<SPIF) ));
}

uint8_t spiReceive(void)
{
    uint8_t data= 0xFF;
    // wait until last transfer is finished
    while(!(SPSR & (1<<SPIF) ));
    // send dummy byte
    SPDR = data;
    // wait until transfer is completed
    while(!(SPSR & (1<<SPIF) ));
    // retrieve data
    data = SPDR;
    return data;
}
void spiSetPrescaler(spi_prescaler_t prescaler)
{
    switch prescaler
        case SPI_PRESCALER_128:
        {
            SPCR |=  (1 << SPR1 | 1 << SPR0);
            SPSR &= ~(1 << SP2X);
            break;
        }
    	case SPI_PRESCALER_4:
        {
            SPCR &= ~(1 << SPR1 | 1 << SPR0);
            SPSR &= ~(1 << SP2X);
            break;
        }
}
