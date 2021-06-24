/**
  ******************************************************************************
  * @file    ArmHeadAction.c
  * @author  ������
  * @brief   ҡͷ���ֶ���
  *
	@verbatim
	
	@endverbatim
  * @{
**/

/* Includes ------------------------------------------------------------------*/
#include "ArmHeadAction.h"


/**
 ******************************************************************************
 *  @defgroup �ⲿ����
 *  @brief 
 *
**/
//ҡͷ���� ������ҡ60�ȣ�����ҡ120�ȣ����ص�ԭλ��
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
//��ʾ�жϵľ��ֶ��� ����ֻ�ֱ��Ⱥ�����½��� 
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

//ײ��ǰ�ľ��ֶ�������ֻ�ֱ۾���ĳһ��ͬ������
void UpHitHand()
{
    ServoMotorAngleSet(TIM_CHANNEL_1,120);
    ServoMotorAngleSet(TIM_CHANNEL_3,120);
}

//ײ������ֱ��½����� ����ֻ�ֱۻص�ԭλ��
void DownHitHand()
{
    ServoMotorAngleSet(TIM_CHANNEL_1,30);
    ServoMotorAngleSet(TIM_CHANNEL_3,60);
}


