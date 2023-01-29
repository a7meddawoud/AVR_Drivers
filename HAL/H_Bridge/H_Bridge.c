/*
 * H_Bridge.c
 *
 *  Created on: Jan 18, 2023
 *      Author: a7med
 */
#include "H_Bridge.h"
void H_Bridge_vInit(){
	//----------- on this part motor1 is connected to 3y and VCC and motor2 is connected to 4y and Ground
	SET_BIT(DDRD,5);	//---- EN1
	SET_BIT(DDRC,5);	//--- 3A
	SET_BIT(DDRC,6);	//--- 4A
	//------- on this part the two motors are connected to 1Y and 2Y
	SET_BIT(DDRD,4);	//--- EN2
	SET_BIT(DDRC,3);	//--- 1A
	SET_BIT(DDRC,4);	//--- 2A
}
/* ---- Following 3 Functions if for ConnectionsToGroundAndVoltage ----*/
void H_Bridge_vRunM1AndStopM2(){
	SET_BIT(PORTD,5);	//---EN1 High
	CLR_BIT(PORTC,5);	//---3A Low
	CLR_BIT(PORTC,6);	//---4A Low
}
void H_Bridge_vRunM2AndStopM1(){
	SET_BIT(PORTD,5);	//---EN1 High
	SET_BIT(PORTC,5);	//---3A High
	SET_BIT(PORTC,6);	//---4A High
}
void H_Bridge_vM1AndM2FreeRuningStop(){
	CLR_BIT(PORTD,5);	//---EN1 Low
}
/* ---- Following Functions if for BidirectionalDCMotorControl ----*/
void H_Bridge_vM1AndM2TurnRight(){
	SET_BIT(PORTD,4);	//--- EN2 High
	CLR_BIT(PORTC,3);	//--- 1A Low
	SET_BIT(PORTC,4);	//--- 2A High
}
void H_Bridge_vM1AndM2TurnLeft(){
	SET_BIT(PORTD,4);	//--- EN2 High
	SET_BIT(PORTC,3);	//--- 1A High
	CLR_BIT(PORTC,4);	//--- 2A Low
}
void H_Bridge_vM1AndM2FastStop(){
	CLR_BIT(PORTD,4);	//--- EN2 Low
}
