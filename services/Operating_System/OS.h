/*
 * OS.h
 *
 *  Created on: Feb 10, 2023
 *      Author: a7med
 */

#ifndef MIDDLEWARE_OPERATING_SYSTEM_OS_H_
#define MIDDLEWARE_OPERATING_SYSTEM_OS_H_

#include "../../MCAL/Timer1/Timer1.h"

typedef struct task{
	void(*ptr)();
	u32 preucuty;
}tasks;

void OS_vInit();
void OS_AddTask(u8 Loc_preuorty,u32 Loc_preucuty, void(*ptrr)(void));
void OS_Scheduler();
void OS_StartScheduler();
#endif /* MIDDLEWARE_OPERATING_SYSTEM_OS_H_ */
