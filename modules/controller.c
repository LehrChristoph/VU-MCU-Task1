#include <avr/io.h>
#include "controller.h"
#include "stdint.h"

static uint16_t lastProcessValue=0;

void init_controller(void){
    
    /* Set up PWM */
    TCCR1A |= 1<<WGM11 | 1<<COM1B1;
    TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
    OCR1B = 0;
    ICR1 = MAX_OCR1B;
    
    /*PWM */
    DDRB |= 1<<PINB6;
    PORTB &= ~(1<<PINB6);
}

void pd_Controller(uint16_t setPoint, uint16_t processValue){
    
    int8_t pidH,pidL;
    
    int8_t setPointH = setPoint >> 8;
    uint8_t setPointL = setPoint & 255;
    
    int8_t processValueH = processValue >> 8;
    uint8_t processValueL = processValue & 255;
    
    int8_t lastProcessValueH = lastProcessValue >> 8;
    uint8_t lastProcessValueL= lastProcessValue & 255;
    
    lastProcessValue = processValue;
    //overflow/undeflow checks not for P and I controller not neccessery because MAX_INT and MIN_INT are not reachable, maximum error for D share would be 5900 and P Share would be +- 2950 
    
    asm volatile(
        ".equ temp1,    0x10"           "\n\t"
        ".equ temp2,    0x11"           "\n\t"
        "push temp1"                    "\n\t"
        "push temp2"                    "\n\t"
        
        // calc error
        
        "mov temp1, %[setValueL]"       "\n\t"
        "mov temp2, %[setValueH]"       "\n\t"
        "sub temp1, %[currentValueL]"   "\n\t"
        "sbc temp2, %[currentValueH]"   "\n\t"
        
        // P Term

        "asr temp2"                     "\n\t"
        "ror temp1"                     "\n\t"
        "asr temp2"                     "\n\t"
        "ror temp1"                     "\n\t"
        "asr temp2"                     "\n\t"
        "ror temp1"                     "\n\t"

        "mov %[pidL], temp1"            "\n\t"
        "mov %[pidH], temp2"            "\n\t"  

        
        "subi  %[pidH],0"                "\n\t"
        //Checks
        "brmi underflowCheck"           "\n\t"
        
        "lds temp1, 0x8A"               "\n\t"//OCR1BL
        "lds temp2, 0x8B"               "\n\t"//OCR1BH
        "add temp1, %[pidL]"            "\n\t"
        "adc temp2, %[pidH]"            "\n\t"
        
        "sbci temp2, %[ocr1BMaxH]"      "\n\t"
        "brlo oldValue"                      "\n\t"
        "ldi temp2,%[ocr1BMaxH]"        "\n\t"
        "ldi temp1,%[ocr1BMaxL]"         "\n\t"
        "rjmp end"                      "\n\t"
        
        "oldValue:"                     "\n\t"
        "subi temp2, -%[ocr1BMaxH]"      "\n\t"
        "rjmp end"                      "\n\t"
        
        "underflowCheck:"               "\n\t"
        
        "lds temp1, 0x8A"               "\n\t"//OCR1BL
        "lds temp2, 0x8B"               "\n\t"//OCR1BH
        "add temp1, %[pidL]"            "\n\t"
        "adc temp2, %[pidH]"            "\n\t"
        
        "brpl end"                      "\n\t"
        "ldi temp2,0"                   "\n\t"
        "ldi temp1,1"                   "\n\t"
        
        "end:"                          "\n\t"
        
        "sts 0x8A, temp1"               "\n\t"
        "sts 0x8B, temp2"               "\n\t"
        
        //Overflow Undeflow Check
        "pop temp2"                     "\n\t"
        "pop temp1"                     "\n\t"
        : // output values 
            [pidH] "=d" (pidH),
            [pidL] "=d" (pidL)
        : // input values 
            [setValueH] "d" (setPointH),
            [setValueL] "d" (setPointL),
            [currentValueH] "d" (processValueH),
            [currentValueL] "d" (processValueL),
            [lastValueH] "d" (lastProcessValueH),
            [lastValueL] "d" (lastProcessValueL),
            [ocr1BMaxH] "M" ((uint8_t)((MAX_OCR1B-1) >>8)),
            [ocr1BMaxL] "M" (((MAX_OCR1B-1) & 0x00FF))
            
    );
    
//     pid = (((int16_t)pidH) << 8) | (0x00FF & ((uint16_t)pidL)); //#paranoia
// 
//     return pid;
}
