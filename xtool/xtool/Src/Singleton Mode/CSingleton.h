#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;

class CSingleton
{
public:
	CSingleton() {}

	~CSingleton() {}

	static CSingleton* getSingletonNormal();

	static CSingleton* getSingleLock();

	static CSingleton* getSingleDoubleLock();

	static CSingleton* getSingleSafe();

	void getStartThread();

	void Calc();

public:
	static CSingleton* s_pSingleton;

	std::thread m_thread;
};


