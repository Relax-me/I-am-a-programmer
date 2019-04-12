// Game.cpp : 实现文件
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "Game.h"
#include "Level.h"
#include "afxdialogex.h"


// Game 对话框

IMPLEMENT_DYNAMIC(Game, CDialogEx)

Game::Game(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GAME, pParent)
	, m_role(0)
	, m_level(0)
{

}

Game::~Game()
{
}

void Game::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXIT, m_btnExit);
	DDX_Control(pDX, IDC_FAST, m_btnFast);
	DDX_Control(pDX, IDC_MUSIC, m_btnMusic);
	DDX_Control(pDX, IDC_SLOW, m_btnSlow);
	DDX_Control(pDX, IDC_START, m_btnStart);
	DDX_Control(pDX, IDC_STOP, m_btnStop);
}


BEGIN_MESSAGE_MAP(Game, CDialogEx)
	ON_BN_CLICKED(IDC_EXIT, &Game::OnBnClickedExit)
	ON_WM_PAINT()
//	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MUSIC, &Game::OnBnClickedMusic)
	ON_BN_CLICKED(IDC_STOP, &Game::OnBnClickedStop)
	ON_BN_CLICKED(IDC_SLOW, &Game::OnBnClickedSlow)
	ON_BN_CLICKED(IDC_START, &Game::OnBnClickedStart)
	ON_BN_CLICKED(IDC_FAST, &Game::OnBnClickedFast)
END_MESSAGE_MAP()


// Game 消息处理程序


void Game::OnBnClickedExit()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	Level l;
	l.m_role = m_role;
	l.DoModal();
}


void Game::OnPaint()
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
	bmpBackground.LoadBitmap(IDB_GAME);    //载入资源中图片
	BITMAP   m_bitmap;                         //图片变量               
	bmpBackground.GetBitmap(&m_bitmap);       //将图片载入位图中
											  //将位图选入临时内存设备环境
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//调用函数显示图片StretchBlt显示形状可变
	dc.SetStretchBltMode(HALFTONE);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);		   // 不为绘图消息调用 CDialogEx::OnPaint()
}

void Game::OnBnClickedMusic()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Game::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Game::OnBnClickedSlow()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Game::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Game::OnBnClickedFast()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL Game::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_btnExit.LoadBitmaps(IDB_GAME_EXIT);
	m_btnExit.SizeToContent();
	m_btnMusic.LoadBitmaps(IDB_GAME_MUSIC);
	m_btnMusic.SizeToContent();
	m_btnSlow.LoadBitmaps(IDB_GAME_SLOW);
	m_btnSlow.SizeToContent();
	m_btnFast.LoadBitmaps(IDB_GAME_FAST);
	m_btnFast.SizeToContent();
	m_btnStart.LoadBitmaps(IDB_GAME_START);
	m_btnStart.SizeToContent();
	m_btnStop.LoadBitmaps(IDB_GAME_STOP);
	m_btnStop.SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
