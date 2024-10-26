/*
 * CC_TMR.h
 *
 *  Created on: Sep 22, 2024
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

#ifndef INC_CC_TMR_H_
	#define INC_CC_TMR_H_
	//HEADERS
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Pinout mapping definitions

	//CONSTANTS

	//DATA TYPES

	//VARIABLES PROTOTYPES

	//FUNCTIONS PROTOTYPES
	uint8_t CC_TMR_CheckTimIntFlag(const TIM_HandleTypeDef*);
	uint32_t CC_TMR_GetElapsedCounts(const TIM_HandleTypeDef*);
	uint32_t CC_TMR_GetLimitCounts(const TIM_HandleTypeDef*);
	uint8_t CC_TMR_TimerInit(TIM_HandleTypeDef*);
	uint8_t CC_TMR_TimerStartAndInterruptsGen(TIM_HandleTypeDef*);
	uint8_t CC_TMR_StartTimer(TIM_HandleTypeDef*);
	uint8_t CC_TMR_StopTimer(TIM_HandleTypeDef*);
	void CC_TMR_SetTimer(TIM_HandleTypeDef*, uint32_t);

#endif /* INC_CC_TMR_H_ */
