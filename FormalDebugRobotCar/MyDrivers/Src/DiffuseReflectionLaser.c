/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  YL
  * @brief   漫反射激光传感器驱动
  *
  @verbatim
	高反射率表面  LED亮 输出低电平
  低反射率表面  LED灭 输出高电平

	例如          在白线上      高反射率 LED亮 低电平
		            在绿毯上      低反射率 LED灭 高电平

	因此          低反射率到高反射率      负跳变 下降沿
								高反射率到低反射率      正跳变 上升沿
	采用10ms状态机方法消抖
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
 *  @defgroup 驱动
 *  @brief 
 *
**/
void DiffuseReflectionLaserInit(void)  //漫反射激光初始化
{
	Left_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, LEFT_DRLASER_GPIO_PIN);
	Right_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, RIGHT_DRLASER_GPIO_PIN);
	DiffuseReflectionLaserChangeReset();
}

void LeftDiffuseReflectionLaserChangeSet(void)  //左漫反射激光变化标志置一
{
    Left_DFLaser_Change_State = Changed;
}

void RightDiffuseReflectionLaserChangeSet(void)  //右漫反射激光变化标志置一
{
    Right_DFLaser_Change_State = Changed;
}

void LeftDiffuseReflectionLaserChangeReset(void)  //左漫反射激光变化标志清零
{
  Left_DFLaser_Change_State = UnChange;
}

void RightDiffuseReflectionLaserChangeReset(void)  //右漫反射激光变化标志清零
{
	Right_DFLaser_Change_State = UnChange;
}

void DiffuseReflectionLaserChangeReset(void)  //左右漫反射激光变化标志清零
{
  LeftDiffuseReflectionLaserChangeReset();
	RightDiffuseReflectionLaserChangeReset();
}

void DiffuseReflectionLaserStateJudge(void)
{
	static int8_t LeftCountTimes = 0;
	static int8_t RightCountTimes = 0;

	//如果读到左边电平改变
	if(LeftDiffuseReflectionLaserIsChange() == Changed)
	{
		if (LeftDiffuseReflectionLaserStateGet() == GPIO_PIN_RESET)
    {
			//小于10就增加一次在线上的计数 否则不增加该值
			if (LeftCountTimes < 10)
			{
					LeftCountTimes++;
			}
    }
    else //不是低就是高 左边读到高电平(在毯子上)
    {
			if (LeftCountTimes > 0)
			{
					//大于0就增加一次不在线上(或者降低在线上)的计数 不大于0就不减少
					LeftCountTimes--;
			}
    }
		LeftDiffuseReflectionLaserChangeReset();
	}
	
	//如果读到右边电平改变
	if(RightDiffuseReflectionLaserIsChange() == Changed)
	{
		if (RightDiffuseReflectionLaserStateGet() == GPIO_PIN_RESET)
		{
			//小于10就增加一次在线上的计数 否则不增加该值
			if (RightCountTimes < 10)
			{
					RightCountTimes++;
			}
			RightDiffuseReflectionLaserChangeReset();
		}
		else //不是低就是高 右边读到高电平(在毯子上)
		{
			if (RightCountTimes > 0)
			{
					//大于0就增加一次不在线上(或者降低在线上)的计数 不大于0就不减少
					RightCountTimes--;
			}
			RightDiffuseReflectionLaserChangeReset();
		}
	}

	/* 完成采样 开始分析究竟反馈在线上还是不在线上 */

	//左边
	//统计到 > 4次在线上(也就是5次) 认为的却在线上
	if (LeftCountTimes > 4)
	{
		//在线上LED亮 LOW
		Left_DRLaser_State = GPIO_PIN_RESET;
	}
	else
	{
		//不在线上 HIGH
		Left_DRLaser_State = GPIO_PIN_SET;
	}

	//右边
	//统计到 > 4次在线上(也就是5次) 认为的却在线上
	if (RightCountTimes > 4)
	{
		//在线上LED亮 LOW
		Right_DRLaser_State = GPIO_PIN_RESET;
	}
	else
	{
		//不在线上LED灭 HIGH
		Right_DRLaser_State = GPIO_PIN_SET;
	}
}

/**
 ******************************************************************************
 *  @defgroup 参数获取
 *  @brief 
 *
**/
GPIO_PinState LeftDiffuseReflectionLaserStateGet(void)  //左漫反射激光值获取
{
	return Left_DRLaser_State;
}

GPIO_PinState RightDiffuseReflectionLaserStateGet(void)  //右漫反射激光值获取
{
  return Right_DRLaser_State;
}

DiffuseReflectionLaser_Change_State LeftDiffuseReflectionLaserIsChange(void)  //左漫反射激光变化标志获取
{
	return Left_DFLaser_Change_State;
}

DiffuseReflectionLaser_Change_State RightDiffuseReflectionLaserIsChange(void)  //右漫反射激光变化标志获取
{
	return Right_DFLaser_Change_State;
}