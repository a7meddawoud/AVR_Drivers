/*
 * ADC.h
 *
 *  Created on: Jan 9, 2023
 *      Author: a7med
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include <util/delay.h>

#include "../EXTI/EXTI.h"
#include "Config_ADC.h"
#define ADC_vect			 __vector_16
//---- ADCSRA BITs
#define Interrupt 1
#define Polling 0
#define SingleConvertion 0
#define FreeRunningMode 1
#define ExternalInterrupt 2
#define ADIF GET_BIT(ADCSRA,4)

#define StartConversion SET_BIT(ADCSRA,6)
#define CheckConversoin GET_BIT(ADCSRA,6)
//-----ADMUX BITs

#define ADC0 ADMUX=ADMUX|0x00
#define ADC1 ADMUX=ADMUX|0x01
#define ADC2 ADMUX=ADMUX|0x02
#define ADC3 ADMUX=ADMUX|0x03
#define ADC4 ADMUX=ADMUX|0x04
#define ADC5 ADMUX=ADMUX|0x05
#define ADC6 ADMUX=ADMUX|0x06
#define ADC7 ADMUX=ADMUX|0x07

void ADC_vInit();
u16 ADC_vGetVal();
void ADC_vADCCallBack(void(*ptr)(void));
#endif /* MCAL_ADC_ADC_H_ */
