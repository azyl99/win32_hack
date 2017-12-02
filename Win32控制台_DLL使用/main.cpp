#include <Windows.h>
#include <iostream>
#pragma comment (lib, "Win32_DLL")

#include "../Win32_DLL/Win32_DLL_Cpp.h"
extern "C" VOID MyMsgBox(LPTSTR msg);

int main()
{
	std::cout << MathFuncs::MyMathFuncs::Add(1, 2.5) << std::endl;
	MyMsgBox(L"我在这里");
	return 0;
}