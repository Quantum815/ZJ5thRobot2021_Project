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
  /* e.g. write a character to the UART4 and Loop until the end of transmission */
  HAL_UART_Transmit(&DebugUartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}


/**
 ******************************************************************************
 *  @defgroup 数据测试
 *  @brief
 *
**/
void DebugGyro(void)  //陀螺仪数据测试
{
	int i;
	printf("%lf %lf %lf\n", GyroRollAngleGet(), GyroPitchAngleGet(), GyroYawAngleGet());
	for(i=0; i<11; i++)
		printf("%d ", GyroOneOfElevenReceiveBufferGet(i));
	printf("\n");
}

void DebugGraySensor(void)
{
	int i;
	for(i=0; i<15; i++)
		printf("%d ", GraySensorOneOfFifteenReceiveValueGet(i));
	printf("\n");
}