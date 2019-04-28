#pragma once
#include "afxwin.h"
#include "MyButton.h"
#include "MyDataFile.h"


// Role 对话框

class Role : public CDialogEx
{
	DECLARE_DYNAMIC(Role)

public:
	Role(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Role();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROLE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	CMyDataFile m_data;
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	CBitmapButton m_role_del1;
	CBitmapButton m_role_del2;
	CBitmapButton m_role_del3;
	afx_msg void OnBnClickedRoleDel1();
	afx_msg void OnBnClickedRoleDel2();
	afx_msg void OnBnClickedRoleDel3();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedRoleBtn1();
	afx_msg void OnBnClickedRoleBtn2();
	afx_msg void OnBnClickedRoleBtn3();
};
