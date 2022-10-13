/*
 * App.c
 *
 *  Created on: Oct 11, 2022
 *      Author: LENOVO
 */

#include"LCD.h"
#include"gpio.h"
#include"common_macros.h"
#include <avr/io.h>
#include "lm35_sensor.h"
#include "DC_Motor_Driver.h"
#include "adc.h"
#include "PWM.h"



uint8 g_temp;
uint8  g_state=0;
uint8 g_speed = 0;



void app_logic(void){
	g_temp=LM35_getTemperature();


	if(g_temp<30){

		g_speed =0;
		g_state=STOP;
	}


	else if((g_temp>=30) && (g_temp<60)){
		g_speed =25;
		g_state=CW;
	}


	else if((g_temp>=60) && (g_temp<90)){
		g_speed =50;
		g_state=CW;

	}

	else if((g_temp>=90) && (g_temp<120)){
		g_speed =75;
		g_state=CW;

	}
	else if(g_temp>=120) {
		g_speed =100;
		g_state=CW;

	}
	DcMotor_Rotate(g_state,g_speed);

	if(g_temp>=100){
		if(	g_state==CW){
			LCD_displayStringRowColumn(0,7,"ON");
		}
		else if(g_state==STOP){
			LCD_displayStringRowColumn(0,7,"OFF");
		}

		LCD_moveCursor(1, 6);
		LCD_intgerToString(g_temp);
	}
	else{
		if(	g_state==CW){
			LCD_displayStringRowColumn(0,7,"ON");
		}
		else if(g_state==STOP){
			LCD_displayStringRowColumn(0,7,"OFF");
		}
		LCD_moveCursor(1, 6);
		LCD_intgerToString(g_temp);
		LCD_displayCharacter(' ');


	}





}






int main(void)
{
	ADC_ConfigType adc_struct ={V_INT,FCPU_8};
	LCD_init(); /* Initialize the LCD */

	DcMotor_Init();
	ADC_init(&adc_struct);
	LCD_displayStringRowColumn(0, 0, "Fan is ");
	LCD_displayStringRowColumn(1, 0, "Temp =     C");



	while(1)
	{
		app_logic();

	}

}
