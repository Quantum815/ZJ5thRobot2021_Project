/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  YL
  * @brief   漫反射激光传感器驱动（基本完善）
  *
  @verbatim
	高反射率表面  LED亮 输出低电平
  低反射率表面  LED灭 输出高电平

	例如          在白线上      高反射率 LED亮 低电平
		            在绿毯上      低反射率 LED灭 高电平

	因此          低反射率到高反射率      负跳变 下降沿
								高反射率到低反射率      正跳变 上升沿
	采用10ms消抖，5V供电
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "DiffuseReflectionLaser.h"

/* Define\Declare ------------------------------------------------------------*/
GPIO_PinState Left_DRLaser_State;
GPIO_PinState Right_DRLaser_State;
DiffuseReflectionLaser_Change_State Left_DFLaser_Change_State = UnChange;
DiffuseReflectionLaser_Change_State Right_DFLaser_Change_State = UnChange;

/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief 
 *
**/
//漫反射激光初始化
void DiffuseReflectionLaserInit(void)
{
	Left_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, LEFT_DRLASER_GPIO_PIN);
	Right_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, RIGHT_DRLASER_GPIO_PIN);
	DiffuseReflectionLaserChangeReset();
}

//左漫反射激光值获取
GPIO_PinState LeftDiffuseReflectionLaserStateGet(void)  
{
	return Left_DRLaser_State;
}

//右漫反射激光值获取
GPIO_PinState RightDiffuseReflectionLaserStateGet(void)  
{
  return Right_DRLaser_State;
}

//左漫反射激光变化标志获取
DiffuseReflectionLaser_Change_State LeftDiffuseReflectionLaserIsChange(void)  
{
	return Left_DFLaser_Change_State;
}

//右漫反射激光变化标志获取
DiffuseReflectionLaser_Change_State RightDiffuseReflectionLaserIsChange(void)  
{
	return Right_DFLaser_Change_State;
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
void DiffuseReflectionLaserStateJudge(void)
{
	static uint8_t LeftEliminateShakingFlag = 0;
	static uint8_t RightEliminateShakingFlag = 0;

	//如果读到左边电平改变
	if(LeftDiffuseReflectionLaserIsChange())
	{
		Left_DRLaser_State = !Left_DRLaser_State;
		LeftDiffuseReflectionLaserChangeReset();
	}
	
	//如果读到右边电平改变
	if(RightDiffuseReflectionLaserIsChange())
	{
		Right_DRLaser_State = !Right_DRLaser_State;
		RightDiffuseReflectionLaserChangeReset();
	}
}

//左漫反射激光变化标志置一
void LeftDiffuseReflectionLaserChangeSet(void)  
{
    Left_DFLaser_Change_State = Changed;
}

//右漫反射激光变化标志置一
void RightDiffuseReflectionLaserChangeSet(void)  
{
    Right_DFLaser_Change_State = Changed;
}

//左漫反射激光变化标志清零
void LeftDiffuseReflectionLaserChangeReset(void)  
{
  Left_DFLaser_Change_State = UnChange;
}

//右漫反射激光变化标志清零
void RightDiffuseReflectionLaserChangeReset(void)  
{
	Right_DFLaser_Change_State = UnChange;
}

//左右漫反射激光变化标志清零
void DiffuseReflectionLaserChangeReset(void)  
{
  LeftDiffuseReflectionLaserChangeReset();
	RightDiffuseReflectionLaserChangeReset();
}