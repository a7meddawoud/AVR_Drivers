/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SPI.c
 *        \brief  this file contains SPI Functions
 *
 *      \details  this file contains SPI Init, Send, Receive, and Interrupts callback  functions. these functions will make using SPI much easier
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SPI.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*Sptr)(void)='\0';

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : SPI_vInit()
* \Description     :  initialize the SPI registers according to the chosen mode in Config_SPI
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
*
*******************************************************************************/
void SPI_vInit(){
#if SPIMode1==SPIPolling
	#if SPIMode==SPISlave
		SPCR=0b00100100;
		SET_BIT(SPCR,6); //Enable SPI

		CLR_BIT(DDRB,4);
		CLR_BIT(DDRB,5);
		SET_BIT(DDRB,6);
		CLR_BIT(DDRB,7);
	#elif SPIMode==SPIMaster
		SPCR=0b00110000|(SPIPrescaler&0x03);
		SPSR|=(GET_BIT(SPIPrescaler,2));
		SET_BIT(DDRB,4);
		SET_BIT(DDRB,5);
		CLR_BIT(DDRB,6);
		SET_BIT(DDRB,7);

		SET_BIT(SPCR,6);	//Enable SPI
	#endif
#elif SPIMode1==SPIInterrupt
	#if SPIMode==SPISlave
		SPCR=0b10100100;
		SET_BIT(SPCR,6);	//Enable SPI

		CLR_BIT(DDRB,4);
		CLR_BIT(DDRB,5);
		SET_BIT(DDRB,6);
		CLR_BIT(DDRB,7);
	#elif SPIMode==SPIMaster
		SPCR=0b00110000|(SPIPrescaler&0x03);
		SPSR|=(GET_BIT(SPIPrescaler,2));
		SET_BIT(SPCR,6);	//Enable SPI

		SET_BIT(DDRB,4);
		SET_BIT(DDRB,5);
		CLR_BIT(DDRB,6);
		SET_BIT(DDRB,7);
	#endif
#endif

}
/******************************************************************************
* \Syntax          : SPI_vMasterWrite(u8 Loc_WriteData)
* \Description     : used to send data to slave
* \Parameters (in) : Loc_WriteData  data wanted to send
* \Parameters (out): None
*******************************************************************************/
void SPI_vMasterWrite(u8 Loc_WriteData){
	SPDR=Loc_WriteData;
	while(!GET_BIT(SPSR,7));
}
/******************************************************************************
* \Syntax          : SPI_vMasterReadWrite(u8 Loc_WriteData,u8 *Loc_ReadData)
* \Description     : used to read data from slave
* \Parameters (in) : &Loc_ReadData address of the variable wanted to store data in
* \Parameters (out): None
*******************************************************************************/
void SPI_vMasterReadWrite(u8 Loc_WriteData,u8 *Loc_ReadData){
	SPDR=Loc_WriteData;
	while(!GET_BIT(SPSR,7));
	*Loc_ReadData = SPDR;
}
/******************************************************************************
* \Syntax          : SPI_vSlaveRead(u8 *Loc_ReadData)
* \Description     : used to read data from master
* \Parameters (in) : &Loc_ReadData address of the variable wanted to store data in
* \Parameters (out): None
*******************************************************************************/
void SPI_vSlaveRead(u8 *Loc_ReadData){
	while(!GET_BIT(SPSR,7));
	*Loc_ReadData = SPDR;
}
/******************************************************************************
* \Syntax          : SPI_vTransferCompleteInterruptEnable(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when Transfer Complete interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void SPI_vTransferCompleteInterruptEnable(void(*ptr)(void)){
	if(ptr!='\0'){
		Sptr=ptr;
	}
}

/**********************************************************************************************************************
 *  Interrupts Service Routine
 *********************************************************************************************************************/
ISR(SPI_STC_vect){
	if(Sptr!='\0'){
		Sptr();
	}
}
/**********************************************************************************************************************
 *  END OF FILE: SPI.c
 *********************************************************************************************************************/
