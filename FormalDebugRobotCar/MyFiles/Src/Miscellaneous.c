/**
  ******************************************************************************
  * @file    Miscellaneous.c
  * @author  YL
  * @brief   ���׷����ģ�鼰�ӿ�
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
 *  @defgroup ���ݲ���
 *  @brief
 *
**/
//���������ݲ���
void DebugGyro(void)
{
	int i;
	printf("%lf %lf %lf\n", GyroRollAngleGet(), GyroPitchAngleGet(), GyroYawAngleGet());
//	for(i=0; i<11; i++)
//		printf("%d ", GyroOneOfElevenReceiveBufferGet(i));
//	printf("\n");
}

//�Ҷȴ���������
void DebugGraySensor(void)
{
	int i;
	for(i=0; i<14; i++)
		printf("%d ", GraySensorOneOfFifteenReceiveValueGet(i));
	printf("\n");
}

//�������
void DebugServoMotor(void)
{
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 180);
	HAL_Delay(200);
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 0);
	HAL_Delay(400);
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 90);
	HAL_Delay(5000);
}

//�����伤�⴫��������
void DebugDiffuseReflectionLaser(void)
{
	printf("%d %d %d %d\n", LeftDiffuseReflectionLaserStateGet(), RightDiffuseReflectionLaserStateGet(), 
	LeftDiffuseReflectionLaserIsChange(), RightDiffuseReflectionLaserIsChange());
}