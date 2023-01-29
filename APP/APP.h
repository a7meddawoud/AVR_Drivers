/*
 * APP.h
 *
 *  Created on: Dec 25, 2022
 *      Author: a7med
 *      APP files uses the _7Segma.h and PushButtons functions to do specific tasks
 *      this file include prototype of each function
 */
#ifndef APP_H
#define APP_H
#include "HAL/_7Segma/_7Segma.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include "HAL/ledAndBuzzer/LedAndBuzzer.h"
#include "HAL/LCD/LCD.h"
#include "HAL/PushButtons/PushButtons.h"
#include "MCAL/ADC/ADC.h"
void APP_vPrintNumberSS(u8 loc_u8SegmaPrintNumber1, u8 loc_u8SegmaPrintNumber2);
void APP_vPrintTwoDigitNumberSS(u8 loc_u8SegmaPrintNumber);
void APP_vPrintDecimalNumberSS(f32 loc_f32SegmaDecimalNumber);
void APP_vPrint0to99SS();
void APP_vPrint1MinuteSS();
void APP_vClickCounterPB();
void APP_v3Leds1MinuteEachSS();
void APP_vTaskFinsh();
void APP_vToString(u8 str[], u16 num);
void APP_vCalculatorLCD();
void APP_vWriteStringManyTimesLCD(u8 *Loc_u8Array,u8 Loc_u8size);
u8 APP_u8compareArray(u8 *ptr1,u8 *ptr2,u8 size);
void APP_vLocker(u8 *Loc_CorrectUserName,u8 *Loc_CorrectPassword);
void APP_vVolumeLCD();
void APP_vVolumeVerticalLCD();
#endif //APP_H
