#pragma once
#include "afxwin.h"
#include "Operate.h"


// Game 对话框

class Game : public CDialogEx
{
	DECLARE_DYNAMIC(Game)

public:
	Game(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Game();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	// 角色123
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
	///////////////////////////
	int in[50];
	int inIndex;
	int inNum;
	//////////////////////////
	int out[50];
	int outTrue[50];
	int outIndex;
	int outNum;
	//////////////////////////
	int ram[20];
	bool isRamUsed[20];
	int ramUsesNum;
	//////////////////////////
	Operate* operate[1024];
	int runIndex;
	int operateLine;
	int operateCount;
	//////////////////////////
	void Check();
	void runError();
	void runOk();
	void initGame();
};
