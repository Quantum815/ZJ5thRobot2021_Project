/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  ��������־Զ��������
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
//	//�����ǳ�ʼ���������ڵ�һ��
//	GyroInit();		
//	
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
	//��ʱ������
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim2);
}

//������ѭ��
void UserLoop(void)  
{
	//���ԣ���Ļ��Ӧͦ�ٶ۵Ĳο��ã�
//	DebugGyro();
//	
//	DebugGraySensor();
//	
//	DebugServoMotor();
//	
//	DebugDiffuseReflectionLaser();
	
	DebugRangingLaser();

}

