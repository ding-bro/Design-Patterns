#include "CBuilderMode.h"

void CBuilderMode::ShowInappropriate()
{
	// ��ͨ��д�����ǽ���һ��ͨ�õķ�����������ͨ�Ķ�̬
	// �����������������ĸ��ַ���
	// �Դ�ʵ�ַ�����ͳһ

	// ����ʯͷ��......
	std::unique_ptr<CHouse>punHouse = std::make_unique<CStoneHouse>();
	punHouse->init();

	punHouse.reset();

	// ����ƽ���......
	punHouse = std::make_unique<CGoldHouse>();
	punHouse->init();
}

void CBuilderMode::ShowModerate()
{
}

// ʲô�����?
void CBuilderMode::ShowProper()
{
	// ��ʵ����д������úܸ��Ӷ������������
	CHouse* pHouse = nullptr;

	std::unique_ptr<CHouseDirector>punDirector = std::make_unique<CHouseDirector>(new CStoneHouseBuilder);
	pHouse = punDirector->Config();
}
