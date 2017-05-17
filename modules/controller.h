/*This file has been prepared for Doxygen automatic documentation generation.*/
/*! \file *********************************************************************
 *
 * \brief Header file for pid.c.
 *
 * - File:               pid.h
 * - Compiler:           IAR EWAAVR 4.11A
 * - Supported devices:  All AVR devices can be used.
 * - AppNote:            AVR221 - Discrete PID controller
 *
 * \author               Atmel Corporation: http://www.atmel.com \n
 *                       Support email: avr@atmel.com
 *
 * $Name: RELEASE_1_0 $
 * $Revision: 1.1 $
 * $RCSfile: pid.h,v $
 * $Date: 2006/02/16 11:46:13 $
 *****************************************************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "stdint.h"

#define MAX_OCR1B 2950
//#define MAX_OCR1B 1475
//#define MAX_OCR1B 640

void init_controller(void);

void pd_Controller(uint16_t setPoint, uint16_t processValue);

#endif
