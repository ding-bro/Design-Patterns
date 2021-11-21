#pragma once

#include "../CDesignMode.h"

#include "CMainFormFactory.h"
#include "CFileSpliter.h"

/*
	����ģʽ���ڸ���������ʹ���ߺ;�������֮�����Ϲ�ϵ
	���һ�������仯�ľ������ͣ�����Ϲ�ϵ (new) �ᵼ������Ĵ���
*/

/*
	����ģʽͨ�����������ַ�������Ҫ�����ľ���������ӳٵ����࣬�Ӷ�ʵ��һ����չ
	���Ǹ��ĵĲ��ԣ��ϺõĽ�������ֽ���ϵĹ�ϵ
*/

/*
	����ģʽ��� "��������" ������仯��ȱ������Ҫ�� ��������/���� ��ͬ
*/

class CFactoryMode : public CDesignMode
{
public:
	CFactoryMode();

	~CFactoryMode();

	void ShowInappropriate();

	void ShowModerate() {}

	void ShowProper();

public:
	CMainFormFactoryInappropriate* m_pMainFormInappropriate;
	CMainFormFactory* m_pMainFormProper;

	CFactorySpliter* m_pFactorySpliter;
};

