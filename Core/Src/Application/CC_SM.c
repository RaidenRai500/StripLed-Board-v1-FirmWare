/*
 * CC_SM.c
 *
 *  Created on: Sep 11, 2024
 *      Author: Admin
 */

//Headers
#include "Application\CC_SM.h"
#include <string.h>  		//Include for strncpy()
#include <stdlib.h>			//Inlcude for utoa()

//Global Variables Declaration

//Functions
void CC_SM_SetColor(CC_LED_Colors_t RequestedColor)
//Connector between the State Machine and the LED's controller
{
	uint8_t i=0;
	while(i<CC_LED_MAX_STRIPS)
	{
		CC_LED_hStrip[i].color = RequestedColor;
		i++;
	}
}

void CC_SM_UsartSM(void* param1, void* param2, void* param3)
{
	static CC_SM_SerialStatesTypedef UsartSM_state=UART_SM_WELCOME_MESSAGE;
	char sendString[TX_BUFF_LENGTH];

	switch (UsartSM_state)
	{
	case UART_SM_WELCOME_MESSAGE:
		CC_ML_SendUARTString((const char*)MESSAGE1, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE2, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE3, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)CC_APP_BoardData.HwCode, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE4, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)CC_APP_BoardData.uC, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE5, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)CC_APP_BoardData.SwVer, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE6, &CC_ML_SERIAL_DEBUG_HANDLER);
		utoa(CC_APP_BoardData.id, sendString, 10);									//Converting the identifier to ascii in decimal base
		CC_ML_SendUARTString((const char*)sendString, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_GETTING_COLORS_MESSAGE;
	break;

	case UART_SM_GETTING_COLORS_MESSAGE:
		CC_ML_SendUARTString((const char*)MESSAGE7, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE8, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_GET_COLOR_ALL;
	break;

	case UART_SM_GET_COLOR_ALL:
		char input_char=*(pCC_ML_SERIAL_DEBUG_RxData+0);
		switch (input_char)
		{
		case '\0':					//No order gotten

		break;
		case 'E':
		case 'e':					//Exit order
			UsartSM_state=UART_SM_EXIT;
		break;
		case 'R':
		case 'r':					//Set all red
			CC_SM_SetColor(RED);
		break;
		case 'G':
		case 'g':					//Set all green
			CC_SM_SetColor(GREEN);
		break;
		case 'B':
		case 'b':					//Set all blue
			CC_SM_SetColor(BLUE);
		break;
		case 'Y':
		case 'y':					//Set all yellow
			CC_SM_SetColor(YELLOW);
		break;
		case 'P':
		case 'p':					//Set all pink
			CC_SM_SetColor(PINK);
		break;
		case 'C':
		case 'c':					//Set all pink
			CC_SM_SetColor(CYAN);
		break;
		case 'W':
		case 'w':					//Set all white
			CC_SM_SetColor(WHITE);
		break;
		case 'O':
		case 'o':					//Set all off
			CC_SM_SetColor(BLACK);
		break;
		default:					//Wrong order gotten
			UsartSM_state=UART_SM_WRONG_INPUT;
		break;
		}
		CC_ML_ClearUARTRxData();
	break;

	case UART_SM_WRONG_INPUT:
		CC_ML_SendUARTString((const char*)MESSAGE_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE9, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_GET_COLOR_ALL;
	break;

	case UART_SM_EXIT:
		CC_ML_SendUARTString((const char*)MESSAGE_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE10, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MESSAGE_TRIPLERETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_STOP;
	break;

	case UART_SM_STOP:

	break;
	}
}

