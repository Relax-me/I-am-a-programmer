
// I am a programmer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIamaprogrammerApp: 
// �йش����ʵ�֣������ I am a programmer.cpp
//

class CIamaprogrammerApp : public CWinApp
{
public:
	CIamaprogrammerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIamaprogrammerApp theApp;