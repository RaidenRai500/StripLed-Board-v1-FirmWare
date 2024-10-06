/*
 * CC_LEDPWM.h
 *
 *  Created on: Sep 26, 2024
 *      Author: Admin
 */

#ifndef INC_APPLICATION_CC_LEDPWM_H_
	#define INC_APPLICATION_CC_LEDPWM_H_
	//Headers
	#include "MiddleLayer\CC_ML.h"	//Definitions to work with drivers

	//Constants
	#define CC_LEDPWM_SOFTPWMBASECOUNTS 100						//Equivalent counts for the soft PWM
	#define CC_LEDPWM_INITDUTY 0								//Duty cycle by default
	#define CC_LEDPWM_TOTALSTRIPS 10							//Number of led strips
//	const uint8_t CC_LEDPWM_TotalStrips=CC_LEDPWM_TOTALSTRIPS;	//Number of led strips

	//Data types
	struct CC_LEDPWM_Strip_t
	{
		uint8_t RedDuty;		//Duty cycle for the red led. Value from 0 to 100
		uint8_t GreenDuty;		//Same for green led
		uint8_t BlueDuty;		//Same for blue led
		uint32_t RedCounts;		//Equivalent counts according duty for the red led
		uint32_t GreenCounts;
		uint32_t BlueCounts;
	};
	typedef struct CC_LEDPWM_Strip_t CC_LEDPWM_Strip_t;

	struct CC_LEDPWM_SoftPwmControl_t
	{
		uint32_t Counter;			//Counts ongoing
		uint32_t BaseCounts;		//Total counts equivalent to 100% duty
	};
	typedef struct CC_LEDPWM_SoftPwmControl_t CC_LEDPWM_SoftPwmControl_t;

	struct CC_LEDPWM_SoftPwm_t
	{
		CC_LEDPWM_Strip_t Strip[CC_LEDPWM_TOTALSTRIPS];
		CC_LEDPWM_SoftPwmControl_t Control;
	};
	typedef struct CC_LEDPWM_SoftPwm_t CC_LEDPWM_SoftPwm_t;

	struct CC_LED_StripLedFuncts_t
		{
		void(*pRedLedOnFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pRedLedOffFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pGreenLedOnFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pGreenLedOffFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pBlueLedOnFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		void(*pBlueLedOffFunction[CC_LEDPWM_TOTALSTRIPS])(void);
		};
	typedef struct CC_LED_StripLedFuncts_t CC_LED_StripLedFuncts_t;

	//Variables Prototypes
	extern CC_LEDPWM_SoftPwm_t  CC_LEDPWM_Strip;
	extern const uint8_t CC_LEDPWM_TotalStrips;

	//Function Prototypes
	void CC_LEDPWM_Init(CC_LEDPWM_SoftPwm_t*);
	void CC_LEDPWM_IncreaseCntr(void*, void*, void*);
	void CC_LEDPWM_UpdatePwms(void*, void*, void*);
	void CC_LEDPWM_CntrCalculus(void*, void*, void*);

#endif /* INC_APPLICATION_CC_LEDPWM_H_ */
