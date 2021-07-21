/**
  ******************************************************************************
  * @file    LinePatrolAction.c
  * @author  ����
  * @brief   Ѳ�߶���
  * 
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "LinePatrolAction.h"

/* Define\Declare ------------------------------------------------------------*/
Pid_ArgumentTypeDef Pid_NormalSpeedLinePatrol;

/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief 
 *
**/
void NormalLineSpeedPatrol(double current)
{
	int16_t Torque = Current2Torque(current);
	int16_t LSpeed = Torque - GetPIDValue(&Pid_NormalSpeedLinePatrol, GraySensorBiasGet());  //������ʵ�ʲ����PID�㷨û��֤����֤����
  int16_t RSpeed = Torque + GetPIDValue(&Pid_NormalSpeedLinePatrol, GraySensorBiasGet());
	SetMotorSpeed(LMOTOR, &LSpeed);
	SetMotorSpeed(RMOTOR, &RSpeed);
}



/**
 ******************************************************************************
 *  @defgroup �ڲ�����
 *  @brief 
 *
**/

//�Ҷ�ƫ��ֵ��ȡ����ֵ����
double GraySensorBiasGet(void)
{
	uint8_t i;
	uint16_t temp1 = 0, temp2 = 0;
	double Bias;
	
	for (i = 0; i < 7; i++)
			temp1 += GraySensorOneOfFifteenReceiveValueGet(i);  //�㷨�д��Ľ�
	for (i = 8; i < 15; i++)
			temp2 += GraySensorOneOfFifteenReceiveValueGet(i);
	
	Bias = (sqrt(temp1) - sqrt(temp2)) / (temp1 + temp2);
	
//	printf("%lf\n", Bias);  //������
	
	return Bias;
}