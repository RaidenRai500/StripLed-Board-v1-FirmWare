/*
 * CC_LEDPWM.c
 *
 *  Created on: Sep 26, 2024
 *      Author: Admin
 */

//Headers
#include "Application\CC_LEDPWM.h"

//Global Variables Declaration
	CC_LEDPWM_SoftPwm_t  CC_LEDPWM_Strip;
	const uint8_t CC_LEDPWM_TotalStrips=CC_LEDPWM_TOTALSTRIPS;
extern	const CC_LED_StripLedFuncts_t CC_ML_LedsStripsFunctions;


//Functions
void CC_LEDPWM_Init(CC_LEDPWM_SoftPwm_t* const pStripControl)
//Initializing the strip's control structure
{
	uint8_t i=0;

	pStripControl->Control.BaseCounts=CC_LEDPWM_SOFTPWMBASECOUNTS;
	pStripControl->Control.Counter=0;

	while(i<CC_LEDPWM_TOTALSTRIPS)
	{
		pStripControl->Strip[i].RedDuty=CC_LEDPWM_INITDUTY;
		pStripControl->Strip[i].GreenDuty=CC_LEDPWM_INITDUTY;
		pStripControl->Strip[i].BlueDuty=CC_LEDPWM_INITDUTY;
		i++;
	}
}

void CC_LEDPWM_CntrCalculus(void* const param1, void* const param2, void* const param3)
//Calculus of the equivalent counts to be reached to accomplish with the given duty
//1st parameter is the struct to manage the strips and 2nd is the number of strips
{
	CC_LEDPWM_SoftPwm_t* const pStripData=(CC_LEDPWM_SoftPwm_t*)param1;
	const uint8_t NumStrips=*((uint8_t*)param2);					// Casting and dereference
	uint8_t i=0;

	while (i<NumStrips)
	{
		pStripData->Strip[i].RedCounts=(pStripData->Strip[i].RedDuty*pStripData->Control.BaseCounts)/100;
		pStripData->Strip[i].GreenCounts=(pStripData->Strip[i].GreenDuty*pStripData->Control.BaseCounts)/100;
		pStripData->Strip[i].BlueCounts=(pStripData->Strip[i].BlueDuty*pStripData->Control.BaseCounts)/100;
		i++;
	}
}

void CC_LEDPWM_IncreaseCntr(void* const param1, void* const param2, void* const param3)
{
	CC_LEDPWM_SoftPwm_t* const pStripData=(CC_LEDPWM_SoftPwm_t*) param1;
	pStripData->Control.Counter++;
	if (pStripData->Control.Counter>pStripData->Control.BaseCounts)
	{
		pStripData->Control.Counter=0;
	}
}

void CC_LEDPWM_UpdatePwms(void* const param1, void* const param2, void* const param3)
{
	const CC_LEDPWM_SoftPwm_t* const pStripData=(CC_LEDPWM_SoftPwm_t*)param1;
//	const CC_LED_StripLedFuncts_t* const pStripFuncts=(CC_LED_StripLedFuncts_t*)param2;
	uint8_t i=0;

	while(i<CC_LEDPWM_TOTALSTRIPS)
	{
		if (pStripData->Control.Counter<pStripData->Strip[i].RedCounts)
		{
			(*CC_ML_LedsStripsFunctions.pRedLedOnFunction[i])();
//			(*pStripFuncts->pRedLedOnFunction[i])();
		}
		else
		{
//			(*pStripFuncts->pRedLedOffFunction[i])();
			(*CC_ML_LedsStripsFunctions.pRedLedOffFunction[i])();
		}
		if (pStripData->Control.Counter<pStripData->Strip[i].GreenCounts)
		{
//			(*pStripFuncts->pGreenLedOnFunction[i])();
			(*CC_ML_LedsStripsFunctions.pGreenLedOnFunction[i])();
		}
		else
		{
//			(*pStripFuncts->pGreenLedOffFunction[i])();
			(*CC_ML_LedsStripsFunctions.pGreenLedOffFunction[i])();
		}
		if (pStripData->Control.Counter<pStripData->Strip[i].BlueCounts)
		{
//			(*pStripFuncts->pBlueLedOnFunction[i])();
			(*CC_ML_LedsStripsFunctions.pBlueLedOnFunction[i])();
		}
		else
		{
//			(*pStripFuncts->pBlueLedOffFunction[i])();
			(*CC_ML_LedsStripsFunctions.pBlueLedOffFunction[i])();
		}
		i++;
	}
}

