#pragma once

#include "../CDesignMode.h"
#include "CSingleton.h"

enum ConstructionMode
{
	Noraml,
	OneMutex,
	DoubleCheckLock,
	CallOnce
};

class CSingletonMode : public CDesignMode
{
public:
	CSingletonMode() { m_pSingleton = new CSingleton; }
	~CSingletonMode() {}

	void ShowInappropriate();

	void ShowModerate();

	void ShowProper();

	void getObject(ConstructionMode eMode);

	void RunThread();

public:
	CSingleton* m_pSingleton;

	std::mutex m_Mutex;
	std::condition_variable m_Condition;
};
