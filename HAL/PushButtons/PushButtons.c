/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PushButtoms.c
 *        \brief  used to check Button State
 *
 *      \details  each function will read the value from the pin connected to the button but the check will happen
 *      Twice as there might be some noise.
 *		*********Note: these Pushbuttons is externally PulledDown**********
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PushButtons.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : u8 PushButton_u8Button0()
* \Description     : function check button 0 which is connected to portB Pin0
*
* \Parameters (in) : None
* \Parameters (out): u8
* \Return value:   : 0 or 1
*******************************************************************************/
u8 PushButton_u8Button0(){
	DIO_vSetPinDirection(PortB, Pin0, Pin_InPut);
	if(DIO_u8PGetPinValue(PortB,Pin0)){
		_delay_ms(25);
		if(DIO_u8PGetPinValue(PortB,Pin0)){
			return 1;
		}
	}
	return 0;
}
/******************************************************************************
* \Syntax          : u8 PushButton_u8Button1()
* \Description     : function check button 1 which is connected to portD Pin6
*
* \Parameters (in) : None
* \Parameters (out): u8
* \Return value:   : 0 or 1
*******************************************************************************/
u8 PushButton_u8Button1(){
	DIO_vSetPinDirection(PortD, Pin6, Pin_InPut);
	if(DIO_u8PGetPinValue(PortD,Pin6)){
		_delay_ms(25);
		if(DIO_u8PGetPinValue(PortD,Pin6)){
			return 1;
		}
	}
	return 0;
}
/******************************************************************************
* \Syntax          : u8 PushButton_u8Button2()
* \Description     : function check button 2 which is connected to portD Pin2
*
* \Parameters (in) : None
* \Parameters (out): u8
* \Return value:   : 0 or 1
*******************************************************************************/
u8 PushButton_u8Button2(){
	DIO_vSetPinDirection(PortD, Pin2, Pin_InPut);
	if(DIO_u8PGetPinValue(PortD,Pin2)){
		_delay_ms(25);
		if(DIO_u8PGetPinValue(PortD,Pin2)){
			return 1;
		}
	}
	return 0;
}
/******************************************************************************
* \Syntax          : u8 PushButton_u8Button1LonPress()
* \Description     : function check button 1 and wait until it is not pressed then return 1
*
* \Parameters (in) : None
* \Parameters (out): u8
* \Return value:   : 0 or 1
*******************************************************************************/
u8 PushButton_u8Button1LonPress(){
	if(PushButton_u8Button1()){
		while(PushButton_u8Button1()){
			_delay_ms(10);
		}
		return 1;
	}
	else{
		return 0;
	}
}
/******************************************************************************
* \Syntax          : u8 PushButton_u8Button1LonPress()
* \Description     : function check button 1 if it was pressed for 1SEC ore more return 1 otherwise it return 0
*
* \Parameters (in) : None
* \Parameters (out): u8
* \Return value:   : 0 or 1
*******************************************************************************/
u8 PushButton_u8Button2OneSec(){
	u8 Delay=0;
	while(PushButton_u8Button2()){
		_delay_ms(10);
		Delay++;
	}
	if(Delay>29){
		return 1;
	}
	else{
		return 0;
	}
}
