#pragma once

#include "CFileSpliter.h"

struct SMessageBox
{
	void open() {}
};
struct SProgressBar
{
	void setValue(int iValue) {}
};
struct SButton
{
	void click() {}
};

class CMainFormFactoryInappropriate
{
public:

	void ButtonOneClick();

public:
	SMessageBox* m_pMessageBox;
	SProgressBar* m_pProgressBar;
	SButton* m_pButton;
};

class CMainFormFactory
{
public:
	CMainFormFactory(CFactorySpliter* pFactory) : m_pFactorySpliter(pFactory) {}

	~CMainFormFactory() { delete m_pFactorySpliter; m_pFactorySpliter = nullptr; }

	void ButtonOneClick();

public:
	CFactorySpliter* m_pFactorySpliter;

	SMessageBox* m_pMessageBox;
	SProgressBar* m_pProgressBar;
	SButton* m_pButton;
};