#include "CTemplateMethod.h"

CTemplateMethod::CTemplateMethod()
{
	this->m_pCappInappropriate = new CApplicationInappropriate;
	this->m_pDataInappropriate = new CDataBaseInappropriate;
	this->m_pCappProper = new CApplication;
}

CTemplateMethod::~CTemplateMethod()
{
	this->m_pCappInappropriate;
	this->m_pDataInappropriate;
	this->m_pCappProper;

	m_pCappInappropriate = nullptr;
	m_pDataInappropriate = nullptr;
	m_pCappProper = nullptr;
}

void CTemplateMethod::ShowInappropriate()
{
	// 当应用程序和数据库的开发模式分开
	// 如果使用单个类的声明，程序就会显得冗余

	m_pCappInappropriate->getStepOne();
	m_pCappInappropriate->getStepTwo();

	for (int i = 0; i < 4; i++)
	{
		m_pDataInappropriate->getStepThree();
	}

	m_pDataInappropriate->getStepFour();
}

void CTemplateMethod::ShowProper()
{
	// 使用继承，直接使用具体集成方法类

	this->m_pDataProper = new CApplication;
	m_pDataProper->run();

	delete m_pDataProper;
	m_pDataProper = nullptr;
}

