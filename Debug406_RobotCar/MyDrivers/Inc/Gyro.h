#ifndef GYRO_H_
#define GYRO_H_

#include "usart.h"

#define GYRO_USART_TX_GPIO_PORT  GPIOA      
#define GYRO_USART_TX_GPIO_PIN   GPIO_PIN_2
#define GYRO_USART_RX_GPIO_PORT  GPIOA      
#define GYRO_USART_RX_GPIO_PIN   GPIO_PIN_3

#define GyroUartHandle huart8

void Short2Char(short sData, uint8_t cData[]);
short Char2Short(uint8_t cData[]);
uint8_t GyroCheckSumJudge(void);
double GyroEulerAnglesProcess(uint8_t cData[]);

void GyroInit(void);
void GyroOpen(void);
void GyroClose(void);
void GyroGetAllAngles(void);
double GetGyroRollAngle(void);
double GetGyroPitchAngle(void);
double GetGyroYawAngle(void);
uint8_t* GetGyroReceiveBuffer(void);

#endif