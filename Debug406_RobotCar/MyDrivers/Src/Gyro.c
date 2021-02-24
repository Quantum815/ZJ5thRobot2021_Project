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
	(++) 内容：加速度，角速度，欧拉角
	(++) 通讯速率：115200
	(++) 回传速率：200Hz
	(++) I2C设备地址：0x50
	(#) 其余内容默认
	@endverbatim
  * @{
**/
 
/* Includes ------------------------------------------------------------------*/
#include "Gyro.h"


/**
 ******************************************************************************
 *  @defgroup 底层调用
 *  @brief Short2Char，Char2Short
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

/**
 ******************************************************************************
 *  @defgroup 驱动
 *  @brief
 *
**/

