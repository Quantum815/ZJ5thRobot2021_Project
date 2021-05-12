#ifndef GRAYSENSOR_H_
#define GRAYSENSOR_H_

#include <string.h>
#include "usart.h"

#define GRAYSENSOR_UART4_TX_GPIO_PORT GPIOB
#define GRAYSENSOR_UART4_TX_GPIO_PIN  GPIO_PIN_10
#define GRAYSENSOR_UART4_RX_GPIO_PORT GPIOB
#define GRAYSENSOR_UART4_RX_GPIO_PIN  GPIO_PIN_11

#define GraySensorUartHandle huart3

//配置指令
static uint8_t GraySensorTestConfiguration[2] = {0x00, 0xaa};  //测试
static uint8_t GraySensorLineLightConfiguration[2] = {0x00, 0xc9};  //自动线上亮度配置
static uint8_t GraySensorGroundLightConfiguration[2] = {0x00, 0xca};  //自动地上亮度配置
static uint8_t GraySensorLineAdConfiguration[2] = {0x00, 0xc1};  //自动设置线AD值
static uint8_t GraySensorGroundAdConfiguration[2] = {0x00, 0xc2};  //自动设置地AD值

//读取指令
static uint8_t GraySensorGetFifteenThresholdValue[2] = {0x00, 0xd7};  //读取15路阈值
static uint8_t GraySensorGetFifteenLineValue[2] = {0x00, 0xd1};  //读取15路设置线值
static uint8_t GraySensorGetFifteenGroundValue[2] = {0x00, 0xd2};  //读取15路设置地值
static uint8_t GraySensorGetFifteenDigitalValue[2] = {0x00, 0xd8};  //读取15路数字量
static uint8_t GraySensorGetFifteenAnalogValue[2] = {0x00, 0xd9};  //读取15路模拟量
static uint8_t GraySensorGetFifteenSigleAnalogValue[2] = {0x00, 0xdb};  //读取单模拟量值


void GraySensorInit(void);

//配置
void GraySensorConfigTest(void);
void GraySensorConfigLineLight(void);
void GraySensorConfigGroundLight(void);
void GraySensorManualConfigLight(uint8_t light);
void GraySensorConfigLineAd(void);
void GraySensorConfigGroundAd(void);
void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold);

//读取
void GraySensorFifteenThresholdValueGet(void);
void GraySensorFifteenLineValueGet(void);
void GraySensorFifteenGroundValueGet(void);
void GraySensorFifteenDigitalValueGet(void);
void GraySensorFifteenAnalogValueGet(void);
void GraySensorSingleAnalogValueGet(void);

uint8_t GraySensorOneOfFifteenReceiveValueGet(uint8_t num);

#endif