/**
  ******************************************************************************
  * @file    Miscellaneous.c
  * @author  YL
  * @brief   不易分类的模块及接口
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "Miscellaneous.h"
#include "usart.h"

/**
  * @brief  测试
  * @param  无
  * @retval 无
  */
void Debug(void)
{
		HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_GPIO_PIN);
		HAL_Delay(1000);
}