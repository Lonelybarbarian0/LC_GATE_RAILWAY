/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define Alarm_Trigger1_Pin GPIO_PIN_0
#define Alarm_Trigger1_GPIO_Port GPIOC
#define Lock_Trigger_Pin GPIO_PIN_2
#define Lock_Trigger_GPIO_Port GPIOC
#define SIDE2_RX2_Pin GPIO_PIN_1
#define SIDE2_RX2_GPIO_Port GPIOA
#define SIDE1_RX2_Pin GPIO_PIN_3
#define SIDE1_RX2_GPIO_Port GPIOA
#define BOOM1_ADC_Pin GPIO_PIN_4
#define BOOM1_ADC_GPIO_Port GPIOA
#define BOOM2_ADC_Pin GPIO_PIN_5
#define BOOM2_ADC_GPIO_Port GPIOA
#define FREE_ADC1_Pin GPIO_PIN_4
#define FREE_ADC1_GPIO_Port GPIOC
#define FREE_ADC2_Pin GPIO_PIN_5
#define FREE_ADC2_GPIO_Port GPIOC
#define FREE_ADC3_Pin GPIO_PIN_0
#define FREE_ADC3_GPIO_Port GPIOB
#define BOOM1_LS11_Pin GPIO_PIN_12
#define BOOM1_LS11_GPIO_Port GPIOB
#define BOOM1_LS11_EXTI_IRQn EXTI15_10_IRQn
#define BOOM1_LS12_Pin GPIO_PIN_13
#define BOOM1_LS12_GPIO_Port GPIOB
#define BOOM1_LS12_EXTI_IRQn EXTI15_10_IRQn
#define BOOM1_LS21_Pin GPIO_PIN_14
#define BOOM1_LS21_GPIO_Port GPIOB
#define BOOM1_LS21_EXTI_IRQn EXTI15_10_IRQn
#define BOOM1_LS22_Pin GPIO_PIN_15
#define BOOM1_LS22_GPIO_Port GPIOB
#define BOOM1_LS22_EXTI_IRQn EXTI15_10_IRQn
#define BOOM2_LS11_Pin GPIO_PIN_6
#define BOOM2_LS11_GPIO_Port GPIOC
#define BOOM2_LS11_EXTI_IRQn EXTI9_5_IRQn
#define BOOM2_LS12_Pin GPIO_PIN_7
#define BOOM2_LS12_GPIO_Port GPIOC
#define BOOM2_LS12_EXTI_IRQn EXTI9_5_IRQn
#define BOOM2_LS21_Pin GPIO_PIN_8
#define BOOM2_LS21_GPIO_Port GPIOC
#define BOOM2_LS21_EXTI_IRQn EXTI9_5_IRQn
#define BOOM2_LS22_Pin GPIO_PIN_9
#define BOOM2_LS22_GPIO_Port GPIOC
#define BOOM2_LS22_EXTI_IRQn EXTI9_5_IRQn
#define SIDE1_RX1_Pin GPIO_PIN_10
#define SIDE1_RX1_GPIO_Port GPIOA
#define SIDE2_RX1_Pin GPIO_PIN_11
#define SIDE2_RX1_GPIO_Port GPIOC
#define Lock_Feedback1_Pin GPIO_PIN_3
#define Lock_Feedback1_GPIO_Port GPIOB
#define Lock_Feedback1_EXTI_IRQn EXTI3_IRQn
#define Lock_Feedback2_Pin GPIO_PIN_4
#define Lock_Feedback2_GPIO_Port GPIOB
#define Lock_Feedback2_EXTI_IRQn EXTI4_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
