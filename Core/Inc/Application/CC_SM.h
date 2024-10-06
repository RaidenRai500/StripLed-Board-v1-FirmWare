/*
 * CC_SM.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Admin
 */

#ifndef INC_CC_SM_H_
	#define INC_CC_SM_H_
	//Headers
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers
	
	//Constants
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

	//Data types
	enum CC_SM_SerialStatesTypedef
	{
		UART_SM_WELCOME_MESSAGE=0,
		UART_SM_GETTING_COLORS_MESSAGE,
		UART_SM_GET_COLOR_ALL,
		UART_SM_WRONG_INPUT,
		UART_SM_EXIT,
		UART_SM_STOP,
	};
	typedef enum CC_SM_SerialStatesTypedef CC_SM_SerialStatesTypedef;

	//Variables Prototypes

	//Function Prototypes
	void CC_SM_UsartSM(void*, void*, void*);

#endif /* INC_CC_SM_H_ */
