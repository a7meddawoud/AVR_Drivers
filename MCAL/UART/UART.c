/*
 * UART.c
 *
 *  Created on: Jan 25, 2023
 *      Author: a7med
 */

#include "UART.h"

void(*Uptr1)(void)='\0';
void(*Uptr2)(void)='\0';
void(*Uptr3)(void)='\0';

void UART_vInit(){
	UBRRL=103;
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRB,4);
	UCSRC=0b10000110;
}
void UART_vSendChar(u8 Loc_SendChar){
	while(GET_BIT(UCSRA,6));
	UDR=Loc_SendChar;
}
u8 UART_u8RecieveChar(){
	while(!(GET_BIT(UCSRA,7)));
	return UDR;
}
void UART_vRXCompleteInterruptEnable(){
	SET_BIT(UCSRB,7);
}
void UART_vTXCompleteInterruptEnable(){
	SET_BIT(UCSRB,6);
}
void UART_vDataRegisterEmptyInterruptEnable(){
	SET_BIT(UCSRB,5);
}
void UART_RXCompleteCallBack(void(*ptr1)(void)){
	if(ptr1!='\0'){
		Uptr1=ptr1;
	}
}
void UART_TXCompleteCallBack(void(*ptr2)(void)){
	if(ptr2!='\0'){
		Uptr2=ptr2;
	}
}
void UAART_DataRegisterEmptyCallBack(void(*ptr3)(void)){
	if(ptr3!='\0'){
		Uptr3=ptr3;
	}
}
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
