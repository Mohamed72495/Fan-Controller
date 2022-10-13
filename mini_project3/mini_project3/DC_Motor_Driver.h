/*
 * DC_Motor_Driver.h
 *
 *  Created on: Oct 11, 2022
 *      Author: LENOVO
 */

#ifndef DC_MOTOR_DRIVER_H_
#define DC_MOTOR_DRIVER_H_

#include  "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define MOTOR_PORT_ID                   PORTB
#define MAX_NO							255
#define MAX_SPEED						100

#define MOTOR_E_PORT_ID                 PORTB_ID
#define MOTOR_E_PIN_ID                  PIN3_ID

#define MOTOR_IN1_PORT_ID                 PORTB_ID
#define MOTOR_IN1_PIN_ID                  PIN0_ID

#define MOTOR_IN2_PORT_ID                 PORTB_ID
#define MOTOR_IN2_PIN_ID                  PIN1_ID



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum{
	STOP , CW , ANTI_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the DC-Motor driver.
 */
void DcMotor_Init(void);


/*
 * Description :
 * Function responsible for initialize the DC-Motor driver.
 * The function responsible for rotate the DC Motor or stop the motor
 *  based on the input state value
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);


#endif /* DC_MOTOR_DRIVER_H_ */
