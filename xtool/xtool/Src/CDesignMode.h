#pragma once

#include <iostream>
using namespace std;

typedef enum enDesignMode
{
	TemplateMethod,
	StrategyMode,
	FactoryMode,
	AbstractFactory,
	PrototypeMode,
	SingletonMode,
	BuilderMode
};

// ≥ÈœÛ¿‡
class CDesignMode
{
public:
	CDesignMode() {}

	virtual ~CDesignMode() {}

	virtual void ShowProper() = 0;

	virtual void ShowModerate() = 0;

	virtual void ShowInappropriate() = 0;
};

