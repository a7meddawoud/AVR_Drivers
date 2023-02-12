/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  OS.c
 *        \brief  a very Simple Operating System
 *
 *      \details  this file can be used to run more than one Task at the Same Time tasks don't include super loop
 *
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "OS.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
tasks a[NumOfTasks];
volatile u32 OS_Counter=0;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void OS_vInit()
* \Description     : initialize the Timer1 parameters so it can be used here
*
* \Sync\Async      : Synchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void OS_vInit(){
	Timer1_vInit();
	EXTI_vEnableGIE();
	Timer1_vCompareChannelAInterruptEnable();
}
/******************************************************************************
* \Syntax          : void OS_AddTask(u8 Loc_preuorty,u32 Loc_preucuty, void(*ptrr)(void))
* \Description     : add Task to the operating System
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : Loc_priority	determine tasks that will run first
* 					Loc_preucuty	determine after what time function will run again (time is selected in OS_Config)
* 					ptrr	address of the function that will run
* \Parameters (out): None
*******************************************************************************/
void OS_AddTask(u8 Loc_priority,u32 Loc_preucuty, void(*ptrr)(void)){
	a[Loc_priority].preucuty=Loc_preucuty;
	a[Loc_priority].ptr=ptrr;
}
/******************************************************************************
* \Syntax          : void OS_Scheduler()
* \Description     : Run the tasks with according to priorities
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void OS_Scheduler(){
	u8 i=0;
	OS_Counter++;
	for(i=0;i<NumOfTasks;i++){

		if((OS_Counter % a[i].preucuty)==0){

			a[i].ptr();
		}
	}
}
/******************************************************************************
* \Syntax          : void OS_Scheduler()
* \Description     : Start the operating System
*
* \Sync\Async      : Asynchronous
* \Parameters (in) : None
* \Parameters (out): None
*******************************************************************************/
void OS_StartScheduler(){
	u16 xx=((u32)Time_ms*SystemFrequancy_Khz)/T1Prescaler;
	Timer1_vChannelACopmareRegister(xx);
	Timer1_vChannelACompareCallBack(OS_Scheduler);
}
/**********************************************************************************************************************
 *  END OF FILE: OS.c
 *********************************************************************************************************************/
