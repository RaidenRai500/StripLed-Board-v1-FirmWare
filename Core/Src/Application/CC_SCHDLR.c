/*
 * CC_SCHDLR.c
 *
 *  Created on: Sep 18, 2024
 *      Author: Admin
 */
//Headers
#include <MiddleLayer/CC_ML.h>
#include "Application\CC_SCHDLR.h"
#include "Application\CC_APP.h"

//Global Variables Declaration
CC_SCHDLR_Scheduler_t CC_SCHDLR_FastScheduler;
CC_SCHDLR_Scheduler_t CC_SCHDLR_SlowScheduler;			//Executed inside the first scheduler (nested)
CC_SCHDLR_Usage_t CC_SCHDLR_MainSchedulerUsage;			//Faster scheduler taks usage

//Functions
void CC_SCHDLR_Scheduler(
						void* const pSchedulerStruct,
						void* const param2,
						void* const param3
						)
//Procedure thought to be executed over a non-stop timer interruption.
//Every time it triggers a task is executed (function or procedures).
//and next execution it will execute next task.
//Up to CC_SCHDLR_MAX_THREADS tasks. Only one every time, but restarting
//when the last is done.
{
	CC_SCHDLR_Scheduler_t* pSchedulerData;

	pSchedulerData = (CC_SCHDLR_Scheduler_t*)pSchedulerStruct;
	((void (*)(void*, void*, void*))pSchedulerData->Task2Launch[pSchedulerData->TaskOngoing].function)	//Task pSchedulerData->TaskOngoing dereferencing and calling
	(
		pSchedulerData->Task2Launch[pSchedulerData->TaskOngoing].input_param1,							//Task pSchedulerData->TaskOngoing parameter 1
		pSchedulerData->Task2Launch[pSchedulerData->TaskOngoing].input_param2, 							//Task pSchedulerData->TaskOngoing parameter 2
		pSchedulerData->Task2Launch[pSchedulerData->TaskOngoing].input_param3 							//Task pSchedulerData->TaskOngoing parameter 3
	);
	pSchedulerData->IntCount++;
	pSchedulerData->TaskOngoing++;
	if(pSchedulerData->TaskOngoing==CC_SCHDLR_MAX_THREADS)
	{
		pSchedulerData->TaskOngoing=0;		//Restart tasks
	}
	CC_SCHDLR_CheckForSchedulerOverflow(pSchedulerData);
}

void CC_SCHDLR_CheckForSchedulerOverflow(CC_SCHDLR_Scheduler_t* const pSchedulerData)
//It is checked if an interrupt happened while ISR is attended.
//It should be used inside the timer's ISR.
{
	if (CC_TMR_CheckTimIntFlag(&CC_ML_SCHEDULER_BASETIME_HANDLER)==1)
	{
		pSchedulerData->MissIntCnt++;  		//Overflow count
	}
}

void CC_SCHDLR_SchedulerUsage(CC_SCHDLR_Usage_t* const pSchedulerControl, const uint8_t task_number)
//Function to calculate the usage of the scheduler.
//It must be launched a different timer from the used for the scheduler at the
//ISR starting, and stop before that.
//Then both counts are compared and the % of time used to execute the current
//scheduler's task is calculated.
//If needed this calculus could be done outside the ISR as it is a float calculus
//and therefore it is slow.
{
	uint32_t ControllerTimerCounts;
	uint32_t SchedulerTimerTotalCounts;
	float usage;

	ControllerTimerCounts=CC_ML_GetTimerElapsedCounts(&CC_ML_SCHEDULER_CHRONO_HANDLER);
	pSchedulerControl->TaskUsageCounts[task_number]=ControllerTimerCounts;
	SchedulerTimerTotalCounts=CC_ML_GetTimerLimitCounts(&CC_ML_SCHEDULER_BASETIME_HANDLER);
	pSchedulerControl->TotalAvailableCounts[task_number]=SchedulerTimerTotalCounts;
	usage=((float)ControllerTimerCounts)/((float)SchedulerTimerTotalCounts);
	usage=usage*100.0;
	pSchedulerControl->TaskUsageRatio[task_number]=usage;
}

void CC_SCHDLR_InitFastScheduler(CC_SCHDLR_Scheduler_t* const data)
//Loading the scheduler's structure with functions and/or procedures to launch,
//and also their parameters.
//Void pointers to be able to launch different kinds of functions.
{
	void (*pfunction) (void*, void*, void*);		//Pointer to void function with 3 void pointers as a parameters
	CC_SCHDLR_Scheduler_t* pNestedScheduler;	//Pointer to nested scheduler data

	data->TaskOngoing=0;
	data->IntCount=0;
	data->MissIntCnt=0;
	data->BaseTimems=CC_SCHDLR_BASE_TIME;

	pfunction=&CC_APP_Nop;										//Task0 initialization
	data->Task2Launch[0].function=(void*)pfunction;
	data->Task2Launch[0].input_param1=(void*)NULL;
	data->Task2Launch[0].input_param2=(void*)NULL;
	data->Task2Launch[0].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task1 initialization
	data->Task2Launch[1].function=(void*)pfunction;
	data->Task2Launch[1].input_param1=(void*)NULL;
	data->Task2Launch[1].input_param2=(void*)NULL;
	data->Task2Launch[1].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task2 initialization
	data->Task2Launch[2].function=(void*)pfunction;
	data->Task2Launch[2].input_param1=(void*)NULL;
	data->Task2Launch[2].input_param2=(void*)NULL;
	data->Task2Launch[2].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task3 initialization
	data->Task2Launch[3].function=(void*)pfunction;
	data->Task2Launch[3].input_param1=(void*)NULL;
	data->Task2Launch[3].input_param2=(void*)NULL;
	data->Task2Launch[3].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task4 initialization
	data->Task2Launch[4].function=(void*)pfunction;
	data->Task2Launch[4].input_param1=(void*)NULL;
	data->Task2Launch[4].input_param2=(void*)NULL;
	data->Task2Launch[4].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task5 initialization
	data->Task2Launch[5].function=(void*)pfunction;
	data->Task2Launch[5].input_param1=(void*)NULL;
	data->Task2Launch[5].input_param2=(void*)NULL;
	data->Task2Launch[5].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task6 initialization
	data->Task2Launch[6].function=(void*)pfunction;
	data->Task2Launch[6].input_param1=(void*)NULL;
	data->Task2Launch[6].input_param2=(void*)NULL;
	data->Task2Launch[6].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task7 initialization
	data->Task2Launch[7].function=(void*)pfunction;
	data->Task2Launch[7].input_param1=(void*)NULL;
	data->Task2Launch[7].input_param2=(void*)NULL;
	data->Task2Launch[7].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task8 initialization
	data->Task2Launch[8].function=(void*)pfunction;
	data->Task2Launch[8].input_param1=(void*)NULL;
	data->Task2Launch[8].input_param2=(void*)NULL;
	data->Task2Launch[8].input_param3=(void*)NULL;


	pfunction=&CC_SCHDLR_Scheduler;								//Task9 initialization. Nested scheduler
	data->Task2Launch[9].function=(void*)pfunction;
	pNestedScheduler=&CC_SCHDLR_SlowScheduler;
	data->Task2Launch[9].input_param1=(void*)pNestedScheduler;
	data->Task2Launch[9].input_param2=(void*)NULL;
	data->Task2Launch[9].input_param3=(void*)NULL;

	//HAL_IWDG_Refresh(&hiwdg);						//Watchdog refresh
}

void CC_SCHDLR_InitSlowScheduler(CC_SCHDLR_Scheduler_t* const data)
//Loading the scheduler's structure with functions and/or procedures to launch,
//and also their parameters.
//Void pointers to be able to launch different kinds of functions.
{
	void (*pfunction) (void*, void*, void*);		//Pointer to void function with 3 void pointers as a parameters
	uint8_t* 				puint8;					//Pointer to uint8_t
	CC_DIPSW_DipSw_t* 		pCC_DIPSW_DipSw;		//Pointer CC_DIPSW_DipSw_t
	CC_APP_Config_t* 		pCC_SYS_Config;			//Pointer CC_APP_Config_t
	FDCAN_HandleTypeDef* 	pFDCAN_HandleTypeDef;	//Pointer FDCAN_HandleTypeDef
	FDCAN_TxHeaderTypeDef* 	pFDCAN_TxHeaderTypeDef;	//Pointer FDCAN_TxHeaderTypeDef
	CC_LEDPWM_SoftPwm_t* 	pCC_LEDPWM_SoftPwm;		//Pointer to strip leds control data
	const uint8_t* 			puint8_2;				//Constant pointer to a constant uint8_t data

	data->TaskOngoing=0;							//AIXO HO VULL A FORA. PEL NESTED ES RARO
	data->IntCount=0;
	data->MissIntCnt=0;
	data->BaseTimems=CC_SCHDLR_BASE_TIME*CC_SCHDLR_MAX_THREADS;

	pfunction=&CC_APP_BoardLedBlinking;							//Task9.0 initialization. Led blinking
	data->Task2Launch[0].function=(void*)pfunction;
	puint8=&CC_APP_BlinkCnts;
	data->Task2Launch[0].input_param1=(void*)puint8;
	data->Task2Launch[0].input_param2=(void*)NULL;
	data->Task2Launch[0].input_param3=(void*)NULL;

	pfunction=&CC_ML_GetDipSwitch4pos;							//Task9.1 initialization. DIP-Switch update
	data->Task2Launch[1].function=(void*) pfunction;
	pCC_DIPSW_DipSw=&CC_DIPSW_DipSwitch;
	data->Task2Launch[1].input_param1=(void*)pCC_DIPSW_DipSw;
	data->Task2Launch[1].input_param2=(void*)NULL;
	data->Task2Launch[1].input_param3=(void*)NULL;

	pfunction=&CC_ML_UpdateIdSysFromDipSwitch;					//Task9.2 initialization. Board Id update from DIP-Switch
	data->Task2Launch[2].function=(void*)pfunction;
	pCC_DIPSW_DipSw=&CC_DIPSW_DipSwitch;
	pCC_SYS_Config=&CC_APP_BoardData;
	data->Task2Launch[2].input_param1=(void*)pCC_SYS_Config;
	data->Task2Launch[2].input_param2=(void*)pCC_DIPSW_DipSw;
	data->Task2Launch[2].input_param3=(void*)NULL;

	pfunction=&CC_SM_UsartSM;									//Task9.3 initialization. USART state machine
	data->Task2Launch[3].function=(void*)pfunction;
	data->Task2Launch[3].input_param1=(void*)NULL;
	data->Task2Launch[3].input_param2=(void*)NULL;
	data->Task2Launch[3].input_param3=(void*)NULL;

	pfunction=&CC_ML_SendMessageCAN;							//Task9.4 initialization. Send CAN
	data->Task2Launch[4].function=(void*)pfunction;
	pFDCAN_HandleTypeDef=&hfdcan2;
	pFDCAN_TxHeaderTypeDef=&CC_CAN_TxHeader;
	puint8=CC_CAN_TxData;
	data->Task2Launch[4].input_param1=(void*)pFDCAN_HandleTypeDef;
	data->Task2Launch[4].input_param2=(void*)pFDCAN_TxHeaderTypeDef;
	data->Task2Launch[4].input_param3=(void*)puint8;

	pfunction=&CC_LEDPWM_CntrCalculus;										//Task9.5 initialization
	data->Task2Launch[5].function=(void*)pfunction;
	pCC_LEDPWM_SoftPwm=&CC_LEDPWM_Strip;
	data->Task2Launch[5].input_param1=(void*)pCC_LEDPWM_SoftPwm;
	puint8_2=&CC_LEDPWM_TotalStrips;
	data->Task2Launch[5].input_param2=(void*)puint8_2;
	data->Task2Launch[5].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task9.6 initialization
	data->Task2Launch[6].function=(void*)pfunction;
	data->Task2Launch[6].input_param1=(void*)NULL;
	data->Task2Launch[6].input_param2=(void*)NULL;
	data->Task2Launch[6].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task9.7 initialization
	data->Task2Launch[7].function=(void*)pfunction;
	data->Task2Launch[7].input_param1=(void*)NULL;
	data->Task2Launch[7].input_param2=(void*)NULL;
	data->Task2Launch[7].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task9.8 initialization
	data->Task2Launch[8].function=(void*)pfunction;
	data->Task2Launch[8].input_param1=(void*)NULL;
	data->Task2Launch[8].input_param2=(void*)NULL;
	data->Task2Launch[8].input_param3=(void*)NULL;

	pfunction=&CC_APP_Nop;										//Task9.9 initialization
	data->Task2Launch[9].function=(void*)pfunction;
	data->Task2Launch[9].input_param1=(void*)NULL;
	data->Task2Launch[9].input_param2=(void*)NULL;
	data->Task2Launch[9].input_param3=(void*)NULL;
}


