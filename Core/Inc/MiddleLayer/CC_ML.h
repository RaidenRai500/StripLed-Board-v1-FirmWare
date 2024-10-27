/*
 * CC_MW.h
 *
 *  Created on: Sep 21, 2024
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
//Middleware connecting the drivers and the application layer
#ifndef INC_CC_MW_H_
	#define INC_CC_MW_H_
	//HEADERS
	//HAL headers
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Handlers defined here
	//Low side headers
	#include "Drivers\CC_BOARDLED.h"
	#include "Drivers\CC_CAN.h"
	#include "Drivers\CC_DIPSW.h"
	#include "Drivers\CC_LED.h"
	#include "Drivers\CC_SERIAL.h"
	#include "Drivers\CC_TMR.h"
	#include "Drivers\CC_WATCHDOG.h"
	//Hide side headers
	#include "Application\CC_APP.h"
	#include "Application\CC_LEDPWM.h"
	#include "Application\CC_SCHDLR.h"
	#include "Application\CC_SM.h"
	#include "Application\CC_ERR.h"

	//Exported variables prototypes
	extern FDCAN_HandleTypeDef hfdcan2;
	extern TIM_HandleTypeDef htim14;
	extern UART_HandleTypeDef huart1;
	extern TIM_HandleTypeDef htim6;
	extern TIM_HandleTypeDef htim7;
	extern IWDG_HandleTypeDef hiwdg;

	//CONSTANTS
	//Scheduler
	#define CC_ML_SCHEDULER_BASETIME_HANDLER htim14
	#define CC_ML_SCHEDULER_CHRONO_HANDLER htim6
	//SoftPWM
	#define CC_ML_PWM_GEN_BASETIME htim7
	//Serial Debug Comms
	#define CC_ML_SERIAL_DEBUG_HANDLER huart1
	//CAN Comms
	#define CC_ML_PERIPHERALS_CAN hfdcan2
	//WatchDog
	#define CC_WATCHDOG_HANDLER hiwdg	// Inner watchdog handler

	//DATA TYPES

	//VARIABLES PROTOTYPES
	extern uint8_t CC_SERIAL_RxData[];
	extern const uint8_t* const pCC_ML_SERIAL_DEBUG_RxData;			//Pointer to the UART received data
	extern const uint8_t* const pCC_ML_CAN_RxData;					//Pointer to CAN's Rx data. Read only.
	extern FDCAN_TxHeaderTypeDef CC_ML_CAN_TxHeader;				//CAN transmit header
	extern FDCAN_RxHeaderTypeDef CC_ML_CAN_RxHeader;				//CAN receiver header
	extern const CC_LED_StripLedFuncts_t CC_ML_LedsStripsFunctions;	//Pointer to the struct with the loaded soft-PWM functions

	//FUNCTIONS PROTOTYPES
	void CC_ML_StartSoftPwmBasetimeAndInterrupts(void);
	void CC_ML_RefreshWatchdog(void*, void*, void*);
	uint32_t CC_ML_GetTimerElapsedCounts(const TIM_HandleTypeDef*);
	uint32_t CC_ML_GetTimerLimitCounts(const TIM_HandleTypeDef*);
	void CC_ML_StartTimer(TIM_HandleTypeDef*);
	void CC_ML_StopTimer(TIM_HandleTypeDef*);
	void CC_ML_SetTimer(TIM_HandleTypeDef*, uint32_t);
	uint8_t CC_ML_CheckTimIntFlag(const TIM_HandleTypeDef*);
	void CC_ML_StartScheduler(void);
	void CC_ML_InitCan(void);
	void CC_ML_StartCan(void);
	void CC_ML_EnableCanRxInt(void);
	void CC_ML_SendMessageCan(void*, void*, void*);
	void CC_ML_SetCanRxAdress(void*, void*, void*);
	void CC_ML_GetDipSwitch4pos(void*, void*, void*);
	void CC_ML_UpdateSysIdFromDipSwitch(void*, void*, void*);
	void CC_ML_EnableRxIntUart(void);
	void CC_ML_SendUARTChar(const uint8_t*, UART_HandleTypeDef*);
	void CC_ML_SendUARTString(const char*, UART_HandleTypeDef*);
	void CC_ML_ClearUARTRxData(void);
	void CC_ML_LedBoardToggle(void);


#endif /* INC_CC_MW_H_ */
