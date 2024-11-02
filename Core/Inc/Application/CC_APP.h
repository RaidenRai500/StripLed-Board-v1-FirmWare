/*
 * CC_APP.h
 *
 *  Created on: Sep 23, 2024
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

#ifndef INC_APPLICATION_CC_APP_H_
	#define INC_APPLICATION_CC_APP_H_
	//HEADERS
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers

	//CONSTANTS
	#define CC_APP_LED_BOARD_FREQ_DEFAULT 10				//Counts to get a blinking of 1s (1s On - 1s Off) with a base time of 100ms. Default state.
	#define CC_APP_BOARDHWCODE 		"PR023G.HW.B00_01" 		//Hardware identifier of the board
	#define CC_APP_FWVER			"CLAP CLAP IND V0.0"	//Software version of the code
	#define CC_APP_SUMMARY			"Soft PWM control of 10 led-strips. No OS"
	#define CC_APP_MICROCONTROLLER 	"STM32G0B1CBT6"

	//DATA TYPES
	struct CC_APP_Config_t
	{
		char HwCode[sizeof(CC_APP_BOARDHWCODE)];		//Sizeof returns the length of the string including the null terminator
		char SwVer[sizeof(CC_APP_FWVER)];
		char Summary[sizeof(CC_APP_SUMMARY)];
		char uC[sizeof(CC_APP_MICROCONTROLLER)];
		uint8_t id;
	};
	typedef struct CC_APP_Config_t CC_APP_Config_t;

	//VARIABLES PROTOTYPES
	extern uint8_t CC_APP_BlinkCnts;			//Variable to set the board's led blinking frequency
	extern CC_APP_Config_t CC_APP_BoardData;	//Handler with the board's data

	//FUNCTIONS PROTOTYPES
	void CC_APP_BoardLedBlinking(void*, void*, void*);
	void CC_APP_Nop(void*, void*, void*);
	void CC_APP_SetBoardParam(CC_APP_Config_t*);

#endif /* INC_APPLICATION_CC_APP_H_ */
