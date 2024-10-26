/*
 * CC_SERIAL.c
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
#include "Drivers\CC_SERIAL.h"

//GLOBAL VARIABLES DECLARATION
uint8_t CC_SERIAL_RxData[CC_SERIAL_RX_BUFF_LENGTH];

//FUNCTIONS
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* const huart)
//UART callback
{
	uint8_t error=0;
	/* Prevent unused argument(s) compilation warning */
	UNUSED(huart);

	/* NOTE : This function should not be modified, when the callback is needed,
			the HAL_UART_RxCpltCallback can be implemented in the user file.
	*/
	//  HAL_UART_Transmit(huart, CC_SERIAL_RxData, 1, 10);					//Gives back the character gotten
	error=HAL_UART_Receive_IT(
					  	  	  huart,
							  CC_SERIAL_RxData,
							  CC_SERIAL_RX_CHAR_TIME
					  	  	  );	//Restarts the listening and interruption by serial comm
	if(error!=0)
	{
		//TRACTAMENT D'ERRORS AQUÍ
	}
}

inline uint8_t CC_SERIAL_SendData	(
							UART_HandleTypeDef* const huart,
							const uint8_t* const tx_buffer,
							const uint16_t Size
							)
{
    return HAL_UART_Transmit(huart, tx_buffer, Size, CC_SERIAL_TX_TIMEOUT);	//Send the string via UART

}

inline uint8_t CC_SERIAL_EnableRxIntUART(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
	return HAL_UART_Receive_IT(huart, pData, Size);
}
