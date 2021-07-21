/**
  ******************************************************************************
  * @file    LinePatrolAction.c
  * @author  俞立
  * @brief   巡线动作
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
 *  @defgroup 外部调用
 *  @brief 
 *
**/
void NormalLineSpeedPatrol(double current)
{
	int16_t Torque = Current2Torque(current);
	int16_t LSpeed = Torque - GetPIDValue(&Pid_NormalSpeedLinePatrol, GraySensorBiasGet());  //正负得实际测过，PID算法没验证不保证可用
  int16_t RSpeed = Torque + GetPIDValue(&Pid_NormalSpeedLinePatrol, GraySensorBiasGet());
	SetMotorSpeed(LMOTOR, &LSpeed);
	SetMotorSpeed(RMOTOR, &RSpeed);
}



/**
 ******************************************************************************
 *  @defgroup 内部调用
 *  @brief 
 *
**/

//灰度偏移值获取（比值法）
double GraySensorBiasGet(void)
{
	uint8_t i;
	uint16_t temp1 = 0, temp2 = 0;
	double Bias;
	
	for (i = 0; i < 7; i++)
			temp1 += GraySensorOneOfFifteenReceiveValueGet(i);  //算法有待改进
	for (i = 8; i < 15; i++)
			temp2 += GraySensorOneOfFifteenReceiveValueGet(i);
	
	Bias = (sqrt(temp1) - sqrt(temp2)) / (temp1 + temp2);
	
//	printf("%lf\n", Bias);  //测试用
	
	return Bias;
}