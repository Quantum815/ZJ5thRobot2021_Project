/**
  ******************************************************************************
  * @file    RangingLaser.c
  * @author  YL
  * @brief   ��༤�⴫�����������д��Ľ��� 6.1
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
const uint32_t refSpadCount = 3;
const uint8_t isApertureSpads = 0;
uint8_t VhvSettings;
uint8_t PhaseCal;
const int32_t OffsetMicroMeter = 12000;
FixPoint1616_t XTalkCompensation;

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

	//�ر�XSHUT(Ӳ������ģʽ�ĸ�λ����ˣ��͵�ƽ��Ч)
  HAL_GPIO_WritePin(RANGINGLASER_XSHUT_GPIO_PORT, RANGINGLASER_XSHUT_GPIO_PIN, GPIO_PIN_RESET);
  HAL_Delay(20);
	//ʹ��XSHUT
  HAL_GPIO_WritePin(RANGINGLASER_XSHUT_GPIO_PORT, RANGINGLASER_XSHUT_GPIO_PIN, GPIO_PIN_SET);
  HAL_Delay(20);

  //�ر�stm32�ⲿ�ж�
  HAL_NVIC_DisableIRQ(EXTI9_5_IRQn);

	//ע�⣬���³�ʼУ׼������˳���ܸĶ�������������
	
	//��ʼ��������*****************************
	//ȷ���豸����׼������
	VL53L0X_WaitDeviceBooted(Dev);
	
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
//	//�ο�SPADsУ׼���������⻷��Ҫ�󣬼Ӹ�У׼������У׼����ע�ͣ�
//	if(Status == VL53L0X_ERROR_NONE)
//		Status = VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads);
//	else
//		Error_Handler();

	 //�¶�У׼��������ʼ��Ҳ��ʹ�ã�
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal);
	else
		Error_Handler();
	
//	//ƫ��У׼���ڰ������°Ѱ�ɫ���壨88%�����ʣ�����Լ100mm���ٷ����飩У׼���봦���У���ע�ͣ�
//	if(Status == VL53L0X_ERROR_NONE)	
//		Status = VL53L0X_PerformOffsetCalibration(Dev, 100<<16, &OffsetMicroMeter);
//	else
//		Error_Handler();
	
//  //����У׼���ϰ������°ѻ�ɫ���壨17%�����ʣ�����Լ450mm������ʵ����������޸ģ�У׼���봦���У���ע�ͣ�
//	if(Status == VL53L0X_ERROR_NONE)		
//		Status = VL53L0X_PerformXTalkCalibration(Dev, 450<<16, &XTalkCompensation);
//	else
//		Error_Handler();
	//*****************************************	
	
	//������༤�⴫��������
	RangingLaserOpen();
	
	//����stm32�ⲿ�ж�
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}


//������༤�⴫������ࣨ�������رպ�ʹ�ã�
void RangingLaserOpen(void)
{
	//����������*******************************
	//�趨�ο�SPADs��У׼ֵ
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_SetReferenceSpads(Dev, refSpadCount, isApertureSpads);
	else
		Error_Handler();
	
	//�趨�¶�У׼ֵ
	if(Status == VL53L0X_ERROR_NONE)	
		Status = VL53L0X_SetRefCalibration(Dev, VhvSettings, PhaseCal);
	else
		Error_Handler();

	//�趨ƫ��У׼ֵ
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_SetOffsetCalibrationDataMicroMeter(Dev, OffsetMicroMeter);
	else
		Error_Handler();

//	//�趨����У׼ֵ
//	if(Status == VL53L0X_ERROR_NONE)
//		Status = VL53L0X_SetXTalkCompensationRateMegaCps(Dev, XTalkCompensation);
//	else
//		Error_Handler();
//	//���ô��Ų���
//	if(Status == VL53L0X_ERROR_NONE)
//		Status = VL53L0X_SetXTalkCompensationEnable(Dev, 1);
//	else
//		Error_Handler();
	//*****************************************	
	
	//����������ȡģʽ�趨�������������趨��ʹ�ã�����ֻ�ܶ�ȡһ����ֵ��
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);  //������ȡ
	else
		Error_Handler();
	
	//�ж����ú���*****************************
	//IO��״̬����
//	if(Status == VL53L0X_ERROR_NONE)
//		Status = VL53L0X_SetGpioConfig(Dev, 0, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING, 
//			VL53L0X_GPIOFUNCTIONALITY_NEW_MEASURE_READY, VL53L0X_INTERRUPTPOLARITY_LOW);
//	else
//		Error_Handler();
	//*****************************************

	if(Status == VL53L0X_ERROR_NONE)	
		Status = VL53L0X_StartMeasurement(Dev);
	else
		Error_Handler();
}


//�رղ�༤�⴫������ࣨ������������ʹ�ã�һ�㲻�أ�
//δ�����飬����ò��ɣ�����ϵYL���Թ��������ԣ�����
void RangingLaserClose(void)
{
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_StopMeasurement(Dev);
	else
		Error_Handler();
	RangingLaserDistance = 0;
}

//��༤�⴫������ǰ�����ȡ  ��λ��mm
uint16_t RangingLaserDistanceGet(void)
{
	if(RangingLaserDistance <= 1200)
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
//��༤�⴫������ǰ�����жϷ�ʽ��ȡ
void RangingLaserInterruptDistanceProcess(void)
{
	if(Status == VL53L0X_ERROR_NONE)
		Status = VL53L0X_GetRangingMeasurementData(Dev, &RangingData);
	else
		Error_Handler();
	
	RangingLaserDistance = RangingData.RangeMilliMeter;
	Status = VL53L0X_ClearInterruptMask(Dev, VL53L0X_REG_SYSTEM_INTERRUPT_GPIO_NEW_SAMPLE_READY);
}

//��༤�⴫������ǰ������ѯ��ʽ��ȡ
void RangingLaserPollingDistanceProcess(void)
{
	uint8_t pMeasurementDataReady = 0;
	if(VL53L0X_GetMeasurementDataReady(Dev, &pMeasurementDataReady) == VL53L0X_ERROR_NONE)
	{
		if(pMeasurementDataReady == 1)
		{
			VL53L0X_GetRangingMeasurementData(Dev, &RangingData);
			RangingLaserDistance = RangingData.RangeMilliMeter;
		}
	}
}