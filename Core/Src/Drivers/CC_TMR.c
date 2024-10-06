/*
 * CC_TMR.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Admin
 */
//Headers
#include "Drivers\CC_TMR.h"

//Global Variables Declaration

//Functions
uint8_t CC_TMR_CheckTimIntFlag(const TIM_HandleTypeDef* const htim)
{
	if (__HAL_TIM_GET_FLAG(htim, TIM_FLAG_UPDATE))	//Check if another interrupt event has happened
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

uint32_t CC_TMR_GetElapsedCounts(const TIM_HandleTypeDef* const htim)
{
	return __HAL_TIM_GET_COUNTER(htim);
}

uint32_t CC_TMR_GetLimitCounts(const TIM_HandleTypeDef* const htim)
{
	return __HAL_TIM_GET_AUTORELOAD(htim);
}
