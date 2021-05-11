/**
  ******************************************************************************
  * @file    DiffuseReflectionLaser.c
  * @author  YL
  * @brief   �����伤�⴫��������
  *
  @verbatim
	�߷����ʱ���  LED�� ����͵�ƽ
  �ͷ����ʱ���  LED�� ����ߵ�ƽ

	����          �ڰ�����      �߷����� LED�� �͵�ƽ
		            ����̺��      �ͷ����� LED�� �ߵ�ƽ

	���          �ͷ����ʵ��߷�����      ������ �½���
								�߷����ʵ��ͷ�����      ������ ������
	����10ms״̬����������
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
 *  @defgroup ����
 *  @brief 
 *
**/
void DiffuseReflectionLaserInit(void)  //�����伤���ʼ��
{
	Left_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, LEFT_DRLASER_GPIO_PIN);
	Right_DRLaser_State = HAL_GPIO_ReadPin(DRLASER_GPIO_PORT, RIGHT_DRLASER_GPIO_PIN);
	DiffuseReflectionLaserChangeReset();
}

void LeftDiffuseReflectionLaserChangeSet(void)  //�������伤��仯��־��һ
{
    Left_DFLaser_Change_State = Changed;
}

void RightDiffuseReflectionLaserChangeSet(void)  //�������伤��仯��־��һ
{
    Right_DFLaser_Change_State = Changed;
}

void LeftDiffuseReflectionLaserChangeReset(void)  //�������伤��仯��־����
{
  Left_DFLaser_Change_State = UnChange;
}

void RightDiffuseReflectionLaserChangeReset(void)  //�������伤��仯��־����
{
	Right_DFLaser_Change_State = UnChange;
}

void DiffuseReflectionLaserChangeReset(void)  //���������伤��仯��־����
{
  LeftDiffuseReflectionLaserChangeReset();
	RightDiffuseReflectionLaserChangeReset();
}

void DiffuseReflectionLaserStateJudge(void)
{
	static int8_t LeftCountTimes = 0;
	static int8_t RightCountTimes = 0;

	//���������ߵ�ƽ�ı�
	if(LeftDiffuseReflectionLaserIsChange() == Changed)
	{
		if (LeftDiffuseReflectionLaserStateGet() == GPIO_PIN_RESET)
    {
			//С��10������һ�������ϵļ��� �������Ӹ�ֵ
			if (LeftCountTimes < 10)
			{
					LeftCountTimes++;
			}
    }
    else //���ǵ;��Ǹ� ��߶����ߵ�ƽ(��̺����)
    {
			if (LeftCountTimes > 0)
			{
					//����0������һ�β�������(���߽���������)�ļ��� ������0�Ͳ�����
					LeftCountTimes--;
			}
    }
		LeftDiffuseReflectionLaserChangeReset();
	}
	
	//��������ұߵ�ƽ�ı�
	if(RightDiffuseReflectionLaserIsChange() == Changed)
	{
		if (RightDiffuseReflectionLaserStateGet() == GPIO_PIN_RESET)
		{
			//С��10������һ�������ϵļ��� �������Ӹ�ֵ
			if (RightCountTimes < 10)
			{
					RightCountTimes++;
			}
			RightDiffuseReflectionLaserChangeReset();
		}
		else //���ǵ;��Ǹ� �ұ߶����ߵ�ƽ(��̺����)
		{
			if (RightCountTimes > 0)
			{
					//����0������һ�β�������(���߽���������)�ļ��� ������0�Ͳ�����
					RightCountTimes--;
			}
			RightDiffuseReflectionLaserChangeReset();
		}
	}

	/* ��ɲ��� ��ʼ�����������������ϻ��ǲ������� */

	//���
	//ͳ�Ƶ� > 4��������(Ҳ����5��) ��Ϊ��ȴ������
	if (LeftCountTimes > 4)
	{
		//������LED�� LOW
		Left_DRLaser_State = GPIO_PIN_RESET;
	}
	else
	{
		//�������� HIGH
		Left_DRLaser_State = GPIO_PIN_SET;
	}

	//�ұ�
	//ͳ�Ƶ� > 4��������(Ҳ����5��) ��Ϊ��ȴ������
	if (RightCountTimes > 4)
	{
		//������LED�� LOW
		Right_DRLaser_State = GPIO_PIN_RESET;
	}
	else
	{
		//��������LED�� HIGH
		Right_DRLaser_State = GPIO_PIN_SET;
	}
}

/**
 ******************************************************************************
 *  @defgroup ������ȡ
 *  @brief 
 *
**/
GPIO_PinState LeftDiffuseReflectionLaserStateGet(void)  //�������伤��ֵ��ȡ
{
	return Left_DRLaser_State;
}

GPIO_PinState RightDiffuseReflectionLaserStateGet(void)  //�������伤��ֵ��ȡ
{
  return Right_DRLaser_State;
}

DiffuseReflectionLaser_Change_State LeftDiffuseReflectionLaserIsChange(void)  //�������伤��仯��־��ȡ
{
	return Left_DFLaser_Change_State;
}

DiffuseReflectionLaser_Change_State RightDiffuseReflectionLaserIsChange(void)  //�������伤��仯��־��ȡ
{
	return Right_DFLaser_Change_State;
}