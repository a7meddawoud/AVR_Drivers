/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file EEPROM.c
 *        \brief  this file used to to send or receive data from an external EEPROM
 *
 *      \details  EEPROM uses I2C Communication protocol so in EEPROM Functions I2C functions will be used
 *      		to sent or receive data according to EEPROM frame.
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "EEPROM.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : EEPROM_INIT()
* \Description     : initialize the I2C registers (used mode in Config_I2C must be selected as I2CMaster)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None

*******************************************************************************/
void EEPROM_INIT(){
	I2C_vInit();
}
/******************************************************************************
* \Syntax          : EEPROM_vWrite(u8 page , u8 add ,u8 data)
* \Description     : used to send data to an address in the EEPROM
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : page	EEPROM Start and page number
* 					 add	address wanted to write data in
* 					 data	data wanted to be written
* \Parameters (out): None
*******************************************************************************/
void EEPROM_vWrite(u8 page , u8 add ,u8 data){
	u8 page_add = (page<<1)+0xA0;
	I2C_vSendStart();
	I2C_vSendSlaveAdressWithWrite(page_add);			/* Start I2C with device write address */
	I2C_SendData(add);					/* Write start memory address for data write */
	I2C_SendData(data);
	_delay_ms(10);
	I2C_vSendStop();					/* Stop I2C */
}
/******************************************************************************
* \Syntax          : EEPROM_vRead(u8 page , u8 add)
* \Description     : used to read data from an address in the EEPROM
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : page	EEPROM Start and page number
* 					 add	address wanted to read data from
* 					 &data	address of variable wanted to store data in
* \Parameters (out): None
*******************************************************************************/
void EEPROM_vRead(u8 page , u8 add,u8* data){
	*data =0;
	u8 page_write_add = (page<<1)+0xA0;
	u8 page_read_add  = page_write_add + 1;
	_delay_ms(10);
	I2C_vSendStart();
	I2C_vSendSlaveAdressWithWrite(page_write_add);							/* Start I2C with device write address */
	I2C_SendData(add);							/* Write start memory address */
	I2C_vRepeatedSendStart();
	I2C_vSendSlaveAdressWithRead(page_read_add);			/* Repeat start I2C SLA+R */
	I2C_vMasterReadData(&data);
	I2C_vSendStop();							/* Stop I2C */
}
