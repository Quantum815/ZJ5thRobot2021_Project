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
	//��ʱ������
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
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

