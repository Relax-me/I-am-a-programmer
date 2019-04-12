// Role.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "I am a programmer.h"
#include "Role.h"
#include "Level.h"
#include "afxdialogex.h"
#include "MyDataFile.h"


// Role �Ի���

IMPLEMENT_DYNAMIC(Role, CDialogEx)

Role::Role(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ROLE, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Role::~Role()
{
}

void Role::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Role_Del1, m_role_del1);
	DDX_Control(pDX, IDC_Role_Del2, m_role_del2);
	DDX_Control(pDX, IDC_Role_Del3, m_role_del3);
}


BEGIN_MESSAGE_MAP(Role, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_Role_Del1, &Role::OnBnClickedRoleDel1)
	ON_BN_CLICKED(IDC_Role_Del2, &Role::OnBnClickedRoleDel2)
	ON_BN_CLICKED(IDC_Role_Del3, &Role::OnBnClickedRoleDel3)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_Role_Btn1, &Role::OnBnClickedRoleBtn1)
	ON_BN_CLICKED(IDC_Role_Btn2, &Role::OnBnClickedRoleBtn2)
	ON_BN_CLICKED(IDC_Role_Btn3, &Role::OnBnClickedRoleBtn3)
END_MESSAGE_MAP()


// Role ��Ϣ�������


void Role::OnPaint()
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
	bmpBackground.LoadBitmap(IDB_ROLE);    //������Դ��ͼƬ
	BITMAP   m_bitmap;                         //ͼƬ����               
	bmpBackground.GetBitmap(&m_bitmap);       //��ͼƬ����λͼ��
											  //��λͼѡ����ʱ�ڴ��豸����
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);
	//���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
	dc.SetStretchBltMode(HALFTONE);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	//////////////////
	int role_1 = m_data.getRoleL(1);
	int role_2 = m_data.getRoleL(2);
	int role_3 = m_data.getRoleL(3);
	CString strRole_1, strRole_2, strRole_3;
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(89,86,117));
	CFont   font;
	LOGFONT   lf;
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = -30;
	lf.lfWeight = 700;
	lf.lfClipPrecision = CLIP_LH_ANGLES;
	memcpy(lf.lfFaceName, "΢���ź�",sizeof("΢���ź�"));
	lf.lfEscapement = -60;
	font.CreateFontIndirect(&lf);
	dc.SelectObject(&font);
	if (role_1 == -1)
	{
		dc.TextOutW(175,590,L"δ����");
	}
	else
	{
		strRole_1.Format(L"%d������Ա", (role_1 - 1) / 5 + 1);
		dc.TextOutW(155, 590, strRole_1);
	}
	font.DeleteObject();
	//////////////////////////////////
	lf.lfEscapement = -10; 
	font.CreateFontIndirect(&lf);
	dc.SelectObject(&font);
	if (role_2 == -1)
	{
		dc.TextOutW(480, 608, L"δ����");
	}
	else
	{
		strRole_2.Format(L"%d������Ա", (role_2 - 1) / 5 + 1);
		dc.TextOutW(460, 608, strRole_2);
	}
	font.DeleteObject();
	//////////////////////////////////
	lf.lfEscapement = 60;
	font.CreateFontIndirect(&lf);
	dc.SelectObject(&font);
	if (role_3 == -1)
	{
		dc.TextOutW(810, 597, L"δ����");
	}
	else
	{
		strRole_3.Format(L"%d������Ա", (role_3 - 1) / 5 + 1);
		dc.TextOutW(790, 597, strRole_3);
	}
	font.DeleteObject();
}


BOOL Role::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	m_role_del1.LoadBitmaps(IDB_ROLE_DEL_BTN);
	m_role_del1.SizeToContent();
	m_role_del2.LoadBitmaps(IDB_ROLE_DEL_BTN);
	m_role_del2.SizeToContent();
	m_role_del3.LoadBitmaps(IDB_ROLE_DEL_BTN);
	m_role_del3.SizeToContent();
	////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void Role::OnBnClickedRoleDel1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_data.setRoleL(1, -1);
	InvalidateRect(NULL, FALSE);
}


void Role::OnBnClickedRoleDel2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_data.setRoleL(2, -1);
	InvalidateRect(NULL, FALSE);
}


void Role::OnBnClickedRoleDel3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_data.setRoleL(3, -1);
	InvalidateRect(NULL, FALSE);
}


HBRUSH Role::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	//����������Ǳ����Ǵ�ɫ����
	/*  if(nCtlColor == CTLCOLOR_BTN)
	{
	pDC->SetBkMode(TRANSPARENT);
	hbr = (HBRUSH) ::GetStockObject(NULL_BRUSH);
	}   */
	//û�취����һ�����ܵġ�����֣��ڱ�����ͼƬ������£�nCtlColor��������CTLCOLOR_BTN�ˣ��������ϵ���Կ϶���
	//ÿ���ؼ�������������Ϣ
	UINT id = pWnd->GetDlgCtrlID();
	if (id == IDC_Role_Btn1 || id == IDC_Role_Btn2 || id == IDC_Role_Btn3)
	{
		pDC->SetBkMode(TRANSPARENT);

		CRect rc;
		pWnd->GetWindowRect(&rc);
		ScreenToClient(&rc);

		CDC* dc = GetDC();

		pDC->BitBlt(0, 0, rc.Width(), rc.Height(), dc, rc.left, rc.top, SRCCOPY);  //�Ѹ����ڱ���ͼƬ�Ȼ�����ť��

		ReleaseDC(dc);

		hbr = (HBRUSH) ::GetStockObject(NULL_BRUSH);
	}
	return hbr;
}


void Role::OnBnClickedRoleBtn1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	int role_1 = m_data.getRoleL(1);
	if(role_1 == -1)
	{
		m_data.setRoleL(1, 0);
		InvalidateRect(NULL, FALSE);
	}
	Level Lchoose;
	Lchoose.m_role = 1;
	Lchoose.DoModal();
}


void Role::OnBnClickedRoleBtn2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	int role_2 = m_data.getRoleL(2);
	if (role_2 == -1)
	{
		m_data.setRoleL(2, 0);
		InvalidateRect(NULL, FALSE);
	}
	Level Lchoose; 
	Lchoose.m_role = 2;
	Lchoose.DoModal();
}


void Role::OnBnClickedRoleBtn3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	int role_3 = m_data.getRoleL(3);
	if (role_3 == -1)
	{
		m_data.setRoleL(3, 0);
		InvalidateRect(NULL, FALSE);
	}
	Level Lchoose;
	Lchoose.m_role = 3;
	Lchoose.DoModal();
}
