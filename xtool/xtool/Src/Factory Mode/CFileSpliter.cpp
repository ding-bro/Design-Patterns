#include "CFilespliter.h"

void CBinarySpliter::Split()
{
	return;
}

void CTxtSpliter::Split()
{
	return;
}

void CImageSpliter::Split()
{
	return;
}

void CVideoSpliter::Split()
{
	return;
}

CFileSpliter* CFactoryBinarySpliter::getFileSpliter()
{
	CBinarySpliter* pBinarySpliter = new CBinarySpliter;
	return pBinarySpliter;
}

CFileSpliter* CFactoryTxtSpliter::getFileSpliter()
{
	CTxtSpliter* pTxtSpliter = new CTxtSpliter;
	return pTxtSpliter;
}

CFileSpliter* CFactoryImageSpliter::getFileSpliter()
{
	CImageSpliter* pImageSpliter = new CImageSpliter;
	return pImageSpliter;
}

CFileSpliter* CFactoryVideoSpliter::getFileSpliter()
{
	CVideoSpliter* pVideoSpliter = new CVideoSpliter;
	return pVideoSpliter;
}
