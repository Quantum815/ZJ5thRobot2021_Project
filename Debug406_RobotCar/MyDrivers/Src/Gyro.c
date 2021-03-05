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
	(++) ���ݣ����ٶȣ����ٶȣ�ŷ����
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
double RollAngle, PitchAngle, YawAngle;
uint8_t GyroUnlockInstruction[5] = {0xff, 0xaa, 0x69, 0x88, 0xb5};  //����ָ��
uint8_t GyroAutoCalibration[5] = {0xff, 0xaa, 0x63, 0x00, 0x00};  //�������Զ�У׼
uint8_t GyroKeepConfiguration[5] = {0xff, 0xaa, 0x00, 0x00, 0x00};  //��������

/**
 ******************************************************************************
 *  @defgroup �ײ����
 *  @brief Short2Char��Char2Short
 *
**/
void Short2Char(short sData,unsigned char cData[])
{
	cData[0]=sData&0xff;
	cData[1]=sData>>8;
}

short Char2Short(unsigned char cData[])
{
	return ((short)cData[1]<<8)|cData[0];
}

double GyroEulerAnglesProcess(unsigned char cData[])
{
	return (double)Char2Short(cData)/32768.0*180.0;
}

/**
 ******************************************************************************
 *  @defgroup ����
 *  @brief
 *
**/
void GyroInit(void)
{
	uint8_t i;
	for(i=0; i<2; i++)
	{
		HAL_UART_Transmit(&huart5, GyroUnlockInstruction, 5, 10);
		HAL_Delay(100);
		HAL_UART_Transmit(&huart5, GyroAutoCalibration, 5, 10);
		HAL_Delay(100);
		HAL_UART_Transmit(&huart5, GyroKeepConfiguration, 5, 10);
		HAL_Delay(100);
	}

}
