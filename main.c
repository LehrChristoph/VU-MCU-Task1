
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

//typedef int (*compfn)(const void*, const void*);

/* prototypes */
static void init(void);
static uint8_t calc_median(uint8_t *);

/* constants */

#define ADC_MODE_RPM 1
#define ADC_MODE_SAMPLE 2
#define ADC_MODE_START_FFT 4

#define TIMER1_COUNTER_TOP_PWM 640
#define TIMER3_COUNTER_TOP 125
#define TIMER5_COUNTER_TOP 5000

#define ISR_ADC_FC 1 
#define ISR_INPUT_CAPTURE 2
#define ISR_FFT 4
#define ISR_EXTERNAL 8

#define GLCD_DISPLAY_RPM 1
#define GLCD_DISPLAY_FFT 2

#define MODE_USE_ADC 1
#define MODE_USE_ZIGBEE 2
#define MODE_NOISE_REDUCTION 4

/* variables */
static volatile uint8_t median_array[5] = {0,0,0,0,0};
static volatile uint8_t source_mode=0;

static volatile uint8_t isr_flags=0;
static volatile uint16_t measured_rpm=0;

static complex_t fft_buffter[FFT_N];		/* FFT buffer */
static uint16_t fft_spectrum[FFT_N/2];		/* Spectrum output buffer */
static int16_t fft_capture[FFT_N];
static volatile uint8_t fft_counter=0;

int main(void)
{
    uint8_t adc_mode=ADC_MODE_RPM;
    uint16_t set_rpm  =0;
    uint8_t counter =0;
    uint8_t median_count =0;
    uint8_t median =0;
    uint8_t median_array[5] = {0,0,0,0,0};
    
    uint8_t displayMode=GLCD_DISPLAY_RPM;
    
    /* init interrupts and ports */
    init();
    
    adc_mode = ADC_MODE_RPM;
    
    sei();   
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
   
    while(TRUE)
    {
        if(isr_flags ==0){
            sleep_cpu();
        }
        
        if((isr_flags & ISR_ADC_FC) == ISR_ADC_FC){
            isr_flags &= ~(ISR_ADC_FC);
            //get value from Potentiometer
            if(adc_mode ==ADC_MODE_RPM){
                
                median_array[median_count] = ADCH;
                //if new adc value equal median, no new calculation necessary
                if(median_array[median_count] != median){
                    uint8_t median_temp = calc_median(median_array);
                    
                    if(median != median_temp){
                        median = median_temp;
                        if(source_mode ==MODE_USE_ADC){
                            OCR1B = median *2.4;
                        }
                    }
                    
                    set_rpm = 10.7843*median+650;
                }
                median_count=(median_count+1)%5;
                counter++;

                adc_mode =ADC_MODE_SAMPLE;  
                ADMUX |= (1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
                
            //Sampling for FFT
            }else if(adc_mode == ADC_MODE_SAMPLE){
                
                fft_capture[fft_counter] = ADCW >> 6;
                fft_counter= (fft_counter +1)%128;
                
                if(fft_counter %2==0){
                    adc_mode = ADC_MODE_RPM;
                    ADMUX &= ~(1<< MUX2 | 1<< MUX1 | 1 <<MUX0) ;
                }
            }
        }
        
        if((isr_flags & ISR_EXTERNAL) == ISR_EXTERNAL){
            if((displayMode & GLCD_DISPLAY_RPM) == GLCD_DISPLAY_RPM){
                displayMode &= ~(GLCD_DISPLAY_RPM);
                displayMode |= GLCD_DISPLAY_FFT;
            }else{
                displayMode &= ~(GLCD_DISPLAY_FFT);
                displayMode |= GLCD_DISPLAY_RPM;
            }
            glcdFillScreen(GLCD_CLEAR);
            
            isr_flags &= ~(ISR_EXTERNAL);
        }
        
        if((isr_flags & ISR_INPUT_CAPTURE) == ISR_INPUT_CAPTURE){
            
            isr_flags &= ~(ISR_INPUT_CAPTURE);
            
            if(set_rpm > measured_rpm){
                
                uint16_t variance = set_rpm - measured_rpm;
                uint8_t compensation =0;
                
                if(variance > 100){
                    compensation =25;
                } else if(variance >50 ){
                    compensation =10;
                } else if(variance >20 ){
                    compensation =5;
                } else{
                    compensation =1;
                }
                
                if(OCR1B + compensation < TIMER1_COUNTER_TOP_PWM){
                    OCR1B+=compensation;
                }else{
                    OCR1B = TIMER1_COUNTER_TOP_PWM;
                }
            }
            else if(set_rpm < measured_rpm) {
                
                uint16_t variance = measured_rpm-set_rpm;
                uint8_t compensation =0;
                
                if(variance > 100){
                    compensation =25;
                } else if(variance >50 ){
                    compensation =10;
                } else if(variance >20 ){
                    compensation =5;
                } else{
                    compensation =1;
                }
                
                if(OCR1B - compensation >=1){
                    OCR1B-=compensation;
                }else{
                    OCR1B =0;
                }
            }
            
            if(displayMode == GLCD_DISPLAY_RPM){
                
                char line1[30]="";
                char line2[30]="";
                xy_point line_set_rpm, line_input_capture_rpm, rect_clear_left, rect_clear_right;
            
            
                line_set_rpm.x = 3;
                line_set_rpm.y = 8;
                
                line_input_capture_rpm.x=3;
                line_input_capture_rpm.y=18;
                
                rect_clear_left.x = 60;
                rect_clear_left.y = 0;
                
                rect_clear_right.x=100;
                rect_clear_right.y=24;
                
                if(set_rpm < 1000){
                    sprintf(line1, "Set:       %d RPM", set_rpm);
                }else{
                    sprintf(line1, "Set:      %d RPM", set_rpm);
                }
                
                if(measured_rpm < 1000){
                    sprintf(line2, "Measured:  %d RPM", measured_rpm);
                }else{
                    sprintf(line2, "Measured: %d RPM", measured_rpm);
                }
                
                glcdFillRect(rect_clear_left, rect_clear_right, &glcdClearPixel);
                glcdDrawText(line1, line_set_rpm, &Standard5x7, &glcdSetPixel);
                glcdDrawText(line2, line_input_capture_rpm, &Standard5x7, &glcdSetPixel);
            }
        }
        
        if((isr_flags & ISR_FFT) == ISR_FFT){

            isr_flags &= ~(ISR_FFT);
            
            uint16_t max_specs[8] = {fft_spectrum[2],fft_spectrum[3],fft_spectrum[4],fft_spectrum[5],fft_spectrum[6],fft_spectrum[7],fft_spectrum[7],fft_spectrum[9]};
            uint16_t sum_up=0;
            
            for(int i=10; i<FFT_N/2; i++){
                uint16_t min =max_specs[0];
                uint8_t index_min=0;
                
                for(int j =1; j<8; j++){
                    if(max_specs[j]<min){
                        min=max_specs[j];
                        index_min =j;
                    }
                }
                if(fft_spectrum[i] > min){
                    max_specs[index_min] = fft_spectrum[i];
                }
            }
            
            for(int i=0; i<8;i++){
                sum_up += max_specs[i];
            }
            
            if(sum_up > 6400+0.78125*measured_rpm){
                
                if(source_mode == MODE_NOISE_REDUCTION){
                    set_rpm-=(set_rpm /10);
                }else{
                    set_rpm = 1500;
                }
                
                source_mode = MODE_NOISE_REDUCTION;
                
            }else if(source_mode == MODE_NOISE_REDUCTION){
                set_rpm+=(set_rpm /20);
            }

            if((displayMode & GLCD_DISPLAY_FFT) == GLCD_DISPLAY_FFT){
                glcdFillScreen(GLCD_CLEAR);
                
                for(int i=0; i<FFT_N/2;i++){
                    xy_point top, bottom;
                    
                    top.x=i*2;
                    if(fft_spectrum[i]>=63){
                        top.y=0;
                    }else{
                        top.y=63-fft_spectrum[i];
                    }
                    
                    bottom.x=i*2+1;
                    bottom.y=63;
                    
                    glcdFillRect(top, bottom, &glcdSetPixel);
                }   
            }
        }   
        
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
    
    /*PWM */
    DDRB |= 1<<PINB6;
    PORTB &= ~(1<<PINB6);
    
    /* external interrupt */
    DDRD &= ~(1 << PIND0); 
    PORTD |= 1 << PIND0;
    
    /* ADC0 && ADC7 */
    DDRF &= ~(PINF0 | PINF7);
    PORTF |=  (PINF0 | PINF7);
    
    /* input capture */
    DDRL &= ~(PINL0);
    PORTL&= ~(PINL0);
    
    /* Set up PWM */
    TCCR1A |= 1<<WGM11 | 1<<COM1B1;
    TCCR1B |= 1<<WGM12 | 1<<WGM13 | 1<<CS10;
    OCR1B = 0;
    ICR1 = TIMER1_COUNTER_TOP_PWM;
    
    /* Set up ADC */
    ADMUX |=  1<<ADLAR;
    ADCSRA |=  1<<ADEN | 1 << ADIE;

    /* Setup Timer 3 for Sampling and FFT*/
    TCCR3B |= 1<<WGM32 | 1<<CS31;// | 1<<CS30;
    OCR3A = TIMER3_COUNTER_TOP;
    TIMSK3|= 1<<OCIE3A;
    
    /* Set up Timer4 for Input capture */
    TCCR4B|= 1<<ICNC4 | 1<<CS42;// | 1<< ICES4;
    TIMSK4|= 1<<ICIE4;
    
    /* Set up Timer4 for Input capture */
    TCCR5B|= 1<<WGM52 | 1<<CS51 | 1<<CS50;
    OCR5A = TIMER5_COUNTER_TOP;
    TIMSK5|= 1<<OCIE5A;
    
    /* Set up GLCD */    
    glcdInit();
    glcdFillScreen(GLCD_CLEAR);
    
    /* external interrupt */
    EICRA |= 1 << ISC01;
    EIMSK |= 1 << INT0;
    
}

static uint8_t calc_median(uint8_t * median_array){
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
ISR(ADC_vect)           
{   
    isr_flags |= ISR_ADC_FC;
}


ISR(TIMER3_COMPA_vect)
{       
    TCNT3=0;
    ADCSRA |= 1 <<ADSC;
}


ISR(TIMER4_CAPT_vect)
{    
    isr_flags |= ISR_INPUT_CAPTURE;    
    measured_rpm = 15 / (ICR4 *0.000008);
    TCNT4=0;
}

ISR(TIMER5_COMPA_vect, ISR_NOBLOCK) /* non blocking adc interrupt */
{   
    //input for fft
    fft_input(fft_capture, fft_buffter);
    //start fft
    fft_execute(fft_buffter);
    //get result of fft
    fft_output(fft_buffter, fft_spectrum);
    
    isr_flags |= ISR_FFT;
}

ISR(INT0_vect){
    isr_flags |= ISR_EXTERNAL;
}
