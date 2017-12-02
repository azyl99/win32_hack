#include "stdafx.h"
#include <Windows.h>

extern "C" __declspec(dllexport) VOID MyMsgBox(LPTSTR msg);

VOID MyMsgBox(LPTSTR lpMsg)
{
	TCHAR lpModuleName[MAX_PATH];// 本项目生成的exe的路径文件名
	GetModuleFileName(NULL, lpModuleName, MAX_PATH);
	MessageBox(NULL, lpMsg, lpModuleName, MB_OK);// 父亲,内容,标题
}