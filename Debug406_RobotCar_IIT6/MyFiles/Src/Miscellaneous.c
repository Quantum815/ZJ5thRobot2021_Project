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

int fputc(int ch, FILE *f)
{	
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  HAL_UART_Transmit(&DebugUartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}