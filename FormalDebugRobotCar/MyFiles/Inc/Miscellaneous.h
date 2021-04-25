#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"

#define DEBUG_UART4_TX_GPIO_PORT  GPIOA      
#define DEBUG_UART4_TX_GPIO_PIN   GPIO_PIN_0
#define DEBUG_UART4_RX_GPIO_PORT  GPIOA      
#define DEBUG_UART4_RX_GPIO_PIN   GPIO_PIN_1

#define DebugUartHandle huart4

int fputc(int ch, FILE *f);

#endif
