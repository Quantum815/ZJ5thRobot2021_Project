/**
  ******************************************************************************
  * @file    ServoMotor.c
  * @author  YL
  * @brief   手臂伺服电机驱动
  *
  @verbatim
	摇头舵机5V电源，摇臂舵机7.2-8V电源
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "ServoMotor.h"

/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief
 *
**/
//三个舵机初始化
void ServoMotorInit(void)
{
	HAL_TIM_PWM_Start(&htim1, LEFT_ARM_SERVO_CHANNEL);
	HAL_TIM_PWM_Start(&htim1, SHAKE_HEAD_SERVO_CHANNEL);
	HAL_TIM_PWM_Start(&htim1, RIGHT_ARM_SERVO_CHANNEL);
	ServoMotorAngleSet(LEFT_ARM_SERVO_CHANNEL, 90);
	ServoMotorAngleSet(RIGHT_ARM_SERVO_CHANNEL, 90);
	ServoMotorAngleSet(SHAKE_HEAD_SERVO_CHANNEL, 90);
}

//舵机角度设置 范围：0~180度
void ServoMotorAngleSet(uint32_t channel, uint8_t angle)
{
	__HAL_TIM_SET_COMPARE(&htim1, channel, 5+angle/9);
}