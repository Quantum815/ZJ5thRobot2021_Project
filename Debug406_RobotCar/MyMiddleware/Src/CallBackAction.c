#include "CallBackAction.h"

//�����ж�
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	//������
	if(huart == &GyroUartHandle && GyroOpenFlag)
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
				GyroReceiveNum = 0;
    }
		else
			GyroReceiveNum++;
			HAL_UART_Receive_IT(&GyroUartHandle,&GyroReceiveBuffer[GyroReceiveNum],1);
	}
	//�Ҷȴ�����
	else if(huart == &GraySensorUartHandle)
	{

	}
}

//�ⲿ�ж�
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}
