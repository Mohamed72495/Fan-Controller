 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Mohamed Tarek
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


typedef enum{
	V_AREF , V_AVCC , V_RVR ,V_INT
}ADC_Volt_ref;

typedef enum{
	FCPU_2 , FCPU_2_1 , FCPU_4 ,FCPU_8,FCPU_16,FCPU_32,FCPU_64_FCPU_128
}ADC_Prescaler;


typedef struct
{
	ADC_Volt_ref volt;
	ADC_Prescaler freq;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
