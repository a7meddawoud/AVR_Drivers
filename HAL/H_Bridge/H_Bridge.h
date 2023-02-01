/*
 * H_Bridge.h
 *
 *  Created on: Jan 18, 2023
 *      Author: a7med
 */

#ifndef HAL_H_BRIDGE_H_BRIDGE_H_
#define HAL_H_BRIDGE_H_BRIDGE_H_
#include "../../MCAL/DIO/DIO.h"
#define ConnectionsToGroundAndVoltage 0
#define BidirectionalDCMotorControl 1

void H_Bridge_vInit();
void H_Bridge_vRunM1AndStopM2();
void H_Bridge_vRunM2AndStopM1();
void H_Bridge_vM1AndM2FreeRuningStop();
void H_Bridge_vM1AndM2TurnRight();
void H_Bridge_vM1AndM2TurnLeft();
void H_Bridge_vM1AndM2FastStop();
#endif /* HAL_H_BRIDGE_H_BRIDGE_H_ */
