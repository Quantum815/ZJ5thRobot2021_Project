#ifndef GRAYSENSOR_H_
#define GRAYSENSOR_H_

#include "usart.h"

#define GRAYSENSOR_UART4_TX_GPIO_PORT GPIOA
#define GRAYSENSOR_UART4_TX_GPIO_PIN  GPIO_PIN_0
#define GRAYSENSOR_UART4_RX_GPIO_PORT GPIOA
#define GRAYSENSOR_UART4_RX_GPIO_PIN  GPIO_PIN_1

#define GraySensorUartHandle huart4

//≈‰÷√÷∏¡Ó
void GraySensorConfigTest(void);
void GraySensorConfigLineLight(void);
void GraySensorConfigGroundLight(void);
void GraySensorManualConfigLight(uint8_t light);
void GraySensorConfigLineAd(void);
void GraySensorConfigGroundAd(void);
void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold);

//∂¡»°÷∏¡Ó
void GraySensorFifteenThresholdValueGet(void);
void GraySensorFifteenDigitalValueGet(void);
void GraySensorFifteenAnalogValueGet(void);
void GraySensorSigleAnalogValueGet(void);

void GraySensorInit(void);

uint8_t GetGraySensorOneOfFifteenReceiveValue(uint8_t num);

#endif