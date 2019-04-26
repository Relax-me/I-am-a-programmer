#pragma once
#define UNLOCK FALSE
#define LOCK TRUE
// CMyDataFile ÃüÁîÄ¿±ê

class CMyDataFile : public CObject
{
public:
	bool isLock = LOCK;
	//////////////////////////////
	CString m_strFile = L".//data";
	CMyDataFile();
	virtual ~CMyDataFile();
	void Lock();
	void UnLock();
	int getRoleL(int role);
	int getRoleLR(int role,int level);
	void setRoleL(int role,int level);
	void setRoleLR(int role, int level, int record);
};


