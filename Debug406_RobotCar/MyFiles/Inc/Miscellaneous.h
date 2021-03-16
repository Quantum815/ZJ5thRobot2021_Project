#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"

#define DEBUG_UART8_TX_GPIO_PORT  GPIOE      
#define DEBUG_UART8_TX_GPIO_PIN   GPIO_PIN_1
#define DEBUG_UART8_RX_GPIO_PORT  GPIOE      
#define DEBUG_UART8_RX_GPIO_PIN   GPIO_PIN_0

#define DebugUartHandle huart8

int fputc(int ch, FILE *f);

#endif
