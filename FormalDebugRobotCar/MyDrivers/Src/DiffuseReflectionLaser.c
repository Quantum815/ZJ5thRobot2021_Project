/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  俞立
  * @brief   漫反射激光传感器驱动（基本完善）
  *
  @verbatim
	高反射率表面  LED亮 输出低电平
  低反射率表面  LED灭 输出高电平

	例如          在白线上      高反射率 LED亮 低电平
		            在绿毯上      低反射率 LED灭 高电平

	因此          低反射率到高反射率      负跳变 下降沿
								高反射率到低反射率      正跳变 上升沿
	5V供电
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
	LeftDiffuseReflectionLaserChangeReset();
	RightDiffuseReflectionLaserChangeReset();
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
	static uint16_t CorrectFlag = 0;

	//如果读到左边电平改变
	if(LeftDiffuseReflectionLaserIsChange())
	{
		LeftDiffuseReflectionLaserChangeReset();
		Left_DRLaser_State = !Left_DRLaser_State;
	}	
	//如果读到右边电平改变
	else if(RightDiffuseReflectionLaserIsChange())
	{
		RightDiffuseReflectionLaserChangeReset();
		Right_DRLaser_State = !Right_DRLaser_State;
	}
	//错误矫正
	else
	{
		CorrectFlag++;
		if(CorrectFlag == CORRECT_TIME/10)
		{
			CorrectFlag = 0;
			Left_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, LEFT_DRLASER_GPIO_PIN);
			Right_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, RIGHT_DRLASER_GPIO_PIN);
		}
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
