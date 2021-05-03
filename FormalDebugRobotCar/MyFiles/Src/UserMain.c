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

void UserInit(void)  //主程序初始化
{
	//陀螺仪初始化
//	GyroInit();
//	GyroOpen();
	
	//灰度传感器初始化
//	GraySensorInit();
}

void UserLoop(void)  //主程序循环
{
//	DebugGyro();

//	GraySensorFifteenAnalogValueGet();
//	DebugGraySensor();
	HAL_Delay(100);
}

