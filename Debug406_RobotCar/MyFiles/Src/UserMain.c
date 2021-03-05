/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   ������
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserMain.h"
#include "stm32h7xx_hal.h"

/**
  * @brief  �������ʼ��
  * @param  ��
  * @retval ��
  */
void UserInit(void)
{
	
}

/**
  * @brief  ������ѭ��
  * @param  ��
  * @retval ��
  */
void UserLoop(void)
{
	Debug();
}

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