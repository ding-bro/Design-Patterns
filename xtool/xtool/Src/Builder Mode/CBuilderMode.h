#pragma once

#include "../CDesignMode.h"
#include "CHouse.h"

/*
	Builder ģʽ��Ҫ���� "�ֲ��蹹��һ�����ӵĶ���"
	�������� "�ֲ���" ��һ���ȶ����㷨
	�����Ӷ���ĸ��������򾭳��仯
*/

/*
	�仯���������װ������
	Builderģʽ��ҪӦ�� "���Ӷ����������" ��Ƶ������䶯
	��ȱ����������Ӧ�� "�ֲ��蹹���㷨" ������䶯
*/

class CBuilderMode : public CDesignMode
{
public:
	CBuilderMode() = default;
	~CBuilderMode() = default;

	void ShowInappropriate();

	void ShowModerate();

	void ShowProper();

public:
	std::unique_ptr<CHouse>m_punHouse;

};

