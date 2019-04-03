// Level.cpp : 实现文件
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "Level.h"
#include "afxdialogex.h"


// Level 对话框

IMPLEMENT_DYNAMIC(Level, CDialogEx)

Level::Level(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LEVEL, pParent)
	, m_role(0)
{

}

Level::~Level()
{
}

void Level::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Level, CDialogEx)
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
	ON_WM_NCCALCSIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Level 消息处理程序


BOOL Level::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	scrollinfo.nPage = 10;    //设置滑块大小
	scrollinfo.nMax = 1000;     //设置滚动条的最大位置0--75
	scrollinfo.nPos = 1000;
	SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL); 
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Level::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
	int unit = 3;
	switch (nSBCode)
	{
	case SB_LINEUP:          //Scroll one line up
		scrollinfo.nPos -= 10;
		if (scrollinfo.nPos<scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, unit * 10);
		break;
	case SB_LINEDOWN:           //Scroll one line down
		scrollinfo.nPos += 10;
		if (scrollinfo.nPos + scrollinfo.nPage>scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
		{
			scrollinfo.nPos = scrollinfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, -unit * 10);
		break;
	case SB_PAGEUP:            //Scroll one page up.
		scrollinfo.nPos -= 50;
		if (scrollinfo.nPos <= scrollinfo.nMin)
		{
			scrollinfo.nPos = scrollinfo.nMin;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, unit * 50);
		break;
	case SB_PAGEDOWN:        //Scroll one page down        
		scrollinfo.nPos += 50;
		if (scrollinfo.nPos + scrollinfo.nPage >= scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
		{
			scrollinfo.nPos = scrollinfo.nMax;
			break;
		}
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		ScrollWindow(0, -unit * 50);
		break;
	case SB_ENDSCROLL:      //End scroll
		break;
	case SB_THUMBPOSITION:  //Scroll to the absolute position. The current position is provided in nPos
		break;
	case SB_THUMBTRACK:                  //Drag scroll box to specified position. The current position is provided in nPos
		ScrollWindow(0, (scrollinfo.nPos - nPos)*unit);
		scrollinfo.nPos = nPos;
		SetScrollInfo(SB_VERT, &scrollinfo, SIF_ALL);
		break;
	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


BOOL Level::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// TODO: Add your message handler code here and/or call default 
	SCROLLINFO scrollinfo;
	if (zDelta == 120)
	{
		OnVScroll(SB_PAGEUP, GetScrollPos(SB_VERT), GetScrollBarCtrl(SB_VERT));

		//GetScrollInfo(SB_VERT,&scrollinfo);


		//if(scrollinfo.nPos <= scrollinfo.nMin)
		// {
		// //MessageBox("在最顶端，什么都不做");
		// }
		// else 
		// {
		// scrollinfo.nPos -= 5;
		// SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		// ScrollWindow(0,5);
		// }
	}
	else if (zDelta == -120)
	{
		OnVScroll(SB_PAGEDOWN, GetScrollPos(SB_VERT), GetScrollBarCtrl(SB_VERT));
		//GetScrollInfo(SB_VERT,&scrollinfo);
		//if(scrollinfo.nPos >= (scrollinfo.nMax-scrollinfo.nPage))
		//{
		// //MessageBox("在最底端");
		//}
		//else 
		//{
		// scrollinfo.nPos += 5;
		// SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		// ScrollWindow(0,-5);
		//} 
	}
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
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
}
