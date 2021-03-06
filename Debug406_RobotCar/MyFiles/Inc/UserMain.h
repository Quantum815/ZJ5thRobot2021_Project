#ifndef USERMAIN_H_
#define USERMAIN_H_

#include "Miscellaneous.h"
#include <string.h>
#include "CallBackAction.h"
#include "Gyro.h"
#include "GraySensor.h"

#define LED_GPIO_PORT  GPIOI      
#define LED_GPIO_PIN   GPIO_PIN_8 


void UserInit(void);
void UserLoop(void);

#endif