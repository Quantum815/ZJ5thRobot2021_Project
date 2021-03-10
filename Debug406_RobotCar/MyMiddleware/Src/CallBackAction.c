#include "CallBackAction.h"

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//串口5接收中断（陀螺仪）
	if(huart == &huart2)
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
				GyroGetAllAngles();
				GyroReceiveNum = 0;
			}
			else
			{
				GyroReceiveNum = 0;
			}
    }
		else
			GyroReceiveNum++;
		HAL_UART_Receive_IT(&huart2,&GyroReceiveBuffer[GyroReceiveNum],1);
	}
}