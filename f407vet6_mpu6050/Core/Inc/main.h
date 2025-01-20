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
#define THUMB_FINGER_TEST_LED_Pin GPIO_PIN_2
#define THUMB_FINGER_TEST_LED_GPIO_Port GPIOE
#define INDEX_FINGER_TEST_LED_Pin GPIO_PIN_3
#define INDEX_FINGER_TEST_LED_GPIO_Port GPIOE
#define MIDDLE_FINGER_TEST_LED_Pin GPIO_PIN_4
#define MIDDLE_FINGER_TEST_LED_GPIO_Port GPIOE
#define RING_FINGER_TEST_LED_Pin GPIO_PIN_5
#define RING_FINGER_TEST_LED_GPIO_Port GPIOE
#define BABY_FINGER_TEST_LED_Pin GPIO_PIN_6
#define BABY_FINGER_TEST_LED_GPIO_Port GPIOE
#define MPU_BABY_FINGER_Pin GPIO_PIN_2
#define MPU_BABY_FINGER_GPIO_Port GPIOD
#define MPU_RING_FINGER_Pin GPIO_PIN_3
#define MPU_RING_FINGER_GPIO_Port GPIOD
#define MPU_MIDDLE_FINGER_Pin GPIO_PIN_4
#define MPU_MIDDLE_FINGER_GPIO_Port GPIOD
#define MPU_INDEX_FINGER_Pin GPIO_PIN_5
#define MPU_INDEX_FINGER_GPIO_Port GPIOD
#define MPU_THUMB_Pin GPIO_PIN_6
#define MPU_THUMB_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
