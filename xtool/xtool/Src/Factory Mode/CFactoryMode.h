#pragma once

#include "../CDesignMode.h"

#include "CMainFormFactory.h"
#include "CFileSpliter.h"

/*
	工厂模式用于隔离类对象的使用者和具体类型之间的耦合关系
	面对一个经常变化的具体类型，紧耦合关系 (new) 会导致软件的脆弱
*/

/*
	工厂模式通过面向对象的手法，将所要创建的具体对象工作延迟到子类，从而实现一种扩展
	而非更改的策略，较好的解决了这种紧耦合的关系
*/

/*
	工厂模式解决 "单个对象" 的需求变化，缺点在于要求 创建方法/参数 相同
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

