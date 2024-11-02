/*
 * CC_DIPSW.c
 *
 *  Created on: Sep 8, 2024
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
#include "Drivers\CC_DIPSW.h"

//GLOBAL VARIABLES DECLARATION
CC_DIPSW_DipSw_t CC_DIPSW_DipSwitch;				//Header with the DIP Switch data

//FUNCTIONS
#ifdef DIP_SW1_Pin
	void CC_DIPSW_GetDipSwitch1pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
	}
#endif
#ifdef DIP_SW2_Pin
	void CC_DIPSW_GetDipSwitch2pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
	}
#endif
#ifdef DIP_SW3_Pin
	void CC_DIPSW_GetDipSwitch3pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pData->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
	}
#endif
#ifdef DIP_SW4_Pin
	void CC_DIPSW_GetDipSwitch4pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pData->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pData->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
	}
#endif
#ifdef DIP_SW5_Pin
	void CC_DIPSW_GetDipSwitch5pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pData->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pData->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pData->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
	}
#endif
#ifdef DIP_SW6_Pin
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pData->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pData->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pData->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
		pData->bits.bit5=HAL_GPIO_ReadPin(DIP_SW6_GPIO_Port, DIP_SW6_Pin);
	}
#endif
#ifdef DIP_SW7_Pin
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pData->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pData->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pData->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
		pData->bits.bit5=HAL_GPIO_ReadPin(DIP_SW6_GPIO_Port, DIP_SW6_Pin);
		pData->bits.bit6=HAL_GPIO_ReadPin(DIP_SW7_GPIO_Port, DIP_SW7_Pin);
	}
#endif
#ifdef DIP_SW8_Pin
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* const pData)
	{
		pData->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pData->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pData->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pData->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pData->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
		pData->bits.bit5=HAL_GPIO_ReadPin(DIP_SW6_GPIO_Port, DIP_SW6_Pin);
		pData->bits.bit6=HAL_GPIO_ReadPin(DIP_SW7_GPIO_Port, DIP_SW7_Pin);
		pData->bits.bit7=HAL_GPIO_ReadPin(DIP_SW8_GPIO_Port, DIP_SW8_Pin);
	}
#endif
