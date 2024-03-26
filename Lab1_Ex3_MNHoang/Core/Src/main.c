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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */

typedef enum
{
  STATE_GREEN,
  STATE_YELLOW,
  STATE_RED,
  STATE_YELLOW2
} TrafficLightState;

int counter = -1;
TrafficLightState state = STATE_GREEN;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  while (1)
  {
    switch (state)
    {
    case STATE_GREEN:
      if (counter <= 0)
      {
        // default GREEN ON, alternate RED ON
        HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_SET);      // Green on
        HAL_GPIO_WritePin(GPIOA, GREEN_R_Pin, GPIO_PIN_RESET);  // Green2 off
        HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);   // Yellow off
        HAL_GPIO_WritePin(GPIOA, YELLOW_R_Pin, GPIO_PIN_RESET); // Yellow2 off
        HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);      // Red off
        HAL_GPIO_WritePin(GPIOA, RED_R_Pin, GPIO_PIN_SET);      // Red2 on
        state = STATE_YELLOW;
        counter = 3;
      }
      break;

    case STATE_YELLOW:
      if (counter <= 0)
      {
        // default YELLOW transition
        HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);    // Green off
        HAL_GPIO_WritePin(GPIOA, GREEN_R_Pin, GPIO_PIN_RESET);  // Green2 off
        HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_SET);     // Yellow on
        HAL_GPIO_WritePin(GPIOA, YELLOW_R_Pin, GPIO_PIN_RESET); // Yellow2 off
        HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);      // Red off
        HAL_GPIO_WritePin(GPIOA, RED_R_Pin, GPIO_PIN_SET);      // Red2 on
        state = STATE_RED;
        counter = 2;
      }
      break;

    case STATE_RED:
      if (counter <= 0)
      {
        // default RED ON, alternate GREEN ON
        HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);    // Green off
        HAL_GPIO_WritePin(GPIOA, GREEN_R_Pin, GPIO_PIN_SET);    // Green2 on
        HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);   // Yellow off
        HAL_GPIO_WritePin(GPIOA, YELLOW_R_Pin, GPIO_PIN_RESET); // Yellow2 off
        HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_SET);        // Red on
        HAL_GPIO_WritePin(GPIOA, RED_R_Pin, GPIO_PIN_RESET);    // Red2 off
        state = STATE_YELLOW2;
        counter = 3;
      }
      break;

    case STATE_YELLOW2:
      if (counter <= 0)
      {
        // alternate YELLOW transition
        HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);   // Green off
        HAL_GPIO_WritePin(GPIOA, GREEN_R_Pin, GPIO_PIN_RESET); // Green2 off
        HAL_GPIO_WritePin(GPIOA, YELLOW_Pin, GPIO_PIN_RESET);  // Yellow off
        HAL_GPIO_WritePin(GPIOA, YELLOW_R_Pin, GPIO_PIN_SET);  // Yellow2 on
        HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_SET);       // Red on
        HAL_GPIO_WritePin(GPIOA, RED_R_Pin, GPIO_PIN_RESET);   // Red2 off
        state = STATE_GREEN;
        counter = 2;
      }
      break;
    }

    display7SEG(counter);
    counter--;
    if (counter < 0)
    {
      counter = 0;
    }
    HAL_Delay(1000);
  }
}

void display7SEG(int num)
{
  switch (num)
  {
  case 1:
    HAL_GPIO_WritePin(GPIOB, B_Pin | C_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, A_Pin | D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_SET);
    break;
  case 2:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | G_Pin | E_Pin | D_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, C_Pin | F_Pin, GPIO_PIN_SET);
    break;
  case 3:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | G_Pin | C_Pin | D_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, E_Pin | F_Pin, GPIO_PIN_SET);
    break;
  case 4:
    HAL_GPIO_WritePin(GPIOB, F_Pin | G_Pin | B_Pin | C_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, A_Pin | D_Pin | E_Pin, GPIO_PIN_SET);
    break;
  case 5:
    HAL_GPIO_WritePin(GPIOB, A_Pin | F_Pin | G_Pin | C_Pin | D_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, B_Pin | E_Pin, GPIO_PIN_SET);
    break;
  case 6:
    HAL_GPIO_WritePin(GPIOB, A_Pin | F_Pin | G_Pin | C_Pin | D_Pin | E_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, B_Pin, GPIO_PIN_SET);
    break;
  case 7:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_SET);
    break;
  case 8:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_RESET);
    break;
  case 9:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | F_Pin | G_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, E_Pin, GPIO_PIN_SET);
    break;
  default:
    HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOB, G_Pin, GPIO_PIN_SET);
    break;
  }
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
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, RED_Pin | YELLOW_Pin | GREEN_Pin | RED_R_Pin | YELLOW_R_Pin | GREEN_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : RED_Pin YELLOW_Pin GREEN_Pin RED_R_Pin
                           YELLOW_R_Pin GREEN_R_Pin */
  GPIO_InitStruct.Pin = RED_Pin | YELLOW_Pin | GREEN_Pin | RED_R_Pin | YELLOW_R_Pin | GREEN_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_Pin B_Pin C_Pin D_Pin
                           E_Pin F_Pin G_Pin */
  GPIO_InitStruct.Pin = A_Pin | B_Pin | C_Pin | D_Pin | E_Pin | F_Pin | G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
