/*
 * CC_ERR.c
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
//HEADERS
#include "MiddleLayer\CC_ML.h"
#include "Application\CC_ERR.h"

//GLOBAL VARIABLES DECLARATION
CC_ERR_ErrorsData_t CC_ERR_ErrorControl ={0};

//FUNCTIONS
void CC_ERR_SendStatusCan(const CC_ERR_ErrorsData_t* const pErrorData)
{
	uint8_t Data2Send[CC_CAN_TXDATALENGHT]={0};
	uint32_t PreviousCanId;

	PreviousCanId = CC_ML_CAN_TxHeader.Identifier;				//Saving the CAN's identifier

	//Sending high abstraction layer errors
	CC_ML_CAN_TxHeader.Identifier=CC_ERR_HIGHSIDE_PWM_BASE_MISS_INT_DIR;	//Message id.
	Data2Send[3]=(pErrorData->HighSide.PwmBaseMissInt>>24)&0xFF;		//Chopping information to be sent by CAN
	Data2Send[2]=(pErrorData->HighSide.PwmBaseMissInt>>16)&0xFF;		//32 bits data to be sent thru 8 bit vector
	Data2Send[1]=(pErrorData->HighSide.PwmBaseMissInt>>8)&0xFF;
	Data2Send[0]=pErrorData->HighSide.PwmBaseMissInt&&0xFF;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(Data2Send)
						);
	CC_ML_CAN_TxHeader.Identifier=CC_ERR_HIGHSIDE_SCHEDULER_MISS_INT_DIR;	//Message id.
	Data2Send[3]=(pErrorData->HighSide.SchedulerMissInt>>24)&0xFF;		//Chopping information to be sent by CAN
	Data2Send[2]=(pErrorData->HighSide.SchedulerMissInt>>16)&0xFF;		//32 bit data
	Data2Send[1]=(pErrorData->HighSide.SchedulerMissInt>>8)&0xFF;
	Data2Send[0]=pErrorData->HighSide.SchedulerMissInt&&0xFF;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(Data2Send)
						);
	CC_ML_CAN_TxHeader.Identifier=CC_ERR_HIGHSIDE_CRITIC_PWM_MISS_INT;		//Message id.
	Data2Send[3]=0;														//Cleaning the buffer
	Data2Send[2]=0;														//8 bit data
	Data2Send[1]=0;
	Data2Send[0]=pErrorData->HighSide.CriticPwmBaseMissInt;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(Data2Send)
						);
	CC_ML_CAN_TxHeader.Identifier=CC_ERR_HIGHSIDE_CRITIC_SCHED_MISS_INT;	//Message id.
	Data2Send[3]=0;														//Cleaning the buffer
	Data2Send[2]=0;														//8 bit data
	Data2Send[1]=0;
	Data2Send[0]=pErrorData->HighSide.CriticShedulerMissInt;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(Data2Send)
						);
	//Sending low abstraction layer errors
	CC_ML_CAN_TxHeader.Identifier=CC_ERR_LOWSIDE_WATCHDOG_TRIGGERS_DIR;	//Message id.
	Data2Send[3]=(pErrorData->LowSide.WatchdogTriggersCount>>24)&0xFF;	//Chopping information to be sent by CAN
	Data2Send[2]=(pErrorData->LowSide.WatchdogTriggersCount>>16)&0xFF;	//32 bit data
	Data2Send[1]=(pErrorData->LowSide.WatchdogTriggersCount>>8)&0xFF;
	Data2Send[0]=pErrorData->LowSide.WatchdogTriggersCount&&0xFF;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(NULL)
						);
	CC_ML_CAN_TxHeader.Identifier=CC_ERR_LOWSIDE_CRITIC_WATCHDOG_TRIG_DIR;	//Message id.
	Data2Send[3]=0;														//Cleaning the buffer
	Data2Send[2]=0;														//8 bit data
	Data2Send[1]=0;
	Data2Send[0]=pErrorData->LowSide.CriticWatchdogTriggers;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(Data2Send)
						);
	CC_ML_CAN_TxHeader.Identifier=C_ERR_ERROR_BITMAP_DIR;					//Message id.
	Data2Send[3]=(pErrorData->BitMap.all>>24)&0xFF;														//Cleaning the buffer
	Data2Send[2]=(pErrorData->BitMap.all>>16)&0xFF;														//8 bit data
	Data2Send[1]=(pErrorData->BitMap.all>>8)&0xFF;
	Data2Send[0]=pErrorData->BitMap.all&0xFF;
	CC_ML_SendMessageCan(
						(void*)(&CC_ML_PERIPHERALS_CAN),
						(void*)(&CC_ML_CAN_TxHeader),
						(void*)(Data2Send)
						);
	CC_ML_CAN_TxHeader.Identifier=PreviousCanId;	//Restore the CAN's identifier
}

//void CC_ERR_SendStatus32bits()
//{
//
//}
//
//void CC_ERR_SendStatus8bits()
//{
//
//}


