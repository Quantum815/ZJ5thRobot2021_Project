#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"
#include "Gyro.h"
#include "GraySensor.h"
#include "DiffuseReflectionLaser.h"
#include "ServoMotor.h"

#define DEBUG_UART4_TX_GPIO_PORT  GPIOB      
#define DEBUG_UART4_TX_GPIO_PIN   GPIO_PIN_14
#define DEBUG_UART4_RX_GPIO_PORT  GPIOB      
#define DEBUG_UART4_RX_GPIO_PIN   GPIO_PIN_15

#define DebugUartHandle huart1

int fputc(int ch, FILE *f);

//ต๗สิ
void DebugGyro(void);
void DebugGraySensor(void);
void DebugServoMotor(void);
void DebugDiffuseReflectionLaser(void);

#endif
