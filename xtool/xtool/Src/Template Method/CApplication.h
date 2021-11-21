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

	virtual void getStepOne(); // 重写 --- 变化

	virtual void getStepTwo(); // 重写 --- 变化

};
