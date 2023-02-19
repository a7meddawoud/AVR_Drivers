/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer0.c
 *        \brief  include functions that make Timer0 using easer
 *
 *      \details  functions in this file can be used to initialize Timer0 and use it modes(overflow ,CTC ,PWM)
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer0.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*Tptr1)(void)='\0';
void(*Tptr2)(void)='\0';
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Timer0_vInit()
* \Description     : initialize timer0 according to selected mode in Config_Timer0.h
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
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
/******************************************************************************
 * \Syntax          : Timer0_vEnableCompareInterrupt()
 * \Description     : used enable the Interrupt of the Compare match
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void Timer0_vEnableCompareInterrupt(){
	SET_BIT(TIMSK,1);
}
/******************************************************************************
 * \Syntax          : Timer0_vEnableOverflowInterrupt()
 * \Description     : used enable the Interrupt of the overflow
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void Timer0_vEnableOverflowInterrupt(){
	SET_BIT(TIMSK,0);
}
/******************************************************************************
 * \Syntax          : Timer0_u8ReadCompareFlag()
 * \Description     : used to read the flag of the Compare match
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u8 (0 or 1)
 *******************************************************************************/
u8 Timer0_u8ReadCompareFlag(){
	return GET_BIT(TIFR,1);
}
/******************************************************************************
 * \Syntax          : Timer0_u8ReadOverflowFlag()
 * \Description     : used to read the flag of the Overflow
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u8 (0 or 1)
 *******************************************************************************/
u8 Timer0_u8ReadOverflowFlag(){
	return GET_BIT(TIFR,0);
}
/******************************************************************************
 * \Syntax          : Timer0_vCounterRegister(u8 Loc_u8CounterVal)
 * \Description     : used to set a value to the register TCNT0
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : Loc_u8CounterVal value of the wanted to put in TCNT0
 * \Parameters (out): None
 *******************************************************************************/
void Timer0_vCounterRegister(u8 Loc_u8CounterVal){
	TCNT0= Loc_u8CounterVal;
}
/******************************************************************************
 * \Syntax          : Timer0_vCompareRegister(u8 Loc_u8CompareVal)
 * \Description     : used to set a value to the register OCR0
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : Loc_u8CompareVal value to compare with
 * \Parameters (out): None
 *******************************************************************************/
void Timer0_vCompareRegister(u8 Loc_u8CompareVal){
	OCR0=Loc_u8CompareVal;
}
/******************************************************************************
* \Syntax          : Timer0_vCompareCallBack(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when compare match interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void Timer0_vCompareCallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Tptr1=ptr;
	}
}
/******************************************************************************
* \Syntax          : Timer0_vOverflowCallBack(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when overflow interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void Timer0_vOverflowCallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Tptr2=ptr;
	}
}
/**********************************************************************************************************************
 *  Interrupts Service Routine
 *********************************************************************************************************************/
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
