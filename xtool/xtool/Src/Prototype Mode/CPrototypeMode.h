#pragma once

#include "../CDesignMode.h"

#include "CFileSpliterPrototype.h"
#include "CMainFormPrototype.h"

/*
	ԭ��ģʽͬ�����ڸ���������ʹ���ߺ;������� (�ױ���)֮�����Ϲ�ϵ
	��ͬ��Ҫ����Щ "�ױ���" ӵ�� "�ȶ��Ľӿ�"
*/

/*
	ԭ��ģʽ���� "��δ����ױ����ʵ�����" ���� "ԭ�Ϳ�¡" �ķ�������
	��ʹ�����ǿ��Էǳ����Ķ�̬���� "ӵ��ĳЩ�ȶ��ӿ�" ���¶���
	���蹤��������ע��һ������Ķ��� (��ԭ��)
	Ȼ�����κ���Ҫ�ĵط���¡
*/

class CPrototypeMode : public CDesignMode
{
public:
	CPrototypeMode() {}

	~CPrototypeMode() {}

	void ShowInappropriate();

	void ShowModerate() {}

	void ShowProper();

public:
	CMainFormPrototype* m_pMainForm;
};
