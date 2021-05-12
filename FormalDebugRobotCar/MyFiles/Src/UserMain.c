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

//主程序初始化
void UserInit(void)  
{
	//陀螺仪初始化
	GyroInit();
	//灰度传感器初始化
	GraySensorInit();
	//漫反射激光传感器初始化
	DiffuseReflectionLaserInit();
	//舵机初始化
	ServoMotorInit();
	//定时器开启
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim2);
	//初始化延迟
	HAL_Delay(500);
}

//主程序循环
void UserLoop(void)  
{

//测试
//	DebugGyro();
	
//	DebugGraySensor();
	
//	DebugServoMotor();
	
//	DebugDiffuseReflectionLaser();
}

