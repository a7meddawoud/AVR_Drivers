/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  I2C.c
 *        \brief  this file contains I2C Functions
 *
 *      \details  this file contains UART Init, Send, Receive, and Interrupts callback  functions. these functions will make using I2C much easier
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "I2C.h"
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
void(*Iptr)(void)='\0';
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : I2C_vInit()
* \Description     :  initialize the I2C registers according to the chosen mode in Config_I2C
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
*
*******************************************************************************/
void I2C_vInit(){
#if I2CMode2==I2CMaster
	TWBR = I2CBitRate;
	TWSR|=(I2CPrescaler&0x03);
	TWAR = (assignedAddress<<1);
	#if I2CMode3==I2CSendACK
		SET_BIT(TWCR,TWEA);
	#endif
	#if I2CMode==I2CInterrupt
		SET_BIT(TWCR,TWIE);
	#endif
	SET_BIT(TWCR,TWEN);
#elif I2CMode2==I2CSlave
	TWAR = (assignedAddress<<1);
	#if I2CMode3==I2CSendACK
		SET_BIT(TWCR,TWEA);
	#endif
	#if I2CMode==I2CInterrupt
		SET_BIT(TWCR,TWIE);
	#endif
	SET_BIT(TWCR,TWEN);
#endif

}
/******************************************************************************
* \Syntax          : I2C_Status I2C_vSendStart()
* \Description     : if the data bus is free this function will make this master hold the bus
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vSendStart(){
	I2C_Status local_Status= E_NOT_OK;
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	//CLR_BIT(TWCR,5);
	if((TWSR&0xF8)==0x08){
		local_Status= E_OK;
	}
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_vRepeatedSendStart()
* \Description     : used to make master send data again without stop condition
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vRepeatedSendStart(){
	I2C_Status local_Status= E_NOT_OK;
	SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	if((TWSR&0xF8)==0x10){
		local_Status= E_OK;
	}
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_Status I2C_vSendStop()
* \Description     : used to make master release the bus
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vSendStop(){
	I2C_Status local_Status= E_NOT_OK;
	SET_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	local_Status= E_OK;
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_vSendSlaveAdressWithRead(u8 Loc_SlaveAdress)
* \Description     : used to send slave address wanted to read it's data
* \Sync\Async      : Synchronous
* \Parameters (in) : Loc_SlaveAdress  Slave Address
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vSendSlaveAdressWithRead(u8 Loc_SlaveAddress){
	I2C_Status local_Status= E_NOT_OK;
	CLR_BIT(TWDR,TWD0);
	TWDR=(Loc_SlaveAddress<<1); //First bit is for read or write
	SET_BIT(TWCR,TWINT);

	while(!(GET_BIT(TWCR,TWINT)));
	if((TWSR&0xF8)==0x40){
		local_Status= E_OK;
	}
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_vSendSlaveAdressWithWrite(u8 Loc_SlaveAddress)
* \Description     : used to send slave address wanted to send him data
* \Sync\Async      : Synchronous
* \Parameters (in) : Loc_SlaveAdress  Slave Address
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vSendSlaveAdressWithWrite(u8 Loc_SlaveAddress){
	I2C_Status local_Status= E_NOT_OK;
	SET_BIT(TWDR,TWD0);
	TWDR=(Loc_SlaveAddress<<1); //frist bit is for read or write
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	if((TWSR&0xF8)==0x18){
		local_Status= E_OK;
	}
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_SendData(u8 Loc_Data)
* \Description     : used to send data to slave with The address that was previously sent
* \Sync\Async      : Synchronous
* \Parameters (in) : Loc_Data  data wanted to send
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_SendData(u8 Loc_Data){
	I2C_Status local_Status= E_NOT_OK;
	TWDR=Loc_Data;
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	if((TWSR&0xF8)==0x28){
		local_Status= E_OK;
	}
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_vMasterReadData(u8* ptr)
* \Description     : used to read data from slave with The address that was previously sent
* \Sync\Async      : Synchronous
* \Parameters (in) : &ptr address of the variable wanted to store data in
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vMasterReadData(u8* ptr){
	I2C_Status local_Status= E_NOT_OK;
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	if((TWSR&0xF8)==0x50){
			local_Status= E_OK;
	}
	*ptr=TWDR;
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_MatchAddress()
* \Description     : used to check if this slave address have been received
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_MatchAddress(){
	I2C_Status local_Status= E_NOT_OK;
	if((TWSR&0xF8)!=0x60){
		local_Status= E_OK;
	}
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_vSlaveReadData(u8* ptr)
* \Description     : used to read data from master
* \Sync\Async      : Synchronous
* \Parameters (in) : &ptr address of the variable wanted to store data in
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
I2C_Status I2C_vSlaveReadData(u8* ptr){
	I2C_Status local_Status= E_NOT_OK;
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(!(GET_BIT(TWCR,TWINT)));
	if((TWSR&0xF8)!=0x80){
		local_Status= E_OK;
	}
	*ptr=TWDR;
	return local_Status;
}
/******************************************************************************
* \Syntax          : I2C_vJobFinishedInterruptEnable(void(*ptr)(void))
* \Description     : this function takes the address of a function wanted to run when Job finished interrupt is fired.
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : void(*ptr1)(void)
* \Parameters (out): None
*******************************************************************************/
void I2C_vJobFinishedInterruptEnable(void(*ptr)(void)){
	if(ptr!='\0'){
		Iptr=ptr;
	}
}
/**********************************************************************************************************************
 *  Interrupts Service Routine
 *********************************************************************************************************************/
ISR(TWI_vect){
	if(Iptr!='\0'){
		Iptr();
	}
}
/**********************************************************************************************************************
 *  END OF FILE: I2C.c
 *********************************************************************************************************************/
