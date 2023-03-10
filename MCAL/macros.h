/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <macros.h>
 *       Created on: Dec 24, 2022
 *      Author: a7medDawoud
 *
 *  Description:  <the header file will use bitwise operators to set,get,clear, and toggle a bit value.
 *       bitno---> bit number
 *       reg ---> register which include the bit>
 *
 *********************************************************************************************************************/
#ifndef MACTOS_H
#define MACTOS_H

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SET_BIT(reg,bitno) reg|=(1<<bitno)
#define GET_BIT(reg,bitno) ((reg>>bitno)&1)
#define CLR_BIT(reg,bitno) reg&=(~(1<<bitno))
#define TOG_BIT(reg,bitno) reg^=(1<<bitno)

#endif /* MACTOS_H */

 /**********************************************************************************************************************
 *  END OF FILE: macros.h
 *********************************************************************************************************************/
