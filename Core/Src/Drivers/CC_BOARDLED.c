/*
 * CC_BOARDLED.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Xavier Alsina
 *
Disclaimer:
This project, including all associated documentation and code, is provided "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, or non-infringement.

In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

The code and documentation generated as part of this project are released under the following terms:
1.	Use and Distribution: You are free to use, modify, and distribute the code and documentation in any medium, provided that proper attribution to the original authors is given.
2.	Non-Commercial Use: This project may be used for personal, educational, or non-commercial purposes. If you intend to use any part of this project to generate revenue or for commercial purposes, explicit written permission from the author is required.
3.	No Warranty: The authors make no guarantees about the correctness, reliability, or stability of the code. It is your responsibility to test and verify that the code functions as required in your environment.
4.	Liability: Under no circumstances shall the authors or contributors be held liable for any direct, indirect, incidental, special, or consequential damages arising out of the use of the code or documentation.
5.	Contribution: Any contributions made to this project, including pull requests, are assumed to be provided under the same license and terms as the original project.
6.	Licensing: This project may be subject to additional licensing terms and conditions, particularly if integrating with third-party libraries or systems. It is the user's responsibility to ensure compliance with any such licenses.
 *
 */
//HEADERS
#include "Drivers\CC_BOARDLED.h"

//GLOBAL VARIABLES DECLARATION

//FUNCTIONS
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
