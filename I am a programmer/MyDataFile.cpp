// MyDataFile.cpp : 实现文件
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "MyDataFile.h"


// CMyDataFile

CMyDataFile::CMyDataFile()
{
	CFileFind finder;
	BOOL ifFind = finder.FindFile(m_strFile);
	if (!ifFind)
	{
		::WritePrivateProfileStringW(_T("Role Info"), _T("Role_1"), _T("0"), m_strFile);
		::WritePrivateProfileStringW(_T("Role_1 Level Record"), _T("Level_1"), _T("0"), m_strFile);
		::WritePrivateProfileStringW(_T("Role Info"), _T("Role_2"), _T("0"), m_strFile);
		::WritePrivateProfileStringW(_T("Role_2 Level Record"), _T("Level_1"), _T("0"), m_strFile);
		::WritePrivateProfileStringW(_T("Role Info"), _T("Role_3"), _T("0"), m_strFile);
		::WritePrivateProfileStringW(_T("Role_3 Level Record"), _T("Level_1"), _T("0"), m_strFile);
		Lock();
	}
}

CMyDataFile::~CMyDataFile()
{

}


// CMyDataFile 成员函数


void CMyDataFile::Lock()
{  
	CFile file_read(m_strFile, CFile::modeReadWrite);
	int size = file_read.GetLength();
	char *buffer = NULL;
	buffer = new char[size + 1];  
	file_read.Read(buffer, size);
	file_read.Close();
	for (int i = 0; i < size; i++)
	{
		buffer[i] += 5;
	}
	CFile file_write(m_strFile, CFile::modeReadWrite);
	file_write.Write(buffer, size);
	delete buffer;
	file_write.Close();
}


void CMyDataFile::UnLock()
{
	CFile file_read(m_strFile, CFile::modeReadWrite);
	int size = file_read.GetLength();
	char *buffer = NULL;
	buffer = new char[size + 1];
	file_read.Read(buffer, size);
	file_read.Close();
	for (int i = 0; i < size; i++)
	{
		buffer[i] -= 5;
	}
	CFile file_write(m_strFile, CFile::modeReadWrite);
	file_write.Write(buffer, size);
	delete buffer;
	file_write.Close();
}

int CMyDataFile::getRoleL(int role)
{
	Lock();	 
	CString strRole;
	strRole.Format(L"Role_%d",role);
	CString ret;
	::GetPrivateProfileStringW(_T("Role Info"), strRole, _T("ERROR"), ret.GetBuffer(MAX_PATH), MAX_PATH, m_strFile);
	ret.ReleaseBuffer();	 
	UnLock();
	return atoi(CStringA(ret));
}
int CMyDataFile::getRoleLR(int role, int level)
{
	Lock();	 
	CString strRole,strLevel;
	strRole.Format(L"Role_%d Level Record", role);
	strLevel.Format(L"Level_%d", level);
	CString ret;
	::GetPrivateProfileStringW(strRole, strLevel, _T("ERROR"), ret.GetBuffer(MAX_PATH), MAX_PATH, m_strFile);
	ret.ReleaseBuffer();
	UnLock();
	return atoi(CStringA(ret))	;
}
void CMyDataFile::setRoleL(int role,int level)
{
	Lock();
	CString strRole, strLevel;
	strRole.Format(L"Role_%d",role);
	strLevel.Format(L"%d", level);
	::WritePrivateProfileStringW(_T("Role Info"), strRole, strLevel, m_strFile);
	UnLock();
}
void CMyDataFile::setRoleLR(int role, int level, int record)
{
	Lock();
	CString strRole, strLevel,strRecord;
	strRole.Format(L"Role_%d Level Record", role);
	strLevel.Format(L"Level_%d", level);
	strRecord.Format(L"%d",record);
	::WritePrivateProfileStringW(strRole, strLevel, strRecord, m_strFile);	
	UnLock();
}