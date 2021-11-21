#pragma once

#include "../CDesignMode.h"

#include "CFileSpliterPrototype.h"
#include "CMainFormPrototype.h"

/*
	原型模式同样用于隔离类对象的使用者和具体类型 (易变类)之间的耦合关系
	它同样要求这些 "易变类" 拥有 "稳定的接口"
*/

/*
	原型模式对于 "如何创建易变类的实体对象" 采用 "原型克隆" 的方法来做
	他使得我们可以非常灵活的动态创建 "拥有某些稳定接口" 的新对象
	所需工作仅仅是注册一个新类的对象 (即原型)
	然后在任何需要的地方克隆
*/

class CPrototypeMode : public CDesignMode
{
public:
	CPrototypeMode() {}

	~CPrototypeMode() {}

	void ShowInappropriate();

	void ShowModerate() {}

	void ShowProper();

public:
	CMainFormPrototype* m_pMainForm;
};
