#pragma once


class CFileSpliter
{
public:

	CFileSpliter() {}

	virtual ~CFileSpliter() {}

	virtual void Split() = 0;
};

// 中间的生产基类
class CFactorySpliter
{
public:

	CFactorySpliter() {}

	virtual ~CFactorySpliter() {}

	virtual CFileSpliter* getFileSpliter() = 0;
};

class CBinarySpliter : public CFileSpliter
{
public:
	void Split();
};

class CTxtSpliter : public CFileSpliter
{
public:
	void Split();
};

class CImageSpliter : public CFileSpliter
{
public:
	void Split();
};

class CVideoSpliter : public CFileSpliter
{
public:
	void Split();
};


// 继承生产基类，返回父类指针
class CFactoryBinarySpliter : public CFactorySpliter
{
public:
	CFileSpliter* getFileSpliter();
};

class CFactoryTxtSpliter : public CFactorySpliter
{
public:
	CFileSpliter* getFileSpliter();
};

class CFactoryImageSpliter : public CFactorySpliter
{
public:
	CFileSpliter* getFileSpliter();
};

class CFactoryVideoSpliter : public CFactorySpliter
{
public:
	CFileSpliter* getFileSpliter();
};

