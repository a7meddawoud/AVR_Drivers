/*
 * SPI.h
 *
 *  Created on: Jan 27, 2023
 *      Author: a7med
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../EXTI/EXTI.h"
#include "MCAL/SPI/Config_SPI.h"

#define SPI_STC_vect __vector_12

#define SPIPolling 0
#define SPIInterrupt 1

#define SPISlave 0
#define SPIMaster 1
void SPI_vInit();
void SPI_vMasterWrite(u8 Loc_WriteData);
void SPI_vMasterReadWrite(u8 Loc_WriteData,u8 *Loc_ReadData);
void SPI_vSlaveRead(u8 *Loc_ReadData);
#endif /* MCAL_SPI_SPI_H_ */
