/*
 * CC_LEDPWM.h
 *
 *  Created on: Sep 26, 2024
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

#ifndef INC_APPLICATION_CC_LEDPWM_H_
	#define INC_APPLICATION_CC_LEDPWM_H_
	//HEADERS
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers

	//CONSTANTS
	#define CC_LEDPWM_SOFTPWMBASECOUNTS 100						//Equivalent counts for the soft PWM
	#define CC_LEDPWM_INITDUTY 0								//Duty cycle by default
	#define CC_LEDPWM_TOTALSTRIPS 10							//Number of led strips
//	const uint8_t CC_LEDPWM_TotalStrips=CC_LEDPWM_TOTALSTRIPS;	//Number of led strips

	//DATA TYPES
	struct CC_LEDPWM_Strip_t
	{
		uint8_t RedDuty;		//Duty cycle for the red led. Value from 0 to 100
		uint8_t GreenDuty;		//Same for green led
		uint8_t BlueDuty;		//Same for blue led
		uint32_t RedCounts;		//Equivalent counts according duty for the red led
		uint32_t GreenCounts;
		uint32_t BlueCounts;
	};
	typedef struct CC_LEDPWM_Strip_t CC_LEDPWM_Strip_t;

	struct CC_LEDPWM_SoftPwmControl_t
	{
		uint32_t Counter;			//Counts ongoing
		uint32_t BaseCounts;		//Total counts equivalent to 100% duty
	};
	typedef struct CC_LEDPWM_SoftPwmControl_t CC_LEDPWM_SoftPwmControl_t;

	struct CC_LEDPWM_SoftPwm_t
	{
		CC_LEDPWM_Strip_t Strip[CC_LEDPWM_TOTALSTRIPS];
		CC_LEDPWM_SoftPwmControl_t Control;
	};
	typedef struct CC_LEDPWM_SoftPwm_t CC_LEDPWM_SoftPwm_t;

	struct CC_LED_StripLedFuncts_t
		{
		void(*pRedLedOnFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pRedLedOffFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pGreenLedOnFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pGreenLedOffFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pBlueLedOnFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pBlueLedOffFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		};
	typedef struct CC_LED_StripLedFuncts_t CC_LED_StripLedFuncts_t;

	//VARIABLES PROTOTYPES
	extern CC_LEDPWM_SoftPwm_t  CC_LEDPWM_Strip;
	extern const uint8_t CC_LEDPWM_TotalStrips;

	//FUNCTIONS PROTOTYPES
	void CC_LEDPWM_Init(CC_LEDPWM_SoftPwm_t*);
	void CC_LEDPWM_IncreaseCntr(void*, void*, void*);
	void CC_LEDPWM_UpdatePwms(void*, void*, void*);
	void CC_LEDPWM_CntrCalculus(void*, void*, void*);

#endif /* INC_APPLICATION_CC_LEDPWM_H_ */
