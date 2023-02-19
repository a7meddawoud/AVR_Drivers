/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EXTI.c
 *        \brief  this file contains External interrupts Functions
 *
 *      \details  this file contains functions that enable Global Interrupt Enable and functions to choose which External interrupt wanted to use
 *      and choose its mode  (Low_Level, Any_Change, Rising_Egde, Falling_Edge) and a functions that take the address of the functions wanted to run when Interrupt is fired
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EXTI.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*Gptr0)(void)='\0';
void(*Gptr1)(void)='\0';
void(*Gptr2)(void)='\0';

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : EXTI_vEnableGIE(void)
* \Description     :  function that enable Global Interrupt (GIE)
*
* \Parameters (in) : None
* \Parameters (out): None
*
*******************************************************************************/
void EXTI_vEnableGIE(void){
	SET_BIT(SREG,7);
}
/******************************************************************************
* \Syntax          : EXTI_vEnableGIE(void)
* \Description     : used to enable an specific interrupt passing it's number to the function (INT0,INT1,INT2)
*
* \Parameters (in) : None
* \Parameters (out): None
*
*******************************************************************************/
void EXTI_vEnablePIE(u8 Loc_u8InterruptNumber){
	if (Loc_u8InterruptNumber<=INT2){
		if(Loc_u8InterruptNumber==INT0){
			SET_BIT(GICR,6);
		}
		else if(Loc_u8InterruptNumber==INT1){
			SET_BIT(GICR,7);
		}
		else if(Loc_u8InterruptNumber==INT2){
			SET_BIT(GICR,5);
		}
		else {
			//do nothing
		}
	}
	else {
		//do nothing
	}
}
/******************************************************************************
* \Syntax          : EXIT_vReadPIF(u8 Loc_u8InterruptNumber)
* \Description     : used to read an specific interrupt flag(passing it's number to the function)
*
* \Parameters (in) : None
* \Parameters (out): u8 (0 or 1)
*
*******************************************************************************/
u8 EXIT_vReadPIF(u8 Loc_u8InterruptNumber){
	if (Loc_u8InterruptNumber<=INT2){
			if(Loc_u8InterruptNumber==INT0){
				return GET_BIT(GIFR,6);
			}
			else if(Loc_u8InterruptNumber==INT1){
				return GET_BIT(GIFR,7);
			}
			else if(Loc_u8InterruptNumber==INT2){
				return GET_BIT(GIFR,5);
			}
			else {
				//do nothing
			}
		}
		else {
			//do nothing
		}
	return 0xff;
}
/******************************************************************************
* \Syntax          : EXTI_vSenseControl(u8 Loc_u8InterruptNumber,u8 Loc_u8Mode)
* \Description     : used to choose when the specific interrupt flag(passing it's number to the function)
* 					 will be fired according to the chosen mode (Low_Level, Any_Change, Rising_Egde, Falling_Edge)
*
* \Parameters (in) : None
* \Parameters (out): u8 (0 or 1)
*
*******************************************************************************/
void EXTI_vSenseControl(u8 Loc_u8InterruptNumber,u8 Loc_u8Mode){

	if (Loc_u8InterruptNumber<=INT2){
		if(Loc_u8InterruptNumber==INT0){
			if(Loc_u8Mode<=Falling_Edge){
				if(Loc_u8Mode==Low_Level){
					CLR_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
				}
				else if(Loc_u8Mode==Any_Change){
					SET_BIT(MCUCR,0);
					CLR_BIT(MCUCR,1);
				}
				else if(Loc_u8Mode==Rising_Egde){
					SET_BIT(MCUCR,0);
					SET_BIT(MCUCR,1);
				}
				else if(Loc_u8Mode==Falling_Edge){
					CLR_BIT(MCUCR,0);
					SET_BIT(MCUCR,1);
				}
				else{
					//do nothing
				}
			}
			else{
				//do nothing
			}
		}

		else if(Loc_u8InterruptNumber==INT1){
			if(Loc_u8Mode<=Falling_Edge){
				if(Loc_u8Mode==Low_Level){
					CLR_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
				}
				else if(Loc_u8Mode==Any_Change){
					SET_BIT(MCUCR,2);
					CLR_BIT(MCUCR,3);
				}
				else if(Loc_u8Mode==Rising_Egde){
					SET_BIT(MCUCR,2);
					SET_BIT(MCUCR,3);
				}
				else if(Loc_u8Mode==Falling_Edge){
					CLR_BIT(MCUCR,2);
					SET_BIT(MCUCR,3);
				}
				else{
					//do nothing
				}
			}
			else{
				//do nothing
			}
		}
		else if(Loc_u8InterruptNumber==INT2){
			if(Loc_u8Mode==Falling_Edge||Loc_u8Mode==Rising_Egde){
				if(Loc_u8Mode==Rising_Egde){
					SET_BIT(MCUCSR,6);
				}
				else if(Loc_u8Mode==Falling_Edge){
					CLR_BIT(MCUCSR,6);
				}
				else{
					//do nothing
				}
			}
			else{
				//do nothing
			}
		}
		else {
			//do nothing
		}
	}
	else{
		//do nothing
	}

}
/******************************************************************************
* \Syntax          : EXTI_INT0CallBack(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when External interrupt0 is fired.
*
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void EXTI_INT0CallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Gptr0=ptr;
	}
}
/******************************************************************************
* \Syntax          : EXTI_INT1CallBack(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when External interrupt1 is fired.
*
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void EXTI_INT1CallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Gptr1=ptr;
	}
}
/******************************************************************************
* \Syntax          : EXTI_INT2CallBack(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when External interrupt2 is fired.
*
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void EXTI_INT2CallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Gptr2=ptr;
	}
}

/**********************************************************************************************************************
 *  Interrupts Service Routine
 *********************************************************************************************************************/
ISR(INT0_vect){
	if(Gptr0!='\0'){
		Gptr0();
	}
}
ISR(INT1_vect){
	if(Gptr1!='\0'){
		Gptr1();
	}
}
ISR(INT2_vect){
	if(Gptr2!='\0'){
		Gptr2();
	}
}
/**********************************************************************************************************************
 *  END OF FILE: EXTI.c
 *********************************************************************************************************************/

