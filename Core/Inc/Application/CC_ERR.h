/*
 * CC_ERR.h
 *
 *  Created on: Oct 8, 2024
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

#ifndef INC_APPLICATION_CC_ERR_H_
	#define INC_APPLICATION_CC_ERR_H_

	//HEADERS
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Handlers defined here

	//CONSTANTS
	#define CC_ERR_HIGHSIDE_PWM_BASE_MISS_INT_DIR 	0x010;
	#define CC_ERR_HIGHSIDE_SCHEDULER_MISS_INT_DIR 	0x011;
	#define CC_ERR_HIGHSIDE_CRITIC_PWM_MISS_INT 	0x012;
	#define CC_ERR_HIGHSIDE_CRITIC_SCHED_MISS_INT	0x013;
	#define CC_ERR_LOWSIDE_WATCHDOG_TRIGGERS_DIR	0x014;
	#define CC_ERR_LOWSIDE_CRITIC_WATCHDOG_TRIG_DIR	0x015;
	#define C_ERR_ERROR_BITMAP_DIR					0x016

	//DATA TYPES
	struct CC_ERR_HighAbstractSideErr_t
	{
		uint32_t SchedulerMissInt;
		uint32_t PwmBaseMissInt;
		uint8_t CriticShedulerMissInt;
		uint8_t CriticPwmBaseMissInt;
	};
	typedef struct CC_ERR_HighAbstractSideErr_t CC_ERR_HighAbstractSideErr_t;

	union CC_ERR_ErrorBitmap_prev
	{
		uint8_t CriticWatchdogTriggers:	1;
		uint8_t CanGetMsgError:			1;
		uint8_t CanAddMsg2TxFifoError:	1;
		uint8_t CanStartError:			1;
		uint8_t CanActivNotification:	1;
		uint8_t UartRxError:			1;
		uint8_t UartTxError:			1;
		uint8_t UartRxIntError:			1;
		uint8_t TimerInitError:			1;
		uint8_t TimerBaseStartIntError:	1;
		uint8_t TimerBaseStartError:	1;
		uint8_t	InrWatchDogRefreshErr:	1;
	};
	typedef union CC_ERR_ErrorBitmap_prev CC_ERR_ErrorBitmap_prev;

	union CC_ERR_ErrorBitmap_t
	{
		CC_ERR_ErrorBitmap_prev bits;
		uint32_t all;
	};
	typedef union CC_ERR_ErrorBitmap_t CC_ERR_ErrorBitmap_t;

	struct CC_ERR_LowAbstractSideErr_t
	{
		uint32_t WatchdogTriggersCount;
		uint8_t CriticWatchdogTriggers;

	};
	typedef struct CC_ERR_LowAbstractSideErr_t CC_ERR_LowAbstractSideErr_t;

	struct CC_ERR_ErrorsData_t
	{
		CC_ERR_HighAbstractSideErr_t HighSide;
		CC_ERR_LowAbstractSideErr_t LowSide;
		CC_ERR_ErrorBitmap_t BitMap;
	};
	typedef struct CC_ERR_ErrorsData_t CC_ERR_ErrorsData_t;

	//VARIABLES PROTOTYPES
	extern CC_ERR_ErrorsData_t CC_ERR_ErrorControl;

	//FUNCTIONS PROTOTYPES

#endif /* INC_APPLICATION_CC_ERR_H_ */















