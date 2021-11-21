#pragma once

#include "../CDesignMode.h"
#include "CHouse.h"

/*
	Builder 模式主要用于 "分步骤构建一个复杂的对象"
	在这其中 "分步骤" 是一个稳定的算法
	而复杂对象的各个部分则经常变化
*/

/*
	变化点在哪里，封装在哪里
	Builder模式主要应对 "复杂对象各个部分" 的频繁需求变动
	其缺点在于难以应对 "分步骤构建算法" 的需求变动
*/

class CBuilderMode : public CDesignMode
{
public:
	CBuilderMode() = default;
	~CBuilderMode() = default;

	void ShowInappropriate();

	void ShowModerate();

	void ShowProper();

public:
	std::unique_ptr<CHouse>m_punHouse;

};

