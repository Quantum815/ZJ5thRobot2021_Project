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
	//定时器开启
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
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
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 5);
	HAL_Delay(2000);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 10);
	HAL_Delay(2000);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 15);
	HAL_Delay(2000);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 20);
//	DebugGyro();

//	DebugGraySensor();
	
	HAL_Delay(2000);
}

