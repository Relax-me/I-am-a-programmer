#pragma once
#include "afxwin.h"


// Game �Ի���

class Game : public CDialogEx
{
	DECLARE_DYNAMIC(Game)

public:
	Game(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Game();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	// ��ɫ123
	int m_role;
	afx_msg void OnPaint();
	int m_level;
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedMusic();
	afx_msg void OnBnClickedStop();
	afx_msg void OnBnClickedSlow();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedFast();
	CBitmapButton m_btnExit;
	CBitmapButton m_btnFast;
	CBitmapButton m_btnMusic;
	CBitmapButton m_btnSlow;
	CBitmapButton m_btnStart;
	CBitmapButton m_btnStop;
	virtual BOOL OnInitDialog();
};