/*
 * CC_MW.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */
//Middleware connecting the drivers and the application layer
#ifndef INC_CC_MW_H_
	#define INC_CC_MW_H_
	//Headers
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
	//Hide side headers
	#include "Application\CC_APP.h"
	#include "Application\CC_LEDPWM.h"
	#include "Application\CC_SCHDLR.h"
	#include "Application\CC_SM.h"

	//Exported variables prototypes
	extern FDCAN_HandleTypeDef hfdcan2;
	extern TIM_HandleTypeDef htim14;
	extern UART_HandleTypeDef huart1;
	extern TIM_HandleTypeDef htim6;
	extern TIM_HandleTypeDef htim7;

	//Constants
	//Scheduler
	#define CC_ML_SCHEDULER_BASETIME_HANDLER htim14
	#define CC_ML_SCHEDULER_CHRONO_HANDLER htim6
	//SoftPWM
	#define CC_ML_PWM_GEN_BASETIME htim7
	//Serial Debug Comms
	#define CC_ML_SERIAL_DEBUG_HANDLER huart1
	//CAN Comms
	#define CC_ML_PERIPHERALS_CAN hfdcan2

	//Data types

	//Variables Prototypes
	extern FDCAN_HandleTypeDef hfdcan2;
	extern uint8_t CC_SERIAL_RxData[];
	extern const uint8_t* const pCC_ML_SERIAL_DEBUG_RxData;
//	extern const CC_LED_StripLedFuncts_t CC_ML_LedsStripsFunctions;

	//Function Prototypes
	void CC_ML_SoftPwmBasetimeandIntrrptsInit(void);
	uint32_t CC_ML_GetTimerElapsedCounts(const TIM_HandleTypeDef*);
	uint32_t CC_ML_GetTimerLimitCounts(const TIM_HandleTypeDef*);
	void CC_ML_StartTimer(TIM_HandleTypeDef*);
	void CC_ML_StopTimer(TIM_HandleTypeDef*);
	void CC_ML_SetTimer(TIM_HandleTypeDef*, uint32_t);
	void CC_ML_SchedulerInit(void);
	void CC_ML_InitCAN(void);
	void CC_ML_StartCAN(void);
	void CC_ML_EnableCANInt(void);
	void CC_ML_SendMessageCAN(void*, void*, void*);
	void CC_ML_SetCanRxAdress(void*, void*, void*);
	void CC_ML_GetDipSwitch4pos(void*, void*, void*);
	void CC_ML_UpdateIdSysFromDipSwitch(void*, void*, void*);
	void CC_ML_EnableRxIntUART(void);
	void CC_ML_SendUARTString(const char*, UART_HandleTypeDef*);
	void CC_ML_ClearUARTRxData(void);
	void CC_ML_LedBoardToggle(void);


#endif /* INC_CC_MW_H_ */
