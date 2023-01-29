/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  LedAndBuzzer.c
 *        \brief file is used to control LEDs And Buzzer
 *
 *      \details  this file include Functions that is used to open and close 3 LEDs Connected to PORTD,3 PORTC,2 PORTC,7 and a buzzer Connected to PORTA,3
 *      this file uses DIO.h functions to control LEDs And Buzzer (open And Close)
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "LedAndBuzzer.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vLed0Open()
* \Description     : this function is used to open the led0 which is connected to PortC Pin2
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vLed0Open(){
	DIO_vSetPinDirection(PortC, Pin2, Pin_OutPut);
	DIO_vSetPinValue(PortC, Pin2, Pin_High);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vLed0Close()
* \Description     : this function is used to Close the led0 which is connected to PortC Pin2
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vLed0Close(){
	DIO_vSetPinValue(PortC, Pin2, Pin_Low);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vLed1Open()
* \Description     : this function is used to open the led1 which is connected to PortC Pin7
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vLed1Open(){
	DIO_vSetPinDirection(PortC, Pin7, Pin_OutPut);
	DIO_vSetPinValue(PortC, Pin7, Pin_High);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vLed1Close()
* \Description     : this function is used to Close the led1 which is connected to PortC Pin7
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vLed1Close(){
	DIO_vSetPinValue(PortC, Pin7, Pin_Low);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vLed2Open()
* \Description     : this function is used to open the led2 which is connected to PortD Pin3
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vLed2Open(){
	DIO_vSetPinDirection(PortD, Pin3, Pin_OutPut);
	DIO_vSetPinValue(PortD, Pin3, Pin_High);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vLed2Close()
* \Description     : this function is used to Close the led2 which is connected to PortD Pin3
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vLed2Close(){
	DIO_vSetPinValue(PortD, Pin3, Pin_Low);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vBuzzerOpen()
* \Description     : this function is used to open the Buzzer which is connected to PortA Pin3
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vBuzzerOpen(){
	DIO_vSetPinDirection(PortA, Pin3, Pin_OutPut);
	DIO_vSetPinValue(PortA, Pin3, Pin_High);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vBuzzerClose()
* \Description     : this function is used to Close the Buzzer which is connected to PortA Pin3
*
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vBuzzerClose(){
	DIO_vSetPinValue(PortA, Pin3, Pin_Low);
}
/******************************************************************************
* \Syntax          : void LedAndBuzzer_vFlash(u8 Loc_vNumberOfFlashes)
* \Description     : this function is used to turn on the LEDs and Buzzer for .25sec number of times
*
* \Parameters (in) : u8 Loc_vNumberOfFlashes	Number of LEDs and Buzzer WILL on and off
* \Parameters (out): None
*******************************************************************************/
void LedAndBuzzer_vFlash(u8 Loc_vNumberOfFlashes){
	u8 count;
	for(count=0;count<Loc_vNumberOfFlashes;count++){
		LedAndBuzzer_vBuzzerOpen();
		LedAndBuzzer_vLed0Open();
		LedAndBuzzer_vLed1Open();
		LedAndBuzzer_vLed2Open();
		_delay_ms(250);
		LedAndBuzzer_vBuzzerClose();
		LedAndBuzzer_vLed2Close();
		LedAndBuzzer_vLed0Close();
		LedAndBuzzer_vLed1Close();
		_delay_ms(250);
	}
}
/**********************************************************************************************************************
 *  END OF FILE: LedAndBuzzer.c
 *********************************************************************************************************************/
