#pragma once


class CFileSpliterPrototype
{
public:
	virtual void split() = 0;
	virtual ~CFileSpliterPrototype() {}
};



class CFactorySpliterPortotype
{
public:
	virtual CFileSpliterPrototype* getFactory() = 0;
	virtual ~CFactorySpliterPortotype() {}
};



class CPrototypeFactorySpliter
{
public:
	virtual void split() = 0;
	virtual CPrototypeFactorySpliter* getClone() = 0;
	virtual ~CPrototypeFactorySpliter() {}
};



class CBinarySpliterPrototype : public CFileSpliterPrototype
{
public:
	void split() {}
};
class CFactoryBinarySpliterPrototype : public CFactorySpliterPortotype
{
public:
	CFileSpliterPrototype* getFactory() { return new CBinarySpliterPrototype; }
};
class CCloneBinarySpliter : public CPrototypeFactorySpliter
{
public:
	void split() {}
	CCloneBinarySpliter() {}
	CCloneBinarySpliter(CCloneBinarySpliter*) {}
	CPrototypeFactorySpliter* getClone() { return new CCloneBinarySpliter(this); } // 调用拷贝构造去拷贝自己
};



class CTxtSpliterPrototype : public CFileSpliterPrototype
{
public:
	void split() {}
};
class CFactoryTxtSpliterPrototype : public CFactorySpliterPortotype
{
public:
	CFileSpliterPrototype* getFactory() { return new CTxtSpliterPrototype; }
};
class CCloneTxtSpliter : public CPrototypeFactorySpliter
{
public:
	void split() {}
	CCloneTxtSpliter() {}
	CCloneTxtSpliter(CCloneTxtSpliter*) {}
	CPrototypeFactorySpliter* getClone() { return new CCloneTxtSpliter(this); }
};



class CVedioSplitePrototypr : public CFileSpliterPrototype
{
public:
	void split() {}
};
class CFactoryVedioSpliterPrototype : public CFactorySpliterPortotype
{
public:
	CFileSpliterPrototype* getFactory() { return new CVedioSplitePrototypr; }
};
class CCloneVedioSpliter : public CPrototypeFactorySpliter
{
public:
	void split() {}
	CCloneVedioSpliter() {}
	CCloneVedioSpliter(CCloneVedioSpliter*) {}
	CPrototypeFactorySpliter* getClone() { return new CCloneVedioSpliter(this); }
};