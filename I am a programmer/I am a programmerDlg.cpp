
// I am a programmerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "I am a programmerDlg.h"
#include "afxdialogex.h"
#include "Role.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIamaprogrammerDlg �Ի���



CIamaprogrammerDlg::CIamaprogrammerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_IAMAPROGRAMMER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIamaprogrammerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_startbtn);
}

BEGIN_MESSAGE_MAP(CIamaprogrammerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CIamaprogrammerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CIamaprogrammerDlg ��Ϣ�������

BOOL CIamaprogrammerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_startbtn.LoadBitmaps(IDB_START_BT1, IDB_START_BT0);
	m_startbtn.SizeToContent();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIamaprogrammerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);    //��ȡ�Ի��򳤿�      
		CDC   dcBmp;             //���岢����һ���ڴ��豸����
		dcBmp.CreateCompatibleDC(&dc);             //����������DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_START);    //������Դ��ͼƬ
		BITMAP   m_bitmap;                         //ͼƬ����               
		bmpBackground.GetBitmap(&m_bitmap);       //��ͼƬ����λͼ��
												  //��λͼѡ����ʱ�ڴ��豸����
		CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
		//���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
		dc.SetStretchBltMode(HALFTONE);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CIamaprogrammerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIamaprogrammerDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	Role role;
	role.DoModal();
}
