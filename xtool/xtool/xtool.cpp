
#include "Src\CDesignMode.h"

#include "Src\Template Method\CTemplateMethod.h"
#include "Src\Strategy Mode\CStrategyMode.h"
#include "Src\Factory Mode\CFactoryMode.h"
#include "Src\AbstractFactory Mode\CAbstractFactory.h"
#include "Src\Prototype Mode\CPrototypeMode.h"
#include "Src\Singleton Mode\CSingletonMode.h"
#include "Src\Builder Mode\CBuilderMode.h"

static CDesignMode* pDesignMode;

void DefinitionStatic(enDesignMode endesign)
{
	if (TemplateMethod == endesign)
	{
		pDesignMode = new CTemplateMethod;
	}
	else if (StrategyMode == endesign)
	{
		pDesignMode = new CStrategyMode;
	}
	else if (FactoryMode == endesign)
	{
		pDesignMode = new CFactoryMode;
	}
	else if (AbstractFactory == endesign)
	{
		pDesignMode = new CAbstractFactory;
	}
	else if (PrototypeMode == endesign)
	{
		pDesignMode = new CPrototypeMode;
	}
	else if (SingletonMode == endesign)
	{
		pDesignMode = new CSingletonMode;
	}
	else if (BuilderMode == endesign)
	{
		pDesignMode = new CBuilderMode;
	}
}

void DeleteStatic()
{
	if (pDesignMode)
	{
		delete pDesignMode;
		pDesignMode = nullptr;
	}
}

void ShowDesignMode(enDesignMode endesign, bool bIsExecute = true)
{
	if (bIsExecute)
	{
		DefinitionStatic(endesign);

		if (pDesignMode == nullptr)
		{
			return;
		}

		/*
			Inappropriate
		*/
		pDesignMode->ShowInappropriate();

		/*
			Moderate
		*/
		pDesignMode->ShowModerate();

		/*
			Proper
		*/
		pDesignMode->ShowProper();

		delete pDesignMode;
		pDesignMode = nullptr;
	}
}

int main()
{
	/*
		模板方法
	*/
	ShowDesignMode(TemplateMethod, false);

	/*
		策略模式
	*/
	ShowDesignMode(StrategyMode, false);

	/*
		工厂模式
	*/
	ShowDesignMode(FactoryMode, false);

	/*
		抽象工厂
	*/
	ShowDesignMode(AbstractFactory, false);

	/*
		原型模式
	*/
	ShowDesignMode(PrototypeMode, false);

	/*
		单例模式
	*/
	ShowDesignMode(SingletonMode,false);

	/*
		构建器模式
	*/
	ShowDesignMode(BuilderMode);






	DeleteStatic();

	cout << "End !" << endl;
	return 0;
}