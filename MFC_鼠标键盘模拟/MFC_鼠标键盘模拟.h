
// MFC_������ģ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_������ģ��App: 
// �йش����ʵ�֣������ MFC_������ģ��.cpp
//

class CMFC_������ģ��App : public CWinApp
{
public:
	CMFC_������ģ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_������ģ��App theApp;