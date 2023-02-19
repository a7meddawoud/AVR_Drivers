/*
 * main.c
 *
 *  Created on: Dec 24, 2022
 *      Author: a7medDawoud
 *      in the main function we will used functions that is in APP.h
 *      to run our APP functions
 *      PushButtons functions are used to choose which APP function will run
 */
#include <stdio.h>
//#include "avr\io.h"
#include "APP.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/H_Bridge/H_Bridge.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/Timer1/Timer1.h"
#include "../MCAL/Timer0/Timer0.h"
#include "../MCAL/I2C/I2C.h"
#include "../services/Operating_System/OS.h"
/*void TEST();
u16 z;
u8 arr[6];*/
//void Test2();
/*
u32 counter=0;
void Task1(void);
void Task2(void);
void Task3(void);*/

int main(void){
	I2C_vInit();
	SET_BIT(DDRA,0);

	while(1){
		I2C_vSendStart();
		I2C_vSendSlaveAdressWithWrite(11);
		I2C_SendData('A');
		I2C_vSendStop();
		SET_BIT(PORTA,0);
		_delay_ms(5000);
	}

	/*
	//OS
	SET_BIT(DDRD,3);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,7);
	//SET_BIT(PORTC,7);

	OS_AddTask(0,2,Task1);
	OS_AddTask(1,3,Task2);
	OS_AddTask(2,4,Task3);
	OS_StartScheduler();
	OS_vInit();
	while(1){


	}*/
	/*	//EEprom
	LCD_vInit();
	I2C_vInit();
	u8 counter=0;
	u8 t2=0;
	u8 arr[4];
	u8 arr2[4];
	LCD_vWriteCharacter('A');
	while(1){
		if(PushButton_u8Button2()){
			counter++;
		}
		I2C_vSendStart();
		I2C_vSendSlaveAdress(0b10101001);
		I2C_SendData(0);
		I2C_SendData(counter);
			SET_BIT(DDRC,2);
			SET_BIT(PORTC,2);
		I2C_vSendStop();

			SET_BIT(DDRC,7);
			SET_BIT(PORTC,7);
		_delay_ms(10);
		LCD_vInit();

		I2C_vSendStart();
			SET_BIT(DDRD,3);
			SET_BIT(PORTD,3);
		I2C_vSendSlaveAdress(0b10101001);
		I2C_SendData(0);

		I2C_vRepeatedSendStart();

		I2C_vSendSlaveAdress(0b00000000);
		I2C_vReadData(&t2);
		I2C_vSendStop();
		APP_vToString(arr,t2);
		APP_vToString(arr2,counter);
		LCD_vGoTo(LineOne,0);
		LCD_vWriteString(arr);
		LCD_vGoTo(LineTwo,0);
		LCD_vWriteString(arr2);
	}*/
	/*
	 //I2C
	I2C_vInit();
	while(1){
	I2C_vSendStart();
	I2C_vSendSlaveAdress(0b00000010);
	I2C_SendData('A');
	I2C_vSendStop();

	}*/
	/*
	SPI_vInit();
	SET_BIT(DDRC,2);
	u8 xx;
	while(1){
		SPI_vSlaveRead(&xx);
		if(xx=='A'){
			SET_BIT(PORTC,2);
		}
	}*/
	/*//Timer2
	 * 	TCCR2=0b01101111;
	OCR2=25;
	CLR_BIT(ASSR,3);

	SET_BIT(DDRD,7);*/
	/*	//InPutCapture
	 *
	LCD_vInit();
	EXTI_vEnableGIE();
	Timer0_vCompareCallBack(Test2);
	Timer0_vInit();
	Timer0_vCompareRegister(200);
	Timer0_vEnableCompareInterrupt();
	SET_BIT(DDRD,7);
	SET_BIT(PORTD,7);
	u32 Duty;
	u32 freq;
	u8 arr[10];
	u8 arrr[10];
	Timer1_vInit();
	Timer1_vOverflowInterruptEnable();
	Timer1_vIputCaptureInterruptEnable();
	while(1){
		Timer1_vIputCaptureUnit(&Duty,&freq);
		APP_vToString(arr,Duty);
		APP_vToString(arrr,freq);
		LCD_vGoTo(LineOne,0);
		LCD_vWriteString(arr);
		LCD_vGoTo(LineTwo,0);
		LCD_vWriteString(arrr);
	}*/
	// UART

	//	while(1){
	//
	//	}
	/*
	// * servo Control
	Timer1_vInit();
	while(1){
		if(PushButton_u8Button2()){
			Timer1_vWriteICR1(40000);
			Timer1_vChannelACopmareRegister(2000);
		}
		else if(PushButton_u8Button1()){
			Timer1_vWriteICR1(40000);
			Timer1_vChannelACopmareRegister(4000);
		}
		else if(PushButton_u8Button0()){
			Timer1_vWriteICR1(40000);
			Timer1_vChannelACopmareRegister(3000);
		}
	}*/
	/*
	SET_BIT(DDRD,7);
	SET_BIT(PORTD,7);
	EXTI_vEnableGIE();
	Timer0_vInit();
	Timer0_vEnableCompareInterrupt();
	Timer0_vCompareRegister(250);
	Timer0_vCompareCallBack(Test2);
	while(1){

	}
	 */
	//	APP_vVolumeVerticalLCD();
	/*	EXTI_vEnableGIE();
	ADC_vADCCallBack(TEST);
	LCD_vInit();
	ADC_vInit(Interrupt,ADC1,FreeRunningMode);

		z=ADC_vGetVal(FreeRunningMode);

	//SET_BIT(SREG,7);
	/*	CLR_BIT(PORTA,1);
	ADCSRA = 0x87;			// Enable ADC, fr/128
	ADMUX = 0x61;

	LCD_vInit();
	SET_BIT(ADCSRA,Pin6); //(Start Conversion) after enable


	while(1){

		SET_BIT(ADCSRA,6);
		u32 y;
		u32 z;
		while(GET_BIT(ADCSRA,4)==0);
		_delay_ms(10);

			y = (((u32)ADCH)<<2);
			z = (y*5000)/1024;
			u8 chr[7];
			APP_vToString(chr,z);
			LCD_vWriteString(chr);
			LCD_vGoTo(LineOne,0);
			if(z>1000 && z<2000){
				LedAndBuzzer_vLed0Open();
				LedAndBuzzer_vLed1Close();
				LedAndBuzzer_vLed2Close();

			}
			else if(z<3000 && z>2000){
				LedAndBuzzer_vLed1Open();
				LedAndBuzzer_vLed0Close();
				LedAndBuzzer_vLed2Close();
			}
			else if(z<5000 && z>3000){
				LedAndBuzzer_vLed2Open();
				LedAndBuzzer_vLed0Close();
				LedAndBuzzer_vLed1Close();
			}
			else{
				LCD_vClear();
			}

	}*/
	/*	u8 arr[4]={1,2,1,2};
	u8 ar[3]={1,5,9};
	APP_vLocker(arr,ar);
	LCD_vInit();
	u8 love[8]={0x00,0x0A,0x1F,0x1F,0x1F,0x0E,0x04,0x00};

	_delay_ms(50);
	LCD_vCustomCharacter(love,0);

		LCD_vWriteCharacter(0);

	 while(1){
	 APP_vCalculatorLCD();
	//----------
	 /* 	if(PushButton_u8Button2OneSec()){
		LedAndBuzzer_vLed2Open();
		_delay_ms(250);
		LedAndBuzzer_vLed2Close();
	}
	else if(PushButton_u8Button1LonPress()){
	LedAndBuzzer_vLed1Open();
	_delay_ms(250);
	LedAndBuzzer_vLed1Close();
	}*/
	//	--------keypad
	/*	KAYPAD_vInit();
	u8 xx=KAYPAD_u8GetKey();
	if(xx!=0xff){
		LedAndBuzzer_vLed2Open();
		_delay_ms(250);
		LedAndBuzzer_vLed2Close();
	}
	else if(xx=='-'){
		LedAndBuzzer_vBuzzerOpen();
		_delay_ms(250);
		LedAndBuzzer_vBuzzerClose();
	}
	else if(xx==9){
		LedAndBuzzer_vLed2Open();
		_delay_ms(250);
		LedAndBuzzer_vLed2Close();
	}
	else if(xx=='/'){
		LedAndBuzzer_vBuzzerOpen();
		_delay_ms(250);
		LedAndBuzzer_vBuzzerClose();
		}
	 */

	//-------- LCD

	/*	u8 chr[]="Ahmed";
		APP_vWriteStringManyTimesLCD(chr,sizeof(chr));
		while(1){

		}
	 */
	// --------7Segma
	/*	if(PushButton_u8Button1()){
			APP_vPrint0to99();
			APP_vTaskFinsh();
		}
		else if(PushButton_u8Button2()){
			APP_v3Leds1MinuteEach();
			APP_vTaskFinsh();
		}
		else if(PushButton_u8Button0()){
			APP_vClickCounter();
			APP_vTaskFinsh();
		}
		else{
			//do nothing
		}

	} */
	return 0;
}
/*
void TEST(){
	APP_vToString(arr,z);
	LCD_vWriteString(arr);
	LCD_vGoTo(LineOne,0);

	if(z>1000 && z<2000){
		LedAndBuzzer_vLed0Open();
		LedAndBuzzer_vLed1Close();
		LedAndBuzzer_vLed2Close();

	}
	else if(z<3000 && z>2000){
		LedAndBuzzer_vLed1Open();
		LedAndBuzzer_vLed0Close();
		LedAndBuzzer_vLed2Close();
	}
	else if(z<5000 && z>3000){
		LedAndBuzzer_vLed2Open();
		LedAndBuzzer_vLed0Close();
		LedAndBuzzer_vLed1Close();
	}

}*/
/*
void Test2(){
	counter++;
	if(counter==2){
		CLR_BIT(PORTD,7);
	}
	else if(counter==20){
		SET_BIT(PORTD,7);
		counter=0;
	}
}
 */
/*
 //os

void Task1(){
	TOG_BIT(PORTD,3);
}
void Task2(){
	TOG_BIT(PORTC,2);
}
void Task3(){
	TOG_BIT(PORTC,7);

}*/
