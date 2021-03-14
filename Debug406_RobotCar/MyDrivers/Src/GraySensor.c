/**
  ******************************************************************************
  * @file    GraySensor.c
  * @author  YL
  * @brief   灰度传感器S515驱动
  *
  @verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "GraySensor.h"

HAL_ADC_Start(&hadc1);

void GetBatteryPowerRate(uint8_t* buffer, uint8_t FilterTimes)
{
	int i;
	uint32_t value[FilterTimes+1];
	uint32_t minValue;
	uint32_t maxValue;
	uint32_t temp;
	uint32_t allValue = 0;
	float BatteryPowerRate;
	
	for(i=0; i<FilterTimes; i++)  //滤波
	{
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 10);       
		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
		{
			value[i] = HAL_ADC_GetValue(&hadc1);
			allValue += value[i];
		}                
	}
	
	minValue = value[0];
	maxValue = value[0];
	for(i=0; i<FilterTimes; i++)
	{
		minValue = (minValue<value[i])?minValue:value[i];
		maxValue = (value[i]<maxValue)?maxValue:value[i];    
	}         
	BatteryPowerRate = (allValue-minValue-maxValue)/(FilterTimes-2)/4096.0*100;
	temp = BatteryPowerRate / 0.5;
	if(temp%2)
		BatteryPowerRate = (temp + 1) * 0.5;
	else
		BatteryPowerRate = temp * 0.5;
	if(BatteryPowerRate >= 100)
		BatteryPowerRate = 100;
	
	memset(buffer, 0x00, sizeof(*buffer));
	sprintf((char*)buffer, "%.0f%%   ", BatteryPowerRate);
	if(BatteryPowerRate <= 15)
		Gui_DrawFont_GBK24(105, 60, RED, WHITE, buffer);
	else if(BatteryPowerRate <= 60)
		Gui_DrawFont_GBK24(105, 60, MAGENTA, WHITE, buffer);
	else
		Gui_DrawFont_GBK24(105, 60, BLUE, WHITE, buffer);
	printf("%f", BatteryPowerRate);
}