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
	GraySensorInit();
//	GyroInit();
//	GyroOpen();
}

/**
  * @brief  主程序循环
  * @param  无
  * @retval 无
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

