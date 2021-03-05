#ifndef GYRO_H_
#define GYRO_H_

#include "usart.h"

#define GYRO_USART_TX_GPIO_PORT  GPIOB      
#define GYRO_USART_TX_GPIO_PIN   GPIO_PIN_12
#define GYRO_USART_RX_GPIO_PORT  GPIOB      
#define GYRO_USART_RX_GPIO_PIN   GPIO_PIN_13

extern double RollAngle, PitchAngle, YawAngle;

void Short2Char(short sData, unsigned char cData[]);
short Char2Short(unsigned char cData[]);
double GyroEulerAnglesProcess(unsigned char cData[]);


#endif