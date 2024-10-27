/*
 * CC_SM.c
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

//HEADERS
#include "Application\CC_SM.h"
#include <string.h>  		//Include for strncpy()
#include <stdlib.h>			//Include for utoa()
#include <ctype.h>			//Include for isdigit()

//GLOBAL VARIABLES DECLARATION

//FUNCTIONS
void CC_SM_UsartSM(void* param1, void* param2, void* param3)
{
	static CC_SM_SerialStatesTypedef UsartSM_state=UART_SM_START_MSG;
	char sendString[TX_BUFF_LENGTH];
	char input_char=*(pCC_ML_SERIAL_DEBUG_RxData+0);		//Getting the character received from UART
	uint32_t duty=0;
	static char input_string[3]={0,0,0};
	static uint8_t char_number=0;
	uint8_t i=0;

	switch (UsartSM_state)
	{
	case UART_SM_START_MSG:
		CC_ML_SendUARTString((const char*)"Should we start?\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MSG_Y_OR_N, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_STARTING;
	break;

	case UART_SM_STARTING:
		switch(input_char)
		{
		case 0:
			//No character has been entered
		break;
		case 'Y':
		case 'y':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_WELCOME_MSG;
		break;
		case 'N':
		case 'n':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_EXIT;
		break;
		default:					//Wrong order gotten
			CC_ML_SendUARTString((const char*)MSG_WRONG_SEL, &CC_ML_SERIAL_DEBUG_HANDLER);
			UsartSM_state=UART_SM_START_MSG;
		break;
		}
		CC_ML_ClearUARTRxData();
	break;

	case UART_SM_WELCOME_MSG:
		CC_ML_SendUARTString((const char*)"Welcome to the strip leds control\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"The application which allows you to control your led lights\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"Running over the hardware: ", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)CC_APP_BoardData.HwCode, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MSG_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"With a uC: ", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)CC_APP_BoardData.uC, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MSG_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"Software version: ", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)CC_APP_BoardData.SwVer, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MSG_RETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"Board identifier: ", &CC_ML_SERIAL_DEBUG_HANDLER);
		utoa(CC_APP_BoardData.id, sendString, 10);									//Converting the identifier to ascii in decimal base
		CC_ML_SendUARTString((const char*)sendString, &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_MODE_MSG;
	break;

	case UART_SM_MODE_MSG:
		CC_ML_SendUARTString((const char*)"Would you like to operate or to debug?\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"Operation(O)\n\rDebug(D)\n\rExit(E)\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_MODE;
	break;

	case UART_SM_MODE:
		switch(input_char)
		{
		case 0:
			//No character has been entered
		break;
		case 'O':
		case 'o':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_OPERATION_MSG;
		break;
		case 'D':
		case 'd':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_DEBUG_MSG;
		break;
		case 'E':
		case 'e':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_EXIT;
		break;
		default:
			CC_ML_SendUARTString((const char*)MSG_WRONG_SEL, &CC_ML_SERIAL_DEBUG_HANDLER);
		break;
		}
		CC_ML_ClearUARTRxData();
	break;

	case UART_SM_DEBUG_MSG:
		CC_ML_SendUARTString((const char*)"Debug mode. Showing system data\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)"Press (E) to stop the operation\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_DEBUG;
	break;

	case UART_SM_DEBUG:
		//Send debug data
		if (input_char=='E'||input_char=='e') //Exit?
		{
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);				//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);	//Cleaning the line into the console
			UsartSM_state=UART_SM_MODE_MSG;															//Returning to the main menu
		}
		CC_ML_ClearUARTRxData();									//Cleaning whatever be in the UART's buffer
	break;

	case UART_SM_OPERATION_MSG:
		CC_ML_SendUARTString((const char*)"Please select the desired duty cycle:\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_OPERATION_RED_MSG;
	break;

	case UART_SM_OPERATION_RED_MSG:
		CC_ML_SendUARTString((const char*)"Red leds duty cycle:\n\r(0-100)\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_OPERATION_RED;
	break;

	case UART_SM_OPERATION_RED:
		if(isdigit(input_char))											//Checking if the character given is a numeric digit
		{
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);//Sending the character given back
			input_string[char_number]=input_char;						//Storing to get the total duty value (in a string)
			char_number++;												//Next number
			if (char_number==3)											//3 digits for the duty
			{
				duty=atoi(input_string);								//Conversion to integer
				if (duty>100){duty=100;}								//Saturation
				while (i<CC_LEDPWM_TOTALSTRIPS)
				{
					CC_LEDPWM_Strip.Strip[i].RedDuty=(uint8_t)duty;		//PWM duty updates
					i++;
				}
				i=0;													//Reset variables
				duty=0;
				char_number=0;
				input_string[0]=0;
				input_string[1]=0;
				input_string[2]=0;
				UsartSM_state=UART_SM_OPERATION_GREEN_MSG;				//Next SM state
				CC_ML_SendUARTString((const char*)MSG_RETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			}
			CC_ML_ClearUARTRxData();									//Cleaning whatever be in the UART's buffer
		}
	break;

	case UART_SM_OPERATION_GREEN_MSG:
		CC_ML_SendUARTString((const char*)"Green leds duty cycle:\n\r(0-9)\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_OPERATION_GREEN;
	break;

	case UART_SM_OPERATION_GREEN:
		if(isdigit(input_char))											//Checking if the character given is a numeric digit
		{
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);//Sending the character given back
			input_string[char_number]=input_char;						//Storing to get the total duty value (in a string)
			char_number++;												//Next number
			if (char_number==3)											//3 digits for the duty
			{
				duty=atoi(input_string);								//Conversion to integer
				if (duty>100){duty=100;}								//Saturation
				while (i<CC_LEDPWM_TOTALSTRIPS)
				{
					CC_LEDPWM_Strip.Strip[i].GreenDuty=(uint8_t)duty;	//PWM duty updates
					i++;
				}
				i=0;													//Reset variables
				duty=0;
				char_number=0;
				input_string[0]=0;
				input_string[1]=0;
				input_string[2]=0;
				UsartSM_state=UART_SM_OPERATION_BLUE_MSG;				//Next SM state
				CC_ML_SendUARTString((const char*)MSG_RETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			}
			CC_ML_ClearUARTRxData();									//Cleaning whatever be in the UART's buffer
		}
	break;

	case UART_SM_OPERATION_BLUE_MSG:
		CC_ML_SendUARTString((const char*)"Blue leds duty cycle:\n\r(0-9)\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_OPERATION_BLUE;
	break;

	case UART_SM_OPERATION_BLUE:
		if(isdigit(input_char))											//Checking if the character given is a numeric digit
		{
			CC_ML_SendUARTChar((uint8_t*)(&input_char), &CC_ML_SERIAL_DEBUG_HANDLER);//Sending the character given back
			input_string[char_number]=input_char;						//Storing to get the total duty value (in a string)
			char_number++;												//Next number
			if (char_number==3)											//3 digits for the duty
			{
				duty=atoi(input_string);								//Conversion to integer
				if (duty>100){duty=100;}								//Saturation
				while (i<CC_LEDPWM_TOTALSTRIPS)
				{
					CC_LEDPWM_Strip.Strip[i].BlueDuty=(uint8_t)duty;	//PWM duty updates
					i++;
				}
				i=0;													//Reset variables
				duty=0;
				char_number=0;
				input_string[0]=0;
				input_string[1]=0;
				input_string[2]=0;
				UsartSM_state=UART_SM_OPERATION_REPEAT_MSG;				//Next SM state
				CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN, &CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			}
			CC_ML_ClearUARTRxData();									//Cleaning whatever be in the UART's buffer
		}
	break;

	case UART_SM_OPERATION_REPEAT_MSG:
		CC_ML_SendUARTString((const char*)"Would you like to enter the duties again?\n\rYes(Y)\n\rNo(N)\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_OPERATION_REPEAT;
	break;

	case UART_SM_OPERATION_REPEAT:
		switch(input_char)
		{
		case 0:			//No character has been entered
		break;
		case 'Y':
		case 'y':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_OPERATION_MSG;	//Enter again the duties
		break;
		case 'N':
		case 'n':
			CC_ML_SendUARTChar((uint8_t*)(&input_char),&CC_ML_SERIAL_DEBUG_HANDLER);		//Sending the character given back
			CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN,&CC_ML_SERIAL_DEBUG_HANDLER);//Cleaning the line into the console
			UsartSM_state=UART_SM_MODE_MSG;			//Go to the main menu
		break;
		default:
			CC_ML_SendUARTString((const char*)MSG_WRONG_SEL, &CC_ML_SERIAL_DEBUG_HANDLER);
		break;
		}
		CC_ML_ClearUARTRxData();
	break;

	case UART_SM_EXIT:
		CC_ML_SendUARTString((const char*)"\n\rThanks for using our devices\n\rGoodbye!\n\r", &CC_ML_SERIAL_DEBUG_HANDLER);
		CC_ML_SendUARTString((const char*)MSG_TRIPLERETURN, &CC_ML_SERIAL_DEBUG_HANDLER);
		UsartSM_state=UART_SM_START_MSG;
	break;

	}
}
