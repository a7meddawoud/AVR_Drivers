/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <LedAndBuzzer.h>
 *       Created on: Dec 28, 2022
 *      Author: a7medDawoud
 *
 *  Description:  <this file include the functions which control LEDs and Buzzer>
 *
 *********************************************************************************************************************/
#ifndef HAL_LEDANDBUZZER_LEDANDBUZZER_H_
#define HAL_LEDANDBUZZER_LEDANDBUZZER_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <util/delay.h>

#include "MCAL/DIO/DIO.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void LedAndBuzzer_vLed0Open();
void LedAndBuzzer_vLed0Close();
void LedAndBuzzer_vLed1Open();
void LedAndBuzzer_vLed1Close();
void LedAndBuzzer_vLed2Open();
void LedAndBuzzer_vLed2Close();
void LedAndBuzzer_vBuzzerOpen();
void LedAndBuzzer_vBuzzerClose();
void LedAndBuzzer_vFlash(u8 Loc_vNumberOfFlashes);

#endif /* HAL_LEDANDBUZZER_LEDANDBUZZER_H_ */
/**********************************************************************************************************************
 *  END OF FILE: LedAndBuzzer.h
 *********************************************************************************************************************/
