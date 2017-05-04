/**
    This is the C interrupt callback demo.
    
    Enable the LEDs for port A.
    Whenever INT7 or INT6 is pressed the counting
    mode changes from increasing to decreasing and vice versa.
*/

#define F_CPU       (16000000UL)

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <libglcd/glcd.h>
#include <libglcd/font.h>
#include <libglcd/Standard5x7.h>
#include <libmemstat/memstat.h>
#include <fftavr/ffft.h>

#ifndef NULL
#define NULL    ((void *) 0)
#endif
#ifndef TRUE
#define TRUE    (0 == 0)
#endif
#ifndef FALSE
#define FALSE   (!TRUE)
#endif

typedef int (*compfn)(const void*, const void*);

/* prototypes */
static void init(void);

/* variables */
static volatile uint8_t median_array[5] = {0,0,0,0,0};
static volatile uint8_t median_count =0;
static volatile uint8_t median =0;

static volatile uint16_t rpm_zigbee=0;
static volatile uint16_t set_rpm  =0;
static volatile uint16_t measured_rpm=0;

static volatile uint8_t adc_mode=0;
static volatile uint8_t source_mode=0;

static complex_t fft_buffter[FFT_N];		/* FFT buffer */
static uint16_t fft_spectrum[FFT_N/2];		/* Spectrum output buffer */
static int16_t fft_capture[FFT_N];
static volatile uint8_t fft_counter=0;

static const uint8_t  MODE_USE_ADC = 1;
static const uint8_t  MODE_USE_ZIGBEE = 2;

static const uint8_t  ADC_MODE_RPM = 1;
static const uint8_t  ADC_MODE_SAMPLE = 2;
static const uint8_t  ADC_MODE_START_FFT = 4;

static const uint8_t  TIMER3_COUNTER_TOP_SAMPLE = 25;
static const uint16_t TIMER3_COUNTER_TOP_WAIT   = 2500;
static const uint16_t TIMER5_COUNTER_TOP   = 12500;

int main(void)
{
    /* initialize variables */
    init();
    
    sei();   
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
   
    while(TRUE)
    {
        sleep_cpu();
        
        
        
        
    }
    return 0;
}

static void init(void) {
    /* Initialize LEDs. */    
    DDRB = 0xFF;
    PORTB = 0x00;
    
    DDRC = 0xFF;
    PORTC = 0x00;
    
    DDRD = 0xFF;
    PORTD = 0x00;
    
    
    /* Set up PWM */
    TCCR1A |= 1<<WGM11 | 1<<COM1B1;
    TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
    DDRB |= 1<<PINB6;
    PORTB &= ~( 1<<PINB6);
    OCR1B = 0;
    ICR1 = 639;
    
    /* Set up ADC */
    ADMUX |=  1<<ADLAR;
    ADCSRA |=  1<<ADEN | 1 << ADIE;
    PORTF |=  (PINF0 | PINF7);
    DDRF &= ~(PINF0 | PINF7);
    
    /* Setup Timer 3 for Sampling and FFT*/
    TCCR3B |= 1<<WGM32 | 1<<CS31 | 1<<CS30;
    OCR3A = TIMER3_COUNTER_TOP_WAIT;
    TIMSK3|= 1<<OCIE3A;
    
    /* Set up Timer4 for Input capture */
    TCCR4B|= 1<<ICNC4 | 1<<CS42 | 1<< ICES4;
    TIMSK4|= 1<<ICIE4;
    
    /* Set up Timer4 for Input capture */
    TCCR5B|= 1<<WGM52 | 1<<CS51 | 1<<CS50;
    OCR5A = TIMER5_COUNTER_TOP;
    TIMSK5|= 1<<OCIE5A;
    
    /* Set up GLCD */    
    glcdInit();
    glcdFillScreen(GLCD_CLEAR);
    
    //DDRL  =0x00;
    //PORTL =0x01;
    
    PORTL&= ~(PINL0);
    DDRL &= ~(PINL0);
    
    source_mode=MODE_USE_ADC;
    adc_mode=ADC_MODE_SAMPLE;

}

static uint8_t calc_median(void){
    uint8_t median_temp[5];
    
    //very beautiful array copy function
    median_temp[0] = median_array[0];
    median_temp[1] = median_array[1];
    median_temp[2] = median_array[2];
    median_temp[3] = median_array[3];
    median_temp[4] = median_array[4];
    
    uint8_t i, j;
    for(i=0; i<5; i++) {
        for(j=0; j<(5-i); j++) {
                if(median_temp[j] > median_temp[j+1]) {
                    uint8_t temp = median_temp[j];
                    median_temp[j] = median_temp[j+1];
                    median_temp[j+1] = temp;
                }
        }
    }
    return median_temp[2];
}

/* interrupts */
ISR(ADC_vect, ISR_NOBLOCK)           /* non blocking adc interrupt */
{   
    //get value from Potentiometer
    if((adc_mode & ADC_MODE_RPM)==ADC_MODE_RPM){
        median_array[median_count] = ADCH;
        //if new adc value equal median, no new calculation necessary
        if(median_array[median_count] != median){
            uint8_t median_temp = calc_median();
            
            if(median != median_temp){
                median = median_temp;
                OCR1B = median *2.4;
            }
            //PORTA = ADCH;
            set_rpm = 10.7843*median+650;
        }
        median_count=(median_count+1)%5;
        adc_mode =ADC_MODE_SAMPLE;  
    //Sampling for FFT
    }else if((adc_mode & ADC_MODE_SAMPLE)==ADC_MODE_SAMPLE){
        fft_capture[fft_counter] = ADCH;
        adc_mode = ADC_MODE_RPM;
        if(fft_counter >= 127){
            fft_counter =0;
            //adc_mode = ADC_MODE_RPM;
        }
        //PORTD = ADCH;
    }
}


ISR(TIMER3_COMPA_vect, ISR_NOBLOCK)
{    
    //Conversion from Potentiometer
    OCR3A = TIMER3_COUNTER_TOP_SAMPLE;
    if((adc_mode & ADC_MODE_RPM)==ADC_MODE_RPM){
        ADMUX &= ~(1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
        
    //Sampling mode
    }else if((adc_mode & ADC_MODE_SAMPLE)==ADC_MODE_SAMPLE){
        ADMUX |= (1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
        fft_counter++;
        
    //start FFT
    } if((adc_mode & ADC_MODE_START_FFT)!=0){
        adc_mode=ADC_MODE_RPM;
        OCR3A = TIMER3_COUNTER_TOP_WAIT;
        
        //input for fft
        fft_input(fft_capture, fft_buffter);
        //start fft
        fft_execute(fft_buffter);
        //get result of fft
        fft_output(fft_buffter, fft_spectrum);
        
    }
    TCNT3=0;
    ADCSRA |= 1 <<ADSC;
}


ISR(TIMER4_CAPT_vect)
{    
    //measured_rpm = 62500/(ICR4*30);
    //measured_rpm = 15 / (ICR4 *0.000008);
    measured_rpm = ICR4;
    /*if(set_rpm > measured_rpm){
        OCR1B+=1;
    }
    else if(set_rpm < measured_rpm) {
        OCR1B-=1;
    }*/
    
    TCNT4=0;
}

ISR(TIMER5_COMPA_vect, ISR_NOBLOCK)
{   
    char line1[30]="";
    char line2[30]="";
    xy_point line_set_rpm, line_input_capture_rpm;
    
    line_set_rpm.x = 3;
    line_set_rpm.y = 8;
    
    line_input_capture_rpm.x=3;
    line_input_capture_rpm.y=18;
    
    sprintf(line1, "Set:      %d RPM", set_rpm);
    sprintf(line2, "Measured: %d RPM", measured_rpm);
    
    glcdFillScreen(GLCD_CLEAR);
    glcdDrawText(line1, line_set_rpm, &Standard5x7, &glcdSetPixel);
    glcdDrawText(line2, line_input_capture_rpm, &Standard5x7, &glcdSetPixel);
    TCNT5=0;
}
