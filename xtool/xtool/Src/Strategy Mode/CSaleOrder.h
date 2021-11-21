#pragma once

enum ETax
{
	CN_TAX,
	US_TAX,
	EN_TAX,
	RU_TAX
};

class CCnTaxInappropriate
{
public:
	void CalcTax();
};
class CUsTaxInappropriate
{
public:
	void CalcTax();
};
class CEnTaxInappropriate
{
public:
	void CalcTax();
};
class CRuTaxInappropriate
{
public:
	void CalcTax();
};

class CSaleOrderInappropriate
{
public:

	CSaleOrderInappropriate() {}

	~CSaleOrderInappropriate() {}

	void CalcTax(ETax etaxTemp);
};


class CTaxTransfer
{
public:
	virtual void CalcTax() = 0;
};

class CCnTax : public CTaxTransfer
{
public:
	CCnTax() {}
	~CCnTax() {}

	void CalcTax();
};
class CUsTax : public CTaxTransfer
{
public:
	CUsTax() {}
	~CUsTax() {}

	void CalcTax();
};
class CEnTax : public CTaxTransfer
{
public:
	CEnTax() {}
	~CEnTax() {}

	void CalcTax();
};
class CRuTax : public CTaxTransfer
{
public:
	CRuTax() {}
	~CRuTax() {}

	void CalcTax();
};

class CSaleOrder
{
public:

	CSaleOrder() {}

	~CSaleOrder() {}

	void CalcTax(CTaxTransfer* pTaxTransfer);
};




