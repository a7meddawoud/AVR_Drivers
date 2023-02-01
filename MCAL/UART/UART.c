/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART.c
 *        \brief  this file contains UART Functions
 *
 *      \details  this file contains UART Init, Send, Receive, and Interrupts callback  functions
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "UART.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*Uptr1)(void)='\0';
void(*Uptr2)(void)='\0';
void(*Uptr3)(void)='\0';
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void UART_vInit()
* \Description     : initialize the UART registers according to the chosen mode
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void UART_vInit(){
#if UARTMode==UARTInturrept
	UBRRL=BaudRateRegisters;
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	UCSRC=0b10000110;

	SET_BIT(UCSRB,7);
	SET_BIT(UCSRB,6);
	SET_BIT(UCSRB,5);
#elif UARTMode==UARTPolling
	UBRRL=BaudRateRegisters;
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	UCSRC=0b10000110;
#endif
}
/******************************************************************************
* \Syntax          : void UART_vSendChar(u8 Loc_SendChar)
* \Description     : used to send a 8bit data using UART
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : Loc_SendChar	Data wanted to send
* \Parameters (out): None
*******************************************************************************/
void UART_vSendChar(u8 Loc_SendChar){
	while(!(GET_BIT(UCSRA,6)));
	UDR=Loc_SendChar;
}
/******************************************************************************
* \Syntax          : u8 UART_u8RecieveChar()
* \Description     : used to Receive a 8bit data using UART
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : None
* \Parameters (out): received data
*******************************************************************************/
u8 UART_u8ReceiveChar(){
	while(!(GET_BIT(UCSRA,7)));
	return UDR;
}
/******************************************************************************
* \Syntax          : void UART_RXCompleteCallBack(void(*ptr1)(void))
* \Description     : this function takes the address of a function wanted to run when RX Complete interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void UART_RXCompleteCallBack(void(*ptr1)(void)){
	if(ptr1!='\0'){
		Uptr1=ptr1;
	}
}
/******************************************************************************
* \Syntax          : void UART_TXCompleteCallBack(void(*ptr2)(void))
* \Description     : this function takes the address of a function wanted to run when TX Complete interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void UART_TXCompleteCallBack(void(*ptr2)(void)){
	if(ptr2!='\0'){
		Uptr2=ptr2;
	}
}
/******************************************************************************
* \Syntax          : void UART_TXCompleteCallBack(void(*ptr2)(void))
* \Description     : this function takes the address of a function wanted to run when Data Register Empty interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void UAART_DataRegisterEmptyCallBack(void(*ptr3)(void)){
	if(ptr3!='\0'){
		Uptr3=ptr3;
	}
}
/**********************************************************************************************************************
 *  Interrupts Service Routine
 *********************************************************************************************************************/
ISR(USART_RXC_vect){
	if(Uptr1!='\0'){
		Uptr1();
	}
}
ISR(USART_UDRE_vect){
	if(Uptr2!='\0'){
		Uptr2();
	}
}
ISR(USART_TXC_vect){
	if(Uptr3!='\0'){
		Uptr3();
	}
}
/**********************************************************************************************************************
 *  END OF FILE: UART.c
 *********************************************************************************************************************/
