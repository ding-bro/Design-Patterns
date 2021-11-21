#include "CSaleOrder.h"

void CSaleOrderInappropriate::CalcTax(ETax etaxTemp)
{
	// 不好的方法，逐个累加

	if (CN_TAX == etaxTemp)
	{
		CCnTaxInappropriate* pCN = new CCnTaxInappropriate;
		pCN->CalcTax();

		delete pCN;
	}
	else if (US_TAX == etaxTemp)
	{
		CUsTaxInappropriate* pUS = new CUsTaxInappropriate;
		pUS->CalcTax();

		delete pUS;
	}
	else if (EN_TAX == etaxTemp)
	{
		CEnTaxInappropriate* pEN = new CEnTaxInappropriate;
		pEN->CalcTax();

		delete pEN;
	}
	else if (RU_TAX == etaxTemp)
	{
		CRuTaxInappropriate* pRU = new CRuTaxInappropriate;
		pRU->CalcTax();

		delete pRU;
	}
}

void CCnTaxInappropriate::CalcTax()
{
}
void CUsTaxInappropriate::CalcTax()
{
}
void CEnTaxInappropriate::CalcTax()
{
}
void CRuTaxInappropriate::CalcTax()
{
}

void CCnTax::CalcTax()
{
	return;
}
void CUsTax::CalcTax()
{
	return;
}
void CEnTax::CalcTax()
{
	return;
}
void CRuTax::CalcTax()
{
	return;
}

void CSaleOrder::CalcTax(CTaxTransfer* pTaxTransfer)
{
	pTaxTransfer->CalcTax();
}
