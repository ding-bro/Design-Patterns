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
	// 计算各国的税务
	// 如果使用这样的方法，必须在税务类钟逐个累积添加，如果有100个需求，就要在类钟添加100个判断

	m_pSaleOrderInappropriate->CalcTax(CN_TAX);
	m_pSaleOrderInappropriate->CalcTax(EN_TAX);
	m_pSaleOrderInappropriate->CalcTax(US_TAX);
	m_pSaleOrderInappropriate->CalcTax(RU_TAX);
}

void CStrategyMode::ShowProper()
{
	// 利用多态调用的话，就不用在类的内部去累计添加

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
