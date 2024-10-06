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
	#include "Application\CC_SCHDLR.h"
	#include "Application\CC_SM.h"
	#include "Application\CC_APP.h"
	#include "Application\CC_LEDPWM.h"

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


//	extern uint8_t CC_APP_BlinkCnts;
//	extern CC_SCHDLR_Scheduler_t CC_SCHDLR_FastScheduler;
//	extern CC_DIPSW_DipSw_t CC_DIPSW_DipSwitch;
//	extern CC_APP_Config_t CC_APP_BoardData;
//	extern uint8_t CC_BOARDLED_BlinkCnts;
//	extern CC_LED_Strip_t CC_LED_hStrip[CC_LED_MAX_STRIPS];		//Vector to manage several strip leds
//	extern uint8_t CC_SERIAL_RxData[1];
//	extern UART_HandleTypeDef huart1;
//	extern FDCAN_TxHeaderTypeDef CC_CAN_TxHeader;		//CAN transmit header
//	extern FDCAN_RxHeaderTypeDef CC_CAN_RxHeader;		//CAN receiver header
//	extern uint8_t CC_CAN_RxData[CC_CAN_RXDATALENGHT];	//CAN receiving data
//	extern uint8_t CC_CAN_TxData[CC_CAN_TXDATALENGHT]; 	//CAN sending data

	//Function Prototypes
	void CC_ML_SendMessageCAN(void*, void*, void*);
	void CC_ML_UpdateIdSysFromDipSwitch(void*, void*, void*);
	void CC_ML_GetDipSwitch4pos(void*, void*, void*);
	void CC_ML_SendUARTString(const char*, UART_HandleTypeDef*);
	uint32_t CC_ML_GetTimerElapsedCounts(const TIM_HandleTypeDef*);
	uint32_t CC_ML_GetTimerLimitCounts(const TIM_HandleTypeDef*);
	void CC_ML_ClearUARTRxData(void);
	void CC_ML_LedBoardToggle(void);

#endif /* INC_CC_MW_H_ */
