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
#include "stm32h7xx_hal.h"

void UserInit(void)  //�������ʼ��
{
	//�����ǳ�ʼ��
//	GyroInit();
//	GyroOpen();
	
	//�Ҷȴ�������ʼ��
//	GraySensorInit();
}

void UserLoop(void)  //������ѭ��
{
//	DebugGyro();

//	GraySensorFifteenAnalogValueGet();
//	DebugGraySensor();
	HAL_Delay(100);
}

