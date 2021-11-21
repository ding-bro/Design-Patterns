#include "CMainFormFactory.h"

void CMainFormFactoryInappropriate::ButtonOneClick()
{
	m_pMessageBox->open();
	m_pProgressBar->setValue(100);

	// 这样的写法就是编译式依赖
	// 写法当然是正确的，但是对编译形成了很强的依赖，并且分割器的需求需要在函数里写死
	// 对 C++ 的new形成了很强的依赖
	// 如果将来有100种不同形式的分割器需求，就需要不断的在此函数里累积添加

	CFileSpliter* pBinarySpliter = new CBinarySpliter; // 尽管是抽象类声明，但是还是依赖了具体类
	pBinarySpliter->Split();

	CFileSpliter* pTxtSpliter = new CTxtSpliter;
	pTxtSpliter->Split();

	CFileSpliter* pImageSpliter = new CImageSpliter;
	pImageSpliter->Split();

	CFileSpliter* pVideoSpliter = new CVideoSpliter;
	pVideoSpliter->Split();

	delete pBinarySpliter;
	delete pTxtSpliter;
	delete pImageSpliter;
	delete pVideoSpliter;
}

void CMainFormFactory::ButtonOneClick()
{
	// 所有的设计模式，包括工厂模式，其实都秉承着一个原则
	// 那就是把编译式依赖变成运行时依赖
	// 也就是继承、多态、类之间的动态跳转的概念

	m_pMessageBox->open();
	m_pProgressBar->setValue(100);

	// 虽然这种模式在 CFactoryMode 里仍然需要重复对 CFactorySpliter指针 赋值
	// 需要强调的是，所有的设计模式不可能完全消除类的依赖，这是做不到的
	// 设计模式的作用是在具体类实现里减少编译式依赖

	CFileSpliter* pFileSpliter = nullptr;
	pFileSpliter = m_pFactorySpliter->getFileSpliter(); // 中间的生产基类调用父类接口
	pFileSpliter->Split();
}
