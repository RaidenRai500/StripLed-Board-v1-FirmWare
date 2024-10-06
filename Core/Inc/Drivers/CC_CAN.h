/*
 * CC_CAN.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Admin
 */
#ifndef INC_CC_CAN_H_
	#define INC_CC_CAN_H_
	//Headers
	#include "main.h"
	#include "stm32g0xx_it.h"

	//Constants
	#define CC_CAN_TXDATALENGHT		FDCAN_DLC_BYTES_8		//Number of bytes in the CAN transmissions
	#define CC_CAN_RXDATALENGHT		FDCAN_DLC_BYTES_8		//Number of bytes in the CAN transmissions
	#define CC_CAN_TX_ADRESS		0x101					//Board Tx identifier
	#define CC_CAN_RX_ADRESS		0x201					//Board Rx identifier
	#define CC_CAN_RXPROCESS								//Procedure to execute at Rx call back function
//	#define CAN_FILTER_MASK_START	0x00000000
//	#define CAN_FILTER_MASK_END 	0xFFFFFFFF

	//Data types

	//Variables Prototypes
	extern FDCAN_TxHeaderTypeDef CC_CAN_TxHeader;		//CAN transmit header
	extern FDCAN_RxHeaderTypeDef CC_CAN_RxHeader;		//CAN receiver header
	extern uint8_t CC_CAN_RxData[CC_CAN_RXDATALENGHT];	//CAN receiving data
	extern uint8_t CC_CAN_TxData[CC_CAN_TXDATALENGHT]; 	//CAN sending data
	extern uint32_t CC_CAN_RxAdress;

	//Function Prototypes
	void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef*, uint32_t);
	void CC_CAN_Init(FDCAN_TxHeaderTypeDef*);
	void CC_CAN_SetAddress(const uint32_t);
	void CC_CAN_SendMessage(FDCAN_HandleTypeDef*, const FDCAN_TxHeaderTypeDef*, const uint8_t*);

#endif /* INC_CC_CAN_H_ */
