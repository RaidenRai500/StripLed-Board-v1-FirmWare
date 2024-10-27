/*
 * CC_LEDPWM.c
 *
 *  Created on: Sep 26, 2024
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
#include "Application\CC_LEDPWM.h"

//GLOBAL VARIABLES DECLARATION
	CC_LEDPWM_SoftPwm_t  CC_LEDPWM_Strip;
	const uint8_t CC_LEDPWM_TotalStrips=CC_LEDPWM_TOTALSTRIPS;
	extern const CC_LED_StripLedFuncts_t CC_ML_LedsStripsFunctions;


//FUNCTIONS
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
	const CC_LED_StripLedFuncts_t* const pStripFuncts=(CC_LED_StripLedFuncts_t*)param2;
	uint8_t i=0;

	while(i<CC_LEDPWM_TOTALSTRIPS)
	{
		if (pStripData->Control.Counter<pStripData->Strip[i].RedCounts)
		{
			(*pStripFuncts->pRedLedOnFunction[i])();
		}
		else
		{
			(*pStripFuncts->pRedLedOffFunction[i])();
		}
		if (pStripData->Control.Counter<pStripData->Strip[i].GreenCounts)
		{
			(*pStripFuncts->pGreenLedOnFunction[i])();
		}
		else
		{
			(*pStripFuncts->pGreenLedOffFunction[i])();
		}
		if (pStripData->Control.Counter<pStripData->Strip[i].BlueCounts)
		{
			(*pStripFuncts->pBlueLedOnFunction[i])();
		}
		else
		{
			(*pStripFuncts->pBlueLedOffFunction[i])();
		}
		i++;
	}
}

