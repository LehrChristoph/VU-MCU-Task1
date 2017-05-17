#define F_CPU       (16000000UL)

/* includes */
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <fftavr/ffft.h>
#include <libglcd/glcd.h>
#include <libglcd/font.h>
#include <libglcd/Standard5x7.h>
#include <libmemstat/memstat.h>
#include <libserialnet/serialnet.h>
#include <libserialnet/util.h>

#include <modules/controller.h>
#include <modules/glcd.h>
#include <modules/adc.h>
#include <modules/serialnet.h>

#ifndef NULL
#define NULL    ((void *) 0)
#endif
#ifndef TRUE
#define TRUE    (0 == 0)
#endif
#ifndef FALSE
#define FALSE   (!TRUE)
#endif


/* prototypes */
static void init(void);

/* constants */
#define MAX_RPM 3400
#define MIN_RPM 650
#define TIMER3_COUNTER_TOP_A 250
#define TIMER3_COUNTER_TOP_B 40000
#define TIMER5_COUNTER_TOP 25000

#define ISR_ADC_FC 1 
#define ISR_SERIALNET 2
#define ISR_INPUT_CAPTURE 4
#define ISR_FFT 8
#define ISR_SWITCH_GLCD 16
#define ISR_CLEAR_NOISE_REDUCTION 32
#define ISR_REFRESH 64

#define GLCD_DISPLAY_RPM 1
#define GLCD_DISPLAY_FFT 2

#define MODE_USE_ADC 1
#define MODE_USE_ZIGBEE 2
#define MODE_NOISE_REDUCTION 4

#define SERIALNET_SET_RPM 1 
#define SERIALNET_RESET_RPM 2
#define SERIALNET_RESET_ALERT 4

/* variables */
static volatile uint8_t median=0;
static volatile uint8_t source_mode=0;
static volatile uint16_t set_rpm  =0;

static volatile uint16_t zigbee_address_master=0xFFFF;
static volatile uint16_t zigbee_rpm=0;

static uint8_t isr_flags=0;
static volatile uint16_t measured_rpm=0;

int main(void)
{
    uint16_t sum_up=0;
    
    /* init interrupts and ports */
    init();
    
    static uint8_t displayMode= GLCD_DISPLAY_RPM;
    sei();   
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();
   
    while(TRUE)
    {
        isr_flags |= get_isr_flags();
        
        isr_flags |= get_isr_flags_serialnet();
        
        if(isr_flags ==0){
            sleep_cpu();
        }
        
        if((isr_flags & ISR_ADC_FC) == ISR_ADC_FC){
            isr_flags &= ~(ISR_ADC_FC);

            uint8_t median_tmp = get_median();
            
            if(median != median_tmp){
                
                if(source_mode == MODE_USE_ADC){
                    OCR1B = median_tmp*(MAX_OCR1B/255);
                    set_rpm = 10.784313725*((float)median_tmp)+650;
                }
                median = median_tmp;
            }
        }
        
        if((isr_flags & ISR_SWITCH_GLCD) == ISR_SWITCH_GLCD){
            displayMode =switchScreen();

            isr_flags &= ~(ISR_SWITCH_GLCD);
        }
        
        if((isr_flags & ISR_SERIALNET) == ISR_SERIALNET){
            
            uint8_t serialnet_flags = get_serialnet_flags();
            
            if((serialnet_flags & SERIALNET_RESET_RPM) == SERIALNET_RESET_RPM){
                if(source_mode != MODE_NOISE_REDUCTION){
                    source_mode = MODE_USE_ADC;
                    OCR1B = median*(MAX_OCR1B/255);
                    zigbee_rpm =0;
                    set_rpm = (10.784313725*median)+650;
                }else{
                    zigbee_rpm =0;
                }
            }
            
            if((serialnet_flags & SERIALNET_SET_RPM) == SERIALNET_SET_RPM){
                zigbee_rpm = get_rpm();
                if(source_mode != MODE_NOISE_REDUCTION){
                    source_mode = MODE_USE_ZIGBEE;
                    OCR1B = (zigbee_rpm-MIN_RPM)*(MAX_OCR1B/255);
                    set_rpm = zigbee_rpm;
                }
            }
            
            if((serialnet_flags & SERIALNET_RESET_ALERT) == SERIALNET_RESET_ALERT){
                if(zigbee_rpm>0 && source_mode == MODE_NOISE_REDUCTION){
                    source_mode = MODE_USE_ZIGBEE;
                    OCR1B = (zigbee_rpm-MIN_RPM)*(MAX_OCR1B/255);
                    set_rpm = zigbee_rpm;
                }
            }
            
            isr_flags &= ~(ISR_SERIALNET);
        }
        
        if((isr_flags & ISR_CLEAR_NOISE_REDUCTION) == ISR_CLEAR_NOISE_REDUCTION){
            source_mode = MODE_USE_ADC;
            
            OCR1B = median*(MAX_OCR1B/255);
            set_rpm = 10.784313725*((float)median)+650;
            isr_flags &= ~(ISR_CLEAR_NOISE_REDUCTION);
        }
        
        if((isr_flags & ISR_INPUT_CAPTURE) == ISR_INPUT_CAPTURE){
            
            isr_flags &= ~(ISR_INPUT_CAPTURE);
                        
            measured_rpm = 15 / (ICR4 *0.000008);

        }
        
        if((isr_flags & ISR_FFT) == ISR_FFT){

            isr_flags &= ~(ISR_FFT);
            
            sum_up = get_sum_up();
            
            
            if((sum_up>>5)  > 400+0.048828125*measured_rpm && source_mode != MODE_NOISE_REDUCTION){
                
                set_rpm = set_rpm/2;
                
                if(set_rpm < MIN_RPM){
                    set_rpm = MIN_RPM;
                }
                
                OCR1B = OCR1B / 2;
                
                if(source_mode == MODE_USE_ZIGBEE){
                    uint8_t i=0;
                    serialnet_broadcast_data("NOISEALERT");
                    serialnet_dispatch();
                    
                    while((serialnet_get_state() & SERIALNET_RESPONSE_ERR) == SERIALNET_RESPONSE_ERR && i < 5){
                        serialnet_broadcast_data("NOISEALERT");
                        serialnet_dispatch();
                        i++;
                    }
                    
                    serialnet_clear_state(SERIALNET_RESPONSE_OK);
                    serialnet_clear_state(SERIALNET_RESPONSE_ERR);

                }
                
                source_mode = MODE_NOISE_REDUCTION;
                
            }
            
            enable_ADC();
            
        }   
        
        if((isr_flags & ISR_REFRESH) == ISR_REFRESH){
            serialnet_dispatch();
            //PORTC = serialnet_get_state();
            
            isr_flags &= ~(ISR_REFRESH);
            
            if(sum_up > 300 && source_mode == MODE_NOISE_REDUCTION){
                
                set_rpm -= (set_rpm/10);
                
                if(set_rpm < MIN_RPM){
                    set_rpm =MIN_RPM;
                    OCR1B = 0;
                }else{
                    OCR1B -= (OCR1B/10);
                }
                
            }
            
            pd_Controller(set_rpm, measured_rpm);
            
            if(displayMode == GLCD_DISPLAY_FFT){
                drawFFT(get_fft_spectrum(), FFT_N/2);
            }
            
            if(displayMode == GLCD_DISPLAY_RPM){
                drawInfoScreen(set_rpm, measured_rpm, source_mode,zigbee_rpm);
            }
            PORTC= displayMode;
        }
        
    }
    return 0;
}

static void init(void) {
    /* Initialize debug LEDs. */    
    DDRB = 0xFF;
    PORTB = 0x00;
    
    DDRC = 0xFF;
    PORTC = 0x00;
    
    /* external interrupt */
    DDRD &= ~(1 << PIND1|1 << PIND0); 
    PORTD |= 1 << PIND1 | 1 << PIND0;
    
    /* input capture */
    DDRL &= ~(PINL0);
    PORTL&= ~(PINL0);
    
    /* Set up Timer4 for Input capture */
    TCCR4B|= 1<<ICNC4 | 1<<CS42;// | 1<< ICES4;
    TIMSK4|= 1<<ICIE4;
    
    /* Setup Timer 3 for Sampling and FFT*/
    TCCR5B |= 1<<WGM52 | 1<<CS51 | 1<<CS50;
    OCR5A = TIMER5_COUNTER_TOP;
    TIMSK5|= 1<<OCIE5A;
    
    /* Set up GLCD */    
    init_GLCD();
    
    init_ADC();
    
    init_controller();
    
    /* external interrupt */
    EICRA |= 1 << ISC01| 1 << ISC11;
    EIMSK |= 1 << INT0 | 1 << INT1;
    
    /* set ADC Mode */
    source_mode = MODE_USE_ADC;
    
    init_SerialNet();
}

/* interrupts */

ISR(TIMER5_COMPA_vect)
{ 
    isr_flags |= ISR_REFRESH;
}
    
ISR(TIMER4_CAPT_vect)
{    
    isr_flags |= ISR_INPUT_CAPTURE;    
    TCNT4=0;
}

ISR(INT0_vect){
    isr_flags |= ISR_SWITCH_GLCD;
}

ISR(INT1_vect){
    if(zigbee_rpm ==0){
        isr_flags |= ISR_CLEAR_NOISE_REDUCTION;
    }
}

