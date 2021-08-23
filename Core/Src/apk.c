/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : apk.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 *
 * @param Buff
 * @param size
 * @param Status
 * @return
 */
uint8_t SendEther_Buf(uint8_t *Buff, uint8_t size, uint8_t Status)
{
  uint8_t ret=0;

  /*assert check */
  if (size > MAX_SIZE)
  {
	  return PARM_ERROR;
  }
 if (Buff == 0)
 {
	  return PARM_ERROR;
 }
 if (Status == 0U)
 {
	 return PARM_ERROR;
 }



 for (uint8_t i=0; i<5U ;i++)
 {
	 Buff[i]=Status;
 }



  return ret;

}





#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
