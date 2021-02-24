#ifndef GYRO_H_
#define GYRO_H_

#include "i2c.h"

#define GYRO_I2C_SCL_GPIO_PORT  GPIOB      
#define GYRO_I2C_SCL_GPIO_PIN   GPIO_PIN_6
#define GYRO_I2C_SDA_GPIO_PORT  GPIOB      
#define GYRO_I2C_SDA_GPIO_PIN   GPIO_PIN_7

void Short2Char(short sData, unsigned char cData[]);
short Char2Short(unsigned char cData[]);

#endif