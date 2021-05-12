#ifndef GRAYSENSOR_H_
#define GRAYSENSOR_H_

#include <string.h>
#include "usart.h"

#define GRAYSENSOR_UART4_TX_GPIO_PORT GPIOB
#define GRAYSENSOR_UART4_TX_GPIO_PIN  GPIO_PIN_10
#define GRAYSENSOR_UART4_RX_GPIO_PORT GPIOB
#define GRAYSENSOR_UART4_RX_GPIO_PIN  GPIO_PIN_11

#define GraySensorUartHandle huart3

//����ָ��
static uint8_t GraySensorTestConfiguration[2] = {0x00, 0xaa};  //����
static uint8_t GraySensorLineLightConfiguration[2] = {0x00, 0xc9};  //�Զ�������������
static uint8_t GraySensorGroundLightConfiguration[2] = {0x00, 0xca};  //�Զ�������������
static uint8_t GraySensorLineAdConfiguration[2] = {0x00, 0xc1};  //�Զ�������ADֵ
static uint8_t GraySensorGroundAdConfiguration[2] = {0x00, 0xc2};  //�Զ����õ�ADֵ

//��ȡָ��
static uint8_t GraySensorGetFifteenThresholdValue[2] = {0x00, 0xd7};  //��ȡ15·��ֵ
static uint8_t GraySensorGetFifteenLineValue[2] = {0x00, 0xd1};  //��ȡ15·������ֵ
static uint8_t GraySensorGetFifteenGroundValue[2] = {0x00, 0xd2};  //��ȡ15·���õ�ֵ
static uint8_t GraySensorGetFifteenDigitalValue[2] = {0x00, 0xd8};  //��ȡ15·������
static uint8_t GraySensorGetFifteenAnalogValue[2] = {0x00, 0xd9};  //��ȡ15·ģ����
static uint8_t GraySensorGetFifteenSigleAnalogValue[2] = {0x00, 0xdb};  //��ȡ��ģ����ֵ


void GraySensorInit(void);

//����
void GraySensorConfigTest(void);
void GraySensorConfigLineLight(void);
void GraySensorConfigGroundLight(void);
void GraySensorManualConfigLight(uint8_t light);
void GraySensorConfigLineAd(void);
void GraySensorConfigGroundAd(void);
void GraySensorManualConfigThresholdValue(uint8_t num, uint8_t threshold);

//��ȡ
void GraySensorFifteenThresholdValueGet(void);
void GraySensorFifteenLineValueGet(void);
void GraySensorFifteenGroundValueGet(void);
void GraySensorFifteenDigitalValueGet(void);
void GraySensorFifteenAnalogValueGet(void);
void GraySensorSingleAnalogValueGet(void);

uint8_t GraySensorOneOfFifteenReceiveValueGet(uint8_t num);

#endif