/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  GZL
  * @brief   �����伤�⴫��������
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
int last = 0;//ǰһ��״̬
int now = 0;//��һ��״̬
int laserstate = 0;

/*
** �������ƣ�Getlaserstate()
** �������ã���ȡ���洢���⴫������һʱ��״̬����һʱ��״̬
** �������룺��
** �����������

** ������״̬��ʾ����̺��Ϊ1 ������Ϊ0
*/
void Getlaserstate()
{
    last = now;
	  now = HAL_GPIO_ReadPin(laser_GPIO_Port,laser_Pin);
}
/*
** �������ƣ�judgestate()
** �������ã��жϵ�ǰ״̬
** �������룺��
** �����������

** ������laserstate Ϊ 1 ��ʾ����̺�ϣ�Ϊ 2 ��ʾ��ѭ���� �� Ϊ 3 ��ʾ����̺�����ߵĹ��� ��Ϊ 4 ��ʾ�Ӱ��ߵ���̺�Ĺ��� ��
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

