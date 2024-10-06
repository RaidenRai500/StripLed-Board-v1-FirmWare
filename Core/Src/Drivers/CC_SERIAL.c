/*
 * CC_SERIAL.c
 *
 *  Created on: Sep 15, 2024
 *      Author: Admin
 */
//Headers
#include "Drivers\CC_SERIAL.h"

//Global Variables Declaration
uint8_t CC_SERIAL_RxData[CC_SERIAL_RX_BUFF_LENGTH];

//Functions
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* const huart)
//UART callback
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);

  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_UART_RxCpltCallback can be implemented in the user file.
   */
//  HAL_UART_Transmit(huart, CC_SERIAL_RxData, 1, 10);					//Gives back the character gotten
  HAL_UART_Receive_IT(huart, CC_SERIAL_RxData, CC_SERIAL_RX_CHAR_TIME);	//Restarts the listening and interruption by serial comm
}

void CC_SERIAL_SendData	(
						UART_HandleTypeDef* const huart,
						const uint8_t* const tx_buffer,
						const uint16_t Size
						)
{
    HAL_UART_Transmit(huart, tx_buffer, Size, CC_SERIAL_TX_TIMEOUT);	//Send the string via UART
}

inline void CC_SERIAL_EnableRxIntUART(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	HAL_UART_Receive_IT(huart, pData, Size);
}
