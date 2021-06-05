#ifndef MISCELLANEOUS_H_
#define MISCELLANEOUS_H_

#include <stdio.h>
#include "usart.h"
#include "Gyro.h"
#include "GraySensor.h"
#include "DiffuseReflectionLaser.h"
#include "ServoMotor.h"
#include "RangingLaser.h"
#include "LCD.h"
#include "Gui.h"

//LED
#define LED_GPIO_PORT  GPIOC      
#define LED_GPIO_PIN   GPIO_PIN_13 


//ต๗สิ
void DebugGyro(void);
void DebugGraySensor(void);
void DebugServoMotor(void);
void DebugDiffuseReflectionLaser(void);
void DebugRangingLaser(void);

#endif
