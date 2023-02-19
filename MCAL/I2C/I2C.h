/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <I2C.h>
 *      Created on: Jan 29, 2023
 *      Author: a7meddawoud
 *
 *  Description:  <I2C Communication protocol functions PROTOTYPES and macros>
 *
 *********************************************************************************************************************/
#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../EXTI/EXTI.h"
#include "Config_I2C.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define I2CPolling 0
#define I2CInterrupt 1
#define I2CMaster 0
#define I2CSlave 1
#define I2CSendACK 0
#define I2CNoACK 1

#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

#define TWD0 0

#define TWI_vect __vector_19
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum I2CStat{
	E_OK,
	E_NOT_OK

}I2C_Status;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void I2C_vInit();
I2C_Status I2C_vSendStart();
I2C_Status I2C_vRepeatedSendStart();
I2C_Status I2C_vSendStop();
I2C_Status I2C_vSendSlaveAdressWithRead(u8 Loc_SlaveAddress);
I2C_Status I2C_vSendSlaveAdressWithWrite(u8 Loc_SlaveAddress);
I2C_Status I2C_SendData(u8 Loc_Data);
I2C_Status I2C_vMasterReadData(u8* ptr);
I2C_Status I2C_MatchAddress();
I2C_Status I2C_vSlaveReadData(u8* ptr);
void I2C_vJobFinishedInterruptEnable(void(*ptr)(void));

#endif /* MCAL_I2C_I2C_H_ */
/**********************************************************************************************************************
 *  END OF FILE: I2C.h
 *********************************************************************************************************************/
