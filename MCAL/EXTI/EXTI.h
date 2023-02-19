/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <EXTI.h>
 *      Created on: Jan 7, 2023
 *      Author: a7meddawoud
 *
 *  Description:  <Exeternal Interrupts functions PROTOTYPES and macros>
 *
 *********************************************************************************************************************/
#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../macros.h"
#include "../MCU.h"
#include "../types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#  define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)
//----Table 18. Reset and Interrupt Vectors-----------
#define INT0_vect			 __vector_1
#define INT1_vect			 __vector_2
#define INT3_vect			 __vector_3

#define INT0 0
#define INT1 1
#define INT2 2
#define Low_Level 0
#define Any_Change 1
#define Rising_Egde 2
#define Falling_Edge 3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void EXTI_vEnableGIE();
void EXTI_vEnablePIE(u8 Loc_u8InterruptNumber);
u8 EXIT_vReadPIF(u8 Loc_u8InterruptNumber);
void EXTI_vSenseControl(u8 Loc_u8InterruptNumber,u8 Loc_u8Mode);
void EXTI_INT0CallBack(void(*ptr)(void));
void EXTI_INT1CallBack(void(*ptr)(void));
void EXTI_INT20CallBack(void(*ptr)(void));

#endif /* MCAL_EXTI_EXTI_H_ */
/**********************************************************************************************************************
 *  END OF FILE: EXTI.h
 *********************************************************************************************************************/
