/*
 * LCD.c
 *
 *  Created on: Dec 30, 2022
 *      Author: a7med
 */
#include "LCD.h"
void LCD_vSendCommand(u8 Loc_u8Command){
	DIO_vSetPinValue(PortB, Pin1, Pin_Low);
	DIO_vSetPinValue(PortB, Pin2, Pin_Low);
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);
	//------Send command-------
	DIO_vSetPortValue(PortA,(Loc_u8Command)&0xF0);
	DIO_vSetPinValue(PortB, Pin3, Pin_High);
	_delay_ms(10);
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);
	DIO_vSetPortValue(PortA,(Loc_u8Command<<4));
	DIO_vSetPinValue(PortB, Pin3, Pin_High);
	_delay_ms(10);
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);


}
void LCD_vInit(){
	//------Set used pins as output-----
	DIO_vSetPinDirection(PortB, Pin1, Pin_OutPut);
	DIO_vSetPinDirection(PortB, Pin3, Pin_OutPut);
	DIO_vSetPinDirection(PortB, Pin2, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin4, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin5, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin6, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin7, Pin_OutPut);
	_delay_ms(50);
	LCD_vSendCommand(FunctionSet);
	_delay_ms(2);
	LCD_vSendCommand(DisplayOnControl);
	_delay_ms(2);
	LCD_vSendCommand(DisplayClear);
	_delay_ms(2);
	LCD_vSendCommand(EnrtyMode);
	_delay_ms(2);

}
void LCD_vInitWithOutClear(){
	DIO_vSetPinDirection(PortB, Pin1, Pin_OutPut);
	DIO_vSetPinDirection(PortB, Pin3, Pin_OutPut);
	DIO_vSetPinDirection(PortB, Pin2, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin4, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin5, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin6, Pin_OutPut);
	DIO_vSetPinDirection(PortA, Pin7, Pin_OutPut);

	_delay_ms(50);
	LCD_vSendCommand(FunctionSet);
	_delay_ms(2);
	LCD_vSendCommand(DisplayOnControl);
	_delay_ms(2);
	LCD_vSendCommand(EnrtyMode);
	_delay_ms(2);
}
void LCD_vWriteCharacter(u8 Loc_u8Character){
	DIO_vSetPinValue(PortB, Pin1, Pin_High);
	DIO_vSetPinValue(PortB, Pin2, Pin_Low);
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);
	//------Send command-------
	DIO_vSetPortValue(PortA,(Loc_u8Character)&0xF0);
	DIO_vSetPinValue(PortB, Pin3, Pin_High);
	_delay_ms(10);
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);
	DIO_vSetPortValue(PortA,(Loc_u8Character<<4));
	DIO_vSetPinValue(PortB, Pin3, Pin_High);
	_delay_ms(10);
	DIO_vSetPinValue(PortB, Pin3, Pin_Low);



}
void LCD_vGoTo(u8 Loc_u8Line, u8 Loc_u8CharPos){
	LCD_vSendCommand(Loc_u8Line|Loc_u8CharPos);
}
void LCD_vClear(){
	LCD_vSendCommand(DisplayClear);
	_delay_ms(2);
}
void LCD_vWriteString(u8 *ptr){
	u8 i=0;
	while(ptr[i]!='\0'){
		LCD_vWriteCharacter(ptr[i]);
		i++;
	}
}
void LCD_vCustomCharacter(u8 *ptr,u8 Location){
	u8 i;
	LCD_vSendCommand((0x40)+(Location*8));
	for(i=0;i<8;i++){
		LCD_vWriteCharacter(ptr[i]);
	}


}
void LCD_vCLearOneChar(u8 Loc_u8Line,u8 Loc_u8CharPos){
	u8 chr0[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	LCD_vCustomCharacter(chr0,1);
	LCD_vGoTo(Loc_u8Line,Loc_u8CharPos);
	LCD_vWriteCharacter(1);
}
