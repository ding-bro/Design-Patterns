#pragma once

class CDataConnection
{
public:
	virtual void setConnection() = 0;

	virtual void setConnectString(const char*) = 0;
};
class CDataCommand
{
public:
	virtual void setCommand(const char*) = 0;
};
class CDataReader
{
public:
	virtual bool read() = 0;
};



class CDataConnectionFactoryModerate
{
public:
	virtual CDataConnection* getTransfer() = 0;
};
class CDataCommandFactoryModerate
{
public:
	virtual CDataCommand* getTransfer() = 0;
};
class CDataReaderFactoryModerate
{
public:
	virtual CDataReader* getTransfer() = 0;
};



class CDataFactory
{
public:
	virtual CDataConnection* getConnectTransfer() = 0;
	virtual CDataCommand* getCommandTransfer() = 0;
	virtual CDataReader* getReadTransfer() = 0;
};



class CSqlConnection : public CDataConnection
{
public:
	void setConnection() {}

	void setConnectString(const char*) {}
};
class CSqlCommand : public CDataCommand
{
public:
	void setCommand(const char*) {}
};
class CSqlReader : public CDataReader
{
public:
	bool read() { return false; }
};

class CSqlConnectionFactoryModerate : public CDataConnectionFactoryModerate
{
public:
	CDataConnection* getTransfer() { return new CSqlConnection; }
};
class CSqlCommandFactoryModerate : public CDataCommandFactoryModerate
{
public:
	CDataCommand* getTransfer() { return new CSqlCommand; }
};
class CSqlReaderFatioryModerate : public CDataReaderFactoryModerate
{
public:
	CDataReader* getTransfer() { return new CSqlReader; }
};

class CSqlFactory : public CDataFactory
{
public:
	CDataConnection* getConnectTransfer() { return new CSqlConnection; }
	CDataCommand* getCommandTransfer() { return new CSqlCommand; }
	CDataReader* getReadTransfer() { return new CSqlReader; }
};




class CMySqlConnection : public CDataConnection
{
public:
	void setConnection() {}

	void setConnectString(const char*) {}
};
class CMySqlCommand : public CDataCommand
{
public:
	void setCommand(const char*) {}
};
class CMySqlReader : public CDataReader
{
public:
	bool read() { return false; }
};

class CMySqlConnectionFactoryModerate : public CDataConnectionFactoryModerate
{
public:
	CDataConnection* getTransfer() { return new CMySqlConnection; }
};
class CMySqlCommandFactoryModerate : public CDataCommandFactoryModerate
{
public:
	CDataCommand* getTransfer() { return new CMySqlCommand; }
};
class CMySqlReaderFatioryModerate : public CDataReaderFactoryModerate
{
public:
	CDataReader* getTransfer() { return new CMySqlReader; }
};

class CMySqlFactory : public CDataFactory
{
public:
	CDataConnection* getConnectTransfer() { return new CMySqlConnection; }
	CDataCommand* getCommandTransfer() { return new CMySqlCommand; }
	CDataReader* getReadTransfer() { return new CMySqlReader; }
};



class COracleConnection : public CDataConnection
{
public:
	void setConnection() {}

	void setConnectString(const char*) {}
};
class COracleCommand : public CDataCommand
{
public:
	void setCommand(const char*) {}
};
class COracleReader : public CDataReader
{
public:
	bool read() { return false; }
};

class COracleConnectionFactoryModerate : public CDataConnectionFactoryModerate
{
public:
	CDataConnection* getTransfer() { return new COracleConnection; }
};
class COracleCommandFactoryModerate : public CDataCommandFactoryModerate
{
public:
	CDataCommand* getTransfer() { return new COracleCommand; }
};
class COracleReaderFatioryModerate : public CDataReaderFactoryModerate
{
public:
	CDataReader* getTransfer() { return new COracleReader; }
};

class COracleFactory : public CDataFactory
{
public:
	CDataConnection* getConnectTransfer() { return new COracleConnection; }
	CDataCommand* getCommandTransfer() { return new COracleCommand; }
	CDataReader* getReadTransfer() { return new COracleReader; }
};

