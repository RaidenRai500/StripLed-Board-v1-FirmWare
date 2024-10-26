/*
 * CC_SM.h
 *
 *  Created on: Sep 11, 2024
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

#ifndef INC_CC_SM_H_
	#define INC_CC_SM_H_
	//HEADERS
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers
	
	//CONSTANTS
	#define TX_BUFF_LENGTH 150
	#define ONEMILISEC 1
	#define MESSAGE1 "Welcome to the strip leds control\n\r"
	#define MESSAGE2 "The application which allows you to control your led lights\n\r"
	#define MESSAGE3 "Running over the hardware: "
	#define MESSAGE4 "With a uC: "
	#define MESSAGE5 "Software version: "
	#define MESSAGE6 "Board identifier: "
	#define MESSAGE7 "Please select the color you would like\n\r"
	#define MESSAGE8 "Red(R)\n\rGreen(G)\n\rBlue(B)\n\rWhite(W)\n\rYellow(Y)\n\rPink(P)\n\rCyan(C)\n\rOff(O)\n\rOr just exit the application(E)\n\r"
	#define MESSAGE9 "Wrong selection, please try again\n\r"
	#define MESSAGE10 "Thanks for using our devices\n\rGoodbye!\n\r"
	#define MESSAGE_RETURN 	"\n\r"
	#define MESSAGE_TRIPLERETURN 	"\n\r\n\r\n\r"

	enum CC_SM_SerialStatesTypedef
	{
		UART_SM_START_MSG=0,
		UART_SM_STARTING,
		UART_SM_WELCOME_MSG,
		UART_SM_MODE_MSG,
		UART_SM_MODE,
		UART_SM_DEBUG_MSG,
		UART_SM_DEBUG,
		UART_SM_OPERATION_MSG,
		UART_SM_OPERATION_RED_MSG,
		UART_SM_OPERATION_RED,
		UART_SM_OPERATION_GREEN_MSG,
		UART_SM_OPERATION_GREEN,
		UART_SM_OPERATION_BLUE_MSG,
		UART_SM_OPERATION_BLUE,
		UART_SM_OPERATION_REPEAT_MSG,
		UART_SM_OPERATION_REPEAT,
		UART_SM_EXIT,
		UART_SM_STOP,
	};
	typedef enum CC_SM_SerialStatesTypedef CC_SM_SerialStatesTypedef;

	//VARIABLES PROTOTYPES

	//FUNCTIONS PROTOTYPES
	void CC_SM_UsartSM(void*, void*, void*);

#endif /* INC_CC_SM_H_ */
