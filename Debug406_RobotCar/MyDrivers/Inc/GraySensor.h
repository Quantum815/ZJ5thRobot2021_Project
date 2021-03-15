#ifndef GRAYSENSOR_H_
#define GRAYSENSOR_H_

#include "usart.h"

#define GRAYSENSOR_TX_GPIO_PORT GPIOC
#define GRAYSENSOR_TX_GPIO_PIN  GPIO_PIN_6
#define GRAYSENSOR_RX_GPIO_PORT GPIOC
#define GRAYSENSOR_RX_GPIO_PIN  GPIO_PIN_7

void GraySensorInit(void);
void AdcGetGraysensor(uint8_t* buffer, uint8_t FilterTimes);

#endif