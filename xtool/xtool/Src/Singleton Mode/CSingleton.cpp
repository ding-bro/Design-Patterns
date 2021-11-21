#include "CSingleton.h"

// 如果在头文件中定义了静态变量，初始化操作要在CPP里，并且需要声明静态变量的类型
CSingleton* CSingleton::s_pSingleton = nullptr;

std::mutex m_mutex;
std::once_flag m_onceFlag;

CSingleton* CSingleton::getSingletonNormal()
{
	// 这样的写法如果第一次构造时，当多个线程同时执行时
	// 就会出现重复构造的情况
	if (s_pSingleton == nullptr)
	{
		s_pSingleton = new CSingleton;
	}

	return s_pSingleton;
}

CSingleton* CSingleton::getSingleLock()
{
	// 如果使用互斥锁的话，虽然可以达到避免多线程重复构造CSingleton对象的问题
	// 但是每一次都要经过互斥锁，浪费运行资源
	std::unique_lock<mutex>unLock(m_mutex);
	if (s_pSingleton == nullptr)
	{
		s_pSingleton = new CSingleton;
	}

	return s_pSingleton;
}

CSingleton* CSingleton::getSingleDoubleLock()
{
	// 双重检查锁
	// 使用双重检查锁即可解决资源浪费的问题，只在第一次构造时，互斥锁就已经发挥了作用
	// 第二次时，就不会经过互斥锁
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
	// 使用call_once 让多个线程执行时，只允许其中一个线程执行此函数，其他线程阻塞
	// 这种方法是效率比较高的
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
	thTemp.swap(m_thread); // 与全局的thread交换，thTemp置空

	m_thread.join();
}

void CSingleton::Calc()
{
	for (int i = 0; i < 10000; i++)
	{
		std::cout << i << std::endl;
	}
}
