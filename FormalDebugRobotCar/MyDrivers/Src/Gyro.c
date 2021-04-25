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
GYRO_AngleTypeDef *Gyro_Angle;
uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11];
uint8_t GyroOpenFlag;

//指令
static uint8_t GyroUnlockInstruction[5] = {0xff, 0xaa, 0x69, 0x88, 0xb5};  //解锁指令
static uint8_t GyroAutoCalibration[5] = {0xff, 0xaa, 0x63, 0x00, 0x00};  //陀螺仪自动校准
static uint8_t GyroKeepConfiguration[5] = {0xff, 0xaa, 0x00, 0x00, 0x00};  //保持配置


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

void GyroInit(void)  //陀螺仪初始化
{
	while(HAL_UART_Transmit(&GyroUartHandle, GyroUnlockInstruction, 5, 10) != HAL_OK);
	while (HAL_UART_GetState(&GyroUartHandle) != HAL_UART_STATE_READY);
	while(HAL_UART_Transmit(&GyroUartHandle, GyroAutoCalibration, 5, 10) != HAL_OK);
	while (HAL_UART_GetState(&GyroUartHandle) != HAL_UART_STATE_READY);
	while(HAL_UART_Transmit(&GyroUartHandle, GyroKeepConfiguration, 5, 10) != HAL_OK);
	while (HAL_UART_GetState(&GyroUartHandle) != HAL_UART_STATE_READY);
}

void GyroOpen(void)  //陀螺仪数据获取开启
{
	GyroOpenFlag = 1;
	GyroReceiveNum = 0;
	HAL_UART_Receive_IT(&GyroUartHandle, &GyroReceiveBuffer[0], 1);
}

void GyroClose(void)  //陀螺仪数据获取关闭（用于节约CPU资源）
{
	GyroOpenFlag = 0;
}

void GyroGetAllAngles(void)  //陀螺仪数据处理
{
	Gyro_Angle->PitchAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[2]);
	Gyro_Angle->RollAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[4]);
	Gyro_Angle->YawAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[6]);
}


/**
 ******************************************************************************
 *  @defgroup 数据获取
 *  @brief
 *
**/

double GetGyroRollAngle(void)  //滚动角左负右正 -80~+80
{
	return Gyro_Angle->RollAngle;
}

double GetGyroPitchAngle(void)  //俯仰角上正下负数 -180~+180
{
	return Gyro_Angle->PitchAngle;
}

double GetGyroYawAngle(void)  //偏航角逆时针变大 -180~180
{
	return Gyro_Angle->YawAngle;
}

uint8_t* GetGyroReceiveBuffer(void)  //陀螺仪11位数据包
{
	return GyroReceiveBuffer;
}