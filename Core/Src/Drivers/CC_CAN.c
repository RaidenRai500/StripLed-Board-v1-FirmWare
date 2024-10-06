/*
 * CC_CAN.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Admin
 */
//Headers
#include "Drivers\CC_CAN.h"
#include <string.h>				//Add to use the memcpy funtion

//Global Variables Declaration
uint8_t CC_CAN_RxData[CC_CAN_RXDATALENGHT];
uint8_t CC_CAN_TxData[CC_CAN_TXDATALENGHT];
FDCAN_RxHeaderTypeDef CC_CAN_RxHeader;																//CAN receiver header
FDCAN_TxHeaderTypeDef CC_CAN_TxHeader;
uint32_t CC_CAN_RxAdress=CC_CAN_RX_ADRESS;

//Functions
inline void CC_CAN_EnableCANInt(FDCAN_HandleTypeDef *hfdcan, uint32_t ActiveITs,uint32_t BufferIndexes)
{
	HAL_FDCAN_ActivateNotification(hfdcan, ActiveITs, BufferIndexes);
}

inline void CC_CAN_StartCAN(FDCAN_HandleTypeDef *hfdcan)
{
	HAL_FDCAN_Start(hfdcan);
}

void CC_CAN_SetRxAddress(const uint32_t new_adress)
{
	CC_CAN_RxAdress=new_adress;
}

void CC_CAN_SendMessage(
						FDCAN_HandleTypeDef* const pHeaderCan,
						const FDCAN_TxHeaderTypeDef* const pHeaderTx,
						const uint8_t* const pdata2send
						)
{
	HAL_FDCAN_AddMessageToTxFifoQ
	(
		pHeaderCan,
		pHeaderTx,
		pdata2send
	);
}

void CC_CAN_Init(FDCAN_TxHeaderTypeDef* const txheader )
{
//  hfdcan1.Init.Mode = FDCAN_MODE_BUS_MONITORING;			//Able to receive messages but will not acknowledge them.
//
//	FDCAN_FilterTypeDef sFilterConfig;
//
//	//Rx filter configuration
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
	uint8_t temp_data[CC_CAN_RXDATALENGHT];

	if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
	{
		if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &CC_CAN_RxHeader, temp_data) != HAL_OK)
		{
			Error_Handler();
		}
		if (CC_CAN_RxHeader.Identifier == CC_CAN_RxAdress)
		{
			memcpy(&CC_CAN_RxData,&temp_data, sizeof(temp_data));
//			CC_CAN_RXPROCESS;
		}
	}
}


