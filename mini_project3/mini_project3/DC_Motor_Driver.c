/*
 * DC_Motor_Driver.c
 *
 *  Created on: Oct 11, 2022
 *      Author: LENOVO
 */
#include"gpio.h"
#include"common_macros.h"
#include <avr/io.h>
#include "PWM.h"
#include "DC_Motor_Driver.h"

/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC-Motor driver.
 */
void DcMotor_Init(void){

	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, PIN_OUTPUT);


	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID, LOGIC_LOW);




}


/*
 * Description :
 * Function responsible for initialize the DC-Motor driver.
 * The function responsible for rotate the DC Motor or stop the motor
 *  based on the input state value
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed){

	MOTOR_PORT_ID=(MOTOR_PORT_ID&0xFC)|(state & 0x03);
//	uint8 duty_cycle=(uint8)(((uint16)(MAX_NO*speed))/MAX_SPEED);
//	PWM_Timer0_Start(duty_cycle);
	PWM_Timer0_Start(speed);


}

