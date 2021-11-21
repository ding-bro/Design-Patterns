#include "CBuilderMode.h"

void CBuilderMode::ShowInappropriate()
{
	// 普通的写法就是建立一个通用的方法，就是普通的多态
	// 方法里包含各种子类的各种方法
	// 以此实现方法的统一

	// 建造石头屋......
	std::unique_ptr<CHouse>punHouse = std::make_unique<CStoneHouse>();
	punHouse->init();

	punHouse.reset();

	// 建造黄金屋......
	punHouse = std::make_unique<CGoldHouse>();
	punHouse->init();
}

void CBuilderMode::ShowModerate()
{
}

// 什么玩意儿?
void CBuilderMode::ShowProper()
{
	// 其实这样写反而变得很复杂而且难以理解了
	CHouse* pHouse = nullptr;

	std::unique_ptr<CHouseDirector>punDirector = std::make_unique<CHouseDirector>(new CStoneHouseBuilder);
	pHouse = punDirector->Config();
}
