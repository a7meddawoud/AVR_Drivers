 /**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file   KEYPAD.c
 * 			\Created on: Dec 31, 2022
 *    		 \  Author: a7medDawoud
 *
 *     \  this file contains Keypad functions which enable us to use keypad easily
 *
 *      \this file is used to assign the inputs and outputs for the micro controller and check which key is pressed
 *
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "KEYPAD.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 arr[4][4]={{1,2,3,'+'},
			{4,5,6,'-'},
			{7,8,9,'*'},
			{'%',0,'=','/'}};

/**********************************************************************************************************************
 *  GLOBAL FUNCTION
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void KAYPAD_u8Init()
* \Description     : this function assign the inputs and outputs for the micro controller
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void KAYPAD_vInit(){
	DIO_vSetPortDirection(KEYPAD_PORT,KEYPAD_DIRECTION);
	DIO_vSetPortValue(KEYPAD_PORT,KEYPAD_VALUE);

}

/******************************************************************************
* \Syntax          : u8 KAYPAD_u8GetKey()
* \Description     : this function return which button in the keypad is pressed
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : unsigned char  E_OK
*                                    E_NOT_OK
*******************************************************************************/
u8 KAYPAD_u8GetKey(){
	u8 Loc_u8RowCounter, Loc_u8CoulomsCounter;
	u8 row , coulom, temp;
	coulom=3;
	u8 value=9;
	for(Loc_u8CoulomsCounter=0;Loc_u8CoulomsCounter<4;Loc_u8CoulomsCounter++){
		DIO_vSetPinValue(KEYPAD_PORT,Loc_u8CoulomsCounter,Pin_Low);
		row=3;
		for(Loc_u8RowCounter=4;Loc_u8RowCounter<8;Loc_u8RowCounter++){
			temp=DIO_u8PGetPinValue(KEYPAD_PORT,Loc_u8RowCounter);
			if(temp==0){
				_delay_ms(25);
				temp=DIO_u8PGetPinValue(KEYPAD_PORT,Loc_u8RowCounter);
				if(temp==0){
					value=arr[row][coulom];
					return value;
				}
			}
			row--;
		}
		coulom--;
		DIO_vSetPinValue(KEYPAD_PORT,Loc_u8CoulomsCounter,Pin_High);
	}

	return 0xff;
}
/**********************************************************************************************************************
 *  END OF FILE: KEYPAD.c
 *********************************************************************************************************************/
