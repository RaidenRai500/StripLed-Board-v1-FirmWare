/*
 * CC_BOARDLED.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Admin
 */
//Headers
#include "Drivers\CC_BOARDLED.h"

//Global Variables Declaration

//Functions
#ifdef LED1_Pin
	inline void CC_BOARDLED_Led1TurnOn(void)
	{
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led1TurnOff(void)
	{
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led1Toggle(void)
	{
		HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	}
#endif

#ifdef LED2_Pin
	inline void CC_BOARDLED_Led2TurnOn(void)
	{
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led2TurnOff(void)
	{
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led2Toggle(void)
	{
		HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
	}
#endif

#ifdef LED3_Pin
	inline void CC_BOARDLED_Led3TurnOn(void)
	{
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led3TurnOff(void)
	{
		HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led3Toggle(void)
	{
		HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
	}
#endif

#ifdef LED4_Pin
	inline void CC_BOARDLED_Led4TurnOn(void)
	{
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led4TurnOff(void)
	{
		HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led4Toggle(void)
	{
		HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
	}
#endif

#ifdef LED5_Pin
	inline void CC_BOARDLED_Led5TurnOn(void)
	{
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led5TurnOff(void)
	{
		HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led5Toggle(void)
	{
		HAL_GPIO_TogglePin(LED5_GPIO_Port, LED5_Pin);
	}
#endif

#ifdef LED6_Pin
	inline void CC_BOARDLED_Led6TurnOn(void)
	{
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led6TurnOff(void)
	{
		HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led6Toggle(void)
	{
		HAL_GPIO_TogglePin(LED6_GPIO_Port, LED6_Pin);
	}
#endif

#ifdef LED7_Pin
	inline void CC_BOARDLED_Led7TurnOn(void)
	{
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led7TurnOff(void)
	{
		HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led7Toggle(void)
	{
		HAL_GPIO_TogglePin(LED7_GPIO_Port, LED7_Pin);
	}
#endif

#ifdef LED8_Pin
	inline void CC_BOARDLED_Led8TurnOn(void)
	{
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led8TurnOff(void)
	{
		HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led8Toggle(void)
	{
		HAL_GPIO_TogglePin(LED8_GPIO_Port, LED8_Pin);
	}
#endif

#ifdef LED9_Pin
	inline void CC_BOARDLED_Led9TurnOn(void)
	{
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, CC_BOARDLED_ON);
	}

	inline void CC_BOARDLED_Led9TurnOff(void)
	{
		HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, CC_BOARDLED_OFF);
	}

	inline void CC_BOARDLED_Led9Toggle(void)
	{
		HAL_GPIO_TogglePin(LED9_GPIO_Port, LED9_Pin);
	}
#endif
