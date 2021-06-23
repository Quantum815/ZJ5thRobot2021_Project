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
	
	//����PID��ʼ��
	PIDInit(&Pid_NormalSpeedLinePatrol, 0.000001, 0, 100, 10, 500, 0.1, 0.1);  //�������õ������������д��
	
	
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

