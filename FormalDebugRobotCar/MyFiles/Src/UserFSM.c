/**
  ******************************************************************************
  * @file    MatrixKeyBoard.c
  * @author  YL
  * @brief   主状态机
  *
  @verbatim
	无
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserFSM.h"

/* Define\Declare ------------------------------------------------------------*/
FSM_t CarFSM;

FSMTable_t CarTable[] =
{
//当前的状态		当前状态执行函数		跳转事件条件函数		下一个状态

	{ A,          AA,         Axxx,           B         },
	{ B,          BB,         Bxxx,           C          },
	{ C,          CC,         Cxxx,           A          },
};


void AA(FSM_t* FSM)
{
	HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_RESET);
}

void BB(FSM_t* FSM)
{
	HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_SET);
}

void CC(FSM_t* FSM)
{
	HAL_GPIO_WritePin(LED_GPIO_PORT, LED_GPIO_PIN, GPIO_PIN_RESET);
}

uint8_t Axxx(void)
{
	static int i = 0;
	i++;
	if(i >= 100)
	{
		i = 0;
		return 1;
	}
	else
		return 0;
}

uint8_t Bxxx(void)
{
	static int j = 0;
	j++;
	if(j >= 200)
	{
		j = 0;
		return 1;
	}
	else
		return 0;
}

uint8_t Cxxx(void)
{
	static int k = 0;
	k++;
	if(k >= 100)
	{
		k = 0;
		return 1;
	}
	else
		return 0;
}