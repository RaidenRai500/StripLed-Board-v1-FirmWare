/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DIP_SW1_Pin GPIO_PIN_13
#define DIP_SW1_GPIO_Port GPIOC
#define DIP_SW2_Pin GPIO_PIN_14
#define DIP_SW2_GPIO_Port GPIOC
#define DIP_SW3_Pin GPIO_PIN_15
#define DIP_SW3_GPIO_Port GPIOC
#define DIP_SW4_Pin GPIO_PIN_0
#define DIP_SW4_GPIO_Port GPIOA
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOA
#define B10_Pin GPIO_PIN_2
#define B10_GPIO_Port GPIOA
#define G10_Pin GPIO_PIN_3
#define G10_GPIO_Port GPIOA
#define R10_Pin GPIO_PIN_4
#define R10_GPIO_Port GPIOA
#define B9_Pin GPIO_PIN_5
#define B9_GPIO_Port GPIOA
#define G9_Pin GPIO_PIN_6
#define G9_GPIO_Port GPIOA
#define R9_Pin GPIO_PIN_7
#define R9_GPIO_Port GPIOA
#define B8_Pin GPIO_PIN_2
#define B8_GPIO_Port GPIOB
#define G8_Pin GPIO_PIN_10
#define G8_GPIO_Port GPIOB
#define R8_Pin GPIO_PIN_11
#define R8_GPIO_Port GPIOB
#define B7_Pin GPIO_PIN_12
#define B7_GPIO_Port GPIOB
#define G7_Pin GPIO_PIN_13
#define G7_GPIO_Port GPIOB
#define R7_Pin GPIO_PIN_14
#define R7_GPIO_Port GPIOB
#define B6_Pin GPIO_PIN_15
#define B6_GPIO_Port GPIOB
#define G6_Pin GPIO_PIN_8
#define G6_GPIO_Port GPIOA
#define R6_Pin GPIO_PIN_6
#define R6_GPIO_Port GPIOC
#define B5_Pin GPIO_PIN_7
#define B5_GPIO_Port GPIOC
#define G5_Pin GPIO_PIN_11
#define G5_GPIO_Port GPIOA
#define R5_Pin GPIO_PIN_12
#define R5_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_13
#define SWCLK_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_14
#define SWDIO_GPIO_Port GPIOA
#define B4_Pin GPIO_PIN_15
#define B4_GPIO_Port GPIOA
#define G4_Pin GPIO_PIN_0
#define G4_GPIO_Port GPIOD
#define R4_Pin GPIO_PIN_1
#define R4_GPIO_Port GPIOD
#define B3_Pin GPIO_PIN_2
#define B3_GPIO_Port GPIOD
#define G3_Pin GPIO_PIN_3
#define G3_GPIO_Port GPIOD
#define R3_Pin GPIO_PIN_3
#define R3_GPIO_Port GPIOB
#define B2_Pin GPIO_PIN_4
#define B2_GPIO_Port GPIOB
#define G2_Pin GPIO_PIN_5
#define G2_GPIO_Port GPIOB
#define R2_Pin GPIO_PIN_6
#define R2_GPIO_Port GPIOB
#define B1_Pin GPIO_PIN_7
#define B1_GPIO_Port GPIOB
#define G1_Pin GPIO_PIN_8
#define G1_GPIO_Port GPIOB
#define R1_Pin GPIO_PIN_9
#define R1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
