/**
  ******************************************************************************
  * @file    UserMain.c
  * @author  YL
  * @brief   主程序
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "UserMain.h"
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"


//VL53L0X_RangingMeasurementData_t RangingData;
//VL53L0X_Dev_t  vl53l0x_c; // center module
//VL53L0X_DEV    Dev = &vl53l0x_c;

////
//// VL53L0X initialisation stuff
////
//	uint32_t refSpadCount;
//	uint8_t isApertureSpads;
//	uint8_t VhvSettings;
//	uint8_t PhaseCal;


//主程序初始化
void UserInit(void)  
{
	

	
//	printf("msalamon.pl VL53L0X test\n\r");

//  Dev->I2cHandle = &hi2c3;
//  Dev->I2cDevAddr = 0x52;

//	//TOF_XSHUT
//  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET); // Disable XSHUT
//  HAL_Delay(20);
//  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_SET); // Enable XSHUT
//  HAL_Delay(20);

//  //
//  // VL53L0X init for Single Measurement
//  //

//  VL53L0X_WaitDeviceBooted( Dev );
//  VL53L0X_DataInit( Dev );
//  VL53L0X_StaticInit( Dev );
//  VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
//  VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
//  VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING);

//  // Enable/Disable Sigma and Signal check
//  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1);
//  VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1);
//  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, (FixPoint1616_t)(0.1*65536));
//  VL53L0X_SetLimitCheckValue(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, (FixPoint1616_t)(60*65536));
//  VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev, 33000);
//  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_PRE_RANGE, 18);
//  VL53L0X_SetVcselPulsePeriod(Dev, VL53L0X_VCSEL_PERIOD_FINAL_RANGE, 14);

	//定时器开启
	HAL_TIM_Base_Start_IT(&htim4);
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim2);
	//测距激光传感器初始化
	RangingLaserInit();	
	//陀螺仪初始化
	GyroInit();
	//灰度传感器初始化
	GraySensorInit();
	//漫反射激光传感器初始化
	DiffuseReflectionLaserInit();
	//舵机初始化
	ServoMotorInit();
}

//主程序循环
void UserLoop(void)  
{
//	VL53L0X_PerformSingleRangingMeasurement(Dev, &RangingData);

//	if(RangingData.RangeStatus == 0)
//	{
//		printf("Measured distance: %i\n\r", RangingData.RangeMilliMeter);
//		
//	}
	
//测试
//	DebugGyro();
	
//	DebugGraySensor();
	
//	DebugServoMotor();
	
//	DebugDiffuseReflectionLaser();
	
	DebugRangingLaser();
}

