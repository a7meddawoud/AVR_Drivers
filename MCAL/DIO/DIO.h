/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <DIO.c>
 *       Created on: Dec 24, 2022
 *      Author: a7medDawoud
 *
 *  Description:  <this file is used to set value and direction to a whole register or a Bit.
 *      this file include the redefine of each used word so functions can be used easily.
 *      and also include the prototype of all functions in DIO.c each function is explained in DIO.c>
 *
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <util/delay.h>

#include "../macros.h"
#include "../MCU.h"
#include "../types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PortA 0
#define PortB 1
#define PortC 2
#define PortD 3
#define Port_OutPut 255
#define Port_InPut 0
#define Port_High 255
#define Port_Low 0
#define Pin_OutPut 1
#define Pin_InPut 0
#define Pin_High 1
#define Pin_Low 0
#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void DIO_vSetPortDirection(u8 Loc_u8PortID, u8 Loc_u8PortDirection);
void DIO_vSetPortValue(u8 Loc_u8PortID, u8 Loc_u8PortValue);
u8 DIO_u8PGetPortValue(u8 Loc_u8PortID);
void DIO_vTogPortValue(u8 Loc_u8PortID);
void DIO_vSetPinDirection(u8 Loc_u8PortID, u8 Loc_u8PinID, u8 Loc_u8PinDirection);
void DIO_vSetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID, u8 Loc_u8PinValue);
u8 DIO_u8PGetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID);
void DIO_vTogPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID);

#endif //DIO_H
/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
