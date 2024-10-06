/*
 * CCLED.c
 *
 *  Created on: Sep 7, 2024
 *      Author: Admin
 */
//Headers
#include "Drivers\CC_LED.h"

//Global Variables Declaration
CC_LED_Strip_t CC_LED_hStrip[CC_LED_MAX_STRIPS];		//Vector to manage several strip leds

//Functions
void CC_LED_InitStrips(void)
{
	uint8_t index=0;
	for (index=0; index<CC_LED_MAX_STRIPS; index++)
	{
		CC_LED_hStrip[index].color=BLACK;
		CC_LED_hStrip[index].number=index+1;
	}
}
void CC_LED_UpdateStrips(void)
{
	static uint8_t i=0;

	CC_LED_SetColorAndStrip(&CC_LED_hStrip[i]);
	i++;
	if (i==CC_LED_MAX_STRIPS)
	{
		  i =0;
	}
}
//Common actions
void CC_LED_SetColorAndStrip(const CC_LED_Strip_t* const StripData)
//Setting strip led colors without PWM
{
	// Error protection
	if( (StripData->number>CC_LED_MAX_STRIPS) || (StripData->number==0) )	// Checking parameters input
	{
		return;
	}
	if(StripData->color<RED||StripData->color>BLACK)	//Fastest way to check if the color parameter is outside the enum definition.
	{
		return;
	}
	// Body
	switch (StripData->number)
	{
	case 1:
		CC_LED_SetColorStrip1(StripData->color);
		break;
	case 2:
		CC_LED_SetColorStrip2(StripData->color);
		break;
	case 3:
		CC_LED_SetColorStrip3(StripData->color);
		break;
	case 4:
		CC_LED_SetColorStrip4(StripData->color);
		break;
	case 5:
		CC_LED_SetColorStrip5(StripData->color);
		break;
	case 6:
		CC_LED_SetColorStrip6(StripData->color);
		break;
	case 7:
		CC_LED_SetColorStrip7(StripData->color);
		break;
	case 8:
		CC_LED_SetColorStrip8(StripData->color);
		break;
	case 9:
		CC_LED_SetColorStrip9(StripData->color);
		break;
	case 10:
		CC_LED_SetColorStrip10(StripData->color);
		break;
	}
}

void CC_LED_SetColorStrip1(const CC_LED_Colors_t color)
{
	//Body
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip1Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip1Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip1Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip1Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip1Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip1Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip1White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip1();
		break;
	}
}
void CC_LED_SetColorStrip2(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip2Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip2Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip2Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip2Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip2Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip2Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip2White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip2();
		break;
	}
}
void CC_LED_SetColorStrip3(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip3Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip3Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip3Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip3Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip3Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip3Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip3White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip3();
		break;
	}
}
void CC_LED_SetColorStrip4(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip4Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip4Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip4Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip4Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip4Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip4Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip4White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip4();
		break;
	}
}
void CC_LED_SetColorStrip5(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip5Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip5Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip5Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip5Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip5Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip5Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip5White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip5();
		break;
	}
}
void CC_LED_SetColorStrip6(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip6Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip6Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip6Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip6Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip6Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip6Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip6White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip6();
		break;
	}
}
void CC_LED_SetColorStrip7(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip7Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip7Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip7Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip7Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip7Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip7Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip7White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip7();
		break;
	}
}
void CC_LED_SetColorStrip8(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip8Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip8Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip8Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip8Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip8Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip8Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip8White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip8();
		break;
	}
}
void CC_LED_SetColorStrip9(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip9Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip9Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip9Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip9Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip9Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip9Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip9White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip9();
		break;
	}
}
void CC_LED_SetColorStrip10(const CC_LED_Colors_t color)
{
	switch (color)
	{
	case RED:
		CC_LED_TurnOnStrip10Red();
		break;
	case GREEN:
		CC_LED_TurnOnStrip10Green();
		break;
	case BLUE:
		CC_LED_TurnOnStrip10Blue();
		break;
	case YELLOW:
		CC_LED_TurnOnStrip10Yellow();
		break;
	case PINK:
		CC_LED_TurnOnStrip10Pink();
		break;
	case CYAN:
		CC_LED_TurnOnStrip10Cyan();
		break;
	case WHITE:
		CC_LED_TurnOnStrip10White();
		break;
	case BLACK:
		CC_LED_TurnOffStrip10();
		break;
	}
}
//1st strip actions
void CC_LED_TurnOnStrip1Red(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip1Green(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip1Blue(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip1White(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip1Yellow(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip1Pink(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip1Cyan(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip1(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
}
//2nd strip actions
void CC_LED_TurnOnStrip2Red(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip2Green(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip2Blue(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip2White(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip2Yellow(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip2Pink(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip2Cyan(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip2(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}
//3rd strip actions
void CC_LED_TurnOnStrip3Red(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip3Green(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip3Blue(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip3White(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip3Yellow(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip3Pink(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip3Cyan(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip3(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_RESET);
}
//4th strip actions
void CC_LED_TurnOnStrip4Red(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip4Green(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip4Blue(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip4White(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip4Yellow(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip4Pink(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip4Cyan(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip4(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_RESET);
}
//5th strip actions
void CC_LED_TurnOnStrip5Red(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip5Green(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip5Blue(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip5White(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip5Yellow(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip5Pink(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip5Cyan(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip5(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_RESET);
}
//6th strip actions
void CC_LED_TurnOnStrip6Red(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip6Green(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip6Blue(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip6White(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip6Yellow(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip6Pink(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip6Cyan(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip6(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_RESET);
}
//7th strip actions
void CC_LED_TurnOnStrip7Red(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip7Green(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip7Blue(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip7White(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip7Yellow(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip7Pink(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip7Cyan(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip7(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_RESET);
}
//8th strip actions
void CC_LED_TurnOnStrip8Red(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip8Green(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip8Blue(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip8White(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip8Yellow(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip8Pink(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip8Cyan(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip8(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_RESET);
}
//9th strip actions
void CC_LED_TurnOnStrip9Red(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip9Green(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip9Blue(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip9White(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip9Yellow(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip9Pink(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip9Cyan(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip9(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_RESET);
}
//10th strip actions
void CC_LED_TurnOnStrip10Red(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip10Green(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip10Blue(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip10White(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip10Yellow(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_RESET);
}
void CC_LED_TurnOnStrip10Pink(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOnStrip10Cyan(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_SET);
}
void CC_LED_TurnOffStrip10(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_RESET);
}

//Single led action
//Strip1
inline void CC_LED_TurnOnRedOnStrip1(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip1(void)
{
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip1(void)
{
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip1(void)
{
	  HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip1(void)
{
	  HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip1(void)
{
	  HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, GPIO_PIN_RESET);
}
//Strip2
inline void CC_LED_TurnOnRedOnStrip2(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip2(void)
{
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip2(void)
{
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip2(void)
{
	  HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip2(void)
{
	  HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip2(void)
{
	  HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, GPIO_PIN_RESET);
}
//Strip3
inline void CC_LED_TurnOnRedOnStrip3(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip3(void)
{
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip3(void)
{
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip3(void)
{
	  HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip3(void)
{
	  HAL_GPIO_WritePin(G3_GPIO_Port, G3_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip3(void)
{
	  HAL_GPIO_WritePin(B3_GPIO_Port, B3_Pin, GPIO_PIN_RESET);
}
//Strip4
inline void CC_LED_TurnOnRedOnStrip4(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip4(void)
{
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip4(void)
{
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip4(void)
{
	  HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip4(void)
{
	  HAL_GPIO_WritePin(G4_GPIO_Port, G4_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip4(void)
{
	  HAL_GPIO_WritePin(B4_GPIO_Port, B4_Pin, GPIO_PIN_RESET);
}
//Strip5
inline void CC_LED_TurnOnRedOnStrip5(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip5(void)
{
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip5(void)
{
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip5(void)
{
	  HAL_GPIO_WritePin(R5_GPIO_Port, R5_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip5(void)
{
	  HAL_GPIO_WritePin(G5_GPIO_Port, G5_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip5(void)
{
	  HAL_GPIO_WritePin(B5_GPIO_Port, B5_Pin, GPIO_PIN_RESET);
}
//Strip6
inline void CC_LED_TurnOnRedOnStrip6(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip6(void)
{
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip6(void)
{
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip6(void)
{
	  HAL_GPIO_WritePin(R6_GPIO_Port, R6_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip6(void)
{
	  HAL_GPIO_WritePin(G6_GPIO_Port, G6_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip6(void)
{
	  HAL_GPIO_WritePin(B6_GPIO_Port, B6_Pin, GPIO_PIN_RESET);
}
//Strip7
inline void CC_LED_TurnOnRedOnStrip7(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip7(void)
{
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip7(void)
{
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip7(void)
{
	  HAL_GPIO_WritePin(R7_GPIO_Port, R7_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip7(void)
{
	  HAL_GPIO_WritePin(G7_GPIO_Port, G7_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip7(void)
{
	  HAL_GPIO_WritePin(B7_GPIO_Port, B7_Pin, GPIO_PIN_RESET);
}
//Strip8
inline void CC_LED_TurnOnRedOnStrip8(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip8(void)
{
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip8(void)
{
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip8(void)
{
	  HAL_GPIO_WritePin(R8_GPIO_Port, R8_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip8(void)
{
	  HAL_GPIO_WritePin(G8_GPIO_Port, G8_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip8(void)
{
	  HAL_GPIO_WritePin(B8_GPIO_Port, B8_Pin, GPIO_PIN_RESET);
}
//Strip9
inline void CC_LED_TurnOnRedOnStrip9(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip9(void)
{
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip9(void)
{
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip9(void)
{
	  HAL_GPIO_WritePin(R9_GPIO_Port, R9_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip9(void)
{
	  HAL_GPIO_WritePin(G9_GPIO_Port, G9_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip9(void)
{
	  HAL_GPIO_WritePin(B9_GPIO_Port, B9_Pin, GPIO_PIN_RESET);
}
//Strip10
inline void CC_LED_TurnOnRedOnStrip10(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnGreenOnStrip10(void)
{
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOnBlueOnStrip10(void)
{
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_SET);
}
inline void CC_LED_TurnOffRedOnStrip10(void)
{
	  HAL_GPIO_WritePin(R10_GPIO_Port, R10_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffGreenOnStrip10(void)
{
	  HAL_GPIO_WritePin(G10_GPIO_Port, G10_Pin, GPIO_PIN_RESET);
}
inline void CC_LED_TurnOffBlueOnStrip10(void)
{
	  HAL_GPIO_WritePin(B10_GPIO_Port, B10_Pin, GPIO_PIN_RESET);
}




























