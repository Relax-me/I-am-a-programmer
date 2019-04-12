// Game.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "Game.h"
#include "Level.h"
#include "afxdialogex.h"


// Game �Ի���

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


// Game ��Ϣ�������


void Game::OnBnClickedExit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	Level l;
	l.m_role = m_role;
	l.DoModal();
}


void Game::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
	CPaintDC   dc(this);
	CRect   rect;
	GetClientRect(&rect);    //��ȡ�Ի��򳤿�      
	CDC   dcBmp;             //���岢����һ���ڴ��豸����
	dcBmp.CreateCompatibleDC(&dc);             //����������DC
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_GAME);    //������Դ��ͼƬ
	BITMAP   m_bitmap;                         //ͼƬ����               
	bmpBackground.GetBitmap(&m_bitmap);       //��ͼƬ����λͼ��
											  //��λͼѡ����ʱ�ڴ��豸����
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
	dc.SetStretchBltMode(HALFTONE);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);		   // ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}

void Game::OnBnClickedMusic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Game::OnBnClickedStop()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Game::OnBnClickedSlow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Game::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void Game::OnBnClickedFast()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL Game::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
				  // �쳣: OCX ����ҳӦ���� FALSE
}
