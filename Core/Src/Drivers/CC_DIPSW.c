/*
 * CC_DIPSW.c
 *
 *  Created on: Sep 8, 2024
 *      Author: Admin
 */
//Headers
#include "Drivers\CC_DIPSW.h"

//Global Variables Declaration
CC_DIPSW_DipSw_t CC_DIPSW_DipSwitch;				//Header with the DIP Switch data

//Functions
#ifdef DIP_SW1_Pin
	void CC_DIPSW_GetDipSwitch1pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
	}
#endif
#ifdef DIP_SW2_Pin
	void CC_DIPSW_GetDipSwitch2pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
	}
#endif
#ifdef DIP_SW3_Pin
	void CC_DIPSW_GetDipSwitch3pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pdata->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
	}
#endif
#ifdef DIP_SW4_Pin
	void CC_DIPSW_GetDipSwitch4pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pdata->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pdata->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
	}
#endif
#ifdef DIP_SW5_Pin
	void CC_DIPSW_GetDipSwitch5pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pdata->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pdata->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pdata->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
	}
#endif
#ifdef DIP_SW6_Pin
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pdata->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pdata->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pdata->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
		pdata->bits.bit5=HAL_GPIO_ReadPin(DIP_SW6_GPIO_Port, DIP_SW6_Pin);
	}
#endif
#ifdef DIP_SW7_Pin
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pdata->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pdata->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pdata->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
		pdata->bits.bit5=HAL_GPIO_ReadPin(DIP_SW6_GPIO_Port, DIP_SW6_Pin);
		pdata->bits.bit6=HAL_GPIO_ReadPin(DIP_SW7_GPIO_Port, DIP_SW7_Pin);
	}
#endif
#ifdef DIP_SW8_Pin
	void CC_DIPSW_GetDipSwitch8pos(CC_DIPSW_DipSw_t* const pdata)
	{
		pdata->bits.bit0=HAL_GPIO_ReadPin(DIP_SW1_GPIO_Port, DIP_SW1_Pin);
		pdata->bits.bit1=HAL_GPIO_ReadPin(DIP_SW2_GPIO_Port, DIP_SW2_Pin);
		pdata->bits.bit2=HAL_GPIO_ReadPin(DIP_SW3_GPIO_Port, DIP_SW3_Pin);
		pdata->bits.bit3=HAL_GPIO_ReadPin(DIP_SW4_GPIO_Port, DIP_SW4_Pin);
		pdata->bits.bit4=HAL_GPIO_ReadPin(DIP_SW5_GPIO_Port, DIP_SW5_Pin);
		pdata->bits.bit5=HAL_GPIO_ReadPin(DIP_SW6_GPIO_Port, DIP_SW6_Pin);
		pdata->bits.bit6=HAL_GPIO_ReadPin(DIP_SW7_GPIO_Port, DIP_SW7_Pin);
		pdata->bits.bit7=HAL_GPIO_ReadPin(DIP_SW8_GPIO_Port, DIP_SW8_Pin);
	}
#endif
