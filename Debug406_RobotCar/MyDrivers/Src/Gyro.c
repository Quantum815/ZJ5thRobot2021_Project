/**
  ******************************************************************************
  * @file    Gyro.c
  * @author  YL
  * @brief   ������JY901S����
  *
  @verbatim
	(#) JY901S����
	(++) �����㷨��ˮƽ��װ���Զ�У׼
	(++) ���ٶȣ�2g
	(++) �����ǣ�250deg/s
	(++) ����20Hz
	(++) ���ݣ�ŷ����
	(++) ͨѶ���ʣ�115200
	(++) �ش����ʣ�200Hz
	(++) I2C�豸��ַ��0x50
	(#) ��������Ĭ��
	@endverbatim
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"

/* Define\Declare ------------------------------------------------------------*/
volatile double RollAngle, PitchAngle, YawAngle;
uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11];
uint8_t GyroUnlockInstruction[5] = {0xff, 0xaa, 0x69, 0x88, 0xb5};  //����ָ��
uint8_t GyroAutoCalibration[5] = {0xff, 0xaa, 0x63, 0x00, 0x00};  //�������Զ�У׼
uint8_t GyroKeepConfiguration[5] = {0xff, 0xaa, 0x00, 0x00, 0x00};  //��������

/**
 ******************************************************************************
 *  @defgroup �ײ����
 *  @brief Short2Char, Char2Short, GyroEulerAnglesProcess
 *
**/
void Short2Char(short sData,uint8_t cData[])
{
	cData[0]=sData&0xff;
	cData[1]=sData>>8;
}

short Char2Short(uint8_t cData[])
{
	return ((short)cData[1]<<8)|cData[0];
}

uint8_t GyroCheckSumJudge(void)
{
	uint8_t sum = 0;
	sum += GyroReceiveBuffer[0];
	sum += GyroReceiveBuffer[1];
	sum += GyroReceiveBuffer[2];
	sum += GyroReceiveBuffer[3];
	sum += GyroReceiveBuffer[4];
	sum += GyroReceiveBuffer[5];
	sum += GyroReceiveBuffer[6];
	sum += GyroReceiveBuffer[7];
	sum += GyroReceiveBuffer[8];
	sum += GyroReceiveBuffer[9];
	if(GyroReceiveBuffer[10] != sum)
		return 0;
	else
		return 1;
}

double GyroEulerAnglesProcess(uint8_t cData[])
{
	return (double)Char2Short(&cData[0])/32768.0*180.0;
}

/**
 ******************************************************************************
 *  @defgroup ����
 *  @brief
 *
**/
void GyroInit(void)
{
//	HAL_UART_Transmit(&huart5, GyroUnlockInstruction, 5, 10);
//	HAL_Delay(100);
//	HAL_UART_Transmit(&huart5, GyroAutoCalibration, 5, 10);
//	HAL_Delay(100);
//	HAL_UART_Transmit(&huart5, GyroKeepConfiguration, 5, 10);
//	HAL_Delay(100);
	HAL_UART_Receive_IT(&huart5, &GyroReceiveBuffer[0], 1);
}
