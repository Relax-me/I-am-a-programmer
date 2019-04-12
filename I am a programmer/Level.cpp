// Level.cpp : 实现文件
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "Level.h"
#include "Game.h"
#include "Role.h"
#include "MyDataFile.h"
#include "afxdialogex.h"


// Level 对话框

IMPLEMENT_DYNAMIC(Level, CDialogEx)

Level::Level(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LEVEL, pParent)
	, m_role(0)
	, m_index(0)
	, m_ismove(false)
	, m_downIndex(0)
	, m_indexTemp(0)
{

}

Level::~Level()
{
}

void Level::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_btnBack);
}


BEGIN_MESSAGE_MAP(Level, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_NCCALCSIZE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &Level::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// Level 消息处理程序


BOOL Level::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	scrollinfo.nPage = 10;    //设置滑块大小
	scrollinfo.nMax = 1887;     //设置滚动条的最大位置0--75
	scrollinfo.nPos = 1887;
	SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	m_btnBack.LoadBitmaps(IDB_LEVEL_BACK);
	m_btnBack.SizeToContent();
	CMyDataFile m_data;
	m_level = m_data.getRoleL(m_role);
	m_index = 1887 * m_level / 21;
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Level::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	/*
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	int unit = 3;
	switch (nSBCode)
	{
	case SB_LINEUP:          //Scroll one line up
		m_index += 10;
		scrollinfo.nPos -= 10;
		if (scrollinfo.nPos<scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			m_index = 1887;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		//ScrollWindow(0, unit * 10);
		break;
	case SB_LINEDOWN:           //Scroll one line down
		m_index -= 10;
		scrollinfo.nPos += 10;
		if (scrollinfo.nPos + scrollinfo.nPage>scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
		{
			scrollinfo.nPos = scrollinfo.nMax;
			m_index = 0;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		//ScrollWindow(0, -unit * 10);
		break;
	case SB_PAGEUP:            //Scroll one page up.
		m_index += 50;
		scrollinfo.nPos -= 50;
		if (scrollinfo.nPos <= scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			m_index = 1887;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		//ScrollWindow(0, unit * 50);
		break;
	case SB_PAGEDOWN:        //Scroll one page down      
		m_index -= 50;
		scrollinfo.nPos += 50;
		if (scrollinfo.nPos + scrollinfo.nPage >= scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
		{
			scrollinfo.nPos = scrollinfo.nMax;
			m_index = 0;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		//ScrollWindow(0, -unit * 50);
		break;
	case SB_ENDSCROLL:      //End scroll
		break;
	case SB_THUMBPOSITION:  //Scroll to the absolute position. The current position is provided in nPos
		break;
	case SB_THUMBTRACK:                  //Drag scroll box to specified position. The current position is provided in nPos
		//ScrollWindow(0, (scrollinfo.nPos - nPos)*unit);
		scrollinfo.nPos = nPos;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		break;
	}
	*/
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL Level::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// TODO: Add your message handler code here and/or call default 
	SCROLLINFO scrollinfo;
	if (zDelta == 120)
	{
		//OnVScroll(SB_PAGEUP, GetScrollPos(SB_VERT), GetScrollBarCtrl(SB_VERT));
		m_index += 50;
	}
	else if (zDelta == -120)
	{
		//OnVScroll(SB_PAGEDOWN, GetScrollPos(SB_VERT), GetScrollBarCtrl(SB_VERT));
		m_index -= 50;
	}
	if (m_index < 0)m_index = 0;
	if (m_index > 1887)m_index = 1887;
	InvalidateRect(NULL, FALSE);
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void Level::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ShowScrollBar(SB_VERT, FALSE);
	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);
}


void Level::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);    //获取对话框长宽      
	CDC   dcBmp;             //定义并创建一个内存设备环境
	dcBmp.CreateCompatibleDC(&dc);             //创建兼容性DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_LEVEL);    //载入资源中图片
	BITMAP   m_bitmap;                         //图片变量               
	bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
											  //将位图选入临时内存设备环境
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//调用函数显示图片StretchBlt显示形状可变
	dc.SetStretchBltMode(HALFTONE);
	//dc.StretchBlt(0, -1000, rect.Width(), 600, &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, m_bitmap.bmHeight-800-m_index, m_bitmap.bmWidth, 800, SRCCOPY);
	//CString index;
	//int realIndex = m_index * 0.862573;
	//index.Format(L"x = %d  y = %d  index = %d realY = %d", mx, my, m_index, my - realIndex);
	//dc.TextOutW(600, 600,index);
}


void Level::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
	Role r;
	r.DoModal();  
}


void Level::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int level = getLeave(point.x, point.y);
	if (level != -1) {
		if (level <= m_level + 1) {
			CDialog::OnOK();
			Game g;
			g.m_level = level;
			g.DoModal();
		}
	}
	else {
		m_ismove = true;
		m_downIndex = point.y;
		m_indexTemp = m_index;
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


int Level::getLeave(int x, int y)
{
	int realIndex = m_index * 0.862573;
	if (x > 420 && x < 470 && (y - realIndex)> 450 && (y - realIndex) < 500)return 1;
	if (x > 420 && x < 470 && (y - realIndex)> 355 && (y - realIndex) < 407)return 2;
	if (x > 420 && x < 470 && (y - realIndex)> 260 && (y - realIndex) < 315)return 3;
	if (x > 420 && x < 470 && (y - realIndex)> 167 && (y - realIndex) < 218)return 4;
	if (x > 420 && x < 470 && (y - realIndex)>  70 && (y - realIndex) < 125)return 5;
	if (x > 420 && x < 470 && (y - realIndex)> -23 && (y - realIndex) <  30)return 6;
	if (x > 493 && x < 542 && (y - realIndex)>-117 && (y - realIndex) < -66)return 7;
	if (x > 493 && x < 542 && (y - realIndex)>-211 && (y - realIndex) <-160)return 8;
	if (x > 493 && x < 542 && (y - realIndex)>-305 && (y - realIndex) <-253)return 9;
	if (x > 420 && x < 470 && (y - realIndex)>-400 && (y - realIndex) <-350)return 10;
	if (x > 420 && x < 470 && (y - realIndex)>-492 && (y - realIndex) <-443	)return 11;
	if (x > 420 && x < 470 && (y - realIndex)>-592 && (y - realIndex) <-541)return 12;
	if (x > 493 && x < 542 && (y - realIndex)>-685 && (y - realIndex) <-634)return 13;
	if (x > 420 && x < 470 && (y - realIndex)>-780 && (y - realIndex) <-728)return 14;
	if (x > 420 && x < 470 && (y - realIndex)>-872 && (y - realIndex) <-823)return 15;
	if (x > 420 && x < 470 && (y - realIndex)>-967 && (y - realIndex) <-917)return 16;
	if (x > 420 && x < 470 && (y - realIndex)>-1062 && (y - realIndex) <-1010)return 17;
	if (x > 420 && x < 470 && (y - realIndex)>-1154 && (y - realIndex) <-1100)return 18;
	if (x > 420 && x < 470 && (y - realIndex)>-1249 && (y - realIndex) <-1197)return 19;
	if (x > 420 && x < 470 && (y - realIndex)>-1344 && (y - realIndex) <-1292)return 20;
	if (x > 423 && x < 473 && (y - realIndex)>-1439 && (y - realIndex) <-1387)return 21; 
	return -1;
}
void Level::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_ismove) {
		m_ismove = false;
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void Level::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	mx = point.x;
	my = point.y;
	///////////////////////
	CRect   rect;
	GetClientRect(&rect);
	if (point.x <= 20 || point.y <= 20 || point.x >= rect.Width()-20 || point.y >= rect.Height()-20) {
		m_ismove = false;
	}
	if (m_ismove) {
		m_index = m_indexTemp + (point.y - m_downIndex);
		if (m_index < 0)m_index = 0;
		if (m_index > 1887)m_index = 1887;
	}
	InvalidateRect(NULL, FALSE);
	CDialogEx::OnMouseMove(nFlags, point);
}
