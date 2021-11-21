#include "CSingletonMode.h"

void CSingletonMode::getObject(ConstructionMode eMode)
{
	if (Noraml == eMode)
	{
		CSingleton* pSingleton = CSingleton::getSingletonNormal();
	}
	else if (OneMutex == eMode)
	{
		CSingleton* pSingleton = CSingleton::getSingleLock();
	}
	else if (DoubleCheckLock == eMode)
	{
		CSingleton* pSingleton = CSingleton::getSingleDoubleLock();
	}
	else if (CallOnce == eMode)
	{
		CSingleton* pSingleton = CSingleton::getSingleSafe();
	}
}

void CSingletonMode::ShowInappropriate()
{
	CSingleton::s_pSingleton = nullptr;

	std::unique_lock<mutex>unLockOne(this->m_Mutex);

	// ��ͨд����ֱ���жϾ�̬���ر����Ƿ�Ϊ��
	std::thread thOne(&CSingletonMode::getObject, this, Noraml);
	std::thread thTwo(&CSingletonMode::getObject, this, Noraml);

	thOne.join();
	thTwo.join();

	// ��ʱ?  ʹ�ó���ò�Ʋ���
	this->m_Condition.wait_for(unLockOne, std::chrono::seconds(1));

	ShowModerate();
}

void CSingletonMode::ShowModerate()
{
	// ��ʹ��˫�ؼ����
	CSingleton::s_pSingleton = nullptr;
	std::thread thOne(&CSingletonMode::getObject, this, OneMutex);
	std::thread thTwo(&CSingletonMode::getObject, this, OneMutex);

	thOne.join();
	thTwo.join();

	// ˫�ؼ����
	CSingleton::s_pSingleton = nullptr;
	std::thread thThree(&CSingletonMode::getObject, this, DoubleCheckLock);
	std::thread thFour(&CSingletonMode::getObject, this, DoubleCheckLock);

	thThree.join();
	thFour.join();
}

void CSingletonMode::ShowProper()
{
	// ʹ��C++ 11 std::call_once
	CSingleton::s_pSingleton = nullptr;
	std::thread thOne(&CSingletonMode::getObject, this, CallOnce);
	std::thread thTwo(&CSingletonMode::getObject, this, CallOnce);

	thOne.join();
	thTwo.join();
}


