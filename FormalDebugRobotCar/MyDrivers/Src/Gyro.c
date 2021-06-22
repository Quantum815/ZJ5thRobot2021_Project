/**
  ******************************************************************************
  * @file    Gyro.c
  * @author  ����
  * @brief   ������JY901S���������ƣ� 6.1
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
	��װʱ�ϲ೯ǰ��ʹ��3.3V��Դ
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"

/* Define\Declare ------------------------------------------------------------*/
static Gyro_AngleTypeDef *Gyro_Angle;

uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11] = {1};  //��ֹ�״�У��ͳ���


/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief 
 *
**/
//�����ǳ�ʼ����Ĭ�Ͽ��������ǣ�
void GyroInit(void)  
{
	Gyro_Angle->RollAngle = 0;
	Gyro_Angle->PitchAngle = 0;
	Gyro_Angle->YawAngle = 0;
	GyroReceiveNum = 0;
	HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 11);
	
}

//�ű���ȡ������������ -80~+80
double GyroRollAngleGet(void)  
{
	return Gyro_Angle->RollAngle;
}

//�ű���ȡ�����������¸��� -180~+180
double GyroPitchAngleGet(void)  
{
	return Gyro_Angle->PitchAngle;
}

//�ű���ȡƫ������ʱ���� -180~180
double GyroYawAngleGet(void)  
{
	return Gyro_Angle->YawAngle;
}

//�ű���ȡ������11λ���ݰ�ĳһλ��һ���ò����� num��Χ0~10
uint8_t GyroOneOfElevenReceiveBufferGet(uint8_t num)  
{
	if(num >= 0 && num <= 10)
		return GyroReceiveBuffer[num];
	else 
		return 1;
}


//�����������������޸ĺ�ʹ�ã�����������
//*****************************************************************
//*****************************************************************
/**
 ******************************************************************************
 *  @defgroup �ڲ�����
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

void GyroGetAllAngles(void)
{
	Gyro_Angle->PitchAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[2]);
	Gyro_Angle->RollAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[4]);
	Gyro_Angle->YawAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[6]);
}
