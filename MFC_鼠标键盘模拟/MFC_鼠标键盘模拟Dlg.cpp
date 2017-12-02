
// MFC_鼠标键盘模拟Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_鼠标键盘模拟.h"
#include "MFC_鼠标键盘模拟Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFC_鼠标键盘模拟Dlg 对话框



CMFC_鼠标键盘模拟Dlg::CMFC_鼠标键盘模拟Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC__DIALOG, pParent)
	, m_StrCaption(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_鼠标键盘模拟Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAPTION, m_StrCaption);
	DDX_Control(pDX, IDC_BTN, m_start);
}

BEGIN_MESSAGE_MAP(CMFC_鼠标键盘模拟Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN, &CMFC_鼠标键盘模拟Dlg::OnBnClickedBtn)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMFC_鼠标键盘模拟Dlg 消息处理程序

BOOL CMFC_鼠标键盘模拟Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_鼠标键盘模拟Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_鼠标键盘模拟Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_鼠标键盘模拟Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_鼠标键盘模拟Dlg::OnBnClickedBtn()
{
	CString strBtn;// 显示在按钮上的文字
	int nInterval;
	// 获取编辑框的文字
	GetDlgItemText(IDC_EDIT_CAPTION, m_StrCaption);
	// 第二个参数传递转换int是否成功，如果是NULL/FALSE/0，就是不取
	// 第三个参数指示是否是有符号数
	nInterval = GetDlgItemInt(IDC_EDIT_INTERVAL, 0, TRUE);

	// 判断输入的值是否非法
	if (m_StrCaption == "" || nInterval == 0)
	{
		return;
	}
	m_start.GetWindowText(strBtn);
	if (strBtn == L"开始")
	{
		// 最后一个参数为NULL，则通过WM_TIMER的消息处理函数来处理定时事件。
		SetTimer(1, nInterval * 1000, NULL);// 1是定时器的编号
		m_start.SetWindowText(L"停止");
		// 该函数允许/禁止指定的窗口或控件接受鼠标和键盘的输入，当输入被禁止时，窗口不响应鼠标和按键的输入。
		// 因为这个程序要模拟鼠标和键盘的操作，为了避免本程序会失去焦点
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(FALSE);
	}
	else
	{
		KillTimer(1);
		m_start.SetWindowText(L"开始");
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(TRUE);
	}
}


void CMFC_鼠标键盘模拟Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	HWND hWnd;
	switch (nIDEvent)
	{
	case 1:// 1号定时器
		hWnd = ::FindWindow(NULL, m_StrCaption.GetBuffer());
		
		// lParam的0到15位为该键在键盘上的重复次数，经常设为1，即按键1次；
		// 16至23位为键盘的扫描码，通过MapVirtualKey配合其参数可以得到；
		// 24位为扩展键，即某些右ALT和CTRL；
		// 29、30、31位按照说明设置即可（第30位对于keydown在和shift等结合的时候通常要设置为1）。
		::PostMessage(hWnd, WM_KEYDOWN, 0x30, (LPARAM)10);// 并没有重复10次
		::PostMessage(hWnd, WM_KEYDOWN, VK_RETURN, 1);
		::PostMessage(hWnd, WM_KEYUP, VK_RETURN, 1);
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
