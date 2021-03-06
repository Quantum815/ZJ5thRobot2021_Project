/**
  ******************************************************************************
  * @file    Gyro.c
  * @author  YL
  * @brief   陀螺仪JY901S驱动
  *
  @verbatim
	(#) JY901S设置
	(++) 九轴算法，水平安装，自动校准
	(++) 加速度：2g
	(++) 陀螺仪：250deg/s
	(++) 带宽：20Hz
	(++) 内容：欧拉角
	(++) 通讯速率：115200
	(++) 回传速率：200Hz
	(++) I2C设备地址：0x50
	(#) 其余内容默认
	@endverbatim
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"

/* Define\Declare ------------------------------------------------------------*/
volatile double RollAngle, PitchAngle, YawAngle;
uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11];
uint8_t GyroUnlockInstruction[5] = {0xff, 0xaa, 0x69, 0x88, 0xb5};  //解锁指令
uint8_t GyroAutoCalibration[5] = {0xff, 0xaa, 0x63, 0x00, 0x00};  //陀螺仪自动校准
uint8_t GyroKeepConfiguration[5] = {0xff, 0xaa, 0x00, 0x00, 0x00};  //保持配置

/**
 ******************************************************************************
 *  @defgroup 底层调用
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
 *  @defgroup 驱动
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
