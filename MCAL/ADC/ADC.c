
/*
 * ADC.c
 *
 *  Created on: Jan 9, 2023
 *      Author: a7med
 */
void(*Aptr)(void)='\0';

#include "ADC.h"
void ADC_vInit(){
#if PollingOrInterrupt==Polling
	#if	ADCMode==SingleConvertion
		ADCSRA = 0x87;
	#elif ADCMode==FreeRunningMode
		ADCSRA = 0xA7;
		SFIOR = SFIOR|0x00;
	#elif ADCMode==ExternalInterrupt
		ADCSRA = 0xA7;
		SFIOR = SFIOR|0x20;
	#endif
#elif PollingOrInterrupt==Interrupt
	#if ADCMode==SingleConvertion
		ADCSRA = 0x8F;
	#elif ADCMode==FreeRunningMode
		ADCSRA = 0xAF;
		CLR_BIT(SFIOR,5);
		CLR_BIT(SFIOR,6);
		CLR_BIT(SFIOR,7);
	#elif ADCMode==ExternalInterrupt
		ADCSRA = 0xAF;
		//	SFIOR = SFIOR|0x20;
		CLR_BIT(SFIOR,5);
		SET_BIT(SFIOR,6);
		CLR_BIT(SFIOR,7);
	#endif
#endif
	ADMUX=(0x60|((ADCNum)&0x1F));
	}
	u16 ADC_vGetVal(){
		StartConversion;
		u32 y;
		u32 z;
	#if ADCMode==FreeRunningMode
			while((ADIF)==0);
	#elif ADCMode==SingleConvertion
			StartConversion;
			while(CheckConversoin==1);
	#endif
		_delay_ms(10);
		y = (((u32)ADCH)<<2);
		z = (y*5000)/1024;
		return z;
	}
	void ADC_vADCCallBack(void(*ptr)(void)){
		if(ptr!='\0'){
			Aptr=ptr;
		}
	}
ISR(ADC_vect){
		if(Aptr!='\0'){
			Aptr();
		}
	}
