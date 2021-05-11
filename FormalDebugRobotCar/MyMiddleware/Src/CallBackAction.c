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

int flag1,flag2;

//���ڽ����ж�
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
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
	//�Ҷȴ�����
	if(huart == &GraySensorUartHandle)
	{
		flag2 = 1;
	}
}

//���ڷ����ж�
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	//�Ҷȴ�����
	if(huart == &GraySensorUartHandle)
	{
		flag1 = 1;
	}
}

//*****************************************************************
//��ʱ���ж�
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  //10ms ״̬��,10ms��ȡ������
	if(htim == &htim2)
	{

	}
  //10ms ��������ȡ
	else if(htim == &htim3)
	{
		static uint8_t GraySensorGetFifteenAnalogValue[2] = {0x00, 0xd9};  //��ȡ15·ģ����
		if(flag1 == 1)
		{
			if(HAL_UART_Receive_DMA(&GraySensorUartHandle, GraySensorReceiveBuffer, 18) != HAL_OK)
				Error_Handler();
			flag1 = 0;
		}
		else if(flag2 == 1)
		{
			if(HAL_UART_Transmit_DMA(&GraySensorUartHandle, GraySensorGetFifteenAnalogValue, 2) != HAL_OK)
				Error_Handler();
			flag2 = 0;
		}
//		GraySensorFifteenAnalogValueGet();	
	}
  //500ms LED�жϹ���״̬���������ƣ�
	else if(htim == &htim4)
	{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	}
}

//*****************************************************************
//�ⲿ�ж�
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//  switch(GPIO_Pin)
//  {
//    case LEFT_DRLASER_GPIO_PIN: LeftDiffuseReflectionLaserChangeSet(); break;
//    case RIGHT_DRLASER_GPIO_PIN: RightDiffuseReflectionLaserChangeSet(); break;
//    default: DiffuseReflectionLaserChangeReset(); break;
//  }
}
