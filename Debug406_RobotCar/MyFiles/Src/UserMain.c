/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   ������
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserMain.h"
#include "stm32h7xx_hal.h"

/**
  * @brief  �������ʼ��
  * @param  ��
  * @retval ��
  */
void UserInit(void)
{
	GyroInit();
}

/**
  * @brief  ������ѭ��
  * @param  ��
  * @retval ��
  */
void UserLoop(void)
{
	printf("%lf %lf %lf\r\n", GyroGetRollAngle(), GyroGetPitchAngle(), GyroGetYawAngle());
//	HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	HAL_Delay(5);
}

