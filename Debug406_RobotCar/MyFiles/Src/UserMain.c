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
	GyroInit();
}

/**
  * @brief  主程序循环
  * @param  无
  * @retval 无
  */
void UserLoop(void)
{
	printf("%lf %lf %lf\r\n", GyroGetRollAngle(), GyroGetPitchAngle(), GyroGetYawAngle());
//	HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	HAL_Delay(5);
}

