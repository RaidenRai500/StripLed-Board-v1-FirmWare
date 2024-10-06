/*
 * CC_DIPSW.h
 *
 *  Created on: Sep 8, 2024
 *      Author: Admin
 */
#ifndef INC_CC_DIPSW_H_
	#define INC_CC_DIPSW_H_
	//Headers
	#include "main.h"
	#include "stm32g0xx_it.h"

	//Constants

	//Data types
	struct CC_DIPSW_contacts
	{
		uint8_t bit0:1;
		uint8_t bit1:1;
		uint8_t bit2:1;
		uint8_t bit3:1;
		uint8_t bit4:1;
		uint8_t bit5:1;
		uint8_t bit6:1;
		uint8_t bit7:1;
	};
	union CC_DIPSW_DipSw_t
	{
		uint8_t all;
		struct CC_DIPSW_contacts bits;
	};
	typedef union CC_DIPSW_DipSw_t CC_DIPSW_DipSw_t;

	//Variables Prototypes
	extern CC_DIPSW_DipSw_t CC_DIPSW_DipSwitch;				//Header with the DIP Switch data

	//Function Prototypes
	void CC_DIPSW_GetDipSwitch1pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch2pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch3pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch4pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch5pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch6pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch7pos(CC_DIPSW_DipSw_t* pdata);
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* pdata);

#endif /* INC_CC_DIPSW_H_ */
