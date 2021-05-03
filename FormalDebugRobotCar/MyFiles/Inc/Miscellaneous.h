#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"
#include "Gyro.h"
#include "GraySensor.h"

#define DEBUG_UART4_TX_GPIO_PORT  GPIOB      
#define DEBUG_UART4_TX_GPIO_PIN   GPIO_PIN_14
#define DEBUG_UART4_RX_GPIO_PORT  GPIOB      
#define DEBUG_UART4_RX_GPIO_PIN   GPIO_PIN_15

#define LED_GPIO_PORT  GPIOC      
#define LED_GPIO_PIN   GPIO_PIN_13 

#define DebugUartHandle huart1

int fputc(int ch, FILE *f);

//����
void DebugGyro(void);
void DebugGraySensor(void);

#endif
