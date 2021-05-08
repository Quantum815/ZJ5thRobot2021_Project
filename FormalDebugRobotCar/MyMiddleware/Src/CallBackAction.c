/**
  ******************************************************************************
  * @file    CallBackAction.c
  * @author  YL
  * @brief   回调函数
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

//串口中断
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//陀螺仪（基本完善）  5.2
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
	//灰度传感器（基本完善）5.3
	else if(huart == &GraySensorUartHandle)
	{
		//空（请勿添加任何代码）
	}
}

//*****************************************************************
//定时器中断
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  //10ms 状态机,10ms读取传感器
	if(htim == &htim2)
	{
		
	}
  //10ms 传感器读取
	else if(htim == &htim3)
	{
//		GraySensorFifteenAnalogValueGet();
	}
  //500ms LED判断工作状态（基本完善）
	else if(htim == &htim4)
	{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	}
}

//*****************************************************************
//外部中断
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  switch(GPIO_Pin)
  {
    case LEFT_DRLASER_GPIO_PIN: LeftDiffuseReflectionLaserChangeSet(); break;
    case RIGHT_DRLASER_GPIO_PIN: RightDiffuseReflectionLaserChangeSet(); break;
    default: DiffuseReflectionLaserChangeClear(); break;
  }
}
