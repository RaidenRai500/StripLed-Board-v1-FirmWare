/*
 * CC_IPC.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Admin
 */
//Inter-Process Communication file. All functions and procedures to share
//information between inner processes
//Headers
#include "Drivers\CC_IPC.h"

//Global Variables Declaration

//Functions

void CC_IPC_SetCANRxIdFromDipSwitch	(
									const CC_DIPSW_DipSw_t* const pDipSwData,
									uint32_t* const pCanRxId
									)
{
	*pCanRxId=(uint32_t)pDipSwData->all;
}
