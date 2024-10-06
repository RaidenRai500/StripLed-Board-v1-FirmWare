/*
 * CC_APP.h
 *
 *  Created on: Sep 23, 2024
 *      Author: Admin
 */

#ifndef INC_APPLICATION_CC_APP_H_
	#define INC_APPLICATION_CC_APP_H_
	//Headers
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers

	//Constants
	#define CC_APP_LED_INDICATOR_OK_CNTS_BT1MS 	100			//Counts to get a blinking of 1s with a base time of 10ms. OK state
	#define CC_APP_LED_INDICATOR_KO_CNTS_BT1MS 	50			//Counts to get a blinking of 0.5s with a base time of 10ms. KO state
	#define CC_APP_LED_INDICATOR_OK_CNTS_BT10MS	10			//Counts to get a blinking of 1s with a base time of 100ms. OK state
	#define CC_APP_LED_INDICATOR_KO_CNTS_BT10MS	5			//Counts to get a blinking of 0.5s with a base time of 100ms. KO state
	#define CC_APP_BOARDHWCODE 		"PR023G.HW.B00_01" 		//Hardware identifier of the board
	#define CC_APP_FWVER			"CLAP CLAP IND V0.0"	//Software version of the code
	#define CC_APP_SUMMARY			"Soft PWM control of 10 led-strips. No OS"
	#define CC_APP_MICROCONTROLLER 	"STM32G0B1CBT6"

	//Data types
	struct CC_APP_Config_t
	{
		char HwCode[sizeof(CC_APP_BOARDHWCODE)];		//Sizeof returns the length of the string including the null terminator
		char SwVer[sizeof(CC_APP_FWVER)];
		char Summary[sizeof(CC_APP_SUMMARY)];
		char uC[sizeof(CC_APP_MICROCONTROLLER)];
		uint8_t id;
	};
	typedef struct CC_APP_Config_t CC_APP_Config_t;

	//Variables Prototypes
	extern uint8_t CC_APP_BlinkCnts;			//Variable to set the board's led blinking frequency
	extern CC_APP_Config_t CC_APP_BoardData;	//Handler with the board's data

	//Function Prototypes
	void CC_APP_BoardLedBlinking(void*, void*, void*);
	void CC_APP_Nop(void*, void*, void*);
	void CC_APP_SetBoardParam(CC_APP_Config_t*);

#endif /* INC_APPLICATION_CC_APP_H_ */
