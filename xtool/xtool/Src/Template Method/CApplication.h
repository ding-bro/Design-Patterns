#pragma once

#include "CDataBase.h"

/*
	Inappropriate
*/
class CApplicationInappropriate
{
public:

	CApplicationInappropriate() {}

	~CApplicationInappropriate() {}

	void getStepOne();

	void getStepTwo();
};


/*
	Proper
*/
class CApplication : public CDataBase
{
public:

	CApplication() {}

	~CApplication() {}

	virtual void getStepOne(); // ��д --- �仯

	virtual void getStepTwo(); // ��д --- �仯

};
