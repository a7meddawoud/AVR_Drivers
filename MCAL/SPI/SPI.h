/*
 * SPI.h
 *
 *  Created on: Jan 27, 2023
 *      Author: a7med
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../EXTI/EXTI.h"
#include "Config_SPI.h"

#define SPI_STC_vect __vector_12

#define SPIPrescaler4 0x00
#define SPIPrescaler16 0x01
#define SPIPrescaler64 0x02
#define SPIPrescaler128 0x03
#define SPIPrescaler2 0x04
#define SPIPrescaler8 0x05
#define SPIPrescaler32 0x06
#define SPIPrescaler264 0x07

#define SPIPolling 0
#define SPIInterrupt 1

#define SPISlave 0
#define SPIMaster 1
void SPI_vInit();
void SPI_vMasterWrite(u8 Loc_WriteData);
void SPI_vMasterReadWrite(u8 Loc_WriteData,u8 *Loc_ReadData);
void SPI_vSlaveRead(u8 *Loc_ReadData);
#endif /* MCAL_SPI_SPI_H_ */
