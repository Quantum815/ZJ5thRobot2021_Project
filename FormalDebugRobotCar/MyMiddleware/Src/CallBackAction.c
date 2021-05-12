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
		GraySensorFifteenAnalogValueGet();
		DiffuseReflectionLaserStateJudge();
	}
  //500ms LED�жϹ���״̬�����ƣ�
	else if(htim == &htim4)
	{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	}
}


//�����������������޸ģ�����������
//*****************************************************************
//*****************************************************************
//���ڽ����ж�
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//�����ǣ����ƣ�  5.12
	if(huart == &GyroUartHandle && GyroOpenFlag)
	{
		if(GyroReceiveNum == 0)
		{
			if(GyroReceiveBuffer[0] != 0x55)
				GyroReceiveNum = 0;
			else
				GyroReceiveNum = 1;
			if(HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 1) != HAL_OK)
				Error_Handler();
		}
		else if(GyroReceiveNum == 1)
		{
			if(GyroReceiveBuffer[1] != 0x53)
			{
				GyroReceiveNum = 0;
				if(HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 1) != HAL_OK)
					Error_Handler();
			}
			else
			{
				GyroReceiveNum = 2;
				if(HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 9) != HAL_OK)
					Error_Handler();
			}
		}
		else if(GyroReceiveNum == 2)
    {
			if(GyroCheckSumJudge())
				GyroGetAllAngles();
			GyroReceiveNum = 0;
			if(HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 1) != HAL_OK)
					Error_Handler();
    }
		else
		{
			GyroReceiveNum = 0;
			if(HAL_UART_Receive_DMA(&GyroUartHandle, &GyroReceiveBuffer[GyroReceiveNum], 1) != HAL_OK)
					Error_Handler();
		}
	}
	//�Ҷȴ����������ƣ�  5.12
	if(huart == &GraySensorUartHandle)
	{
		GraySensorRecieveFlag = 1;
	}
}

//���ڷ����ж�
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	//�Ҷȴ����������ƣ�  5.12
	if(huart == &GraySensorUartHandle)
	{
		GraySensorTransferFlag = 1;
	}
}

//*****************************************************************
//�ⲿ�ж�
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	//�����伤�⴫�������������ƣ�  5.12
  switch(GPIO_Pin)
  {
    case LEFT_DRLASER_GPIO_PIN: LeftDiffuseReflectionLaserChangeSet(); break;
    case RIGHT_DRLASER_GPIO_PIN: RightDiffuseReflectionLaserChangeSet(); break;
    default: DiffuseReflectionLaserChangeReset(); break;
  }
}
