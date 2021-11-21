#include "CMainFormPrototype.h"

void CMainFormPrototype::ButtonClickInappropriate(CFactorySpliterPortotype* pFactorySpliter)
{
	m_pSpliterPrototype = pFactorySpliter->getFactory();
	m_pSpliterPrototype->split();
}

void CMainFormPrototype::ButtonClickProper(CPrototypeFactorySpliter* pClonePrototype)
{
	m_pClonePrototype = pClonePrototype->getClone();
	m_pClonePrototype->split();
}
