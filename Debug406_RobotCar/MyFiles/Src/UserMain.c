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
		GraySensorManualConfigLight(40);
//	GraySensorInit();
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
//	printf("test\n");
	uint8_t* test;
	GraySensorFifteenAnalogValueGet();
	test = GetGraySensorComfirmOrReceiveValue();
	int i;
	for(i=3; i<18; i++)
		printf("%d ", test[i]);
	printf("\n");
//	printf("%lf  %lf  %lf\r\n", GetGyroRollAngle(), GetGyroPitchAngle(), GetGyroYawAngle());
	HAL_Delay(10);
}

