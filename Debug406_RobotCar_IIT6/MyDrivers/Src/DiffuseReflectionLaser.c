/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  GZL
  * @brief   漫反射激光传感器驱动
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "DiffuseReflectionLaser.h"
#include "stdio.h"
#include "main.h"
#include "usart.h"
#include "stm32h7xx_hal_uart.h"

/* Define\Declare ------------------------------------------------------------*/
int last = 0;//前一刻状态
int now = 0;//这一刻状态
int laserstate = 0;

/*
** 函数名称：Getlaserstate()
** 函数作用：读取并存储激光传感器上一时刻状态和这一时刻状态
** 函数输入：无
** 函数输出：无

** 其他：状态表示在绿毯上为1 白线上为0
*/
void Getlaserstate()
{
    last = now;
	  now = HAL_GPIO_ReadPin(laser_GPIO_Port,laser_Pin);
}
/*
** 函数名称：judgestate()
** 函数作用：判断当前状态
** 函数输入：无
** 函数输出：无

** 其他：laserstate 为 1 表示在绿毯上，为 2 表示在循白线 ， 为 3 表示从绿毯到白线的过程 ，为 4 表示从白线到绿毯的过程 ；
*/
void judgestate()
{
	if(last == now)
	{
		if(now==1)
		{
				laserstate = 1;
		}
		else
		{
				laserstate = 2;
		}
	}
	else
	{
		if(last == 1 && now == 0)
		{
				laserstate = 3;
		}
		if(last == 0 && now == 1)
		{
				laserstate = 4;
		}
	}
}

