/**
  ******************************************************************************
  * @file    RangingLaser.c
  * @author  YL
  * @brief   测距激光传感器驱动（在运行约20s后距离数据不再更新，问题有待解决） 6.1
  *
  @verbatim
	3.3V供电
	参考：VL53L0X_API_v1.0.2.4823_externalx
				VL53L0X说明文档
				UM2356,UM2039
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
const uint32_t refSpadCount = 3;
const uint8_t isApertureSpads = 0;
uint8_t VhvSettings;
uint8_t PhaseCal;
const int32_t OffsetMicroMeter = 24000;
FixPoint1616_t XTalkCompensation;

VL53L0X_Error Status = VL53L0X_ERROR_NONE;
volatile uint16_t RangingLaserDistance;

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

	//XSHUT(硬件待机模式的复位输入端）始终高电平不复位，设备处于工作状态

  //关闭stm32外部中断
  HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);

	//注意，以下初始校准函数的顺序不能改动！！！！！！
	
	//初始化函数类*****************************
	//确保设备启动准备就绪
	VL53L0X_WaitDeviceBooted(Dev);
	
	//数据初始化
	Status = VL53L0X_DataInit(Dev);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	
  //静态初始化
	Status = VL53L0X_StaticInit(Dev);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	//*****************************************	
	

	//数据函数类*******************************
//	//参考SPADs校准：无需特殊环境要求，加盖校准需重新校准（常注释）
//	Status = VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();

	 //温度校准（正常初始化也可使用）
	Status = VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
//	
//	//偏移校准，黑暗环境下把白色物体（88%反射率）放在约100mm（官方建议）校准距离处进行（常注释）
//		Status = VL53L0X_PerformOffsetCalibration(Dev, 100<<16, &OffsetMicroMeter);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
	
//  //串扰校准，较暗环境下把灰色物体（17%反射率）放在约450mm（对照实际情况曲线修改）校准距离处进行（常注释）		
//	Status = VL53L0X_PerformXTalkCalibration(Dev, 450<<16, &XTalkCompensation);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
	//*****************************************	
	
	//启动测距激光传感器测量
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
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
//	
//	//设定温度校准值	
//	Status = VL53L0X_SetRefCalibration(Dev, VhvSettings, PhaseCal);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();

//	//设定偏移校准值
//	Status = VL53L0X_SetOffsetCalibrationDataMicroMeter(Dev, OffsetMicroMeter);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
//
//	//设定串扰校准值
//	Status = VL53L0X_SetXTalkCompensationRateMegaCps(Dev, XTalkCompensation);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
//	//启用串扰补偿
//	Status = VL53L0X_SetXTalkCompensationEnable(Dev, 1);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
	//*****************************************	
	
	//数据连续获取模式设定（必须在数据设定后使用，否则只能读取一次数值）
	Status = VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);  //连续读取
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	
	//中断设置函数*****************************
	//IO口状态设置
	Status = VL53L0X_SetGpioConfig(Dev, 0, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING, 
		VL53L0X_GPIOFUNCTIONALITY_NEW_MEASURE_READY, VL53L0X_INTERRUPTPOLARITY_LOW);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	//*****************************************

	Status = VL53L0X_StartMeasurement(Dev);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
}


//关闭测距激光传感器测距（传感器开启后使用，一般不关）
//未经检验，如非用不可，请联系YL测试功能完整性！！！
void RangingLaserClose(void)
{
	Status = VL53L0X_StopMeasurement(Dev);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	RangingLaserDistance = 0;
}

//测距激光传感器当前距离获取  单位：mm
uint16_t RangingLaserDistanceGet(void)
{
	if(RangingLaserDistance <= 1200)
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
//测距激光传感器当前距离中断方式读取
void RangingLaserInterruptDistanceProcess(void)
{
	Status = VL53L0X_GetRangingMeasurementData(Dev, &RangingData);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
	
	RangingLaserDistance = RangingData.RangeMilliMeter;
	Status = VL53L0X_ClearInterruptMask(Dev, VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
	if(Status != VL53L0X_ERROR_NONE)
		Error_Handler();
//	printf("%d %d %d\n", refSpadCount, isApertureSpads, OffsetMicroMeter);
}

//测距激光传感器当前距离轮询方式读取
void RangingLaserPollingDistanceProcess(void)
{
	uint8_t pMeasurementDataReady = 0;
	if(VL53L0X_GetMeasurementDataReady(Dev, &pMeasurementDataReady) == VL53L0X_ERROR_NONE)
	{
		if(pMeasurementDataReady == 1)
		{
			VL53L0X_GetRangingMeasurementData(Dev, &RangingData);
			RangingLaserDistance = RangingData.RangeMilliMeter;
			VL53L0X_ClearInterruptMask(Dev, VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
		}
	}
}