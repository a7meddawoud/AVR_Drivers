/*
 * UART.h
 *
 *  Created on: Jan 25, 2023
 *      Author: a7med
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../EXTI/EXTI.h"

#define USART_RXC_vect __vector_13
#define USART_UDRE_vect __vector_14
#define USART_TXC_vect __vector_15

void UART_vInit();
void UART_vSendChar(u8 Loc_SendChar);
u8 UART_u8RecieveChar();
void UART_vRXCompleteInterruptEnable();
void UART_vTXCompleteInterruptEnable();
void UART_vDataRegisterEmptyInterruptEnable();
void UART_RXCompleteCallBack(void(*ptr1)(void));
void UART_TXCompleteCallBack(void(*ptr2)(void));
void UAART_DataRegisterEmptyCallBack(void(*ptr3)(void));

#endif /* MCAL_UART_UART_H_ */
