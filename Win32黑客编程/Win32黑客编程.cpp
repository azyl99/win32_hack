// Win32�ڿͱ��.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Win32�ڿͱ��.h"

#define MAX_LOADSTRING 100

// ȫ�ֱ���: 
HINSTANCE hInst;                                // ��ǰʵ��
WCHAR szTitle[MAX_LOADSTRING];                  // �������ı�
WCHAR szWindowClass[MAX_LOADSTRING];            // ����������

// �˴���ģ���а����ĺ�����ǰ������: 
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    DialogMain(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: �ڴ˷��ô��롣

    // ��ʼ��ȫ���ַ���
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ִ��Ӧ�ó����ʼ��: 
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32));

    MSG msg;

    // ����Ϣѭ��: 
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��: 
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��:    ���������ڵ���Ϣ��
//
//  WM_COMMAND  - ����Ӧ�ó���˵�
//  WM_PAINT    - ����������
//  WM_DESTROY  - �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hButton, hwndEdit;
	switch (message)
	{
	case WM_CREATE: //���ڴ�����������Ϣ
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MAIN), hWnd, DialogMain);
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);// �����Ϳ�������������Dialog�ˣ��ص�Dialog������˳�
			
			hwndEdit = CreateWindow(L"edit", NULL,
				WS_CHILD | WS_VISIBLE | WS_BORDER,
				20, 70, 100, 25, hWnd, NULL, NULL, NULL);
			hButton = CreateWindow(L"button", L"ȷ��",
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				350, 70, 80, 25, hWnd, NULL, NULL, NULL);
			return 0;
		}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // �����˵�ѡ��: 
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MAIN), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
			// new add
			RECT rect;

            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: �ڴ˴����ʹ�� hdc ���κλ�ͼ����...
			// ȡ�ô�����ʾ����Ĵ�С
			GetClientRect(hWnd, &rect);
			// ����ַ���, λ��(20,20)
			LPTSTR str = L"Hello world!";
			TextOut(hdc, 20, 20, str, wcslen(str));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DialogMain(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	HWND hWnd = NULL;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		default:
			break;
		case IDC_BUTTON_OPEN:
			// �ڶ��������ǿ��Ƴ��������ڵ���ʾ��ʽ
			// SW_SHOW��ʾ�Ե�ǰ��С�������к�ĳ��򴰿ڲ���ʾ����
			WinExec("Notepad.exe", SW_SHOW);
			break;
		case IDC_BUTTON_CLOSE:
			hWnd = FindWindow(L"Notepad", NULL);// �ڶ��������Ǵ�����
			if (hWnd == NULL)
			{
				MessageBox(NULL, L"û���ҵ����±�", L"����", MB_DEFAULT_DESKTOP_ONLY);
				return (INT_PTR)FALSE;
			}
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);
			break;
		case IDC_BUTTON_GETTITLE: 
		{
			hWnd = FindWindow(L"Notepad", NULL);
			if (hWnd == NULL)
			{
				MessageBox(NULL, L"û���ҵ����±�", L"����", MB_DEFAULT_DESKTOP_ONLY);
				return (INT_PTR)FALSE;
			}
			const int MAX_SIZE = 100;
			TCHAR pCaption[MAX_SIZE] = { 0 };
			SendMessage(hWnd, WM_GETTEXT, (WPARAM)MAXBYTE, (LPARAM)pCaption);
			MessageBox(NULL, pCaption, L"�ҵ�����", MB_DEFAULT_DESKTOP_ONLY);
		
		}	break;
		case IDC_BUTTON_EDITTITLE:
			hWnd = FindWindow(L"Notepad", NULL);
			if (hWnd == NULL)
			{
				MessageBox(NULL, L"û���ҵ����±�", L"����", MB_DEFAULT_DESKTOP_ONLY);
				return (INT_PTR)FALSE;
			}
			SendMessage(hWnd, WM_SETTEXT, (WPARAM)0, (LPARAM)L"��Ϣ����");
			break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hDlg, LOWORD(wParam));
		return (INT_PTR)TRUE;
		break;
	}
	return (INT_PTR)FALSE;
}