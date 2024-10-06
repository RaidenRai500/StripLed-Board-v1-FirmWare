/*
 * CC_SERIAL.h
 *
 *  Created on: Sep 15, 2024
 *      Author: Admin
 */

#ifndef INC_CC_SERIAL_H_
	#define INC_CC_SERIAL_H_
	//Headers
	#include "stm32g0xx_hal.h"		//ST's HAL definitions
	#include "main.h"				//Pinout mapping definitions

	//Constants
	#define CC_SERIAL_RX_BUFF_LENGTH 	1	//Rx buffer length in bytes
	#define CC_SERIAL_RX_CHAR_TIME		1	//Timeout while receiving 1 byte in ms
	#define CC_SERIAL_TX_TIMEOUT		0x01	//Timeout while transmitting in ms

	//Data types

	//Variables Prototypes
	extern uint8_t CC_SERIAL_RxData[1];
	extern UART_HandleTypeDef huart1;

	//Function Prototypes
	void HAL_UART_RxCpltCallback(UART_HandleTypeDef*);
	void CC_SERIAL_SendData(UART_HandleTypeDef*, const uint8_t*, const uint16_t);
	void CC_SERIAL_EnableRxIntUART(UART_HandleTypeDef*, uint8_t*, uint16_t);


#endif /* INC_CC_SERIAL_H_ */



