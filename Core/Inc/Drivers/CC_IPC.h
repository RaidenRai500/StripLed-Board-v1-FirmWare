/*
 * CC_IPC.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Admin
 */
//Header file for the several Inter-Process Communication needs

#ifndef INC_CC_IPC_H_
	#define INC_CC_IPC_H_
	//Headers
	#include "main.h"
	#include "stm32g0xx_it.h"
		//Low side headers
//	#include "Drivers\CC_BOARDLED.h"
	#include "Drivers\CC_CAN.h"
	#include "Drivers\CC_DIPSW.h"
//	#include "Drivers\CC_LED.h"
//	#include "Drivers\CC_SERIAL.h"
//	#include "Drivers\CC_TMR.h"

	//Constants

	//Data types

	//Variables Prototypes

	//Function Prototypes
	void CC_IPC_SetCANRxIdFromDipSwitch(const CC_DIPSW_DipSw_t*, uint32_t*);

#endif /* INC_CC_IPC_H_ */
