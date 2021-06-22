/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  ����
  * @brief   �����伤�⴫�����������������ƣ�
  *
  @verbatim
	�߷����ʱ���  LED�� ����͵�ƽ
  �ͷ����ʱ���  LED�� ����ߵ�ƽ

	����          �ڰ�����      �߷����� LED�� �͵�ƽ
		            ����̺��      �ͷ����� LED�� �ߵ�ƽ

	���          �ͷ����ʵ��߷�����      ������ �½���
								�߷����ʵ��ͷ�����      ������ ������
	5V����
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
 *  @defgroup �ⲿ����
 *  @brief 
 *
**/
//�����伤���ʼ��
void DiffuseReflectionLaserInit(void)
{
	Left_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, LEFT_DRLASER_GPIO_PIN);
	Right_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, RIGHT_DRLASER_GPIO_PIN);
	LeftDiffuseReflectionLaserChangeReset();
	RightDiffuseReflectionLaserChangeReset();
}

//�������伤��ֵ��ȡ
GPIO_PinState LeftDiffuseReflectionLaserStateGet(void)  
{
	return Left_DRLaser_State;
}

//�������伤��ֵ��ȡ
GPIO_PinState RightDiffuseReflectionLaserStateGet(void)  
{
  return Right_DRLaser_State;
}

//�������伤��仯��־��ȡ
DiffuseReflectionLaser_Change_State LeftDiffuseReflectionLaserIsChange(void)  
{
	return Left_DFLaser_Change_State;
}

//�������伤��仯��־��ȡ
DiffuseReflectionLaser_Change_State RightDiffuseReflectionLaserIsChange(void)  
{
	return Right_DFLaser_Change_State;
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
void DiffuseReflectionLaserStateJudge(void)
{
	static uint16_t CorrectFlag = 0;

	//���������ߵ�ƽ�ı�
	if(LeftDiffuseReflectionLaserIsChange())
	{
		LeftDiffuseReflectionLaserChangeReset();
		Left_DRLaser_State = !Left_DRLaser_State;
	}	
	//��������ұߵ�ƽ�ı�
	else if(RightDiffuseReflectionLaserIsChange())
	{
		RightDiffuseReflectionLaserChangeReset();
		Right_DRLaser_State = !Right_DRLaser_State;
	}
	//�������
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

//�������伤��仯��־��һ
void LeftDiffuseReflectionLaserChangeSet(void)  
{
    Left_DFLaser_Change_State = Changed;
}

//�������伤��仯��־��һ
void RightDiffuseReflectionLaserChangeSet(void)  
{
    Right_DFLaser_Change_State = Changed;
}

//�������伤��仯��־����
void LeftDiffuseReflectionLaserChangeReset(void)  
{
  Left_DFLaser_Change_State = UnChange;
}

//�������伤��仯��־����
void RightDiffuseReflectionLaserChangeReset(void)  
{
	Right_DFLaser_Change_State = UnChange;
}
