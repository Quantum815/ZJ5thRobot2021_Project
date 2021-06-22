/**
  ******************************************************************************
  * @file    Gyro.c
  * @author  俞立
  * @brief   陀螺仪JY901S驱动（完善） 6.1
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
	安装时上侧朝前，使用3.3V电源
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"

/* Define\Declare ------------------------------------------------------------*/
static Gyro_AngleTypeDef *Gyro_Angle;

uint8_t GyroReceiveNum;
uint8_t GyroReceiveBuffer[11] = {1};  //防止首次校验和成立


/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief 
 *
**/
//陀螺仪初始化（默认开启陀螺仪）
void GyroInit(void)  
{
	Gyro_Angle->RollAngle = 0;
	Gyro_Angle->PitchAngle = 0;
	Gyro_Angle->YawAngle = 0;
	GyroReceiveNum = 0;
	HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 11);
	
}

//脚本获取滚动角左负右正 -80~+80
double GyroRollAngleGet(void)  
{
	return Gyro_Angle->RollAngle;
}

//脚本获取俯仰角上正下负数 -180~+180
double GyroPitchAngleGet(void)  
{
	return Gyro_Angle->PitchAngle;
}

//脚本获取偏航角逆时针变大 -180~180
double GyroYawAngleGet(void)  
{
	return Gyro_Angle->YawAngle;
}

//脚本获取陀螺仪11位数据包某一位（一般用不到） num范围0~10
uint8_t GyroOneOfElevenReceiveBufferGet(uint8_t num)  
{
	if(num >= 0 && num <= 10)
		return GyroReceiveBuffer[num];
	else 
		return 1;
}


//此行以下请勿随意修改和使用！！！！！！
//*****************************************************************
//*****************************************************************
/**
 ******************************************************************************
 *  @defgroup 内部调用
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
