#ifndef RANGINGLASER_H_
#define RANGINGLASER_H_

#include "i2c.h"
#include "vl53l0x_api.h"
#include "stdio.h"
#include "Miscellaneous.h"

#define RANGINGLASER_I2C3_SCL_GPIO_PORT GPIOA
#define RANGINGLASER_I2C3_SCL_GPIO_PIN  GPIO_PIN_8
#define RANGINGLASER_I2C3_SDA_GPIO_PORT GPIOA
#define RANGINGLASER_I2C3_SDA_GPIO_PIN  GPIO_PIN_9
#define RANGINGLASER_GPIO1_GPIO_PORT GPIOC
#define RANGINGLASER_GPIO1_GPIO_PIN  GPIO_PIN_8
#define RANGINGLASER_XSHUT_GPIO_PORT GPIOC
#define RANGINGLASER_XSHUT_GPIO_PIN  GPIO_PIN_7

void RangingLaserInit(void);
void RangingLaserOpen(void);
void RangingLaserClose(void);
uint16_t RangingLaserDistanceGet(void);
void RangingLaserInterruptDistanceProcess(void);
void RangingLaserPollingDistanceProcess(void);

#endif
