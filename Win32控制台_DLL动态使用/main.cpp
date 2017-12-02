#include <Windows.h>
#include <iostream>

typedef VOID (*PMyMsgBox)(LPTSTR msg);
#define STR(x) #x
#define CAT(a,b) STR(a##b)
int main()
{
	TCHAR libPath[MAX_PATH] = L"../Debug/Win32_DLL.dll";
	HMODULE hModule = LoadLibrary(libPath);
	if (hModule == NULL)
	{
		MessageBox(NULL, L"DLL文件加载失败", L"DLL文件加载失败", MB_OK);
		return -1;
	}
	PMyMsgBox pMyMsgBox = (PMyMsgBox)GetProcAddress(hModule, "MyMsgBox");
	pMyMsgBox(L"hahaha");

	return 0;
}