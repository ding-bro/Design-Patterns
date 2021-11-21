#include "CStrategyMode.h"

CStrategyMode::CStrategyMode()
{
	this->m_pSaleOrderInappropriate = new CSaleOrderInappropriate;
	this->m_pSaleOrderProper = new CSaleOrder;
}

CStrategyMode::~CStrategyMode()
{
	delete this->m_pSaleOrderInappropriate;
	delete this->m_pSaleOrderProper;
}

void CStrategyMode::ShowInappropriate()
{
	// ���������˰��
	// ���ʹ�������ķ�����������˰����������ۻ���ӣ������100�����󣬾�Ҫ���������100���ж�

	m_pSaleOrderInappropriate->CalcTax(CN_TAX);
	m_pSaleOrderInappropriate->CalcTax(EN_TAX);
	m_pSaleOrderInappropriate->CalcTax(US_TAX);
	m_pSaleOrderInappropriate->CalcTax(RU_TAX);
}

void CStrategyMode::ShowProper()
{
	// ���ö�̬���õĻ����Ͳ���������ڲ�ȥ�ۼ����

	CCnTax* pCN = new CCnTax;
	m_pSaleOrderProper->CalcTax(pCN);

	CUsTax* pUS = new CUsTax;
	m_pSaleOrderProper->CalcTax(pUS);

	CEnTax* pEN = new CEnTax;
	m_pSaleOrderProper->CalcTax(pEN);

	CRuTax* pRU = new CRuTax;
	m_pSaleOrderProper->CalcTax(pRU);

	delete pCN;
	delete pUS;
	delete pEN;
	delete pRU;
}
