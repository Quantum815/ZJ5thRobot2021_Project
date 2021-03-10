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

int fputc(int ch,FILE *f)
{	
	uint8_t temp[1]={ch};
	HAL_UART_Transmit(&huart1, temp, 1, 10);
	return ch;
}

int fgetc(FILE *f)
{
	uint8_t ch;
	while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == RESET);
	HAL_UART_Receive(&huart1, (uint8_t*)&ch, 2, 10);
	return ch;
}