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
	// ��Ӧ�ó�������ݿ�Ŀ���ģʽ�ֿ�
	// ���ʹ�õ����������������ͻ��Ե�����

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
	// ʹ�ü̳У�ֱ��ʹ�þ��弯�ɷ�����

	this->m_pDataProper = new CApplication;
	m_pDataProper->run();

	delete m_pDataProper;
	m_pDataProper = nullptr;
}

