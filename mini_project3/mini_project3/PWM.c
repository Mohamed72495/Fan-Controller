/*
 * PWM.c
 *
 *  Created on: Oct 11, 2022
 *      Author: LENOVO
 */
#include "PWM.h"
#include"gpio.h"
#include <avr/io.h>

/******************************************************************************************
                          * Functions definition  *
 ******************************************************************************************/
/*
 * Description:
 * Generate a PWM signal with Timer0 using PWM Mode
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << CS01) | (1 << COM01); /*N=8 , Fast PWM mode , non-inverting*/
	TCNT0 = 0; /*Initial value*/
	OCR0 = duty_cycle; /*set value of the ocr register (non inverted)*/
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT); /*To see the output wave in PB3*/

}
