#ifndef GRAYSENSOR_H_
#define GRAYSENSOR_H_

#include <string.h>
#include "usart.h"

#define GRAYSENSOR_UART4_TX_GPIO_PORT GPIOB
#define GRAYSENSOR_UART4_TX_GPIO_PIN  GPIO_PIN_10
#define GRAYSENSOR_UART4_RX_GPIO_PORT GPIOB
#define GRAYSENSOR_UART4_RX_GPIO_PIN  GPIO_PIN_11

#define GraySensorUartHandle huart3

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
void GraySensorFifteenLineValueGet(void);
void GraySensorFifteenGroundValueGet(void);
void GraySensorFifteenDigitalValueGet(void);
void GraySensorFifteenAnalogValueGet(void);
void GraySensorSingleAnalogValueGet(void);

void GraySensorInit(void);

uint8_t GetGraySensorOneOfFifteenReceiveValue(uint8_t num);

#endif