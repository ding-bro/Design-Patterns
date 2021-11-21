#pragma once

#include "../CDesignMode.h"

#include "CSaleOrder.h"

/*
	策略模式极其子类为组件为组件提供了一系列可重用的算法
	从而可以使得类型在运行时方便根据需要在各个算法中进行切换
*/

/*
	Strategy 模式提供了用条件判断语句的另外一种选择，消除条件判断语句，就是在解耦合
	含有许多条件判断语句的代码通常都需要 Strategy 模式
*/

/*
	如果 Strategy 对象没有实例变量，那么各个上下文可以共享同一个 Strategy对象，从而节省对象开销
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

