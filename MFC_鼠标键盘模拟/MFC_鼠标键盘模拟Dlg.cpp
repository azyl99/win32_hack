
// MFC_������ģ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_������ģ��.h"
#include "MFC_������ģ��Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_������ģ��Dlg �Ի���



CMFC_������ģ��Dlg::CMFC_������ģ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC__DIALOG, pParent)
	, m_StrCaption(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_������ģ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_StrCaption);
	DDX_Control(pDX, IDC_BTN, m_start);
}

BEGIN_MESSAGE_MAP(CMFC_������ģ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN, &CMFC_������ģ��Dlg::OnBnClickedBtn)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFC_������ģ��Dlg ��Ϣ�������

BOOL CMFC_������ģ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFC_������ģ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_������ģ��Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_������ģ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_������ģ��Dlg::OnBnClickedBtn()
{
	CString strBtn;// ��ʾ�ڰ�ť�ϵ�����
	int nInterval;
	// ��ȡ�༭�������
	GetDlgItemText(IDC_EDIT_CAPTION, m_StrCaption);
	// �ڶ�����������ת��int�Ƿ�ɹ��������NULL/FALSE/0�����ǲ�ȡ
	// ����������ָʾ�Ƿ����з�����
	nInterval = GetDlgItemInt(IDC_EDIT_INTERVAL, 0, TRUE);

	// �ж������ֵ�Ƿ�Ƿ�
	if (m_StrCaption == "" || nInterval == 0)
	{
		return;
	}
	m_start.GetWindowText(strBtn);
	if (strBtn == L"��ʼ")
	{
		// ���һ������ΪNULL����ͨ��WM_TIMER����Ϣ������������ʱ�¼���
		SetTimer(1, nInterval * 1000, NULL);// 1�Ƕ�ʱ���ı��
		m_start.SetWindowText(L"ֹͣ");
		// �ú�������/��ָֹ���Ĵ��ڻ�ؼ��������ͼ��̵����룬�����뱻��ֹʱ�����ڲ���Ӧ���Ͱ��������롣
		// ��Ϊ�������Ҫģ�����ͼ��̵Ĳ�����Ϊ�˱��Ȿ�����ʧȥ����
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(FALSE);
	}
	else
	{
		KillTimer(1);
		m_start.SetWindowText(L"��ʼ");
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(TRUE);
	}
}


void CMFC_������ģ��Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	HWND hWnd;
	switch (nIDEvent)
	{
	case 1:// 1�Ŷ�ʱ��
		hWnd = ::FindWindow(NULL, m_StrCaption.GetBuffer());
		
		// lParam��0��15λΪ�ü��ڼ����ϵ��ظ�������������Ϊ1��������1�Σ�
		// 16��23λΪ���̵�ɨ���룬ͨ��MapVirtualKey�����������Եõ���
		// 24λΪ��չ������ĳЩ��ALT��CTRL��
		// 29��30��31λ����˵�����ü��ɣ���30λ����keydown�ں�shift�Ƚ�ϵ�ʱ��ͨ��Ҫ����Ϊ1����
		::PostMessage(hWnd, WM_KEYDOWN, 0x30, (LPARAM)10);// ��û���ظ�10��
		::PostMessage(hWnd, WM_KEYDOWN, VK_RETURN, 1);
		::PostMessage(hWnd, WM_KEYUP, VK_RETURN, 1);
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
