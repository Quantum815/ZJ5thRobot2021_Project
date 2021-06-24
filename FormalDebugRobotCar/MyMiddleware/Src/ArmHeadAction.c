/**
  ******************************************************************************
  * @file    ArmHeadAction.c
  * @author  葛子磊
  * @brief   摇头举手动作
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "ArmHeadAction.h"


/**
 ******************************************************************************
 *  @defgroup 外部调用
 *  @brief 
 *
**/
//摇头动作 （先左摇60度，再右摇120度，最后回到原位）
void ShakeHead()
{
    int16_t minitimeA = 0;
    minitimeA++;
    if((minitimeA>=198)&&(minitimeA<=200))
    {
        ServoMotorAngleSet(TIM_CHANNEL_2,30);
    }
    if((minitimeA>398)&&(minitimeA<=400))
    {
        ServoMotorAngleSet(TIM_CHANNEL_2,150);
    }
    if(minitimeA>400)
    {
        minitimeA=0;
        ServoMotorAngleSet(TIM_CHANNEL_2,90);
    }
}
//表示判断的举手动作 （两只手臂先后举起下降） 
void UpHand()
{
    int16_t minitimeB = 0;
    minitimeB++;
    if((minitimeB>=198)&&(minitimeB<=200))
    {
        ServoMotorAngleSet(TIM_CHANNEL_1,180);
        ServoMotorAngleSet(TIM_CHANNEL_3,180);
    }
    if((minitimeB>=498)&&(minitimeB<500))
    {
        minitimeB=0;
        ServoMotorAngleSet(TIM_CHANNEL_1,30);
        ServoMotorAngleSet(TIM_CHANNEL_3,60);
    }
    
}

//撞击前的举手动作（两只手臂举至某一相同度数）
void UpHitHand()
{
    ServoMotorAngleSet(TIM_CHANNEL_1,120);
    ServoMotorAngleSet(TIM_CHANNEL_3,120);
}

//撞击后的手臂下降动作 （两只手臂回到原位）
void DownHitHand()
{
    ServoMotorAngleSet(TIM_CHANNEL_1,30);
    ServoMotorAngleSet(TIM_CHANNEL_3,60);
}


