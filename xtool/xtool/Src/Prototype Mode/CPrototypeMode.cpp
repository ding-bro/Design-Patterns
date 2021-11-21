#include "CPrototypeMode.h"

void CPrototypeMode::ShowInappropriate()
{
	// 工厂模式写法
	m_pMainForm = new CMainFormPrototype;
	m_pMainForm->ButtonClickInappropriate(new CFactoryBinarySpliterPrototype);
	m_pMainForm->ButtonClickInappropriate(new CFactoryTxtSpliterPrototype);
	m_pMainForm->ButtonClickInappropriate(new CFactoryVedioSpliterPrototype);
}

void CPrototypeMode::ShowProper()
{
	// 原型模式写法 (拷贝)
	m_pMainForm = new CMainFormPrototype;
	m_pMainForm->ButtonClickProper(new CCloneBinarySpliter);
	m_pMainForm->ButtonClickProper(new CCloneTxtSpliter);
	m_pMainForm->ButtonClickProper(new CCloneVedioSpliter);
}
