/*
 * rand.c
 *
 *  Created on: 22 Oct 2018
 *      Author: christoph
 */

#include <stdint.h>
#include <util/atomic.h>

#include "rand.h"

uint16_t LFSR=1;

/**
 * Shift the LFSR to the right, shifting in the LSB of the parameter. Usually
 * not called directly; use the high−level functions below.
 *
 * Returns: The bit shifted out of the LFSR.
 */
uint8_t rand_shift(uint8_t in)
{
    uint8_t out=0;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        asm volatile(
            "lsr %[input]"              "\n\t"  // shift significant bit into carry
            "ror %B[LFSRin]"            "\n\t"  // shift carry in as msb
            "ror %A[LFSRin]"            "\n\t"  // shift output into carr
            "rol %[output]"             "\n\t"  // store output
            ""                          "\n\t"
            "sbrs %[output], 0"         "\n\t"  // check if output is not 0
            "jmp end"                   "\n\t"
            "ldi %[input], 0x80"        "\n\t"  // xor lfsr with polynom 0x80E3
            "eor %B[LFSRin], %[input]"  "\n\t"  // i%[input] can be used because
            "ldi %[input], 0xE3"        "\n\t"  // in 2nd ldi, Bit 0 is set again
            "eor %A[LFSRin], %[input]"  "\n\t"
            ""                          "\n\t"
            "end:"                      "\n\t"

            : //output operand list
                [LFSRout]   "=w" (LFSR),
                [output]    "=d" (out)
            : //input operand list
                [LFSRin]    "0" (LFSR), // LFSR is in and output
                [input]     "1" (in)    // output and input can use the same
            : //clobber list

        );
    }

    return (out&0x01);
}

/**
 * Feed one bit of random data to the LFSR (reseeding).
 */
void rand_feed(uint8_t in)
{
    rand_shift(in&0x01);
}

/**
 * Get one bit of random data from the LFSR.
 */
uint8_t rand1()
{
    uint8_t random = rand_shift(0x00);
    return random &0x01;
}

/**
 * Generate a random 16−bit number.
 */
uint16_t rand16()
{
    uint8_t i=0;
    uint16_t random_value=0;

    for(i=0; i < 16; i++){
        random_value = random_value <<1;
        random_value |=rand_shift((random_value>>1)&0x01);
    }
    return random_value;
}
