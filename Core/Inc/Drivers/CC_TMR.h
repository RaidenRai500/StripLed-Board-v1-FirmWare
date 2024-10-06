/*
 * CC_TMR.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Admin
 */

#ifndef INC_CC_TMR_H_
	#define INC_CC_TMR_H_
	//Headers
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Pinout mapping definitions

	//Constants

	//Data types

	//Variables Prototypes

	//Function Prototypes
	uint8_t CC_TMR_CheckTimIntFlag(const TIM_HandleTypeDef*);
	uint32_t CC_TMR_GetElapsedCounts(const TIM_HandleTypeDef*);
	uint32_t CC_TMR_GetLimitCounts(const TIM_HandleTypeDef*);
	void CC_TMR_TimerInit(TIM_HandleTypeDef*);
	void CC_TMR_TimerStartAndInterruptsGen(TIM_HandleTypeDef*);
	void CC_TMR_StartTimer(TIM_HandleTypeDef*);
	void CC_TMR_StopTimer(TIM_HandleTypeDef*);
	void CC_TMR_SetTimer(TIM_HandleTypeDef*, uint32_t);

#endif /* INC_CC_TMR_H_ */
