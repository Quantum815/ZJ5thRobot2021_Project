/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   主程序
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserMain.h"
#include "stm32h7xx_hal.h"

uint8_t DebugBuffer[30];
uint8_t GyroReceiveNum = 0;

/**
  * @brief  主程序初始化
  * @param  无
  * @retval 无
  */
void UserInit(void)
{
	GyroInit();
	HAL_UART_Receive_IT(&huart5, &GyroReceiveBuffer[GyroReceiveNum], 1);
}

/**
  * @brief  主程序循环
  * @param  无
  * @retval 无
  */
void UserLoop(void)
{
	Debug();
//	int i = 0;
//	for(i=0; i<11; i++)
//	{
//		printf("%c ", GyroReceiveBuffer[i]);
//	}
//	printf("\r\n");
//	printf("%lf  %lf  %lf\n", RollAngle, PitchAngle, YawAngle);
//	HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
	HAL_Delay(200);
}

void Debug(void)
{
	uint8_t length;
	memset(DebugBuffer, 0x00, sizeof(DebugBuffer));
	length = sprintf((char*)DebugBuffer, "%lf %lf %lf\r\n", RollAngle, PitchAngle, YawAngle);
	HAL_UART_Transmit(&huart4, DebugBuffer, length, 10);
	HAL_Delay(1);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//串口5接收中断（陀螺仪）
	if(huart->Instance == UART5)
	{
		if(GyroReceiveNum == 0 && GyroReceiveBuffer[0] != 0x55)
		{
			GyroReceiveNum = 0;
		}
		else if(GyroReceiveNum == 1 && GyroReceiveBuffer[1] != 0x53)
		{
			GyroReceiveNum = 0;
		}
		else if(GyroReceiveNum == 10)
    {
			if(GyroCheckSumJudge())
			{
				RollAngle = 4;
				PitchAngle = 4;
				YawAngle = 4;
//				RollAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[2]);
//				PitchAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[4]);
//				YawAngle = GyroEulerAnglesProcess(&GyroReceiveBuffer[6]);
				GyroReceiveNum = 0;
			}
			else
			{
				GyroReceiveNum = 0;
			}
    }
		else
			GyroReceiveNum++;
		HAL_UART_Receive_IT(&huart5,&GyroReceiveBuffer[GyroReceiveNum],1);
	}
}

