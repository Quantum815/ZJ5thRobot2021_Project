#ifndef GYRO_H_
#define GYRO_H_

#include "usart.h"

#define GYRO_USART_TX_GPIO_PORT  GPIOB      
#define GYRO_USART_TX_GPIO_PIN   GPIO_PIN_12
#define GYRO_USART_RX_GPIO_PORT  GPIOB      
#define GYRO_USART_RX_GPIO_PIN   GPIO_PIN_13

extern double RollAngle, PitchAngle, YawAngle;
extern uint8_t GyroReceiveBuffer[11];

void Short2Char(short sData, uint8_t cData[]);
short Char2Short(uint8_t cData[]);
uint8_t GyroCheckSumJudge(void);
double GyroEulerAnglesProcess(uint8_t cData[]);

void GyroInit(void);

#endif