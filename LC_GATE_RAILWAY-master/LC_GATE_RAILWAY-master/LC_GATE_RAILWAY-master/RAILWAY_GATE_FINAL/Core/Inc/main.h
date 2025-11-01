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
#define BOOM1_ADC_Pin GPIO_PIN_4
#define BOOM1_ADC_GPIO_Port GPIOA
#define BOOM2_ADC_Pin GPIO_PIN_5
#define BOOM2_ADC_GPIO_Port GPIOA
#define BYPASS_SW_NC_Pin GPIO_PIN_1
#define BYPASS_SW_NC_GPIO_Port GPIOB
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
#define USB_D__Pin GPIO_PIN_11
#define USB_D__GPIO_Port GPIOA
#define USB_D_A12_Pin GPIO_PIN_12
#define USB_D_A12_GPIO_Port GPIOA
#define SIDE2_RX1_Pin GPIO_PIN_11
#define SIDE2_RX1_GPIO_Port GPIOC
#define LOCK_EKT_NO_Pin GPIO_PIN_3
#define LOCK_EKT_NO_GPIO_Port GPIOB
#define LOCK_EKT_NO_EXTI_IRQn EXTI3_IRQn
#define BYPASS_SW_NO_Pin GPIO_PIN_4
#define BYPASS_SW_NO_GPIO_Port GPIOB
#define BYPASS_SW_NO_EXTI_IRQn EXTI4_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
