/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

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
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void clearAllClock();
void setNumberOnClock(int number);
void clearNumberOnClock(int number);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  clearAllClock();
  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  int secondsInTwelve = 0;
  int minutesInTwelve = 0;

  while (1)
  {
    //   HAL_GPIO_WritePin(GPIOA, _12_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _12_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _1_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _1_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _2_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _2_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _3_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _3_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _4_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _4_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _5_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _5_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _6_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _6_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _7_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _7_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _8_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _8_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _9_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _9_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _10_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _10_Pin, GPIO_PIN_RESET);
    //   HAL_GPIO_WritePin(GPIOA, _11_Pin, GPIO_PIN_SET);
    //   HAL_Delay(1000);

    //   HAL_GPIO_WritePin(GPIOA, _11_Pin, GPIO_PIN_RESET);

    seconds++;
    if (seconds == 60)
    {
      seconds = 0;
      minutes++;
    }
    if (minutes == 60)
    {
      minutes = 0;
      hours++;
    }
    if (hours == 12)
    {
      hours = 0;
    }

    clearAllClock();
    // second handler
    if (seconds < 5)
    {
      setNumberOnClock(12);
    }
    else
    {
      secondsInTwelve = seconds / 5;
      setNumberOnClock(secondsInTwelve);
    }
    // minute handler
    if (minutes < 5)
    {
      setNumberOnClock(12);
    }
    else
    {
      minutesInTwelve = minutes / 5;
      setNumberOnClock(minutesInTwelve);
    }
    // hour handler
    if (hours < 1)
    {
      setNumberOnClock(12);
    }
    else
    {
      setNumberOnClock(hours);
    }
    HAL_Delay(1000);
  } // end of while loop
  /* USER CODE END 3 */
}

void clearAllClock()
{
  HAL_GPIO_WritePin(GPIOA, _12_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _3_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _4_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _5_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _6_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _7_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _8_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _9_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _10_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, _11_Pin, GPIO_PIN_RESET);
}
void setNumberOnClock(int num)
{
  if (num == 12)
    HAL_GPIO_WritePin(GPIOA, _12_Pin, GPIO_PIN_SET);

  if (num == 1)
    HAL_GPIO_WritePin(GPIOA, _1_Pin, GPIO_PIN_SET);

  if (num == 2)
    HAL_GPIO_WritePin(GPIOA, _2_Pin, GPIO_PIN_SET);

  if (num == 3)
    HAL_GPIO_WritePin(GPIOA, _3_Pin, GPIO_PIN_SET);

  if (num == 4)
    HAL_GPIO_WritePin(GPIOA, _4_Pin, GPIO_PIN_SET);

  if (num == 5)
    HAL_GPIO_WritePin(GPIOA, _5_Pin, GPIO_PIN_SET);

  if (num == 6)
    HAL_GPIO_WritePin(GPIOA, _6_Pin, GPIO_PIN_SET);

  if (num == 7)
    HAL_GPIO_WritePin(GPIOA, _7_Pin, GPIO_PIN_SET);

  if (num == 8)
    HAL_GPIO_WritePin(GPIOA, _8_Pin, GPIO_PIN_SET);

  if (num == 9)
    HAL_GPIO_WritePin(GPIOA, _9_Pin, GPIO_PIN_SET);

  if (num == 10)
    HAL_GPIO_WritePin(GPIOA, _10_Pin, GPIO_PIN_SET);

  if (num == 11)
    HAL_GPIO_WritePin(GPIOA, _11_Pin, GPIO_PIN_SET);
}

void clearNumberOnClock(int num)
{
  if (num == 12)
    HAL_GPIO_WritePin(GPIOA, _12_Pin, GPIO_PIN_RESET);
  if (num == 1)
    HAL_GPIO_WritePin(GPIOA, _1_Pin, GPIO_PIN_RESET);
  if (num == 2)
    HAL_GPIO_WritePin(GPIOA, _2_Pin, GPIO_PIN_RESET);
  if (num == 3)
    HAL_GPIO_WritePin(GPIOA, _3_Pin, GPIO_PIN_RESET);
  if (num == 4)
    HAL_GPIO_WritePin(GPIOA, _4_Pin, GPIO_PIN_RESET);
  if (num == 5)
    HAL_GPIO_WritePin(GPIOA, _5_Pin, GPIO_PIN_RESET);
  if (num == 6)
    HAL_GPIO_WritePin(GPIOA, _6_Pin, GPIO_PIN_RESET);
  if (num == 7)
    HAL_GPIO_WritePin(GPIOA, _7_Pin, GPIO_PIN_RESET);
  if (num == 8)
    HAL_GPIO_WritePin(GPIOA, _8_Pin, GPIO_PIN_RESET);
  if (num == 9)
    HAL_GPIO_WritePin(GPIOA, _9_Pin, GPIO_PIN_RESET);
  if (num == 10)
    HAL_GPIO_WritePin(GPIOA, _10_Pin, GPIO_PIN_RESET);
  if (num == 11)
    HAL_GPIO_WritePin(GPIOA, _11_Pin, GPIO_PIN_RESET);
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */
  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, _12_Pin | _1_Pin | _2_Pin | _3_Pin | _4_Pin | _5_Pin | _6_Pin | _7_Pin | _8_Pin | _9_Pin | _10_Pin | _11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : _12_Pin _1_Pin _2_Pin _3_Pin
                           _4_Pin _5_Pin _6_Pin _7_Pin
                           _8_Pin _9_Pin _10_Pin _11_Pin */
  GPIO_InitStruct.Pin = _12_Pin | _1_Pin | _2_Pin | _3_Pin | _4_Pin | _5_Pin | _6_Pin | _7_Pin | _8_Pin | _9_Pin | _10_Pin | _11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */
  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
