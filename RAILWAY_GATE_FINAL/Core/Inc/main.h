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
#define BOOM1_LS22_Pin GPIO_PIN_13
#define BOOM1_LS22_GPIO_Port GPIOC
#define BOOM1_LS11_Pin GPIO_PIN_2
#define BOOM1_LS11_GPIO_Port GPIOC
#define BOOM1_LS12_Pin GPIO_PIN_3
#define BOOM1_LS12_GPIO_Port GPIOC
#define S1_L2_Pin GPIO_PIN_1
#define S1_L2_GPIO_Port GPIOA
#define S2_L2_Pin GPIO_PIN_3
#define S2_L2_GPIO_Port GPIOA
#define BOOM1_ADC_Pin GPIO_PIN_4
#define BOOM1_ADC_GPIO_Port GPIOA
#define BOOM2_ADC_Pin GPIO_PIN_5
#define BOOM2_ADC_GPIO_Port GPIOA
#define BOOM2_LS22_Pin GPIO_PIN_1
#define BOOM2_LS22_GPIO_Port GPIOB
#define BOOM2_LS11_Pin GPIO_PIN_13
#define BOOM2_LS11_GPIO_Port GPIOB
#define BOOM2_LS12_Pin GPIO_PIN_14
#define BOOM2_LS12_GPIO_Port GPIOB
#define BOOM2_LS21_Pin GPIO_PIN_15
#define BOOM2_LS21_GPIO_Port GPIOB
#define S2_L1_Pin GPIO_PIN_10
#define S2_L1_GPIO_Port GPIOA
#define AT1_Pin GPIO_PIN_15
#define AT1_GPIO_Port GPIOA
#define AT_Pin GPIO_PIN_10
#define AT_GPIO_Port GPIOC
#define S1_L1_Pin GPIO_PIN_11
#define S1_L1_GPIO_Port GPIOC
#define LT_Pin GPIO_PIN_12
#define LT_GPIO_Port GPIOC
#define L_FB1_Pin GPIO_PIN_2
#define L_FB1_GPIO_Port GPIOD
#define L_FB2_Pin GPIO_PIN_3
#define L_FB2_GPIO_Port GPIOB
#define BOOM1_LS21_Pin GPIO_PIN_7
#define BOOM1_LS21_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
