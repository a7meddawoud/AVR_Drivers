/*
 * SPI.c
 *
 *  Created on: Jan 27, 2023
 *      Author: a7med
 */
#include "SPI.h"

void(*Sptr)(void)='\0';

void SPI_vInit(){
#if SPIMode1==SPIPolling
	#if SPIMode==SPISlave
		SPCR=0b00100100;
		CLR_BIT(SPSR,0);
		SET_BIT(SPCR,6);

		CLR_BIT(DDRB,4);
		CLR_BIT(DDRB,5);
		SET_BIT(DDRB,6);
		CLR_BIT(DDRB,7);
	#elif SPIMode==SPIMaster
		SPCR=0b00110100;
		CLR_BIT(SPSR,0);
		SET_BIT(DDRB,4);
		SET_BIT(DDRB,5);
		CLR_BIT(DDRB,6);
		SET_BIT(DDRB,7);

		SET_BIT(SPCR,6);
	#endif
#elif SPIMode1==SPIInterrupt
	#if SPIMode==SPISlave
		SPCR=0b10100100;
		CLR_BIT(SPSR,0);
		SET_BIT(SPCR,6);

		CLR_BIT(DDRB,4);
		CLR_BIT(DDRB,5);
		SET_BIT(DDRB,6);
		CLR_BIT(DDRB,7);
	#elif SPIMode==SPIMaster
		SPCR=0b10110100;
		CLR_BIT(SPSR,0);
		SET_BIT(SPCR,6);

		SET_BIT(DDRB,4);
		SET_BIT(DDRB,5);
		CLR_BIT(DDRB,6);
		SET_BIT(DDRB,7);
	#endif
#endif

}
void SPI_vMasterWrite(u8 Loc_WriteData){
	SPDR=Loc_WriteData;
	while(!GET_BIT(SPSR,7));
}

void SPI_vMasterReadWrite(u8 Loc_WriteData,u8 *Loc_ReadData){
	SPDR=Loc_WriteData;
	while(!GET_BIT(SPSR,7));
	*Loc_ReadData = SPDR;
}

void SPI_vSlaveRead(u8 *Loc_ReadData){
	while(!GET_BIT(SPSR,7));
	*Loc_ReadData = SPDR;
}
void SPI_vTransferCompleteInterruptEnable(void(*ptr)(void)){
	if(ptr!='\0'){
		Sptr=ptr;
	}
}
ISR(SPI_STC_vect){
	if(Sptr!='\0'){
		Sptr();
	}
}
