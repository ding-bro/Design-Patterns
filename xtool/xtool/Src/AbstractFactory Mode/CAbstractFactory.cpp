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
	// ��ͨд��
	// ������д������һ������װ�ɺ�����Ҳ�Ե÷ǳ�����
	// ��ʱ�����Ҫ�ܿ� new ��ȥ��������ģʽ
	// ���ٱ���ʱ����

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




	// ��Щ��ʵ�ǿ��Դ�����ⲿʹ�õ�
	// Ŀ����ʵ��Ϊ��ʵ����������ָ��
	// ��ʵҲ����ͨ����Ĺ��캯��ֱ�Ӵ�ָ�����������Ϊ��������������д
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
	// ������ͨ�Ĺ���ģʽд����ʵҲ�Ǳܿ��������ʵ����� new ������
	// ������ʵ���Կ��������������ӡ������ȡ��������ʵ���й�ͬ��
	// ����һ��������һ��ֻ��һ��ָ�����������������԰�������
	// ��һ����Ҫ�ѹ���ϸ�֣����Լ���һ������Ϊһ�����󹤳�

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
	// ��Щ��ʵ�ǿ��Դ�����ⲿʹ�õ�
	// Ŀ����ʵ��Ϊ��ʵ����������ָ��
	// ��ʵҲ����ͨ����Ĺ��캯��ֱ�Ӵ�ָ�����������Ϊ��������������д
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

