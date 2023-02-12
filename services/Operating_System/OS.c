/*
 * OS.c
 *
 *  Created on: Feb 10, 2023
 *      Author: a7med
 */
#include "OS.h"

tasks a[3];
volatile u32 OS_Counter=0;
void OS_vInit(){
	Timer1_vInit();
	EXTI_vEnableGIE();
	Timer1_vCompareChannelAInterruptEnable();
}
void OS_AddTask(u8 Loc_preuorty,u32 Loc_preucuty, void(*ptrr)(void)){
	a[Loc_preuorty].preucuty=Loc_preucuty;
	a[Loc_preuorty].ptr=ptrr;
}
void OS_Scheduler(){
	u8 i=0;
	OS_Counter++;
	for(i=0;i<3;i++){

		if((OS_Counter % a[i].preucuty)==0){

			a[i].ptr();
		}
	}
}
void OS_StartScheduler(){
	Timer1_vChannelACopmareRegister(62500);
	Timer1_vChannelACompareCallBack(OS_Scheduler);
}
