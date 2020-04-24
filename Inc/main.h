/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "FIFOBuffer.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

typedef struct{
	TIM_HandleTypeDef* pTimer2;
	TIM_HandleTypeDef* pTimer3;
	TIM_HandleTypeDef* pTimer4;
	TIM_HandleTypeDef* pTimer5;
	TIM_HandleTypeDef* pTimer8;
	UART_HandleTypeDef* pUART1;
}HardwareResource;

extern HardwareResource g_HR;
extern FIFOBufferInstance g_TxBuffer,g_RxBuffer;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENCODER_D1_Pin GPIO_PIN_0
#define ENCODER_D1_GPIO_Port GPIOA
#define ENCODER_D2_Pin GPIO_PIN_1
#define ENCODER_D2_GPIO_Port GPIOA
#define ENCODER_B1_Pin GPIO_PIN_6
#define ENCODER_B1_GPIO_Port GPIOA
#define ENCODER_B2_Pin GPIO_PIN_7
#define ENCODER_B2_GPIO_Port GPIOA
#define MOTOR_A2_Pin GPIO_PIN_4
#define MOTOR_A2_GPIO_Port GPIOC
#define MOTOR_C2_Pin GPIO_PIN_5
#define MOTOR_C2_GPIO_Port GPIOC
#define MOTOR_B2_Pin GPIO_PIN_0
#define MOTOR_B2_GPIO_Port GPIOB
#define MOTOR_D2_Pin GPIO_PIN_1
#define MOTOR_D2_GPIO_Port GPIOB
#define MOTOR_A1_Pin GPIO_PIN_6
#define MOTOR_A1_GPIO_Port GPIOC
#define MOTOR_B1_Pin GPIO_PIN_7
#define MOTOR_B1_GPIO_Port GPIOC
#define MOTOR_C1_Pin GPIO_PIN_8
#define MOTOR_C1_GPIO_Port GPIOC
#define MOTOR_D1_Pin GPIO_PIN_9
#define MOTOR_D1_GPIO_Port GPIOC
#define ENCODER_A1_Pin GPIO_PIN_15
#define ENCODER_A1_GPIO_Port GPIOA
#define ENCODER_A2_Pin GPIO_PIN_3
#define ENCODER_A2_GPIO_Port GPIOB
#define ENCODER_C1_Pin GPIO_PIN_6
#define ENCODER_C1_GPIO_Port GPIOB
#define ENCODER_C2_Pin GPIO_PIN_7
#define ENCODER_C2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
