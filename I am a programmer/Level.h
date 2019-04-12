#pragma once
#include "afxwin.h"


// Level 对话框

class Level : public CDialogEx
{
	DECLARE_DYNAMIC(Level)

public:
	Level(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Level();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LEVEL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//角色123
	int m_role;
	int m_level;
	int mx, my;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	int m_index;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	bool m_ismove;
	int m_downIndex;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_indexTemp;
	int getLeave(int x,int y);
	CBitmapButton m_btnBack;
};
