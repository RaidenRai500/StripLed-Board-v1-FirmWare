/*
 * CC_APP.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Admin
 */
//Headers
#include "Application\CC_APP.h"
#include <string.h>  				// Include for strncpy()

//Global Variables Declaration
uint8_t CC_APP_BlinkCnts=CC_APP_LED_INDICATOR_OK_CNTS_BT10MS;	//Variable used to set the board's led blink frequency
CC_APP_Config_t CC_APP_BoardData;								//Handler with the board's data

//Functions
void CC_APP_Nop(void* param1, void* param2, void* param3)
{
	__asm__("nop");
}

void CC_APP_BoardLedBlinking(void* const param1, void* param2, void* param3)
{
	uint8_t TotalCounts;
	static uint8_t counts=0;				//Static var to keep the value between entries.

	TotalCounts=*((uint8_t*)param1);		//Same TotalCounts on and off
	if(counts<TotalCounts)
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
	strncpy(SysData->HwCode,CC_APP_BOARDHWCODE, length);	//Copy the constant string
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



