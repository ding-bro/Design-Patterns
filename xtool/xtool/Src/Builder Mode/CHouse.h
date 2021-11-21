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

	// �������ʣ������ڻ���Ĺ��캯�����������Ķ�̬����
	// Υ���˶�̬�󶨵Ĺ�����ʵ���Ǿ�̬��
	// ��Ϊ�ڶ�̬��������ķ���ʱ��������Ҫ���������Ĺ��캯��
	// �������������û�д���������Ĺ��캯����Ҫȥ��������ķ�����������Υ����̬��ԭ��
	
	//CHouse()
	//{
	//	this->getBuildOne(); // ��̬��
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
	
	// ��ʱ��Ҳ��ϸ�ֳ��ܶ�С������
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
		//m_pHouse->getPartOne(); // ϸ�ֳ�һЩС�Ĳ���
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
		//m_pHouse->getPartOne(); // ϸ�ֳ�һЩС�Ĳ���
	}

	void getBuildTwo()
	{
		//m_pHouse->getPartTwo(); // ϸ�ֳ�һЩС�Ĳ���
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

