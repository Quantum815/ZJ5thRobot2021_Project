/**
  ******************************************************************************
  * @file    CallBackAction.c
  * @author  YL
  * @brief   �ص�����
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "CallBackAction.h"
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)  //�����ж�
{
	//�����ǣ��������ƣ�  5.2
	if(huart == &GyroUartHandle && GyroOpenFlag)
	{
		if(GyroReceiveNum == 0)
		{
			if(GyroReceiveBuffer[0] != 0x55)
				GyroReceiveNum = 0;
			else
				GyroReceiveNum = 1;
			HAL_UART_Receive_IT(&GyroUartHandle,&GyroReceiveBuffer[GyroReceiveNum],1);
		}
		else if(GyroReceiveNum == 1)
		{
			if(GyroReceiveBuffer[1] != 0x53)
			{
				GyroReceiveNum = 0;
				HAL_UART_Receive_IT(&GyroUartHandle,&GyroReceiveBuffer[GyroReceiveNum],1);
			}
			else
			{
				GyroReceiveNum = 2;
				HAL_UART_Receive_IT(&GyroUartHandle,&GyroReceiveBuffer[GyroReceiveNum],9);
			}
		}
		else if(GyroReceiveNum == 2)
    {
			if(GyroCheckSumJudge())
				GyroGetAllAngles();
			GyroReceiveNum = 0;
			HAL_UART_Receive_IT(&GyroUartHandle,&GyroReceiveBuffer[GyroReceiveNum],1);
    }
		else
		{
			GyroReceiveNum = 0;
			HAL_UART_Receive_IT(&GyroUartHandle,&GyroReceiveBuffer[GyroReceiveNum],1);
		}
	}
	//�Ҷȴ��������������ƣ�5.3
	else if(huart == &GraySensorUartHandle)
	{
		//�գ���������κδ��룩
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)  //��ʱ���ж�
{
  //10ms ״̬��
	if(htim == &htim2)
	{
		
	}
  //10ms ��������ȡ
	else if(htim == &htim3)
	{
//		GraySensorFifteenAnalogValueGet();
	}
  //1000ms LED�жϹ���״̬���������ƣ�
	else if(htim == &htim4)
	{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	}
}
