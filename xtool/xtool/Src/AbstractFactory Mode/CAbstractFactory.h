#pragma once

#include "../CDesignMode.h"

#include "CDataLibrary.h"

/*
	���û��Ӧ�� "��ϵ�ж��󴴽�" ������仯������ȫû�б�Ҫʹ�ó��󹤳�ģʽ
	��ʱ���ü򵥵Ĺ�����ȫ����
*/

/*
	"ϵ�ж���" ָ������ĳһ�ض�ϵ���µĶ���֮�����໥�����������õĹ�ϵ
	��ͬϵ�еĶ���֮�䲻���໥����
*/

/*
	���󹤳�ģʽ��Ҫ����Ӧ�� "��ϵ��" ������䶯����ȱ����������Ӧ�� "�¶���" ������䶯
*/

class CAbstractFactory : public CDesignMode
{
public:
	CAbstractFactory();

	~CAbstractFactory();

	void ShowInappropriate();

	void ShowModerate();

	void ShowProper();

public:
	// ��ͨд��
	CSqlConnection* m_pSqlConnect;
	CSqlCommand* m_pSqlCommand;
	CSqlReader* m_pSqlRead;
	CMySqlConnection* m_pMySqlConnect;
	CMySqlCommand* m_pMySqlCommand;
	CMySqlReader* m_pMySqlRead;
	COracleConnection* m_pOraConnect;
	COracleCommand* m_pOraCommand;
	COracleReader* m_pOraRead;

	// ----------------------------------
	CDataConnection* m_pDataConnect;
	CDataCommand* m_pDataCommand;
	CDataReader* m_pDataRead;
	// ----------------------------------

	// ����ģʽд��
	CDataConnectionFactoryModerate* m_pDataConnectFactoryModerate;
	CDataCommandFactoryModerate* m_pDataCommandFactoryModerate;
	CDataReaderFactoryModerate* m_pDataReaderFactoryModerate;

	// ���󹤳�ģʽд��
	CDataFactory* m_pDataFactory;
};
