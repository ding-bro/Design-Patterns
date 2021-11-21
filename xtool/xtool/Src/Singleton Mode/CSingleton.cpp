#include "CSingleton.h"

// �����ͷ�ļ��ж����˾�̬��������ʼ������Ҫ��CPP�������Ҫ������̬����������
CSingleton* CSingleton::s_pSingleton = nullptr;

std::mutex m_mutex;
std::once_flag m_onceFlag;

CSingleton* CSingleton::getSingletonNormal()
{
	// ������д�������һ�ι���ʱ��������߳�ͬʱִ��ʱ
	// �ͻ�����ظ���������
	if (s_pSingleton == nullptr)
	{
		s_pSingleton = new CSingleton;
	}

	return s_pSingleton;
}

CSingleton* CSingleton::getSingleLock()
{
	// ���ʹ�û������Ļ�����Ȼ���Դﵽ������߳��ظ�����CSingleton���������
	// ����ÿһ�ζ�Ҫ�������������˷�������Դ
	std::unique_lock<mutex>unLock(m_mutex);
	if (s_pSingleton == nullptr)
	{
		s_pSingleton = new CSingleton;
	}

	return s_pSingleton;
}

CSingleton* CSingleton::getSingleDoubleLock()
{
	// ˫�ؼ����
	// ʹ��˫�ؼ�������ɽ����Դ�˷ѵ����⣬ֻ�ڵ�һ�ι���ʱ�����������Ѿ�����������
	// �ڶ���ʱ���Ͳ��ᾭ��������
	if (s_pSingleton == nullptr)
	{
		std::unique_lock<mutex>unLock(m_mutex);

		if (s_pSingleton == nullptr)
		{
			s_pSingleton = new CSingleton;
		}
	}

	return s_pSingleton;
}


CSingleton* CSingleton::getSingleSafe()
{
	// ʹ��call_once �ö���߳�ִ��ʱ��ֻ��������һ���߳�ִ�д˺����������߳�����
	// ���ַ�����Ч�ʱȽϸߵ�
	std::call_once(m_onceFlag,[=]{
		if (s_pSingleton == nullptr)
		{
			s_pSingleton = new CSingleton;
		}
	});

	return s_pSingleton;
}

void CSingleton::getStartThread()
{
	std::thread thTemp(&CSingleton::Calc, this);
	thTemp.swap(m_thread); // ��ȫ�ֵ�thread������thTemp�ÿ�

	m_thread.join();
}

void CSingleton::Calc()
{
	for (int i = 0; i < 10000; i++)
	{
		std::cout << i << std::endl;
	}
}
