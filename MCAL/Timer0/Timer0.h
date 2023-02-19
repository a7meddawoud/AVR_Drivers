/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Timer0.h>
 *        Created on: Jan 15, 2023
 *      Author: a7meddawoud
 *
 *  Description:  <Timer0 functions prototypes and macros>
 *
 *********************************************************************************************************************/

#ifndef MCAL_TIMER0_TIMER0_H_
#define MCAL_TIMER0_TIMER0_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../EXTI/EXTI.h"
#include "Config_Timer0.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define T0NormalMode 0
#define T0CTCMode 1
#define T0PWMFastMode 2
#define T0PWMPhaseCorrectMode 3
#define T0PreSclaer1024	0x05
#define T0PreSclaer256	0x04
#define T0PreSclaer64		0x03
#define T0PreSclaer8		0x02
#define T0NoPreSclaer		0x01

#define TIMER0_COMP_vect	__vector_10
#define TIMER0_OVF_vect 	__vector_11
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Timer0_vInit();
void Timer0_vCounterRegister(u8 Loc_u8CounterVal);
void Timer0_vCompareRegister(u8 Loc_u8CompareVal);
void Timer0_vEnableCompareInterrupt();
void Timer0_vEnableOverflowInterrupt();
u8 Timer0_u8ReadCompareFlag();
u8 Timer0_u8ReadOverflowFlag();
void Timer0_vCompareCallBack(void(*ptr)(void));
void Timer0_vOverflowCallBack(void(*ptr)(void));
#endif /* MCAL_TIMER0_TIMER0_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Config_Timer0.h
 *********************************************************************************************************************/
