 

/*! \file *********************************************************************
 *
 * \brief General PID implementation for AVR.
 *
 * Discrete PID controller implementation. Set up by giving P/I/D terms
 * to Init_PID(), and uses a struct PID_DATA to store internal values.
 *
 *
 *****************************************************************************/

#include "pid.h"
#include "stdint.h"

#define PID_P_SHARE 1
#define PID_I_SHARE 0
#define PID_D_SHARE 0

/*! \brief Initialization of PID controller parameters.
 *
 *  Initialize the variables used by the PID algorithm.
 *
 *  \param p_factor  Proportional term.
 *  \param i_factor  Integral term.
 *  \param d_factor  Derivate term.
 *  \param pid  Struct with PID status.
 */
void pid_Init(struct PID_DATA *pid)
{
	// Start values for PID controller
	pid->sumError         = 0;
	pid->lastProcessValue = 0;
	// Tuning constants for PID loop
	pid->P_Factor = PID_P_SHARE*SCALING_FACTOR;
	pid->I_Factor = PID_I_SHARE*SCALING_FACTOR;
	pid->D_Factor = PID_D_SHARE*SCALING_FACTOR;
	// Limits to avoid overflow
	pid->maxError    = MAX_INT / (pid->P_Factor + 1);
	pid->maxSumError = MAX_I_TERM / (pid->I_Factor + 1);
}

/*! \brief PID control algorithm.
 *
 *  Calculates output from setpoint, process value and PID status.
 *
 *  \param setPoint  Desired value.
 *  \param processValue  Measured value.
 *  \param pid_st  PID status struct.
 */
int16_t pid_Controller_c(int16_t setPoint, int16_t processValue, struct PID_DATA *pid_st)
{
	int16_t errors, p_term, d_term;
	int32_t i_term, ret, temp;

	errors = setPoint - processValue;

	// Calculate Pterm and limit error overflow
	if (errors > pid_st->maxError) {
		p_term = MAX_INT;
	} else if (errors < -pid_st->maxError) {
		p_term = -MAX_INT;
	} else {
		p_term = pid_st->P_Factor * errors;
	}

	// Calculate Iterm and limit integral runaway
	temp = pid_st->sumError + errors;
	if (temp > pid_st->maxSumError) {
		i_term           = MAX_I_TERM;
		pid_st->sumError = pid_st->maxSumError;
	} else if (temp < -pid_st->maxSumError) {
		i_term           = -MAX_I_TERM;
		pid_st->sumError = -pid_st->maxSumError;
	} else {
		pid_st->sumError = temp;
		i_term           = pid_st->I_Factor * pid_st->sumError;
	}

	// Calculate Dterm
	d_term = pid_st->D_Factor * (pid_st->lastProcessValue - processValue);

	pid_st->lastProcessValue = processValue;

	ret = (p_term + i_term + d_term) / SCALING_FACTOR;
	if (ret > MAX_INT) {
		ret = MAX_INT;
	} else if (ret < -MAX_INT) {
		ret = -MAX_INT;
	}

	return ((int16_t)ret);
}

int16_t pid_Controller_asm(uint16_t setPoint, uint16_t processValue, struct PID_DATA *pid_st){
    
    int8_t pidH,pidL, pid=0;
    
    int8_t setPointH = setPoint >> 8;
    uint8_t setPointL = setPoint & 255;
    
    int8_t processValueH = processValue >> 8;
    uint8_t processValueL = processValue & 255;
    
    int8_t lastProcessValueH = pid_st->lastProcessValue >> 8;
    uint8_t lastProcessValueL = pid_st->lastProcessValue & 255;
    
    pid_st->lastProcessValue = processValue;
    //overflow/undeflow checks not for P and I controller not neccessery because MAX_INT and MIN_INT are not reachable, maximum error for D share would be 5900 and P Share would be +- 2950 
    
    asm volatile(
        ".equ temp1,    0x10"           "\n\t"
        ".equ temp2,    0x11"           "\n\t"
        ".equ constant, 0x12"           "\n\t"
        ".equ valueH,   0x13"           "\n\t"
        ".equ valueL,   0x14"           "\n\t"
        "push temp1"                    "\n\t"
        "push temp2"                    "\n\t"
        "push constant"                 "\n\t"
        "push valueH"                   "\n\t"
        "push valueL"                   "\n\t"
        
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
        
        
        "mov %[pidL], temp1"            "\n\t"
        "mov %[pidH], temp2"            "\n\t"  
        
        // calc diff
        
        "mov temp1, %[lastValueL]"      "\n\t"
        "mov temp2, %[lastValueH]"      "\n\t"
        "sub temp1, %[currentValueL]"   "\n\t"
        "sbc temp2, %[currentValueH]"   "\n\t"
        
        
        // D Term
       
        "asr temp2"                     "\n\t"
        "asr temp2"                     "\n\t"
        "asr temp2"                     "\n\t"
        
        "add %[pidL], temp2"            "\n\t"
        
        //Overflow Undeflow Check
        "pop valueH"                    "\n\t"
        "pop valueL"                    "\n\t"
        "pop constant"                  "\n\t"
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

            [pShare] "M" (PID_P_SHARE),
            [iShare] "M" (PID_I_SHARE),
            [dShare] "M" (PID_D_SHARE)
    );
    
    pid = (((int16_t)pidH) << 8) | (0x00FF & ((int16_t)pidL));

    return pid;
}

/*! \brief Resets the integrator.
 *
 *  Calling this function will reset the integrator in the PID regulator.
 */
void pid_Reset_Integrator(pidData_t *pid_st)
{
	pid_st->sumError = 0;
}
