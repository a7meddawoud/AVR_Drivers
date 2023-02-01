/*
 * I2C.h
 *
 *  Created on: Jan 29, 2023
 *      Author: a7med
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_

#include "../EXTI/EXTI.h"
#include "Config_I2C.h"

#define I2CPolling 0
#define I2CInterrupt 1
#define TWIE 0
#define TWEN 2

#define TWI_vect __vector_19

void I2C_vInit();
void I2C_vSendStart();
void I2C_vRepeatedSendStart();
void I2C_vSendStop();
void I2C_vSendSlaveAdress(u8 Loc_SlaveAdress);
void I2C_SendData(u8 Loc_Data);
void I2C_vReadData(u8* ptr);

#endif /* MCAL_I2C_I2C_H_ */
