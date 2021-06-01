/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   ������
  *
	@verbatim
	ע�⣬�������״̬�������г��ֳ����ͷ��ʼ�ܣ���������DMAǱ���жϸ�λ�����⣬
	���YL��ϵ
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


//�������ʼ��
void UserInit(void)  
{
	//�����ǳ�ʼ��
	GyroInit();
	//��ʱ������
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim2);
	//�Ҷȴ�������ʼ��
	GraySensorInit();
	//��༤�⴫������ʼ��
	RangingLaserInit();
	//�����伤�⴫������ʼ��
	DiffuseReflectionLaserInit();
	//�����ʼ��
	ServoMotorInit();
	//������̳�ʼ��
	MatrixKeyBoardInit();
}

//������ѭ��
void UserLoop(void)  
{
	//����
//	DebugGyro();
	
	DebugGraySensor();
	
//	DebugServoMotor();
	
//	DebugDiffuseReflectionLaser();
	
	DebugRangingLaser();
}

