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

void UserInit(void)  //�������ʼ��
{
	//��ʱ���жϿ���
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim4);
	//�����ǳ�ʼ��
//	GyroInit();
//	GyroOpen();
	
	//�Ҷȴ�������ʼ��
//	GraySensorInit();
}

void UserLoop(void)  //������ѭ��
{
//	DebugGyro();

//	DebugGraySensor();
	
	HAL_Delay(100);
}

