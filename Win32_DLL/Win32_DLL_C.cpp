#include "stdafx.h"
#include <Windows.h>

extern "C" __declspec(dllexport) VOID MyMsgBox(LPTSTR msg);

VOID MyMsgBox(LPTSTR lpMsg)
{
	TCHAR lpModuleName[MAX_PATH];// ����Ŀ���ɵ�exe��·���ļ���
	GetModuleFileName(NULL, lpModuleName, MAX_PATH);
	MessageBox(NULL, lpMsg, lpModuleName, MB_OK);// ����,����,����
}