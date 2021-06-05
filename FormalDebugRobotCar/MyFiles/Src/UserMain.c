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
	//�����ǳ�ʼ���������ڵ�һ��
//	GyroInit();
	//��Ļ��ʼ��
	ILI9341_Init();
	ILI9341_Fill_Screen(GRAY1);
	ILI9341_Set_Rotation(SCREEN_HORIZONTAL_1);
	Gui_DrawFont_GBK24(20, 15, BLACK, WHITE, (uint8_t*)"System initializing......");
//	//�Ҷȴ�������ʼ��
//	GraySensorInit();
//	//��༤�⴫������ʼ��
//	RangingLaserInit();
//	//�����伤�⴫������ʼ��
//	DiffuseReflectionLaserInit();
//	//�����ʼ��
//	ServoMotorInit();
//	//������̳�ʼ��
//	MatrixKeyBoardInit();
//	//״̬����ʼ��
//	FSMInit(&CarFSM, A, CarTable);
//	//��ʱ������
	HAL_TIM_Base_Start_IT(&htim4);
//	HAL_TIM_Base_Start_IT(&htim3);
//	HAL_TIM_Base_Start_IT(&htim2);
	//��ʼ������ˢ��
	HAL_Delay(5000);
	ILI9341_Fill_Screen(WHITE);
}

//������ѭ��
void UserLoop(void)  
{
	//����
//	DebugGyro();
	
//	DebugGraySensor();
	
//	DebugServoMotor();
	
//	DebugDiffuseReflectionLaser();
	
//	DebugRangingLaser();
}

