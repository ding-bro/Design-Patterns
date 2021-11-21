#pragma once

class CHouse
{
public:
	CHouse() = default;
	~CHouse() = default;

	friend class CHouseBuilder;
	friend class CStoneHouseBulder;
	friend class CGoldHouseBulder;
	friend class CHouseDirector;
	friend class CStoneHouseBuilder;
	friend class CGoldHouseBuilder;

	// 留个疑问，不能在基类的构造函数里调用子类的多态函数
	// 违背了动态绑定的规则，这实际是静态绑定
	// 因为在多态调用子类的方法时，必须先要构造出父类的构造函数
	// 而这种情况，还没有创建出父类的构造函数就要去调用子类的方法，明显是违背多态的原理
	
	//CHouse()
	//{
	//	this->getBuildOne(); // 静态绑定
	//}

	void init()
	{
		this->getBuildOne();

		for (int i = 0; i < 5; i++)
		{
			this->getBuildTwo();
		}

		for (int i = 0; i < 5; i++)
		{
			this->getBuildThree();
		}

		this->getBuildFour();
		this->getBuildFive();
	}

protected:
	virtual void getBuildOne() = 0;
	virtual void getBuildTwo() = 0;
	virtual void getBuildThree() = 0;
	virtual void getBuildFour() = 0;
	virtual void getBuildFive() = 0;
	
	// 有时候也会细分出很多小的需求
	virtual void getPartOne() = 0;
	virtual void getPartTwo() = 0;
};

class CStoneHouse : public CHouse
{
public:
	CStoneHouse() = default;
	~CStoneHouse() = default;

	void getBuildOne() {}
	void getBuildTwo() {}
	void getBuildThree() {}
	void getBuildFour() {}
	void getBuildFive() {}

	void getPartOne() {}
	void getPartTwo() {}
};

class CGoldHouse : public CHouse
{
public:
	CGoldHouse() = default;
	~CGoldHouse() = default;

	void getBuildOne() {}
	void getBuildTwo() {}
	void getBuildThree() {}
	void getBuildFour() {}
	void getBuildFive() {}

	void getPartOne() {}
	void getPartTwo() {}
};

class CHouseBuilder
{
public:
	CHouseBuilder() = default;
	~CHouseBuilder() = default;

	friend class CHouseDirector;
	friend class CStoneHouseBuilder;
	friend class CGoldHouseBuilder;

	CHouse* getPointerHouse() { return this->m_pHouse; }

protected:
	CHouse* m_pHouse;

	virtual void getBuildOne() = 0;
	virtual void getBuildTwo() = 0;
	virtual void getBuildThree() = 0;
	virtual void getBuildFour() = 0;
	virtual void getBuildFive() = 0;
};

class CStoneHouseBuilder : public CHouseBuilder
{
public:
	CStoneHouseBuilder() = default;
	~CStoneHouseBuilder() = default;

	void getBuildOne() 
	{
		//m_pHouse->getPartOne(); // 细分出一些小的步骤
	}

	void getBuildTwo() 
	{
		//m_pHouse->getPartTwo(); 
	}

	void getBuildThree() {}
	void getBuildFour() {}
	void getBuildFive() {}
};

class CGoldHouseBuilder : public CHouseBuilder
{
public:
	CGoldHouseBuilder() = default;
	~CGoldHouseBuilder() = default;

	void getBuildOne()
	{
		//m_pHouse->getPartOne(); // 细分出一些小的步骤
	}

	void getBuildTwo()
	{
		//m_pHouse->getPartTwo(); // 细分出一些小的步骤
	}

	void getBuildThree() {}
	void getBuildFour() {}
	void getBuildFive() {}
};

class CHouseDirector
{
public:
	CHouseDirector(CHouseBuilder* pBuilder) : m_pHousebuilder(pBuilder) {}
	~CHouseDirector() = default;

	CHouse* Config()
	{
		m_pHousebuilder->getBuildOne();

		for (int i = 0; i < 5; i++)
		{
			m_pHousebuilder->getBuildTwo();
		}

		for (int i = 0; i < 5; i++)
		{
			m_pHousebuilder->getBuildThree();
		}

		m_pHousebuilder->getBuildFour();
		m_pHousebuilder->getBuildFive();

		return m_pHousebuilder->getPointerHouse();
	}

public:
	CHouseBuilder* m_pHousebuilder;
};

