/*
 * CC_ML.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Admin
 */
/* 	Abstraction layer implemented to decouple main tasks and algorithms from drivers layer */
//Headers
#include "MiddleLayer\CC_ML.h"
#include <string.h>  		//Include for strncpy()
#include <stdlib.h>			//Include for utoa()

//Global Variables Declaration
	//CC_SERIAL
const uint8_t* const pCC_ML_SERIAL_DEBUG_RxData=CC_SERIAL_RxData;		//Pointer to Rx data. Read only
	//CC_LEDS
const CC_LED_StripLedFuncts_t CC_ML_LedsStripsFunctions =
{
	{
		&CC_LED_TurnOnRedOnStrip1,
		&CC_LED_TurnOnRedOnStrip2,
		&CC_LED_TurnOnRedOnStrip3,
		&CC_LED_TurnOnRedOnStrip4,
		&CC_LED_TurnOnRedOnStrip5,
		&CC_LED_TurnOnRedOnStrip6,
		&CC_LED_TurnOnRedOnStrip7,
		&CC_LED_TurnOnRedOnStrip8,
		&CC_LED_TurnOnRedOnStrip9,
		&CC_LED_TurnOnRedOnStrip10
	},
	{
		&CC_LED_TurnOffRedOnStrip1,
		&CC_LED_TurnOffRedOnStrip2,
		&CC_LED_TurnOffRedOnStrip3,
		&CC_LED_TurnOffRedOnStrip4,
		&CC_LED_TurnOffRedOnStrip5,
		&CC_LED_TurnOffRedOnStrip6,
		&CC_LED_TurnOffRedOnStrip7,
		&CC_LED_TurnOffRedOnStrip8,
		&CC_LED_TurnOffRedOnStrip9,
		&CC_LED_TurnOffRedOnStrip10
	},
	{
		&CC_LED_TurnOnGreenOnStrip1,
		&CC_LED_TurnOnGreenOnStrip2,
		&CC_LED_TurnOnGreenOnStrip3,
		&CC_LED_TurnOnGreenOnStrip4,
		&CC_LED_TurnOnGreenOnStrip5,
		&CC_LED_TurnOnGreenOnStrip6,
		&CC_LED_TurnOnGreenOnStrip7,
		&CC_LED_TurnOnGreenOnStrip8,
		&CC_LED_TurnOnGreenOnStrip9,
		&CC_LED_TurnOnGreenOnStrip10
	},
	{
		&CC_LED_TurnOffGreenOnStrip1,
		&CC_LED_TurnOffGreenOnStrip2,
		&CC_LED_TurnOffGreenOnStrip3,
		&CC_LED_TurnOffGreenOnStrip4,
		&CC_LED_TurnOffGreenOnStrip5,
		&CC_LED_TurnOffGreenOnStrip6,
		&CC_LED_TurnOffGreenOnStrip7,
		&CC_LED_TurnOffGreenOnStrip8,
		&CC_LED_TurnOffGreenOnStrip9,
		&CC_LED_TurnOffGreenOnStrip10
	},
	{
		&CC_LED_TurnOnBlueOnStrip1,
		&CC_LED_TurnOnBlueOnStrip2,
		&CC_LED_TurnOnBlueOnStrip3,
		&CC_LED_TurnOnBlueOnStrip4,
		&CC_LED_TurnOnBlueOnStrip5,
		&CC_LED_TurnOnBlueOnStrip6,
		&CC_LED_TurnOnBlueOnStrip7,
		&CC_LED_TurnOnBlueOnStrip8,
		&CC_LED_TurnOnBlueOnStrip9,
		&CC_LED_TurnOnBlueOnStrip10
	},
	{
		&CC_LED_TurnOffBlueOnStrip1,
		&CC_LED_TurnOffBlueOnStrip2,
		&CC_LED_TurnOffBlueOnStrip3,
		&CC_LED_TurnOffBlueOnStrip4,
		&CC_LED_TurnOffBlueOnStrip5,
		&CC_LED_TurnOffBlueOnStrip6,
		&CC_LED_TurnOffBlueOnStrip7,
		&CC_LED_TurnOffBlueOnStrip8,
		&CC_LED_TurnOffBlueOnStrip9,
		&CC_LED_TurnOffBlueOnStrip10
	}
};

//Functions
//SOFTPWM
void CC_ML_SoftPwmBasetimeandIntrrptsInit(void)
{
	CC_TMR_TimerInit(&CC_ML_PWM_GEN_BASETIME);
	CC_TMR_TimerStartAndInterruptsGen(&CC_ML_PWM_GEN_BASETIME);
}

//Scheduler
void CC_ML_SchedulerInit(void)
{
	CC_TMR_TimerInit(&CC_ML_SCHEDULER_BASETIME_HANDLER);
	CC_TMR_TimerStartAndInterruptsGen(&CC_ML_SCHEDULER_BASETIME_HANDLER);
}

//CC_CAN
void CC_ML_InitCAN(void)
{
	CC_CAN_Init(&CC_CAN_TxHeader);
}
void CC_ML_StartCAN(void)
{
	CC_CAN_StartCAN(&CC_ML_PERIPHERALS_CAN);													//Starting CAN module
}
void CC_ML_EnableCANInt(void)
{
	CC_CAN_EnableCANInt(&CC_ML_PERIPHERALS_CAN, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0);
}
void CC_ML_SendMessageCAN(void* param1, void* param2, void* param3)
{
	FDCAN_HandleTypeDef* pHandlerCan;
	FDCAN_TxHeaderTypeDef* pHeaderTxCan;
	uint8_t* pdata2send;

	pHandlerCan=(FDCAN_HandleTypeDef*)param1;
	pHeaderTxCan=(FDCAN_TxHeaderTypeDef*)param2;
	pdata2send= (uint8_t*)param3;
	CC_CAN_SendMessage(pHandlerCan,	pHeaderTxCan, pdata2send);
}
void CC_ML_SetCanRxAdress(void* param1, void* param2, void* param3)
{
	const uint32_t* const pAdress=(uint32_t*)param1;
	CC_CAN_SetRxAddress(*pAdress);
};

//CC_DIPSW
void CC_ML_GetDipSwitch4pos(void* pdata, void* param2, void* param3)
{
	CC_DIPSW_DipSw_t* pDipSwitch;
	pDipSwitch=(CC_DIPSW_DipSw_t*)pdata;

	CC_DIPSW_GetDipSwitch4pos(pDipSwitch);
}
void CC_ML_UpdateIdSysFromDipSwitch(void* BoardData, void* DipSwData, void*)
{
	CC_APP_Config_t* pBoardData=(CC_APP_Config_t*)BoardData;		//Input parameters castings
	CC_DIPSW_DipSw_t* pDipSwitch=(CC_DIPSW_DipSw_t*)DipSwData;

	pBoardData->id = pDipSwitch->all;
}

//CC_TMR
uint32_t CC_ML_GetTimerElapsedCounts(const TIM_HandleTypeDef* const ptimer_header)
{
	return CC_TMR_GetElapsedCounts(ptimer_header);
}
uint32_t CC_ML_GetTimerLimitCounts(const TIM_HandleTypeDef* const ptimer_header)
{
	return 	CC_TMR_GetLimitCounts(ptimer_header);
}
void CC_ML_StartTimer(TIM_HandleTypeDef* htim)
{
	CC_TMR_StartTimer(htim);
}
void CC_ML_StopTimer(TIM_HandleTypeDef* htim)
{
	CC_TMR_StopTimer(htim);
}
void CC_ML_SetTimer(TIM_HandleTypeDef* htim, uint32_t counts)
{
	CC_TMR_SetTimer(htim, counts);
}

//CC_SERIAL
void CC_ML_SendUARTString(const char* String2bSend, UART_HandleTypeDef* const huart)
//Function to send strings via USART
{
    uint32_t length=0;

    length = strlen(String2bSend);  	//Gets length of the string
    length++;  							//Increasing one for the null terminator

    uint8_t tx_buffer[length];  		//Creating an array (VLA) as long as the string to be sent, avoiding like this the intrinsic problem on strncpy() function (no length control)

    strncpy((char*)tx_buffer, String2bSend, length);  		//Copy string to buffer
    CC_SERIAL_SendData(huart, tx_buffer, length);
}
void CC_ML_ClearUARTRxData(void)
{
	CC_SERIAL_RxData[0]='\0';
}
void CC_ML_EnableRxIntUART(void)
{
	CC_SERIAL_EnableRxIntUART(&CC_ML_SERIAL_DEBUG_HANDLER, CC_SERIAL_RxData, 1);
}

	//CC_BOARDLED
void CC_ML_LedBoardToggle(void)
{
	CC_BOARDLED_Led1Toggle();
}


