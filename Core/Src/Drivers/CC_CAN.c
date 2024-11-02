/*
 * CC_CAN.c
 *
 *  Created on: Sep 15, 2024
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
#include "Drivers\CC_CAN.h"
#include <string.h>				//Add to use the memcpy function

//GLOBAL VARIABLES DECLARATION
uint8_t CC_CAN_RxData[CC_CAN_RXDATALENGHT];
uint8_t CC_CAN_TxData[CC_CAN_TXDATALENGHT];
uint32_t CC_CAN_RxAdress=CC_CAN_RX_ADRESS;

FDCAN_TxHeaderTypeDef CC_CAN_TxHeader;
FDCAN_RxHeaderTypeDef CC_CAN_RxHeader;

//FUNCTIONS
inline uint8_t CC_CAN_EnableCANInt(FDCAN_HandleTypeDef *hfdcan, uint32_t ActiveITs,uint32_t BufferIndexes)
{
	return HAL_FDCAN_ActivateNotification(hfdcan, ActiveITs, BufferIndexes);
}

inline uint8_t CC_CAN_StartCAN(FDCAN_HandleTypeDef *hfdcan)
{
	return HAL_FDCAN_Start(hfdcan);
}

void CC_CAN_SetRxAddress(const uint32_t new_adress)
{
	CC_CAN_RxAdress=new_adress;
}

uint8_t CC_CAN_SendMessage
			(
			FDCAN_HandleTypeDef* const pHeaderCan,
			const FDCAN_TxHeaderTypeDef* const pHeaderTx,
			const uint8_t* const pdata2send
			)
{
	return HAL_FDCAN_AddMessageToTxFifoQ
			(
			pHeaderCan,
			pHeaderTx,
			pdata2send
			);
}

void CC_CAN_Init(FDCAN_TxHeaderTypeDef* const txheader )
{


//  txheader->Init.Mode = FDCAN_MODE_BUS_MONITORING;			//Able to receive messages but will not acknowledge them.
//
//	//Rx filter configuration
//	FDCAN_FilterTypeDef sFilterConfig;
//
//	sFilterConfig.IdType = FDCAN_STANDARD_ID;				//Extended identifier
//	//sFilterConfig.FilterType = FDCAN_FILTER_MASK;			//Accepted Ids are only ID1 and ID2
//	sFilterConfig.FilterType = FDCAN_FILTER_RANGE;			//Filter range from FilterID1 to FilterID2
//	sFilterConfig.FilterIndex = 0;
//	sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;	//Configuration filter for FIFO nº0
//	sFilterConfig.FilterID1 = 0x000;						//First possible delta module. Extended id
//	sFilterConfig.FilterID2 = 0x7FF;						//Last possible delta module. Extended id
//	if (HAL_FDCAN_ConfigFilter(&hfdcan2, &sFilterConfig) != HAL_OK){Error_Handler();}		//Filter configuration

	//Tx header configuration
	txheader->Identifier = CC_CAN_TX_ADRESS;			//Transmit identifier
	txheader->IdType = FDCAN_STANDARD_ID;				//Standard format identifier
	txheader->TxFrameType = FDCAN_DATA_FRAME;			//Frame type
	txheader->DataLength = CC_CAN_TXDATALENGHT;			//Length of the data is 8 bytes
	txheader->ErrorStateIndicator = FDCAN_ESI_ACTIVE;	//Error indicator active
	txheader->BitRateSwitch = FDCAN_BRS_OFF;			//Without bit rate switching
	txheader->FDFormat = FDCAN_CLASSIC_CAN;				//Classic format
	txheader->TxEventFifoControl = FDCAN_NO_TX_EVENTS;	//Without any Tx event
	txheader->MessageMarker = 0;						//Identifier (marker) in case of an Tx event
}

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef* const hfdcan, uint32_t RxFifo0ITs)
//CAN bus receiver, FIFO 0 callback (FIFO it is not used).
{
	uint8_t GottenData[CC_CAN_RXDATALENGHT];

	if((RxFifo0ITs&FDCAN_IT_RX_FIFO0_NEW_MESSAGE)!=RESET)
	{
		if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &CC_CAN_RxHeader, GottenData) != HAL_OK)
		{
			//AFEGIR LOG D'ERRORS? VARIABLE GLOBAL? TRENQUEM LA ABSTRACCIÓ?
			Error_Handler();
		}
		if (CC_CAN_RxHeader.Identifier==CC_CAN_RxAdress)
		{
			memcpy(&CC_CAN_RxData,&GottenData, sizeof(GottenData));
//			CC_CAN_RXPROCESS;
		}
	}
}


