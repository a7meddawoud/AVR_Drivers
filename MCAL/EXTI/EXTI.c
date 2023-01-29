/*
 * EXTI.c
 *
 *  Created on: Jan 7, 2023
 *      Author: a7med
 */
#include "EXTI.h"

void(*Gptr0)(void)='\0';
void(*Gptr1)(void)='\0';
void(*Gptr2)(void)='\0';
void EXTI_vEnableGIE(void){
	SET_BIT(SREG,7);
}
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
void EXTI_INT0CallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Gptr0=ptr;
	}
}
void EXTI_INT1CallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Gptr1=ptr;
	}
}
void EXTI_INT2CallBack(void(*ptr)(void)){
	if(ptr!='\0'){
		Gptr2=ptr;
	}
}
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

