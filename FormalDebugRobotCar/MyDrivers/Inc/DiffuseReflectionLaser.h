#ifndef DIFFUSEREFLECTIONLASER_H_
#define DIFFUSEREFLECTIONLASER_H_

#include "gpio.h"

#define DRLASER_GPIO_PORT  GPIOA
#define LEFT_DRLASER_GPIO_PIN   GPIO_PIN_12
#define RIGHT_DRLASER_GPIO_PIN  GPIO_PIN_3

#define CORRECT_TIME 5000 //��ѯ�������ݽ���ʱ��  ��λ��ms

typedef enum
{
  UnChange = 0U,
	Changed
}DiffuseReflectionLaser_Change_State;  //�����伤��ֵ�ı����


void DiffuseReflectionLaserInit(void);
GPIO_PinState LeftDiffuseReflectionLaserStateGet(void);
GPIO_PinState RightDiffuseReflectionLaserStateGet(void);
DiffuseReflectionLaser_Change_State LeftDiffuseReflectionLaserIsChange(void);
DiffuseReflectionLaser_Change_State RightDiffuseReflectionLaserIsChange(void);

void DiffuseReflectionLaserStateJudge(void);
void LeftDiffuseReflectionLaserChangeSet(void);
void RightDiffuseReflectionLaserChangeSet(void);
void LeftDiffuseReflectionLaserChangeReset(void);
void RightDiffuseReflectionLaserChangeReset(void);

#endif
