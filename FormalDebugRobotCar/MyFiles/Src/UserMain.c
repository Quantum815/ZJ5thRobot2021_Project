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
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

void UserInit(void)  //主程序初始化
{
	//定时器中断开启
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim4);
	//陀螺仪初始化
//	GyroInit();
//	GyroOpen();
	
	//灰度传感器初始化
//	GraySensorInit();
}

void UserLoop(void)  //主程序循环
{
//	DebugGyro();

//	DebugGraySensor();
	
	HAL_Delay(100);
}

