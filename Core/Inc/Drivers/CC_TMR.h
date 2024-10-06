/*
 * CC_TMR.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Admin
 */

#ifndef INC_CC_TMR_H_
	#define INC_CC_TMR_H_
	//Headers
	#include "main.h"
	#include "stm32g0xx_it.h"

	//Constants

	//Data types

	//Variables Prototypes

	//Function Prototypes
	uint8_t CC_TMR_CheckTimIntFlag(const TIM_HandleTypeDef*);
	uint32_t CC_TMR_GetElapsedCounts(const TIM_HandleTypeDef*);
	uint32_t CC_TMR_GetLimitCounts(const TIM_HandleTypeDef*);

#endif /* INC_CC_TMR_H_ */
