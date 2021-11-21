#pragma once

#include "../CDesignMode.h"

#include "CDataLibrary.h"

/*
	如果没有应对 "多系列对象创建" 的需求变化，则完全没有必要使用抽象工厂模式
	这时候用简单的工厂完全可以
*/

/*
	"系列对象" 指的是在某一特定系列下的对象之间有相互依赖、或作用的关系
	不同系列的对象之间不能相互依赖
*/

/*
	抽象工厂模式主要在于应对 "新系列" 的需求变动，其缺点在于难以应对 "新对象" 的需求变动
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
	// 普通写法
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

	// 工厂模式写法
	CDataConnectionFactoryModerate* m_pDataConnectFactoryModerate;
	CDataCommandFactoryModerate* m_pDataCommandFactoryModerate;
	CDataReaderFactoryModerate* m_pDataReaderFactoryModerate;

	// 抽象工厂模式写法
	CDataFactory* m_pDataFactory;
};
