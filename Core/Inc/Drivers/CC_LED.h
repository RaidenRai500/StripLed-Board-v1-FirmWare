/*
 * CC_LED.h
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

#ifndef INC_CC_LED_H_
	#define INC_CC_LED_H_
	//HEADERS
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Pinout mapping definitions

	//CONSTANTS
	#define CC_LED_MAX_STRIPS 10	//Maximum number of led strips in the system

	//DATA TYPES
	enum CC_LED_Colors_t
		{
		RED = 0,
		GREEN,
		BLUE,
		YELLOW,
		PINK,
		CYAN,
		WHITE,
		BLACK,
		};
	typedef enum CC_LED_Colors_t CC_LED_Colors_t;

	struct CC_LED_Strip_t
		{
		uint8_t number;
		CC_LED_Colors_t color;
		};
	typedef struct CC_LED_Strip_t CC_LED_Strip_t;

	//VARIABLES PROTOTYPES
	extern CC_LED_Strip_t CC_LED_hStrip[CC_LED_MAX_STRIPS];		//Vector to manage several strip leds

	// Function Prototypes
	void CC_LED_InitStrips(void);
	void CC_LED_UpdateStrips(void);
	void CC_LED_SetColorAndStrip(const CC_LED_Strip_t*);
	void CC_LED_SetColorStrip1(const CC_LED_Colors_t);		//Set an entire strip to a given color
	void CC_LED_SetColorStrip2(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip3(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip4(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip5(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip6(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip7(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip8(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip9(const CC_LED_Colors_t);
	void CC_LED_SetColorStrip10(const CC_LED_Colors_t);
	// Strip 1
	void CC_LED_TurnOnStrip1Red(void);
	void CC_LED_TurnOnStrip1Green(void);
	void CC_LED_TurnOnStrip1Blue(void);
	void CC_LED_TurnOnStrip1Yellow(void);
	void CC_LED_TurnOnStrip1Pink(void);
	void CC_LED_TurnOnStrip1Cyan(void);
	void CC_LED_TurnOnStrip1White(void);
	void CC_LED_TurnOffStrip1(void);
	// Strip 2
	void CC_LED_TurnOnStrip2Red(void);
	void CC_LED_TurnOnStrip2Green(void);
	void CC_LED_TurnOnStrip2Blue(void);
	void CC_LED_TurnOnStrip2Yellow(void);
	void CC_LED_TurnOnStrip2Pink(void);
	void CC_LED_TurnOnStrip2Cyan(void);
	void CC_LED_TurnOnStrip2White(void);
	void CC_LED_TurnOffStrip2(void);
	// Strip 3
	void CC_LED_TurnOnStrip3Red(void);
	void CC_LED_TurnOnStrip3Green(void);
	void CC_LED_TurnOnStrip3Blue(void);
	void CC_LED_TurnOnStrip3Yellow(void);
	void CC_LED_TurnOnStrip3Pink(void);
	void CC_LED_TurnOnStrip3Cyan(void);
	void CC_LED_TurnOnStrip3White(void);
	void CC_LED_TurnOffStrip3(void);
	// Strip 4
	void CC_LED_TurnOnStrip4Red(void);
	void CC_LED_TurnOnStrip4Green(void);
	void CC_LED_TurnOnStrip4Blue(void);
	void CC_LED_TurnOnStrip4Yellow(void);
	void CC_LED_TurnOnStrip4Pink(void);
	void CC_LED_TurnOnStrip4Cyan(void);
	void CC_LED_TurnOnStrip4White(void);
	void CC_LED_TurnOffStrip4(void);
	// Strip 5
	void CC_LED_TurnOnStrip5Red(void);
	void CC_LED_TurnOnStrip5Green(void);
	void CC_LED_TurnOnStrip5Blue(void);
	void CC_LED_TurnOnStrip5Yellow(void);
	void CC_LED_TurnOnStrip5Pink(void);
	void CC_LED_TurnOnStrip5Cyan(void);
	void CC_LED_TurnOnStrip5White(void);
	void CC_LED_TurnOffStrip5(void);
	// Strip 6
	void CC_LED_TurnOnStrip6Red(void);
	void CC_LED_TurnOnStrip6Green(void);
	void CC_LED_TurnOnStrip6Blue(void);
	void CC_LED_TurnOnStrip6Yellow(void);
	void CC_LED_TurnOnStrip6Pink(void);
	void CC_LED_TurnOnStrip6Cyan(void);
	void CC_LED_TurnOnStrip6White(void);
	void CC_LED_TurnOffStrip6(void);
	// Strip 7
	void CC_LED_TurnOnStrip7Red(void);
	void CC_LED_TurnOnStrip7Green(void);
	void CC_LED_TurnOnStrip7Blue(void);
	void CC_LED_TurnOnStrip7Yellow(void);
	void CC_LED_TurnOnStrip7Pink(void);
	void CC_LED_TurnOnStrip7Cyan(void);
	void CC_LED_TurnOnStrip7White(void);
	void CC_LED_TurnOffStrip7(void);
	// Strip 8
	void CC_LED_TurnOnStrip8Red(void);
	void CC_LED_TurnOnStrip8Green(void);
	void CC_LED_TurnOnStrip8Blue(void);
	void CC_LED_TurnOnStrip8Yellow(void);
	void CC_LED_TurnOnStrip8Pink(void);
	void CC_LED_TurnOnStrip8Cyan(void);
	void CC_LED_TurnOnStrip8White(void);
	void CC_LED_TurnOffStrip8(void);
	// Strip 9
	void CC_LED_TurnOnStrip9Red(void);
	void CC_LED_TurnOnStrip9Green(void);
	void CC_LED_TurnOnStrip9Blue(void);
	void CC_LED_TurnOnStrip9Yellow(void);
	void CC_LED_TurnOnStrip9Pink(void);
	void CC_LED_TurnOnStrip9Cyan(void);
	void CC_LED_TurnOnStrip9White(void);
	void CC_LED_TurnOffStrip9(void);
	// Strip 10
	void CC_LED_TurnOnStrip10Red(void);
	void CC_LED_TurnOnStrip10Green(void);
	void CC_LED_TurnOnStrip10Blue(void);
	void CC_LED_TurnOnStrip10Yellow(void);
	void CC_LED_TurnOnStrip10Pink(void);
	void CC_LED_TurnOnStrip10Cyan(void);
	void CC_LED_TurnOnStrip10White(void);
	void CC_LED_TurnOffStrip10(void);
	//Single led action
	void CC_LED_TurnOnRedOnStrip1(void);
	void CC_LED_TurnOnGreenOnStrip1(void);
	void CC_LED_TurnOnBlueOnStrip1(void);
	void CC_LED_TurnOnRedOnStrip2(void);
	void CC_LED_TurnOnGreenOnStrip2(void);
	void CC_LED_TurnOnBlueOnStrip2(void);
	void CC_LED_TurnOnRedOnStrip3(void);
	void CC_LED_TurnOnGreenOnStrip3(void);
	void CC_LED_TurnOnBlueOnStrip3(void);
	void CC_LED_TurnOnRedOnStrip4(void);
	void CC_LED_TurnOnGreenOnStrip4(void);
	void CC_LED_TurnOnBlueOnStrip4(void);
	void CC_LED_TurnOnRedOnStrip5(void);
	void CC_LED_TurnOnGreenOnStrip5(void);
	void CC_LED_TurnOnBlueOnStrip5(void);
	void CC_LED_TurnOnRedOnStrip6(void);
	void CC_LED_TurnOnGreenOnStrip6(void);
	void CC_LED_TurnOnBlueOnStrip6(void);
	void CC_LED_TurnOnRedOnStrip7(void);
	void CC_LED_TurnOnGreenOnStrip7(void);
	void CC_LED_TurnOnBlueOnStrip7(void);
	void CC_LED_TurnOnRedOnStrip8(void);
	void CC_LED_TurnOnGreenOnStrip8(void);
	void CC_LED_TurnOnBlueOnStrip8(void);
	void CC_LED_TurnOnRedOnStrip9(void);
	void CC_LED_TurnOnGreenOnStrip9(void);
	void CC_LED_TurnOnBlueOnStrip9(void);
	void CC_LED_TurnOnRedOnStrip10(void);
	void CC_LED_TurnOnGreenOnStrip10(void);
	void CC_LED_TurnOnBlueOnStrip10(void);

	void CC_LED_TurnOffRedOnStrip1(void);
	void CC_LED_TurnOffGreenOnStrip1(void);
	void CC_LED_TurnOffBlueOnStrip1(void);
	void CC_LED_TurnOffRedOnStrip2(void);
	void CC_LED_TurnOffGreenOnStrip2(void);
	void CC_LED_TurnOffBlueOnStrip2(void);
	void CC_LED_TurnOffRedOnStrip3(void);
	void CC_LED_TurnOffGreenOnStrip3(void);
	void CC_LED_TurnOffBlueOnStrip3(void);
	void CC_LED_TurnOffRedOnStrip4(void);
	void CC_LED_TurnOffGreenOnStrip4(void);
	void CC_LED_TurnOffBlueOnStrip4(void);
	void CC_LED_TurnOffRedOnStrip5(void);
	void CC_LED_TurnOffGreenOnStrip5(void);
	void CC_LED_TurnOffBlueOnStrip5(void);
	void CC_LED_TurnOffRedOnStrip6(void);
	void CC_LED_TurnOffGreenOnStrip6(void);
	void CC_LED_TurnOffBlueOnStrip6(void);
	void CC_LED_TurnOffRedOnStrip7(void);
	void CC_LED_TurnOffGreenOnStrip7(void);
	void CC_LED_TurnOffBlueOnStrip7(void);
	void CC_LED_TurnOffRedOnStrip8(void);
	void CC_LED_TurnOffGreenOnStrip8(void);
	void CC_LED_TurnOffBlueOnStrip8(void);
	void CC_LED_TurnOffRedOnStrip9(void);
	void CC_LED_TurnOffGreenOnStrip9(void);
	void CC_LED_TurnOffBlueOnStrip9(void);
	void CC_LED_TurnOffRedOnStrip10(void);
	void CC_LED_TurnOffGreenOnStrip10(void);
	void CC_LED_TurnOffBlueOnStrip10(void);

#endif /* INC_CC_LED_H_ */












