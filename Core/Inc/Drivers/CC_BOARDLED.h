/*
 * CC_BOARDLED.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Admin
 */

#ifndef INC_CC_BOARDLED_H_
	#define INC_CC_BOARDLED_H_
	//Headers
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Pinout mapping definitions

	//Constants
	#define CC_BOARDLED_ON 1
	#define CC_BOARDLED_OFF 0
	//Data types

	//Variables Prototypes

	//Function Prototypes
	void CC_BOARDLED_Led1TurnOn(void);
	void CC_BOARDLED_Led1TurnOff(void);
	void CC_BOARDLED_Led1Toggle(void);


#endif /* INC_CC_BOARDLED_H_ */
