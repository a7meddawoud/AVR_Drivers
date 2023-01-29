/*
 * _7Segma.c
 *
 *  Created on: Dec 24, 2022
 *      Author: a7medDawoud
 *      the BIT which is used to enable 7Segma 1 is connected to ----> PortB, Pin1
 *      the BIT which is used to enable 7Segma 2 is connected to ----> PortB, Pin2
 *      the BIT which is used to enable 7Segma DOT is connected to ----> PortB, Pin3
 *      and PortA Pin4, Pin5, Pin6, and Pin7 is used to show number .
 */

#include "_7Segma.h"
//------------ SET pins connected to the 7segma as out puts
void _7Segma_vInit(){
	/*----------7SEG_A-->PORTA .4
				7SEG_B-->PORTA .5
				7SEG_C-->PORTA .6
				7SEG_D-->PORTA .7*/
	DIO_vSetPinDirection(PortA, Pin4, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin5, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin6, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin7, Pin_OutPut);
	//-------------ENABLE LINES PINS ----------------
	DIO_vSetPinDirection(PortB, Pin2, Pin_OutPut);
	DIO_vSetPinDirection(PortB, Pin1, Pin_OutPut);
}
//-----------enable 7Segma 1 -----------
void _7Segma_vEnable1(){
	DIO_vSetPinValue(PortB, Pin1, Pin_High);
}
//-----------enable 7Segma 2 -----------
void _7Segma_vEnable2(){
	DIO_vSetPinValue(PortB, Pin2, Pin_High);
}
//-----------Disable 7Segma 1
void _7Segma_vDisable1(){
	DIO_vSetPinValue(PortB, Pin1, Pin_Low);
}
//-----------Disable 7Segma 2
void _7Segma_vDisable2(){
	DIO_vSetPinValue(PortB, Pin2, Pin_Low);
}
//------------enable 7Segma Dot
void _7Segma_vEnableDot(){
	DIO_vSetPinValue(PortB, Pin3, Pin_High);
}
//------------Disable 7Segma Dot
void _7Segma_vDisbleDot(){
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);
}
//----------Show Value on 7Segma ----------
void _7Segma_vShow(u8 loc_u8SegmaShowNumber){
	loc_u8SegmaShowNumber= (loc_u8SegmaShowNumber<<4);
	DIO_vSetPortValue(PortA, loc_u8SegmaShowNumber);
}
//------------ this function take a u8 number and print it on the left 7Segme------
void _7Segma_vPrintNumber1(u8 loc_u8SegmaPrintNumber){
	_7Segma_vEnable1();
	_7Segma_vShow(loc_u8SegmaPrintNumber);
	_7Segma_vDisable1();
}
//------------ this function take a u8 number and print it on the right 7Segme-----
void _7Segma_vPrintNumber2(u8 loc_u8SegmaPrintNumber){
	_7Segma_vEnable2();
	_7Segma_vShow(loc_u8SegmaPrintNumber);
	_7Segma_vDisable2();
}
