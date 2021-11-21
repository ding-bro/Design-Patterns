#pragma once

#include "../CDesignMode.h"

#include "CSaleOrder.h"

/*
	����ģʽ��������Ϊ���Ϊ����ṩ��һϵ�п����õ��㷨
	�Ӷ�����ʹ������������ʱ���������Ҫ�ڸ����㷨�н����л�
*/

/*
	Strategy ģʽ�ṩ���������ж���������һ��ѡ�����������ж���䣬�����ڽ����
	������������ж����Ĵ���ͨ������Ҫ Strategy ģʽ
*/

/*
	��� Strategy ����û��ʵ����������ô���������Ŀ��Թ���ͬһ�� Strategy���󣬴Ӷ���ʡ������
*/

class CStrategyMode : public CDesignMode
{
public:
	CStrategyMode();

	~CStrategyMode();

	void ShowProper();

	void ShowModerate() {}

	void ShowInappropriate();

public:
	CSaleOrderInappropriate* m_pSaleOrderInappropriate;

	CSaleOrder* m_pSaleOrderProper;
};

