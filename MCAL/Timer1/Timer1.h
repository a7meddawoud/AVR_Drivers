/*
 * Timer1.h
 *
 *  Created on: Jan 18, 2023
 *      Author: a7med
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_

#include "../EXTI/EXTI.h"
#include "MCAL/Timer1/Config_Timer1.h"


#define T1OverflowMode 0
#define T1CTCMode 1
#define T1CTCModeICR1 2
#define T1FastPWMICR1 3
#define InputCaptureMode 4

#define T1PhaseCorrectPWMICR1 4
#define T1PreSclaer1024	0x05
#define T1PreSclaer256	0x04
#define T1PreSclaer64		0x03
#define T1PreSclaer8		0x02
#define T1NoPreSclaer		0x01

#define TIMER1_CAPT_vect	__vector_6
#define TIMER1_COMPA_vect	__vector_7
#define TIMER1_COMPB_vect	__vector_8
#define TIMER1_OVF_vect 	__vector_9

void Timer1_vInit();
void Timer1_vPreLoadResgister(u16 Loc_val);
void Timer1_vChannelACopmareRegister(u16 Loc_val);
void Timer1_vChannelBCopmareRegister(u16 Loc_val);
void Timer1_vOverflowCounter();
void Timer1_vInputCaptureCal();
void Timer1_vIputCaptureInterruptEnable();
void Timer1_vCompareChannelAInterruptEnable();
void Timer1_vCompareChannelBInterruptEnable();
void Timer1_vOverflowInterruptEnable();
u8 Timer1_vReadCompareChannelAFlag();
u8 Timer1_vReadCompareChannelBFlag();
u8 Timer1_vReadOverflowFlag();
u16 Timer1_vReadTCNT1();
u16 Timer1_vReadInputCaptureRegister();
void Timer1_vOverflowCallBack(void(*ptr1)(void));
void Timer1_vChannelACompareCallBack(void(*ptr2)(void));
void Timer1_vChannelBCompareCallBack(void(*ptr3)(void));
void Timer1_vIputCaptureCallBack(void(*ptr4)(void));
void Timer1_vIputCaptureUnit(u32* Duty,u32* Frequency);

#endif /* MCAL_TIMER1_TIMER1_H_ */
