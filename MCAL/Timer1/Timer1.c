/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer1.c
 *        \brief  include functions that make Timer1 using easer
 *
 *      \details  functions in this file can be used to initialize Timer1 and use it modes(overflow ,CTC ,PWM,InputCaptureUnit)
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer1.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*T1Ptr1)(void)='\0';
void(*T1Ptr2)(void)='\0';
void(*T1Ptr3)(void)='\0';
void(*T1Ptr4)(void)='\0';

u8 T1Counter;
u8 T1Flag=0;
u16 T1TimeOn;
u8 T1OnCounts;
u16 T1TimeTotal;
u8 T1TotalCounts;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Timer1_vInit()
* \Description     : initialize timer1 according to selected mode in Config_Timer1.h
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void Timer1_vInit(){
	SET_BIT(DDRD,5); // Set Channel A Pin as OutPut
	SET_BIT(DDRD,4); // Set Channel B Pin as OutPut
#if Timer1_Mode==T1OverflowMode
	TCCR1A=0b00000000;
	TCCR1B=0b00000000|Timer1Prescaler;
#elif Timer1_Mode==T1CTCMode
	TCCR1A=0b00001100;
	TCCR1B=0b00001000|Timer1Prescaler;
#elif Timer1_Mode==T1CTCModeICR1
	TCCR1A=0b00001100;
	TCCR1B=0b00011000|Timer1Prescaler;
#elif Timer1_Mode==T1FastPWMICR1
	TCCR1A=0b10100010;
	TCCR1B=0b00011000|Timer1Prescaler;   // prescaler 8Bits
#elif Timer1_Mode==T1PhaseCorrectPWMICR1
	TCCR1A=0b10100010;
	TCCR1B=0b00010000|Timer1Prescaler;
#elif Timer1_Mode==InputCaptureMode
	TCCR1A=0b00000000;
	TCCR1B=0b10000000|Timer1Prescaler;
	Timer1_vOverflowCallBack(Timer1_vOverflowCounter);
	Timer1_vIputCaptureCallBack(Timer1_vInputCaptureCal);
	CLR_BIT(DDRD,6); // Make Pin6 PortD Input
	SET_BIT(TCCR1B,ICES1);  // Capture At rising Edge
#endif
}
/******************************************************************************
* \Syntax          : imer1_vIputCaptureUnit(u32* duty,u32* Frequency)
* \Description     : take the address of used to get duty cycle and Frequency of a PWM wave in the IpnutCaptureUnit Mode
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : &duty	  address of variable that will take duty cycle value of the received PWM wave
* 					 &Frequency	address of variable that will take Frequency value of the received PWM wave
* \Parameters (out): None
*******************************************************************************/
void Timer1_vIputCaptureUnit(u32* duty,u32* Frequency){
	if(T1Flag==3){
		*duty=(u32)(((T1TimeOn+(T1OnCounts*65536))*100)/(T1TimeTotal)+(T1TotalCounts*65536));
		*Frequency=(u32)(T1SystemFrequency/((T1TimeTotal+(T1TotalCounts*65536))*T1InputCalcPrescaler));
	}
}
/******************************************************************************
* \Syntax          : Timer1_vOverflowCounter()
* \Description     : used to increase to global variable T1Counter each Interrupt  (used in the Init of InputCaptureUnit to count all overflows number)
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void Timer1_vOverflowCounter(){
	T1Counter++;
}
/******************************************************************************
* \Syntax          : Timer1_vInputCaptureCal()
* \Description     : used to calculate number of timer ticks in the on time and the total time
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void Timer1_vInputCaptureCal(){
	if(T1Flag==0){
		Timer1_vPreLoadResgister(0);
		T1TimeOn=0;
		T1OnCounts=0;
		T1TimeTotal=0;
		T1TotalCounts=0;
		T1Counter=0;
		CLR_BIT(TCCR1B,ICES1);
		T1Flag++;
	}
	else if(T1Flag==1){
		T1TimeOn=Timer1_vReadTCNT1();
		T1OnCounts=T1Counter;
		SET_BIT(TCCR1B,ICES1);
		T1Flag++;
	}
	else if(T1Flag==2){
		T1TimeTotal=Timer1_vReadTCNT1();
		T1TotalCounts=T1Counter;
		T1Flag++;
	}
}
/******************************************************************************
 * \Syntax          : Timer1_vIputCaptureInterruptEnable()
 * \Description     : used enable the Interrupt of the IputCapture (at rising or falling edge can be changed from (TCCR1B,ICES1))
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vIputCaptureInterruptEnable(){
	SET_BIT(TIMSK,5);
}
/******************************************************************************
 * \Syntax          : Timer1_vCompareChannelAInterruptEnable()
 * \Description     : used enable the Interrupt of the Compare Channel A
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vCompareChannelAInterruptEnable(){
	SET_BIT(TIMSK,4);
}
/******************************************************************************
 * \Syntax          : Timer1_vCompareChannelBInterruptEnable()
 * \Description     : used enable the Interrupt of the Compare Channel B
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vCompareChannelBInterruptEnable(){
	SET_BIT(TIMSK,3);
}
/******************************************************************************
 * \Syntax          : Timer1_vCompareChannelBInterruptEnable()
 * \Description     : used enable the Interrupt of the overflow
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vOverflowInterruptEnable(){
	SET_BIT(TIMSK,2);
}
/******************************************************************************
 * \Syntax          : Timer1_vReadCompareChannelAFlag()
 * \Description     : used to read the flag of the Compare Channel A
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u8 (0 or 1)
 *******************************************************************************/
u8 Timer1_vReadCompareChannelAFlag(){
	return GET_BIT(TIFR,4);
}
/******************************************************************************
 * \Syntax          : Timer1_vReadCompareChannelBFlag()
 * \Description     : used to read the flag of the Compare Channel B
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u8 (0 or 1)
 *******************************************************************************/
u8 Timer1_vReadCompareChannelBFlag(){
	return GET_BIT(TIFR,3);
}
/******************************************************************************
 * \Syntax          : Timer1_vReadOverflowFlag()
 * \Description     : used to read the flag of the Overflow
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u8 (0 or 1)
 *******************************************************************************/
u8 Timer1_vReadOverflowFlag(){
	return GET_BIT(TIFR,2);
}
/******************************************************************************
 * \Syntax          : Timer1_vReadTCNT1()
 * \Description     : used to read the value of the TCNT1 register
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u16 (0 to 65536)
 *******************************************************************************/
u16 Timer1_vReadTCNT1(){
	u16 Read;
	Read=(((u16)TCNT1H)<<8);
	Read=Read|((u16)TCNT1L);
	return Read;
}
/******************************************************************************
 * \Syntax          : Timer1_vReadInputCaptureRegister()
 * \Description     : used to read the value of the InputCapture Register
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : None
 * \Parameters (out): u16 (0 to 65536)
 *******************************************************************************/
u16 Timer1_vReadInputCaptureRegister(){
	u16 Read;
	Read=(((u16)ICR1H)<<8);
	Read=Read|((u16)ICR1L);
	return Read;
}
/******************************************************************************
 * \Syntax          : Timer1_vPreLoadResgister(u16 Loc_val)
 * \Description     : used to set a value to the register TCNT1 (preload)
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : Loc_val value of the wanted preload
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vPreLoadResgister(u16 Loc_val){
	TCNT1H=(Loc_val>>8);
	TCNT1L=Loc_val;
}
/******************************************************************************
 * \Syntax          : Timer1_vWriteICR1(u16 Loc_val)
 * \Description     : used to set a value to the register ICR1
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : Loc_val value of the wanted preload
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vWriteICR1(u16 Loc_val){
	ICR1H=(Loc_val>>8);
	ICR1L=Loc_val;
}
/******************************************************************************
 * \Syntax          : Timer1_vChannelACopmareRegister(u16 Loc_val)
 * \Description     : used to set a value to the register OCR1A
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : Loc_val value to compare with
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vChannelACopmareRegister(u16 Loc_val){
	OCR1AH=(Loc_val>>8);
	OCR1AL=Loc_val;
}
/******************************************************************************
 * \Syntax          : Timer1_vChannelBCopmareRegister(u16 Loc_val)
 * \Description     : used to set a value to the register OCR1B
 *
 * \Sync\Async      : Asynchronous
 * \Parameters (in) : Loc_val value to compare with
 * \Parameters (out): None
 *******************************************************************************/
void Timer1_vChannelBCopmareRegister(u16 Loc_val){
	OCR1BH=(Loc_val>>8);
	OCR1BL=Loc_val;
}
/******************************************************************************
* \Syntax          : Timer1_vOverflowCallBack(void(*ptr1)(void))
* \Description     : this function takes the address of a function wanted to run when Overflow interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void Timer1_vOverflowCallBack(void(*ptr1)(void)){
	if(ptr1!='\0'){
		T1Ptr1=ptr1;
	}
}
/******************************************************************************
* \Syntax          : Timer1_vChannelACompareCallBack(void(*ptr2)(void))
* \Description     : this function takes the address of a function wanted to run when compare match with channel A interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void Timer1_vChannelACompareCallBack(void(*ptr2)(void)){
	if(ptr2!='\0'){
		T1Ptr2=ptr2;
	}
}
/******************************************************************************
* \Syntax          : Timer1_vChannelBCompareCallBack(void(*ptr2)(void))
* \Description     : this function takes the address of a function wanted to run when compare match with channel B interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void Timer1_vChannelBCompareCallBack(void(*ptr3)(void)){
	if(ptr3!='\0'){
		T1Ptr3=ptr3;
	}
}
/******************************************************************************
* \Syntax          : Timer1_vIputCaptureCallBack(void(*ptr4)(void))
* \Description     : this function takes the address of a function wanted to run when InputCapture interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void Timer1_vIputCaptureCallBack(void(*ptr4)(void)){
	if(ptr4!='\0'){
		T1Ptr4=ptr4;
	}
}
/**********************************************************************************************************************
 *  Interrupts Service Routine
 *********************************************************************************************************************/
ISR(TIMER1_COMPA_vect){
	if(T1Ptr2!='\0'){
		T1Ptr2();
	}
}
ISR(TIMER1_COMPB_vect){
	if(T1Ptr3!='\0'){
		T1Ptr3();
	}
}
ISR(TIMER1_OVF_vect){
	if(T1Ptr1!='\0'){
		T1Ptr1();
	}
}
ISR(TIMER1_CAPT_vect){
	if(T1Ptr4!='\0'){
		T1Ptr4();
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Timer1.c
 *********************************************************************************************************************/
