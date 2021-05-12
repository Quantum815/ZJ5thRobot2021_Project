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
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

//�������ʼ��
void UserInit(void)  
{
	//�����ǳ�ʼ��
	GyroInit();
	//�Ҷȴ�������ʼ��
	GraySensorInit();
	//�����伤�⴫������ʼ��
	DiffuseReflectionLaserInit();
	//�����ʼ��
	ServoMotorInit();
	//��ʱ������
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim2);
	//��ʼ���ӳ�
	HAL_Delay(500);
}

//������ѭ��
void UserLoop(void)  
{

//����
//	DebugGyro();
	
//	DebugGraySensor();
	
//	DebugServoMotor();
	
//	DebugDiffuseReflectionLaser();
}

