/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   主程序
  *
	@verbatim
	注意，如果调试状态机过程中出现程序从头开始跑，是陀螺仪DMA潜在判断复位的问题，
	请跟YL联系
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserMain.h"
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"


//主程序初始化
void UserInit(void)  
{
	//陀螺仪初始化（必须在第一）
	GyroInit();		
	//屏幕初始化
	Lcd_Init();
  Lcd_Clear(BLACK);
	LcdAppendList((uint8_t*)"System initializing......");
	
	//灰度传感器初始化
	GraySensorInit();
	//测距激光传感器初始化
	RangingLaserInit();
	//漫反射激光传感器初始化
	DiffuseReflectionLaserInit();
	//舵机初始化
	ServoMotorInit();
	//矩阵键盘初始化
	MatrixKeyBoardInit();
	//状态机初始化
	FSMInit(&CarFSM, A, CarTable);
	//定时器开启
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim2);
	//初始化结束刷屏
	Lcd_Clear(BLACK);
}

//主程序循环
void UserLoop(void)  
{
	//测试（屏幕反应挺迟钝的参考用）
//	DebugGyro();
//	
//	DebugGraySensor();
//	
//	DebugServoMotor();
//	
//	DebugDiffuseReflectionLaser();
	
	DebugRangingLaser();

}

