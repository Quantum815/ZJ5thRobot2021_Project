/**
  ******************************************************************************
  * @file    Miscellaneous.c
  * @author  YL
  * @brief   ���׷����ģ�鼰�ӿ�
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "Miscellaneous.h"
#include "usart.h"

/**
  * @brief  ����
  * @param  ��
  * @retval ��
  */
void Debug(void)
{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
		HAL_Delay(1000);
}