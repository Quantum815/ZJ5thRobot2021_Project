/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   主程序
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserMain.h"
#include "stm32h7xx_hal.h"

/**
  * @brief  主程序初始化
  * @param  无
  * @retval 无
  */
void UserInit(void)
{
	
}

/**
  * @brief  主程序循环
  * @param  无
  * @retval 无
  */
void UserLoop(void)
{
	Debug();
}

/**
  * @brief  测试
  * @param  无
  * @retval 无
  */
void Debug(void)
{
	HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	HAL_Delay(1000);
}