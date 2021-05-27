/**
  ******************************************************************************
  * @file    RangingLaser.c
  * @author  YL
  * @brief   ��༤�⴫�����������п���������Ҫ�����
  *
  @verbatim
	3.3V����
	�ο���VL53L0X_API_v1.0.2.4823_externalx
				VL53L0X˵���ĵ�
				UM2356,UM2039
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "RangingLaser.h"

/* Define\Declare ------------------------------------------------------------*/
//VL53L0X�豸����
VL53L0X_RangingMeasurementData_t RangingData;
VL53L0X_Dev_t vl53l0x_c;
VL53L0X_DEV Dev = &vl53l0x_c;

//VL53L0XУ׼����
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
 *  @defgroup �ⲿ����
 *  @brief
 *
**/
//��༤�⴫������ʼ������༤�⴫����Ĭ�Ͽ�����
void RangingLaserInit(void)
{
  Dev->I2cHandle = &hi2c3;
  Dev->I2cDevAddr = 0x52;
	Dev->comms_type = 1;
	Dev->comms_speed_khz = 400;

	//�ر�XSHUT
  HAL_GPIO_WritePin(RANGINGLASER_XSHUT_GPIO_PORT, RANGINGLASER_XSHUT_GPIO_PIN, GPIO_PIN_RESET);
  HAL_Delay(25);
	//ʹ��XSHUT
  HAL_GPIO_WritePin(RANGINGLASER_XSHUT_GPIO_PORT, RANGINGLASER_XSHUT_GPIO_PIN, GPIO_PIN_SET);
  HAL_Delay(25);

  //�ر�stm32�ⲿ�ж�
  HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);

	//ע�⣬���º���˳��������Ķ�������������
	//��ʼ��������*****************************
//	//�ȴ��豸����
//	VL53L0X_WaitDeviceBooted(Dev);
//	if(Status!=VL53L0X_ERROR_NONE)
//	Error_Handler();
	//���ݳ�ʼ��
	if(Status == VL53L0X_ERROR_NONE)
	  Status = VL53L0X_DataInit(Dev);
	else
		Error_Handler();
	
  //��̬��ʼ��
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_StaticInit(Dev);
	else
		Error_Handler();
	//*****************************************	
	

	//���ݺ�����*******************************
	//�ο�SPADsУ׼���������⻷��Ҫ�󣬼Ӹ�У׼������У׼����ע�ͣ�
	if(Status == VL53L0X_ERROR_NONE)
	  Status = VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
	else
		Error_Handler();

	 //�¶�У׼��������ʼ��Ҳ��ʹ�ã�
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
	else
		Error_Handler();
//	//ƫ��У׼���ڰ������°Ѱ�ɫ���壨85%�����ʣ�����Լ100mm���ٷ����飬�ɱ䣩У׼���봦���У���ע�ͣ�
//	Status=VL53L0X_PerformOffsetCalibration(Dev, 100<<16, &OffsetMicroMeter);
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();
	
//  //����У׼���ϰ������°ѻ�ɫ���壨17%�����ʣ�����Լ450mm������ʵ����������޸ģ�У׼���봦���У���ע�ͣ�
//	Status = VL53L0X_PerformXTalkCalibration(Dev, 450<<16, &XTalkCompensation);            
//	if(Status != VL53L0X_ERROR_NONE)
//		Error_Handler();

		RangingLaserOpen();
	
	//����������ȡģʽ�趨�������������趨��ʹ�ã�����ֻ�ܶ�ȡһ����ֵ��
	if(Status == VL53L0X_ERROR_NONE)
		  Status = VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);  //������ȡ
	else
		Error_Handler();
	//*****************************************
	
	//����stm32�ⲿ�ж�
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}


//������༤�⴫������ࣨ�������رպ�ʹ�ã�
void RangingLaserOpen(void)
{
	//����������*******************************
//	//�趨�ο�SPADs��У׼ֵ
//	Status = VL53L0X_SetReferenceSpads(Dev, refSpadCount, isApertureSpads);   
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	
//	//�趨�¶�У׼ֵ
//	Status = VL53L0X_SetRefCalibration(Dev, VhvSettings, PhaseCal);             
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();

//	//�趨ƫ��У׼ֵ
//	Status = VL53L0X_SetOffsetCalibrationDataMicroMeter(Dev, OffsetMicroMeter);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();

//	//�趨����У׼ֵ
//	Status = VL53L0X_SetXTalkCompensationRateMegaCps(Dev, XTalkCompensation);  
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
//	//���ô��Ų���
//	Status = VL53L0X_SetXTalkCompensationEnable(Dev,1);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	//*****************************************	

	
	//�ж����ú���*****************************
	//IO��״̬����
//	Status = VL53L0X_SetGpioConfig(Dev, (uint8_t)RANGINGLASER_GPIO1_GPIO_PIN, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING,
//		VL53L0X_GPIOFUNCTIONALITY_NEW_MEASURE_READY, VL53L0X_INTERRUPTPOLARITY_LOW);
//	if(Status!=VL53L0X_ERROR_NONE)
//		Error_Handler();
	//*****************************************
	
  Status = VL53L0X_StartMeasurement(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
}


//�رղ�༤�⴫������ࣨ������������ʹ�ã�
void RangingLaserClose(void)
{
  Status = VL53L0X_StopMeasurement(Dev);
	if(Status!=VL53L0X_ERROR_NONE)
		Error_Handler();
	RangingLaserDistance = 0;
}

//��༤�⴫������ǰ�����ȡ  ��λ��mm
uint16_t RangingLaserDistanceGet(void)
{
	if(RangingLaserDistance <= 2000)
		return RangingLaserDistance;
	else
		return 0;
}


//�����������������޸ĺ�ʹ�ã�����������
//*****************************************************************
//*****************************************************************
/**
 ******************************************************************************
 *  @defgroup �ڲ�����
 *  @brief
 *
**/
//��༤�⴫������ǰ�����ȡ
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