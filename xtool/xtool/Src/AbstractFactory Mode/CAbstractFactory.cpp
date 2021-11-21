#include "CAbstractFactory.h"

CAbstractFactory::CAbstractFactory()
{
	m_pSqlConnect = new CSqlConnection;
	m_pSqlCommand = new CSqlCommand;
	m_pSqlRead = new CSqlReader;
	m_pMySqlConnect = new CMySqlConnection;
	m_pMySqlCommand = new CMySqlCommand;
	m_pMySqlRead = new CMySqlReader;
	m_pOraConnect = new COracleConnection;
	m_pOraCommand = new COracleCommand;
	m_pOraRead = new COracleReader;
}

CAbstractFactory::~CAbstractFactory()
{
	delete m_pSqlConnect;
	delete m_pSqlCommand;
	delete m_pSqlRead;
	delete m_pMySqlConnect;
	delete m_pMySqlCommand;
	delete m_pMySqlRead;
	delete m_pOraConnect;
	delete m_pOraCommand;
	delete m_pOraRead;
}

void CAbstractFactory::ShowInappropriate()
{
	// 普通写法
	// 这样的写法即便一个个封装成函数，也显得非常冗余
	// 这时候就需要避开 new ，去引进工厂模式
	// 减少编译时依赖

	// Sql
	m_pSqlConnect->setConnection();
	m_pSqlConnect->setConnectString(".......");

	m_pSqlCommand->setCommand(".......");

	while (m_pSqlRead->read())
	{
		// .......
	}

	// MySql
	m_pMySqlConnect->setConnection();
	m_pMySqlConnect->setConnectString(".......");

	m_pMySqlCommand->setCommand(".......");

	while (m_pMySqlRead->read())
	{
		// .......
	}

	// Oracle
	m_pOraConnect->setConnection();
	m_pOraConnect->setConnectString(".......");

	m_pOraCommand->setCommand(".......");

	while (m_pOraRead->read())
	{
		// .......
	}




	/*----------------------------------------------------------------------------------------------------------*/




	// 这些其实是可以从类的外部使用的
	// 目的其实是为了实例化工厂类指针
	// 其实也可以通过类的构造函数直接传指针进来，不过为了清晰还是这样写
	m_pDataConnectFactoryModerate = new CSqlConnectionFactoryModerate;
	m_pDataCommandFactoryModerate = new CSqlCommandFactoryModerate;
	m_pDataReaderFactoryModerate = new CSqlReaderFatioryModerate;
	ShowModerate();

	m_pDataConnectFactoryModerate = new CMySqlConnectionFactoryModerate;
	m_pDataCommandFactoryModerate = new CMySqlCommandFactoryModerate;
	m_pDataReaderFactoryModerate = new CMySqlReaderFatioryModerate;
	ShowModerate();

	m_pDataConnectFactoryModerate = new COracleConnectionFactoryModerate;
	m_pDataCommandFactoryModerate = new COracleCommandFactoryModerate;
	m_pDataReaderFactoryModerate = new COracleReaderFatioryModerate;
	ShowModerate();
}

void CAbstractFactory::ShowModerate()
{
	// 这种普通的工厂模式写法其实也是避开了在类的实现里对 new 的依赖
	// 但是其实可以看到，不管是连接、命令、读取，他们其实都有共同点
	// 所以一个工厂不一定只有一种指定的生产方法，可以包含多种
	// 不一定非要把工厂细分，可以集成一个工厂为一个抽象工厂

	m_pDataConnect = m_pDataConnectFactoryModerate->getTransfer();
	m_pDataConnect->setConnection();
	m_pDataConnect->setConnectString("......");

	m_pDataCommand = m_pDataCommandFactoryModerate->getTransfer();
	m_pDataCommand->setCommand("......");

	m_pDataRead = m_pDataReaderFactoryModerate->getTransfer();
	while (m_pDataRead->read())
	{
		// ......
	}
}

void CAbstractFactory::ShowProper()
{
	// 这些其实是可以从类的外部使用的
	// 目的其实是为了实例化工厂类指针
	// 其实也可以通过类的构造函数直接传指针进来，不过为了清晰还是这样写
	m_pDataFactory = new CSqlFactory;

	m_pDataConnect = m_pDataFactory->getConnectTransfer();
	m_pDataConnect->setConnection();
	m_pDataConnect->setConnectString("......");

	m_pDataCommand = m_pDataFactory->getCommandTransfer();
	m_pDataCommand->setCommand("......");

	m_pDataRead = m_pDataFactory->getReadTransfer();
	while (m_pDataRead->read())
	{
		// ......
	}

	//m_pDataFactory = new CMySqlFactory;
	//ShowProper();

	//m_pDataFactory = new COracleFactory;
	//ShowProper();
}

