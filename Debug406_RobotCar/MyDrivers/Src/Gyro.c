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
	安装时上侧朝前，
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"

/* Define\Declare ------------------------------------------------------------*/
static double RollAngle, PitchAngle, YawAngle;
uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11];
uint8_t GyroOpenFlag;

//指令
uint8_t GyroUnlockInstruction[5] = {0xff, 0xaa, 0x69, 0x88, 0xb5};  //解锁指令
uint8_t GyroAutoCalibration[5] = {0xff, 0xaa, 0x63, 0x00, 0x00};  //陀螺仪自动校准
uint8_t GyroKeepConfiguration[5] = {0xff, 0xaa, 0x00, 0x00, 0x00};  //保持配置


/**
 ******************************************************************************
 *  @defgroup 底层调用
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
 *  @defgroup 驱动
 *  @brief
 *
**/

void GyroInit(void)
{
	HAL_UART_Transmit(&huart5, GyroUnlockInstruction, 5, 10);
	HAL_Delay(100);
	HAL_UART_Transmit(&huart5, GyroAutoCalibration, 5, 10);
	HAL_Delay(100);
	HAL_UART_Transmit(&huart5, GyroKeepConfiguration, 5, 10);
	HAL_Delay(100);
	HAL_UART_Receive_IT(&huart5, &GyroReceiveBuffer[0], 1);
}

void GyroOpen(void)
{
	GyroOpenFlag = 1;
	HAL_UART_Receive_IT(&huart5, &GyroReceiveBuffer[0], 1);
}

void GyroClose(void)
{
	GyroOpenFlag = 0;
}

void GyroGetAllAngles(void)
{
	PitchAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[2]);
	RollAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[4]);
	YawAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[6]);
}


/**
 ******************************************************************************
 *  @defgroup 数据获取
 *  @brief
 *
**/

//滚动角左负右正 -80~+80
double GetGyroRollAngle(void)
{
	return RollAngle;
}

//俯仰角上正下负数 -180~+180
double GetGyroPitchAngle(void)
{
	return PitchAngle;
}

//偏航角逆时针变大 -180~180
double GetGyroYawAngle(void)
{
	return YawAngle;
}

uint8_t* GetGyroReceiveBuffer(void)
{
	return GyroReceiveBuffer;
}