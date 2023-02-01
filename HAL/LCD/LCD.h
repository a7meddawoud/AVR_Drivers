/*
 * LCD.h
 *
 *  Created on: Dec 30, 2022
 *      Author: a7med
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../MCAL/DIO/DIO.h"
#define LineOne 0x80
#define LineTwo 0xC0
#define FunctionSet 0b00101000
#define DisplayOnControl 0b00001110
#define DisplayClear 0x01
#define EnrtyMode 0b00000110


void LCD_vSendCommand(u8 Loc_u8Command);
void LCD_vInit();
void LCD_vWriteCharacter(u8 Loc_u8Character);
void LCD_vWriteString(u8 *ptr);
void LCD_vClear();
void LCD_vGoTo(u8 Loc_u8Line, u8 Loc_u8CharPos);
void LCD_vInitWithOutClear();
void LCD_vCustomCharacter(u8 *ptr,u8 Location);
#endif /* HAL_LCD_LCD_H_ */
