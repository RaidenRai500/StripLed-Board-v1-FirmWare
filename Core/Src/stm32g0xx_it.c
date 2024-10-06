/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32g0xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32g0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "Application\CC_SCHDLR.h"
//#include "Application\CC_LEDPWM.h"
//#include "MiddleLayer\CC_ML.h"
//#include "Application\CC_LEDPWM.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern FDCAN_HandleTypeDef hfdcan2;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim14;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32G0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32g0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM7 and LPTIM2 global Interrupt.
  */
void TIM7_LPTIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM7_LPTIM2_IRQn 0 */
//Timer used to generate the strip leds soft-PWM. The scheduler running over timer14
//was unable to run all the tasks fast enough.
  /* USER CODE END TIM7_LPTIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim7);
  /* USER CODE BEGIN TIM7_LPTIM2_IRQn 1 */
	CC_LEDPWM_SoftPwm_t* 	pCC_LEDPWM_SoftPwm;									//Pointer to strip leds control data
	pCC_LEDPWM_SoftPwm=&CC_LEDPWM_Strip;

	CC_LEDPWM_UpdatePwms((void*)pCC_LEDPWM_SoftPwm, (void*)NULL, (void*)NULL);
	CC_LEDPWM_IncreaseCntr((void*)pCC_LEDPWM_SoftPwm, (void*)NULL, (void*)NULL);
  /* USER CODE END TIM7_LPTIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM14 global interrupt.
  */
void TIM14_IRQHandler(void)
{
  /* USER CODE BEGIN TIM14_IRQn 0 */
//Note that no reentry is allowed even after to clear the interrupt's flag.
//(HAL_TIM_IRQHandler(&htim14) does it).

//Any interruption with the same or low priority aren't allowed while the ISR
//is executed (the entire code inside must be executed)

//TMR14 is not stopped by nothing, it keeps working and generating flags,
//however the code executed before the flag cleaning should be as short as possible.
//Remember to keep the TIM14 priority as high as possible. At least higher than
//peripherals.

//First action taken is to clear the interrupt flag. Then the scheduler is
//executed if there weren't too many overflows, and afterwards is
//checked if another TMR14 interrupt event has happened by checking again
//the interrupt flag. If so, it means that the procedure lasted too much
//and it is increased the missed interrupts count.

	CC_ML_StartTimer(&CC_ML_SCHEDULER_CHRONO_HANDLER);
  /* USER CODE END TIM14_IRQn 0 */
  HAL_TIM_IRQHandler(&htim14);
  /* USER CODE BEGIN TIM14_IRQn 1 */
	uint8_t current_task;

	current_task=CC_SCHDLR_FastScheduler.TaskOngoing;
	//Overflowing stop
	if(CC_SCHDLR_FastScheduler.MissIntCnt>CC_SCHDLR_MAX_ALLOWED_MISS_INT)	//Check the number of overflows
	{
	//INSERT AN ERROR LOG HERE
		return;																//After a limit Scheduler wont work anymore
	}
	CC_SCHDLR_Scheduler(((void*)&CC_SCHDLR_FastScheduler), (void*)NULL, (void*)NULL);
	CC_ML_StopTimer(&CC_ML_SCHEDULER_CHRONO_HANDLER);
	CC_SCHDLR_SchedulerUsage(&CC_SCHDLR_MainSchedulerUsage, current_task); 	//Keep in mind that the scheduler update the current task, so it needs to work with non-updated current task
	CC_TMR_SetTimer(&CC_ML_SCHEDULER_CHRONO_HANDLER, 0);				//Reset counter timer used to calculate the task's usage

  /* USER CODE END TIM14_IRQn 1 */
}

/**
  * @brief This function handles TIM16, FDCAN1_IT0 and FDCAN2_IT0 Interrupt.
  */
void TIM16_FDCAN_IT0_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_FDCAN_IT0_IRQn 0 */

  /* USER CODE END TIM16_FDCAN_IT0_IRQn 0 */
  HAL_FDCAN_IRQHandler(&hfdcan2);
  /* USER CODE BEGIN TIM16_FDCAN_IT0_IRQn 1 */

  /* USER CODE END TIM16_FDCAN_IT0_IRQn 1 */
}

/**
  * @brief This function handles TIM17, FDCAN1_IT1 and FDCAN2_IT1 Interrupt.
  */
void TIM17_FDCAN_IT1_IRQHandler(void)
{
  /* USER CODE BEGIN TIM17_FDCAN_IT1_IRQn 0 */

  /* USER CODE END TIM17_FDCAN_IT1_IRQn 0 */
  HAL_FDCAN_IRQHandler(&hfdcan2);
  /* USER CODE BEGIN TIM17_FDCAN_IT1_IRQn 1 */

  /* USER CODE END TIM17_FDCAN_IT1_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt / USART1 wake-up interrupt through EXTI line 25.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
