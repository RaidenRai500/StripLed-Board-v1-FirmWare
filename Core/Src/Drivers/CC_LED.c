/*
 * CCLED.c
 *
 *  Created on: Sep 7, 2024
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
#include "Drivers\CC_LED.h"

//GLOBAL VARIABLES DECLARATION

//FUNCTIONS
//Strip1
inline void CC_LED_TurnOnRedOnStrip1(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip1(void)
{
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip1(void)
{
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip1(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip1(void)
{
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip1(void)
{
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
}
//Strip2
inline void CC_LED_TurnOnRedOnStrip2(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip2(void)
{
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip2(void)
{
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip2(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip2(void)
{
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip2(void)
{
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}
//Strip3
inline void CC_LED_TurnOnRedOnStrip3(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip3(void)
{
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip3(void)
{
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip3(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip3(void)
{
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip3(void)
{
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_RESET);
}
//Strip4
inline void CC_LED_TurnOnRedOnStrip4(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip4(void)
{
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip4(void)
{
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip4(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip4(void)
{
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip4(void)
{
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_RESET);
}
//Strip5
inline void CC_LED_TurnOnRedOnStrip5(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip5(void)
{
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip5(void)
{
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip5(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip5(void)
{
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip5(void)
{
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_RESET);
}
//Strip6
inline void CC_LED_TurnOnRedOnStrip6(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip6(void)
{
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip6(void)
{
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip6(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip6(void)
{
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip6(void)
{
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_RESET);
}
//Strip7
inline void CC_LED_TurnOnRedOnStrip7(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip7(void)
{
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip7(void)
{
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip7(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip7(void)
{
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip7(void)
{
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_RESET);
}
//Strip8
inline void CC_LED_TurnOnRedOnStrip8(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip8(void)
{
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip8(void)
{
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip8(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip8(void)
{
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip8(void)
{
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_RESET);
}
//Strip9
inline void CC_LED_TurnOnRedOnStrip9(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip9(void)
{
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip9(void)
{
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip9(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip9(void)
{
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip9(void)
{
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_RESET);
}
//Strip10
inline void CC_LED_TurnOnRedOnStrip10(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip10(void)
{
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip10(void)
{
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip10(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip10(void)
{
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip10(void)
{
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_RESET);
}

