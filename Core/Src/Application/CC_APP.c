/*
 * CC_APP.c
 *
 *  Created on: Sep 23, 2024
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
#include "Application\CC_APP.h"
#include <string.h>  				// Include for strncpy()

//GLOBAL VARIABLES DECLARATION
uint8_t CC_APP_BlinkCnts=CC_APP_LED_BOARD_FREQ_DEFAULT;		//Variable used to set the board's led blink frequency.
CC_APP_Config_t CC_APP_BoardData;							//Board's data

//FUNCTIONS
void CC_APP_Nop(void* param1, void* param2, void* param3)
{
	__asm__("nop");
}

void CC_APP_BoardLedBlinking(void* const param1, void* param2, void* param3)
{
	uint8_t TotalCounts;					//Value who defines the frequency
	static uint8_t counts=0;				//Static var to keep the value between entries.

	TotalCounts=*((uint8_t*)param1);
	if(counts<TotalCounts)					//Same TotalCounts on and off
	{
		counts++;
	}
	else
	{
		CC_ML_LedBoardToggle();
		counts=0;
	}
}

void CC_APP_SetBoardParam(CC_APP_Config_t* const SysData)
{
	size_t  length;

	length=sizeof(SysData->HwCode);							//Extract the length of the array (already defined like a vector of sizeof(constant to store) length)
	strncpy(SysData->HwCode,CC_APP_BOARDHWCODE, length);	//Stores the "constant" string into the system's struct
	SysData->HwCode[length-1]='\0';							//Ensures null terminator (to avoid problems)

	length=sizeof(SysData->SwVer);
	strncpy(SysData->SwVer,CC_APP_FWVER, length);
	SysData->SwVer[length-1]='\0';

	length=sizeof(SysData->HwCode);
	strncpy(SysData->Summary,CC_APP_SUMMARY, length);
	SysData->Summary[length-1]='\0';

	length=sizeof(SysData->uC);
	strncpy(SysData->uC,CC_APP_MICROCONTROLLER, length);
	SysData->uC[length-1]='\0';

	SysData->id=0;
}



