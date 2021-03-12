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
	GyroOpen();
}

/**
  * @brief  ������ѭ��
  * @param  ��
  * @retval ��
  */
void UserLoop(void)
{
	printf("%lf  %lf  %lf\r\n", GetGyroRollAngle(), GetGyroPitchAngle(), GetGyroYawAngle());
	HAL_Delay(10);
}

