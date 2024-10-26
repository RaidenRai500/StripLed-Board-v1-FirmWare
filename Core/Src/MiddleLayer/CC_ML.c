/*
 * CC_ML.c
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
/* 	Abstraction layer implemented to decouple main tasks and algorithms from drivers layer */
//HEADERS
#include "MiddleLayer\CC_ML.h"
#include <string.h>  		//Include for strncpy()
#include <stdlib.h>			//Include for utoa()

//GLOBAL VARIABLES DECLARATION
	//CC_CAN
FDCAN_RxHeaderTypeDef CC_ML_CAN_RxHeader;																//CAN receiver header
FDCAN_TxHeaderTypeDef CC_ML_CAN_TxHeader;
const uint8_t* const pCC_ML_CAN_RxData=CC_CAN_RxData;		//Pointer to CAN's Rx data. Read only.
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

//FUNCTIONS

//Inner Watchdog
void CC_ML_RefreshWatchdog(void* param1, void* param2, void* param3)
{
	uint8_t error=0;
	IWDG_HandleTypeDef* pWatchdogHandler;

	pWatchdogHandler=(IWDG_HandleTypeDef*)param1;
	error=CC_WATCHDOG_RefreshWdg(pWatchdogHandler);
	if(error!=0)
	{
	//TRACTAMENT D'ERRORS AQUÍ
	}
}

//Soft PWM
void CC_ML_StartSoftPwmBasetimeAndInterrupts(void)
{
	CC_TMR_TimerInit(&CC_ML_PWM_GEN_BASETIME);
	CC_TMR_TimerStartAndInterruptsGen(&CC_ML_PWM_GEN_BASETIME);
}

//Scheduler
void CC_ML_StartScheduler(void)
{
	CC_TMR_TimerInit(&CC_ML_SCHEDULER_BASETIME_HANDLER);
	CC_TMR_TimerStartAndInterruptsGen(&CC_ML_SCHEDULER_BASETIME_HANDLER);
}

//CC_SERIAL
void CC_ML_SendUARTChar(const uint8_t* const Char2bSend, UART_HandleTypeDef* const huart)
{
	uint8_t error=0;

	error=CC_SERIAL_SendData(huart, Char2bSend, 1);
	if(error==1)
	{
		//TRACTAMENT D'ERORS AQUÍ
	}
}

void CC_ML_SendUARTString(const char* const String2bSend, UART_HandleTypeDef* const huart)
//Function to send strings via USART. It sends the null terminator.
{
    uint32_t length=0;
    length = strlen(String2bSend);  	//Gets length of the string
    length++;  							//Increasing one for the null terminator
    uint8_t tx_buffer[length];  		//Creating an array (VLA) as long as the string to be sent, avoiding like this the intrinsic problem on strncpy() function (no length control)
    uint8_t error=0;

    strncpy((char*)tx_buffer, String2bSend, length);  		//Copy string to buffer
    error=CC_SERIAL_SendData(huart, tx_buffer, length);
    if(error!=0)
    	{
    		//TRACTAMENT D'ERRORS AQUÍ
    	}
}
void CC_ML_ClearUARTRxData(void)
{
	CC_SERIAL_RxData[0]='\0';
}
void CC_ML_EnableRxIntUart(void)
{
	uint8_t error=0;

	error=CC_SERIAL_EnableRxIntUART(
									&CC_ML_SERIAL_DEBUG_HANDLER,
									CC_SERIAL_RxData,
									1
									);
    if(error!=0)
    	{
    		//TRACTAMENT D'ERRORS AQUÍ
    	}
}

//CC_CAN
void CC_ML_InitCan(void)
{
	CC_CAN_Init(&CC_ML_CAN_TxHeader);
}
void CC_ML_StartCan(void)
{
	uint8_t error=0;

	error=CC_CAN_StartCAN(&CC_ML_PERIPHERALS_CAN);													//Starting CAN module
	if(error!=0)
	{
		//TRACTAMENT D'ERRORS AQUÍ
	}
}
void CC_ML_EnableCanRxInt(void)
{
	uint8_t error=0;

	error=CC_CAN_EnableCANInt	(
								&CC_ML_PERIPHERALS_CAN,
								FDCAN_IT_RX_FIFO0_NEW_MESSAGE,
								0
								);
	if(error!=0)
	{
		//TRACTAMENT D'ERRORS AQUÍ
	}
}
void CC_ML_SendMessageCan(void* param1, void* param2, void* param3)
{
	FDCAN_HandleTypeDef* pHandlerCan;
	FDCAN_TxHeaderTypeDef* pHeaderTxCan;
	uint8_t* pdata2send;
	uint8_t error=0;

	pHandlerCan=(FDCAN_HandleTypeDef*)param1;
	pHeaderTxCan=(FDCAN_TxHeaderTypeDef*)param2;
	pdata2send= (uint8_t*)param3;
	error=CC_CAN_SendMessage(pHandlerCan, pHeaderTxCan, pdata2send);
	if(error!=0)
	{
		//TRACTAMENT D'ERRORS AQUÍ
	}
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
void CC_ML_UpdateSysIdFromDipSwitch(void* BoardData, void* DipSwData, void*)
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
	uint8_t error=0;

	error=CC_TMR_StartTimer(htim);
    if(error!=0)
    	{
    		//TRACTAMENT D'ERRORS AQUÍ
    	}
}
void CC_ML_StopTimer(TIM_HandleTypeDef* htim)
{
	uint8_t error=0;

	error=CC_TMR_StopTimer(htim);
    if(error!=0)
    	{
    		//TRACTAMENT D'ERRORS AQUÍ
    	}
}
void CC_ML_SetTimer(TIM_HandleTypeDef* htim, uint32_t counts)
{
	CC_TMR_SetTimer(htim, counts);
}
uint8_t CC_ML_CheckTimIntFlag(const TIM_HandleTypeDef* const htim)
{
	return CC_TMR_CheckTimIntFlag(htim);
}

//CC_BOARDLED
void CC_ML_LedBoardToggle(void)
{
	CC_BOARDLED_Led1Toggle();
}


