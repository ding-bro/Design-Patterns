#include "CPrototypeMode.h"

void CPrototypeMode::ShowInappropriate()
{
	// ����ģʽд��
	m_pMainForm = new CMainFormPrototype;
	m_pMainForm->ButtonClickInappropriate(new CFactoryBinarySpliterPrototype);
	m_pMainForm->ButtonClickInappropriate(new CFactoryTxtSpliterPrototype);
	m_pMainForm->ButtonClickInappropriate(new CFactoryVedioSpliterPrototype);
}

void CPrototypeMode::ShowProper()
{
	// ԭ��ģʽд�� (����)
	m_pMainForm = new CMainFormPrototype;
	m_pMainForm->ButtonClickProper(new CCloneBinarySpliter);
	m_pMainForm->ButtonClickProper(new CCloneTxtSpliter);
	m_pMainForm->ButtonClickProper(new CCloneVedioSpliter);
}
