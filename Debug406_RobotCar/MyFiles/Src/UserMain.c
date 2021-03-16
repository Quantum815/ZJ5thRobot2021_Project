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
	GraySensorInit();
//	GyroInit();
//	GyroOpen();
}

/**
  * @brief  ������ѭ��
  * @param  ��
  * @retval ��
  */
void UserLoop(void)
{
	uint8_t* test;
	GraySensorManualConfigLight(20);
	GraySensorFifteenAnalogValueGet();
	test = GetGraySensorFifteenValue();
	int i;
	for(i=0; i<15; i++)
		printf("%d ", test[i]);
	printf("test\n");
//	printf("%lf  %lf  %lf\r\n", GetGyroRollAngle(), GetGyroPitchAngle(), GetGyroYawAngle());
	HAL_Delay(10);
}

