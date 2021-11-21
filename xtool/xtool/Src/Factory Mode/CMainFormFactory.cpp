#include "CMainFormFactory.h"

void CMainFormFactoryInappropriate::ButtonOneClick()
{
	m_pMessageBox->open();
	m_pProgressBar->setValue(100);

	// ������д�����Ǳ���ʽ����
	// д����Ȼ����ȷ�ģ����ǶԱ����γ��˺�ǿ�����������ҷָ�����������Ҫ�ں�����д��
	// �� C++ ��new�γ��˺�ǿ������
	// ���������100�ֲ�ͬ��ʽ�ķָ������󣬾���Ҫ���ϵ��ڴ˺������ۻ����

	CFileSpliter* pBinarySpliter = new CBinarySpliter; // �����ǳ��������������ǻ��������˾�����
	pBinarySpliter->Split();

	CFileSpliter* pTxtSpliter = new CTxtSpliter;
	pTxtSpliter->Split();

	CFileSpliter* pImageSpliter = new CImageSpliter;
	pImageSpliter->Split();

	CFileSpliter* pVideoSpliter = new CVideoSpliter;
	pVideoSpliter->Split();

	delete pBinarySpliter;
	delete pTxtSpliter;
	delete pImageSpliter;
	delete pVideoSpliter;
}

void CMainFormFactory::ButtonOneClick()
{
	// ���е����ģʽ����������ģʽ����ʵ��������һ��ԭ��
	// �Ǿ��ǰѱ���ʽ�����������ʱ����
	// Ҳ���Ǽ̳С���̬����֮��Ķ�̬��ת�ĸ���

	m_pMessageBox->open();
	m_pProgressBar->setValue(100);

	// ��Ȼ����ģʽ�� CFactoryMode ����Ȼ��Ҫ�ظ��� CFactorySpliterָ�� ��ֵ
	// ��Ҫǿ�����ǣ����е����ģʽ��������ȫ�������������������������
	// ���ģʽ���������ھ�����ʵ������ٱ���ʽ����

	CFileSpliter* pFileSpliter = nullptr;
	pFileSpliter = m_pFactorySpliter->getFileSpliter(); // �м������������ø���ӿ�
	pFileSpliter->Split();
}
