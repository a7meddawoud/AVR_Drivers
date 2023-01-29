/*
 * Timer0.c
 *
 *  Created on: Jan 15, 2023
 *      Author: a7med
 */
#include "Timer0.h"
void(*Tptr1)(void)='\0';
void(*Tptr2)(void)='\0';
void Timer0_vInit(){
#if Timer0_Mode==T0NormalMode
	TCCR0= 0x00|Timer0Prescaler;

#elif Timer0_Mode==T0CTCMode
	TCCR0=0x08|Timer0Prescaler;
#elif Timer0_Mode==T0PWMFastMode
	TCCR0= 0x44|Timer0Prescaler;
#elif Timer0_Mode==T0PWMPhaseCorrectMode
	TCCR0= 0x40|Timer0Prescaler;
#endif
}
void Timer0_vEnableCompareInterrupt(){
	SET_BIT(TIMSK,1);
}
void Timer0_vEnableOverflowInterrupt(){
	SET_BIT(TIMSK,0);
}
u8 Timer0_u8ReadCompareFlag(){
	return GET_BIT(TIFR,1);
}
u8 Timer0_u8ReadOverflowFlag(){
	return GET_BIT(TIFR,0);
}
void Timer0_vCounterRegister(u8 Loc_u8CounterVal){
	TCNT0= Loc_u8CounterVal;
}
void Timer0_vCompareRegister(u8 Loc_u8CompareVal){
	OCR0=Loc_u8CompareVal;
}
void Timer0_vCompareCallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Tptr1=ptr;
	}
}
void Timer0_vOverflowCallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Tptr2=ptr;
	}
}
ISR(TIMER0_COMP_vect){
	if(Tptr1!='\0'){
		Tptr1();
	}
}
ISR(TIMER0_OVF_vect){
	if(Tptr2!='\0'){
		Tptr2();
	}
}
