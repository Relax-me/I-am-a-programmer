#pragma once


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
	int m_role;
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
	afx_msg void OnPaint();
};
