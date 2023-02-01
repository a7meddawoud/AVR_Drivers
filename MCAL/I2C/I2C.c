/*
 * I2C.c
 *
 *  Created on: Jan 29, 2023
 *      Author: a7med
 */

#include "I2C.h"

void(*Iptr)(void)='\0';

void I2C_vInit(){
#if I2CMode==I2CInterrupt
		TWBR = I2CBitRate;
		SET_BIT(TWCR,TWEN);
		SET_BIT(TWCR,TWIE);
		TWSR = I2CPrescaler;
		TWAR = assignedAddress;
#elif I2CMode==I2CPolling
		TWAR = assignedAddress;
		TWSR = I2CPrescaler;
		TWBR = I2CBitRate;
		SET_BIT(TWCR,TWEN);
#endif
}
void I2C_vSendStart(){
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(!(GET_BIT(TWCR,7)));
}
void I2C_vRepeatedSendStart(){
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,5);
	SET_BIT(TWCR,7);
	while(!(GET_BIT(TWCR,7)));
}
void I2C_vSendStop(){
	SET_BIT(TWCR,2);
	SET_BIT(TWCR,4);
	SET_BIT(TWCR,7);
	while(!(GET_BIT(TWCR,7)));
}
void I2C_vSendSlaveAdress(u8 Loc_SlaveAdress){
	SET_BIT(TWCR,2);
	TWDR=Loc_SlaveAdress; //frist bit is for read or write
	SET_BIT(TWCR,7);
	while(!(GET_BIT(TWCR,7)));
}
void I2C_SendData(u8 Loc_Data){
	SET_BIT(TWCR,2);

	TWDR=Loc_Data;
	SET_BIT(TWCR,7);
	while(!(GET_BIT(TWCR,7)));
}
void I2C_vReadData(u8* ptr){
	SET_BIT(TWCR,2);

	*ptr=TWDR;
	SET_BIT(TWCR,7);
	while(!(GET_BIT(TWCR,7)));
}
void I2C_vJobFinishedInterruptEnable(void(*ptr)(void)){
	if(ptr!='\0'){
		Iptr=ptr;
	}
}
ISR(TWI_vect){
	if(Iptr!='\0'){
		Iptr();
	}
}
