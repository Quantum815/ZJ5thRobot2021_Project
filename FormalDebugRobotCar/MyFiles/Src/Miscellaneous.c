/**
  ******************************************************************************
  * @file    Miscellaneous.c
  * @author  YL
  * @brief   不易分类的模块及接口
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "Miscellaneous.h"

int fputc(int ch, FILE *f)
{	
  /* Place your implementation of fputc here */
  /* e.g. write a character to the UART4 and Loop until the end of transmission */
  HAL_UART_Transmit(&DebugUartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}


/**
 ******************************************************************************
 *  @defgroup 数据测试
 *  @brief
 *
**/
//陀螺仪数据测试
void DebugGyro(void)
{
	int i;
	printf("%lf %lf %lf\n", GyroRollAngleGet(), GyroPitchAngleGet(), GyroYawAngleGet());
//	for(i=0; i<11; i++)
//		printf("%d ", GyroOneOfElevenReceiveBufferGet(i));
//	printf("\n");
}

//灰度传感器测试
void DebugGraySensor(void)
{
	int i;
	for(i=0; i<14; i++)
		printf("%d ", GraySensorOneOfFifteenReceiveValueGet(i));
	printf("\n");
}

//舵机测试
void DebugServoMotor(void)
{
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 180);
	HAL_Delay(200);
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 0);
	HAL_Delay(400);
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 90);
	HAL_Delay(5000);
}

//漫反射激光传感器测试
void DebugDiffuseReflectionLaser(void)
{
	printf("%d %d %d %d\n", LeftDiffuseReflectionLaserStateGet(), RightDiffuseReflectionLaserStateGet(), 
	LeftDiffuseReflectionLaserIsChange(), RightDiffuseReflectionLaserIsChange());
}