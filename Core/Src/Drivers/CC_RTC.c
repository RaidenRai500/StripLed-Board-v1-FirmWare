/*
 * CC_RTC.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
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
#include "Drivers\CC_RTC.h"

//GLOBAL VARIABLES DECLARATION
CC_RTC_TimeStamp_t CC_RTC_DateData;

//FUNCTIONS
uint8_t CC_RTC_ReadTimeAndDate(RTC_HandleTypeDef* const phrtc,	CC_RTC_TimeStamp_t*	const pTimeData)
//Function to update time and date structures data with the last RTC's value.
//A screenshot is done and it must be accessed time and data with the same screenshot.
//No error management. Always OK returned
{
	RTC_TimeTypeDef Time;		//Variable where is updated the time managed by the RTC
	RTC_DateTypeDef Date;		//Variable where is updated the date managed by the RTC

	HAL_RTC_GetTime(phrtc, &Time, RTC_FORMAT_BIN);	//Binary format by defect. Other option is BCD format (avoided)
	HAL_RTC_GetDate(phrtc, &Date, RTC_FORMAT_BIN);  //Date must be read after time

	pTimeData->Year=Date.Year;
	pTimeData->Month=Date.Month;
	pTimeData->Day=Date.Date;
	pTimeData->Hours=Time.Hours;
	pTimeData->Minutes=Time.Minutes;
	pTimeData->Seconds=Time.Seconds;
	pTimeData->MiliSeconds=((Time.SecondFraction-Time.SubSeconds)*1000)/(Time.SecondFraction+1); //SecondFraction= total ticks into a second. Subsecond= Countdown counter
	return HAL_OK;
}

uint8_t CC_RTC_SetTimeAndDate(RTC_HandleTypeDef* const phrtc, const CC_RTC_TimeStamp_t* const pTimeData)
{
	RTC_TimeTypeDef Time={0};		//Variable where is updated the time managed by the RTC
	RTC_DateTypeDef Date={0};		//Variable where is updated the date managed by the RTC

	Time.Hours=pTimeData->Hours;
	Time.Minutes=pTimeData->Minutes;
	Time.Seconds=pTimeData->Seconds;
	Time.TimeFormat=RTC_HOURFORMAT_24;
	Date.Year=pTimeData->Year;
	Date.Month=pTimeData->Month;
	Date.Date=pTimeData->Day;
	if (HAL_RTC_SetTime(phrtc, &Time, RTC_FORMAT_BIN) != HAL_OK)
	{
	    return HAL_ERROR;
	}

	if (HAL_RTC_SetDate(phrtc, &Date, RTC_FORMAT_BIN) != HAL_OK)
	{
	    return HAL_ERROR;
	}
	return HAL_OK;
}

uint8_t CC_RTC_SetDefaultTimeAndDate(RTC_HandleTypeDef* const phrtc)
{
	CC_RTC_TimeStamp_t data={0};

	data.Year=CC_RTC_DEFAULT_YEAR;
	data.Month=CC_RTC_DEFAULT_MONTH;
	data.Day=CC_RTC_DEFAULT_DAY;
	data.Hours=CC_RTC_DEFAULT_HOUR;
	data.Minutes=CC_RTC_DEFAULT_MINUTE;
	data.Seconds=CC_RTC_DEFAULT_SECOND;
	return CC_RTC_SetTimeAndDate(phrtc, &data);
}

uint8_t CC_RTC_Init(RTC_HandleTypeDef* const phrtc)
//RTC initialization with the low speed inner oscillator(LSI) at 32.768Hz
//With the async and sync pre-dividers set to get 1Hz RTC tick
// f_RTC = f_LSI / ((Prediv_sync+1)x(Predib_async+1))
{
	phrtc->Instance = RTC;									//Base @
	phrtc->Init.HourFormat = RTC_HOURFORMAT_24;				//Hours format
	phrtc->Init.AsynchPrediv = 127;							//pre-dividers 1
	phrtc->Init.SynchPrediv = 255;							//pre-dividers 2
	phrtc->Init.OutPut = RTC_OUTPUT_DISABLE;				//No output
	phrtc->Init.OutPutRemap = RTC_OUTPUT_REMAP_NONE;		//Output no remapped to anywhere
	phrtc->Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
	phrtc->Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
	phrtc->Init.OutPutPullUp = RTC_OUTPUT_PULLUP_NONE;

	return HAL_RTC_Init(phrtc);
}
