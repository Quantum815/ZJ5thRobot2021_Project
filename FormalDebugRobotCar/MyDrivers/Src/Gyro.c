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
	��װʱ�ϲ೯ǰ��
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"

/* Define\Declare ------------------------------------------------------------*/
GYRO_AngleTypeDef *Gyro_Angle;
uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11];
uint8_t GyroOpenFlag;

//ָ��
static uint8_t GyroUnlockInstruction[5] = {0xff, 0xaa, 0x69, 0x88, 0xb5};  //����ָ��
static uint8_t GyroAutoCalibration[5] = {0xff, 0xaa, 0x63, 0x00, 0x00};  //�������Զ�У׼
static uint8_t GyroKeepConfiguration[5] = {0xff, 0xaa, 0x00, 0x00, 0x00};  //��������


/**
 ******************************************************************************
 *  @defgroup �ײ����
 *  @brief 
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
	int i;
	
	for(i=0; i<10; i++)
		sum += GyroReceiveBuffer[i];
	
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

void GyroInit(void)  //�����ǳ�ʼ��
{
	while(HAL_UART_Transmit(&GyroUartHandle, GyroUnlockInstruction, 5, 10) != HAL_OK);
	while (HAL_UART_GetState(&GyroUartHandle) != HAL_UART_STATE_READY);
	while(HAL_UART_Transmit(&GyroUartHandle, GyroAutoCalibration, 5, 10) != HAL_OK);
	while (HAL_UART_GetState(&GyroUartHandle) != HAL_UART_STATE_READY);
	while(HAL_UART_Transmit(&GyroUartHandle, GyroKeepConfiguration, 5, 10) != HAL_OK);
	while (HAL_UART_GetState(&GyroUartHandle) != HAL_UART_STATE_READY);
}

void GyroOpen(void)  //���������ݻ�ȡ����
{
	GyroOpenFlag = 1;
	GyroReceiveNum = 0;
	HAL_UART_Receive_IT(&GyroUartHandle, &GyroReceiveBuffer[0], 1);
}

void GyroClose(void)  //���������ݻ�ȡ�رգ����ڽ�ԼCPU��Դ��
{
	GyroOpenFlag = 0;
}

void GyroGetAllAngles(void)  //���������ݴ���
{
	Gyro_Angle->PitchAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[2]);
	Gyro_Angle->RollAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[4]);
	Gyro_Angle->YawAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[6]);
}


/**
 ******************************************************************************
 *  @defgroup ���ݻ�ȡ
 *  @brief
 *
**/

double GetGyroRollAngle(void)  //������������ -80~+80
{
	return Gyro_Angle->RollAngle;
}

double GetGyroPitchAngle(void)  //�����������¸��� -180~+180
{
	return Gyro_Angle->PitchAngle;
}

double GetGyroYawAngle(void)  //ƫ������ʱ���� -180~180
{
	return Gyro_Angle->YawAngle;
}

uint8_t* GetGyroReceiveBuffer(void)  //������11λ���ݰ�
{
	return GyroReceiveBuffer;
}