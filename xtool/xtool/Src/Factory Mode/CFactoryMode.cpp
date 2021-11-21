#include "CFactoryMode.h"

CFactoryMode::CFactoryMode()
{
	m_pMainFormInappropriate = new CMainFormFactoryInappropriate;

	m_pFactorySpliter = new CFactoryBinarySpliter;
	m_pMainFormProper = new CMainFormFactory(m_pFactorySpliter);
}

CFactoryMode::~CFactoryMode()
{
	delete m_pMainFormInappropriate;
	delete m_pMainFormProper;
	delete m_pFactorySpliter;

	m_pMainFormInappropriate = nullptr;
	m_pMainFormProper = nullptr;
	m_pFactorySpliter = nullptr;
}

void CFactoryMode::ShowInappropriate()
{
	m_pMainFormInappropriate->ButtonOneClick();
}

void CFactoryMode::ShowProper()
{
	m_pMainFormProper->ButtonOneClick();

	m_pFactorySpliter = new CFactoryTxtSpliter;
	m_pMainFormProper = new CMainFormFactory(m_pFactorySpliter);
	m_pMainFormProper->ButtonOneClick();

	m_pFactorySpliter = new CFactoryImageSpliter;
	m_pMainFormProper = new CMainFormFactory(m_pFactorySpliter);
	m_pMainFormProper->ButtonOneClick();

	m_pFactorySpliter = new CFactoryVideoSpliter;
	m_pMainFormProper = new CMainFormFactory(m_pFactorySpliter);
	m_pMainFormProper->ButtonOneClick();
}
