#pragma once

#include "CFileSpliterPrototype.h"

class CMainFormPrototype
{
public:
	CMainFormPrototype() {}

	~CMainFormPrototype() {}

	void ButtonClickInappropriate(CFactorySpliterPortotype* pFactorySpliter);

	void ButtonClickProper(CPrototypeFactorySpliter* pClonePrototype);

public:
	CFileSpliterPrototype* m_pSpliterPrototype;

	CPrototypeFactorySpliter* m_pClonePrototype;
};
