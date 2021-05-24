/**
  ******************************************************************************
  * @file    RangingLaser.c
  * @author  YL
  * @brief   测距激光传感器驱动（有卡死现象需要解决）
  *
  @verbatim
	3.3V供电
	参考：VL53L0X_API_v1.0.2.4823_externalx
				VL53L0X说明文档
				UM2356
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "RangingLaser.h"

/* Define\Declare ------------------------------------------------------------*/
//VL53L0X设备参数
VL53L0X_RangingMeasurementData_t RangingData;
VL53L0X_Dev_t vl53l0x_c;
VL53L0X_DEV Dev = &vl53l0x_c;

//VL53L0X校准参数
uint32_t refSpadCount;
uint8_t isApertureSpads;
uint8_t VhvSettings;
uint8_t PhaseCal;
int32_t OffsetMicroMeter;
FixPoint1616_t XTalkCompensation;

//volatile uint8_t TofDataRead;
VL53L0X_Error Status = VL53L0X_ERROR_NONE;
uint16_t RangingLaserDistance;

/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief
 *
**/
//测距激光传感器初始化（测距激光传感器默认开启）
void RangingLaserInit(void)
{
  Dev->I2cHandle = &hi2c3;
  Dev->I2cDevAddr = 0x52;
	Dev->comms_type = 1;
	Dev->comms_speed_khz = 400;

	//关闭XSHUT
  HAL_GPIO_WritePin(RANGINGLASER_XSHUT_GPIO_PORT, RANGINGLASER_XSHUT_GPIO_PIN, GPIO_PIN_RESET);
  HAL_Delay(25);
	//使能XSHUT
  HAL_GPIO_WritePin(RANGINGLASER_XSHUT_GPIO_PORT, RANGINGLASER_XSHUT_GPIO_PIN, GPIO_PIN_SET);
  HAL_Delay(25);

  //关闭stm32外部中断
  HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);

	//初始化函数类*****************************
	//等待设备启动
	VL53L0X_WaitDeviceBooted(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
	Error_Handler();
	//数据初始化
  Status = VL53L0X_DataInit(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	
  //静态初始化
  Status = VL53L0X_StaticInit(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	//*****************************************	
	

	//数据函数类*******************************
  //温度校准（正常初始化也可使用）
	Status = VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	
	//参考SPADs校准：校准时周围5cm没有较近的目标，少红外光下室内校准，加盖校准需重新校准（常注释）
  Status = VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	
//	//偏移校准，较暗环境下把灰色物体（17%反射率）放在约100mm（官方建议140mm）校准距离处进行（常注释）
//	Status=VL53L0X_PerformOffsetCalibration(Dev, 100<<16, &OffsetMicroMeter);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
	
	//  //串扰校准，较暗环境下把灰色物体（17%反射率）放在约450mm（对照实际情况曲线修改）校准距离处进行（常注释）
//	Status = VL53L0X_PerformXTalkCalibration(Dev, 450<<16, &XTalkCompensation);            
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
	
	//数据连续获取模式设定（必须在数据设定后使用，否则只能读取一次数值）
  Status = VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);  //连续读取
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	//*****************************************
	
	RangingLaserOpen();
	
	//开启stm32外部中断
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}


//启动测距激光传感器测距（传感器关闭后使用）
void RangingLaserOpen(void)
{
	//参数函数类*******************************
//	//设定参考SPADs的校准值
//	Status = VL53L0X_SetReferenceSpads(Dev, refSpadCount, isApertureSpads);   
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	
//	//设定温度校准值
//	Status = VL53L0X_SetRefCalibration(Dev, VhvSettings, PhaseCal);             
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();

//	//设定偏移校准值
//	Status = VL53L0X_SetOffsetCalibrationDataMicroMeter(Dev, OffsetMicroMeter);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();

//	//设定串扰校准值
//	Status = VL53L0X_SetXTalkCompensationRateMegaCps(Dev, XTalkCompensation);  
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
//	//启用串扰补偿
//	VL53L0X_SetXTalkCompensationEnable(Dev, 1);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	
//	Status = VL53L0X_SetXTalkCompensationEnable(Dev,1);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	//*****************************************	

	
	//中断设置函数*****************************
	//IO口状态设置
//	Status = VL53L0X_SetGpioConfig(Dev, (uint8_t)RANGINGLASER_GPIO1_GPIO_PIN, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING,
//		VL53L0X_GPIOFUNCTIONALITY_NEW_MEASURE_READY, VL53L0X_INTERRUPTPOLARITY_LOW);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	//*****************************************
	
  Status = VL53L0X_StartMeasurement(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
}


//关闭测距激光传感器测距（传感器开启后使用）
void RangingLaserClose(void)
{
  Status = VL53L0X_StopMeasurement(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	RangingLaserDistance = 0;
}

//测距激光传感器当前距离获取  单位：mm
uint16_t RangingLaserDistanceGet(void)
{
	if(RangingLaserDistance <= 2000)
		return RangingLaserDistance;
	else
		return 0;
}


//此行以下请勿随意修改和使用！！！！！！
//*****************************************************************
//*****************************************************************
/**
 ******************************************************************************
 *  @defgroup 内部调用
 *  @brief
 *
**/
//测距激光传感器当前距离读取
void RangingLaserDistanceProcess(void)
{
	Status = VL53L0X_GetRangingMeasurementData(Dev, &RangingData);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	RangingLaserDistance = RangingData.RangeMilliMeter;
	Status = VL53L0X_ClearInterruptMask(Dev, VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
}