#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"
#include "Gyro.h"
#include "GraySensor.h"
#include "DiffuseReflectionLaser.h"
#include "ServoMotor.h"
#include "RangingLaser.h"
#include "LCD.h"
#include "Gui.h"

//À¶ÑÀµ÷ÊÔ¿Ú
#define BLUETEETH_UART5_TX_GPIO_PORT  GPIOB      
#define BLUETEETH_UART5_TX_GPIO_PIN   GPIO_PIN_13
#define BLUETEETH_UART5_RX_GPIO_PORT  GPIOB
#define BLUETEETH_UART5_RX_GPIO_PIN   GPIO_PIN_12

#define BlueTeethUartHandle huart5

//LED
#define LED_GPIO_PORT  GPIOC      
#define LED_GPIO_PIN   GPIO_PIN_13 


int fputc(int ch, FILE *f);
//µ÷ÊÔ
void DebugGyro(void);
void DebugGraySensor(void);
void DebugServoMotor(void);
void DebugDiffuseReflectionLaser(void);
void DebugRangingLaser(void);

#endif
