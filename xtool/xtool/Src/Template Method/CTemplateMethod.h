#pragma once

#include "../CDesignMode.h"

#include "CApplication.h"
#include "CDataBase.h"

/*
	Template Method模式是一种非常基础性的设计模式，在面向对象系统中有大量的应用
	它用最简洁的机制 (虚函数的多态) 为很多应用程序框架提供了灵活的扩展点
	是代码复用方面的基本实现结构

	除了灵活应对子步骤的变化外，"不要调用我，让我来调用你" 的反向控制结构是 Template Method模式的典型应用
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

