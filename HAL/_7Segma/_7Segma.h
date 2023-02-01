/*
 * _7Segma.h
 *
 *  Created on: Dec 24, 2022
 *      Author: a7medDawoud
 *      the 7sigma used have 2 screens so DIO functions will be used to print on the 7Sigma
 *      this file include the prototype of the functions
 */

#ifndef _7SEGMA_H_
#define _7SEGMA_H_
#include "../../MCAL/DIO/DIO.h"

void _7Segma_vInit();
void _7Segma_vEnable1();
void _7Segma_vEnable2();
void _7Segma_vDisable1();
void _7Segma_vDisable2();
void _7Segma_vEnableDot();
void _7Segma_vDisbleDot();
void _7Segma_vShow(u8 loc_u8SegmaShowNumber);
void _7Segma_vPrintNumber1(u8 loc_u8SegmaPrintNumber);
void _7Segma_vPrintNumber2(u8 loc_u8SegmaPrintNumber);

#endif /* 7SEGMA_H_ */
