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
		GraySensorManualConfigLight(40);
//	GraySensorInit();
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
//	printf("test\n");
	GraySensorFifteenAnalogValueGet();
	int i;
	for(i=0; i<15; i++)
		printf("%d ", GetGraySensorOneOfFifteenReceiveValue(i));
	printf("\n");
//	printf("%lf  %lf  %lf\r\n", GetGyroRollAngle(), GetGyroPitchAngle(), GetGyroYawAngle());
	HAL_Delay(10);
}

