#pragma once

#include "../CDesignMode.h"

#include "CApplication.h"
#include "CDataBase.h"

/*
	Template Methodģʽ��һ�ַǳ������Ե����ģʽ�����������ϵͳ���д�����Ӧ��
	��������Ļ��� (�麯���Ķ�̬) Ϊ�ܶ�Ӧ�ó������ṩ��������չ��
	�Ǵ��븴�÷���Ļ���ʵ�ֽṹ

	�������Ӧ���Ӳ���ı仯�⣬"��Ҫ�����ң�������������" �ķ�����ƽṹ�� Template Methodģʽ�ĵ���Ӧ��
*/

class CTemplateMethod : public CDesignMode
{
public:
	CTemplateMethod();

	~CTemplateMethod();

	void ShowProper();

	void ShowModerate() {}

	void ShowInappropriate();

public:

	CApplicationInappropriate* m_pCappInappropriate;

	CDataBaseInappropriate* m_pDataInappropriate;

	CApplication* m_pCappProper;

	CDataBase* m_pDataProper;
};

