# Message Map And Message Cracker Macros

[Macros index](<macros.md>)

## Backlog

```c
// admin\activec\nodemgr\addsnpin.h
#define MSG_LOADABOUT_REQUEST (WM_USER + 100)
#define MSG_LOADABOUT_COMPLETE (WM_USER + 101)

// admin\activec\nodemgr\taskui.h
#define CHAIN_MSG_MAP_EX(theChainClass) \
    { \
        theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult); \
    }

// admin\services\sched\svc_core\netsch.cxx
#define COMMAND_STRING_LENGTH_APPROX    (((MAX_PATH / 4) + 1) * sizeof(WCHAR))

// admin\wmi\wbem\sdk\activex\controls\singleview\dlgrefquery.h
#define MSG_UPDATE_DIALOG  (WM_USER + 200)

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlcrack.h
#define BEGIN_MSG_MAP_EX(theClass) \
public: \
	BOOL m_bATL3MsgHandled; \
	/* "handled" management for cracked handlers */ \
	BOOL IsMsgHandled() const \
	{ \
		return m_bATL3MsgHandled; \
	} \
	void SetMsgHandled(BOOL bHandled) \
	{ \
		m_bATL3MsgHandled = bHandled; \
	} \
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0) \
	{ \
		BOOL bATL3OldMsgHandled = m_bATL3MsgHandled; \
		BOOL bRet = _ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, dwMsgMapID); \
		m_bATL3MsgHandled = bATL3OldMsgHandled; \
		return bRet; \
	} \
	BOOL _ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID) \
	{ \
		BOOL bHandled = TRUE; \
		hWnd; \
		uMsg; \
		wParam; \
		lParam; \
		lResult; \
		bHandled; \
		switch(dwMsgMapID) \
		{ \
		case 0:
#define MSG_WM_CREATE(func) \
	if (uMsg == WM_CREATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPCREATESTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INITDIALOG(func) \
	if (uMsg == WM_INITDIALOG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COPYDATA(func) \
	if (uMsg == WM_COPYDATA) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (PCOPYDATASTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DESTROY(func) \
	if (uMsg == WM_DESTROY) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOVE(func) \
	if (uMsg == WM_MOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SIZE(func) \
	if (uMsg == WM_SIZE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CSize(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ACTIVATE(func) \
	if (uMsg == WM_ACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (BOOL)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETFOCUS(func) \
	if (uMsg == WM_SETFOCUS) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_KILLFOCUS(func) \
	if (uMsg == WM_KILLFOCUS) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENABLE(func) \
	if (uMsg == WM_ENABLE) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PAINT(func) \
	if (uMsg == WM_PAINT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CLOSE(func) \
	if (uMsg == WM_CLOSE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYENDSESSION(func) \
	if (uMsg == WM_QUERYENDSESSION) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (UINT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYOPEN(func) \
	if (uMsg == WM_QUERYOPEN) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ERASEBKGND(func) \
	if (uMsg == WM_ERASEBKGND) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSCOLORCHANGE(func) \
	if (uMsg == WM_SYSCOLORCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENDSESSION(func) \
	if (uMsg == WM_ENDSESSION) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (UINT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SHOWWINDOW(func) \
	if (uMsg == WM_SHOWWINDOW) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (int)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLOREDIT(func) \
	if (uMsg == WM_CTLCOLOREDIT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORLISTBOX(func) \
	if (uMsg == WM_CTLCOLORLISTBOX) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORBTN(func) \
	if (uMsg == WM_CTLCOLORBTN) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORDLG(func) \
	if (uMsg == WM_CTLCOLORDLG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORSCROLLBAR(func) \
	if (uMsg == WM_CTLCOLORSCROLLBAR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORSTATIC(func) \
	if (uMsg == WM_CTLCOLORSTATIC) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETTINGCHANGE(func) \
	if (uMsg == WM_SETTINGCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPCTSTR)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DEVMODECHANGE(func) \
	if (uMsg == WM_DEVMODECHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPCTSTR)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ACTIVATEAPP(func) \
	if (uMsg == WM_ACTIVATEAPP) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (DWORD)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_FONTCHANGE(func) \
	if (uMsg == WM_FONTCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_TIMECHANGE(func) \
	if (uMsg == WM_TIMECHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CANCELMODE(func) \
	if (uMsg == WM_CANCELMODE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETCURSOR(func) \
	if (uMsg == WM_SETCURSOR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEACTIVATE(func) \
	if (uMsg == WM_MOUSEACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHILDACTIVATE(func) \
	if (uMsg == WM_CHILDACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETMINMAXINFO(func) \
	if (uMsg == WM_GETMINMAXINFO) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPMINMAXINFO)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ICONERASEBKGND(func) \
	if (uMsg == WM_ICONERASEBKGND) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SPOOLERSTATUS(func) \
	if (uMsg == WM_SPOOLERSTATUS) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (UINT)LOWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DRAWITEM(func) \
	if (uMsg == WM_DRAWITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDRAWITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MEASUREITEM(func) \
	if (uMsg == WM_MEASUREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPMEASUREITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DELETEITEM(func) \
	if (uMsg == WM_DELETEITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDELETEITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHARTOITEM(func) \
	if (uMsg == WM_CHARTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_VKEYTOITEM(func) \
	if (uMsg == WM_VKEYTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYDRAGICON(func) \
	if (uMsg == WM_QUERYDRAGICON) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COMPAREITEM(func) \
	if (uMsg == WM_COMPAREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (LPCOMPAREITEMSTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COMPACTING(func) \
	if (uMsg == WM_COMPACTING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCCREATE(func) \
	if (uMsg == WM_NCCREATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPCREATESTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCDESTROY(func) \
	if (uMsg == WM_NCDESTROY) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCCALCSIZE(func) \
	if (uMsg == WM_NCCALCSIZE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((BOOL)wParam, lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCHITTEST(func) \
	if (uMsg == WM_NCHITTEST) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCPAINT(func) \
	if (uMsg == WM_NCPAINT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HRGN)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCACTIVATE(func) \
	if (uMsg == WM_NCACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((BOOL)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETDLGCODE(func) \
	if (uMsg == WM_GETDLGCODE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPMSG)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMOUSEMOVE(func) \
	if (uMsg == WM_NCMOUSEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCLBUTTONDOWN(func) \
	if (uMsg == WM_NCLBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCLBUTTONUP(func) \
	if (uMsg == WM_NCLBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCLBUTTONDBLCLK(func) \
	if (uMsg == WM_NCLBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCRBUTTONDOWN(func) \
	if (uMsg == WM_NCRBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCRBUTTONUP(func) \
	if (uMsg == WM_NCRBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCRBUTTONDBLCLK(func) \
	if (uMsg == WM_NCRBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMBUTTONDOWN(func) \
	if (uMsg == WM_NCMBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMBUTTONUP(func) \
	if (uMsg == WM_NCMBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMBUTTONDBLCLK(func) \
	if (uMsg == WM_NCMBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_KEYDOWN(func) \
	if (uMsg == WM_KEYDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_KEYUP(func) \
	if (uMsg == WM_KEYUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHAR(func) \
	if (uMsg == WM_CHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DEADCHAR(func) \
	if (uMsg == WM_DEADCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSKEYDOWN(func) \
	if (uMsg == WM_SYSKEYDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSKEYUP(func) \
	if (uMsg == WM_SYSKEYUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSCHAR(func) \
	if (uMsg == WM_SYSCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSDEADCHAR(func) \
	if (uMsg == WM_SYSDEADCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSCOMMAND(func) \
	if (uMsg == WM_SYSCOMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_TCARD(func) \
	if (uMsg == WM_TCARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (DWORD)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_TIMER(func) \
	if (uMsg == WM_TIMER) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (TIMERPROC*)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HSCROLL(func) \
	if (uMsg == WM_HSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_VSCROLL(func) \
	if (uMsg == WM_VSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INITMENU(func) \
	if (uMsg == WM_INITMENU) \
	{ \
		SetMsgHandled(TRUE); \
		func((HMENU)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INITMENUPOPUP(func) \
	if (uMsg == WM_INITMENUPOPUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((HMENU)wParam, (UINT)LOWORD(lParam), (BOOL)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUSELECT(func) \
	if (uMsg == WM_MENUSELECT) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUCHAR(func) \
	if (uMsg == WM_MENUCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((TCHAR)LOWORD(wParam), (UINT)HIWORD(wParam), (HMENU)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NOTIFY(func) \
	if (uMsg == WM_NOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((int)wParam, (LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENTERIDLE(func) \
	if (uMsg == WM_ENTERIDLE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEMOVE(func) \
	if (uMsg == WM_MOUSEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEWHEEL(func) \
	if (uMsg == WM_MOUSEWHEEL) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (short)HIWORD(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_LBUTTONDOWN(func) \
	if (uMsg == WM_LBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_LBUTTONUP(func) \
	if (uMsg == WM_LBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_LBUTTONDBLCLK(func) \
	if (uMsg == WM_LBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RBUTTONDOWN(func) \
	if (uMsg == WM_RBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RBUTTONUP(func) \
	if (uMsg == WM_RBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RBUTTONDBLCLK(func) \
	if (uMsg == WM_RBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MBUTTONDOWN(func) \
	if (uMsg == WM_MBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MBUTTONUP(func) \
	if (uMsg == WM_MBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MBUTTONDBLCLK(func) \
	if (uMsg == WM_MBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PARENTNOTIFY(func) \
	if (uMsg == WM_PARENTNOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MDIACTIVATE(func) \
	if (uMsg == WM_MDIACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RENDERFORMAT(func) \
	if (uMsg == WM_RENDERFORMAT) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RENDERALLFORMATS(func) \
	if (uMsg == WM_RENDERALLFORMATS) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DESTROYCLIPBOARD(func) \
	if (uMsg == WM_DESTROYCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DRAWCLIPBOARD(func) \
	if (uMsg == WM_DRAWCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PAINTCLIPBOARD(func) \
	if (uMsg == WM_PAINTCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (const LPPAINTSTRUCT)::GlobalLock((HGLOBAL)lParam)); \
		::GlobalUnlock((HGLOBAL)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_VSCROLLCLIPBOARD(func) \
	if (uMsg == WM_VSCROLLCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CONTEXTMENU(func) \
	if (uMsg == WM_CONTEXTMENU) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SIZECLIPBOARD(func) \
	if (uMsg == WM_SIZECLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (const LPRECT)::GlobalLock((HGLOBAL)lParam)); \
		::GlobalUnlock((HGLOBAL)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ASKCBFORMATNAME(func) \
	if (uMsg == WM_ASKCBFORMATNAME) \
	{ \
		SetMsgHandled(TRUE); \
		func((DWORD)wParam, (LPTSTR)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHANGECBCHAIN(func) \
	if (uMsg == WM_CHANGECBCHAIN) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HSCROLLCLIPBOARD(func) \
	if (uMsg == WM_HSCROLLCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYNEWPALETTE(func) \
	if (uMsg == WM_QUERYNEWPALETTE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PALETTECHANGED(func) \
	if (uMsg == WM_PALETTECHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PALETTEISCHANGING(func) \
	if (uMsg == WM_PALETTEISCHANGING) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DROPFILES(func) \
	if (uMsg == WM_DROPFILES) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDROP)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_WINDOWPOSCHANGING(func) \
	if (uMsg == WM_WINDOWPOSCHANGING) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPWINDOWPOS)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_WINDOWPOSCHANGED(func) \
	if (uMsg == WM_WINDOWPOSCHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPWINDOWPOS)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_EXITMENULOOP(func) \
	if (uMsg == WM_EXITMENULOOP) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENTERMENULOOP(func) \
	if (uMsg == WM_ENTERMENULOOP) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_STYLECHANGED(func) \
	if (uMsg == WM_STYLECHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPSTYLESTRUCT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_STYLECHANGING(func) \
	if (uMsg == WM_STYLECHANGING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPSTYLESTRUCT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SIZING(func) \
	if (uMsg == WM_SIZING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPRECT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOVING(func) \
	if (uMsg == WM_MOVING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPRECT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CAPTURECHANGED(func) \
	if (uMsg == WM_CAPTURECHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DEVICECHANGE(func) \
	if (uMsg == WM_DEVICECHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (DWORD)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COMMAND(func) \
	if (uMsg == WM_COMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DISPLAYCHANGE(func) \
	if (uMsg == WM_DISPLAYCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CSize(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENTERSIZEMOVE(func) \
	if (uMsg == WM_ENTERSIZEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_EXITSIZEMOVE(func) \
	if (uMsg == WM_EXITSIZEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETFONT(func) \
	if (uMsg == WM_GETFONT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETHOTKEY(func) \
	if (uMsg == WM_GETHOTKEY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETICON(func) \
	if (uMsg == WM_GETICON) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETTEXT(func) \
	if (uMsg == WM_GETTEXT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((int)wParam, (LPTSTR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETTEXTLENGTH(func) \
	if (uMsg == WM_GETTEXTLENGTH) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HELP(func) \
	if (uMsg == WM_HELP) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPHELPINFO)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HOTKEY(func) \
	if (uMsg == WM_HOTKEY) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INPUTLANGCHANGE(func) \
	if (uMsg == WM_INPUTLANGCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((DWORD)wParam, (HKL)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INPUTLANGCHANGEREQUEST(func) \
	if (uMsg == WM_INPUTLANGCHANGEREQUEST) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (HKL)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NEXTDLGCTL(func) \
	if (uMsg == WM_NEXTDLGCTL) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)LOWORD(lParam), wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NEXTMENU(func) \
	if (uMsg == WM_NEXTMENU) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)wParam, (LPMDINEXTMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NOTIFYFORMAT(func) \
	if (uMsg == WM_NOTIFYFORMAT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (int)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_POWERBROADCAST(func) \
	if (uMsg == WM_POWERBROADCAST) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((DWORD)wParam, (DWORD)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PRINT(func) \
	if (uMsg == WM_PRINT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam, (UINT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PRINTCLIENT(func) \
	if (uMsg == WM_PRINTCLIENT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam, (UINT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RASDIALEVENT(func) \
	if (uMsg == WM_RASDIALEVENT) \
	{ \
		SetMsgHandled(TRUE); \
		func((RASCONNSTATE)wParam, (DWORD)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETFONT(func) \
	if (uMsg == WM_SETFONT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HFONT)wParam, (BOOL)LOWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETHOTKEY(func) \
	if (uMsg == WM_SETHOTKEY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((int)LOBYTE(LOWORD(wParam)), (UINT)HIBYTE(LOWORD(wParam))); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETICON(func) \
	if (uMsg == WM_SETICON) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (HICON)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETREDRAW(func) \
	if (uMsg == WM_SETREDRAW) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETTEXT(func) \
	if (uMsg == WM_SETTEXT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPCTSTR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_USERCHANGED(func) \
	if (uMsg == WM_USERCHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEHOVER(func) \
	if (uMsg == WM_MOUSEHOVER) \
	{ \
		SetMsgHandled(TRUE); \
		func(wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSELEAVE(func) \
	if (uMsg == WM_MOUSELEAVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENURBUTTONUP(func) \
	if (uMsg == WM_MENURBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func(wParam, (HMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUDRAG(func) \
	if (uMsg == WM_MENUDRAG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(wParam, (HMENU)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUGETOBJECT(func) \
	if (uMsg == WM_MENUGETOBJECT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((PMENUGETOBJECTINFO)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_UNINITMENUPOPUP(func) \
	if (uMsg == WM_UNINITMENUPOPUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(lParam), (HMENU)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUCOMMAND(func) \
	if (uMsg == WM_MENUCOMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func(wParam, (HMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_FORWARDMSG(func) \
	if (uMsg == WM_FORWARDMSG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPMSG)lParam, (DWORD)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_DM_GETDEFID(func) \
	if (uMsg == DM_GETDEFID) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_DM_SETDEFID(func) \
	if (uMsg == DM_SETDEFID) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_DM_REPOSITION(func) \
	if (uMsg == DM_REPOSITION) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_COMMAND(func) \
	if (uMsg == OCM_COMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_NOTIFY(func) \
	if (uMsg == OCM_NOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((int)wParam, (LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_PARENTNOTIFY(func) \
	if (uMsg == OCM_PARENTNOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_DRAWITEM(func) \
	if (uMsg == OCM_DRAWITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDRAWITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_MEASUREITEM(func) \
	if (uMsg == OCM_MEASUREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPMEASUREITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_COMPAREITEM(func) \
	if (uMsg == OCM_COMPAREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (LPCOMPAREITEMSTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_DELETEITEM(func) \
	if (uMsg == OCM_DELETEITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDELETEITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_VKEYTOITEM(func) \
	if (uMsg == OCM_VKEYTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CHARTOITEM(func) \
	if (uMsg == OCM_CHARTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_HSCROLL(func) \
	if (uMsg == OCM_HSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_VSCROLL(func) \
	if (uMsg == OCM_VSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLOREDIT(func) \
	if (uMsg == OCM_CTLCOLOREDIT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORLISTBOX(func) \
	if (uMsg == OCM_CTLCOLORLISTBOX) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORBTN(func) \
	if (uMsg == OCM_CTLCOLORBTN) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORDLG(func) \
	if (uMsg == OCM_CTLCOLORDLG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORSCROLLBAR(func) \
	if (uMsg == OCM_CTLCOLORSCROLLBAR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORSTATIC(func) \
	if (uMsg == OCM_CTLCOLORSTATIC) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CLEAR(func) \
	if (uMsg == WM_CLEAR) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COPY(func) \
	if (uMsg == WM_COPY) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CUT(func) \
	if (uMsg == WM_CUT) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PASTE(func) \
	if (uMsg == WM_PASTE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_UNDO(func) \
	if (uMsg == WM_UNDO) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_HANDLER_EX(id, code, func) \
	if (uMsg == WM_COMMAND && code == HIWORD(wParam) && id == LOWORD(wParam)) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_ID_HANDLER_EX(id, func) \
	if (uMsg == WM_COMMAND && id == LOWORD(wParam)) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_CODE_HANDLER_EX(code, func) \
	if (uMsg == WM_COMMAND && code == HIWORD(wParam)) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_HANDLER_EX(id, cd, func) \
	if (uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_ID_HANDLER_EX(id, func) \
	if (uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_CODE_HANDLER_EX(cd, func) \
	if (uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_RANGE_HANDLER_EX(idFirst, idLast, func) \
	if(uMsg == WM_COMMAND && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_RANGE_CODE_HANDLER_EX(idFirst, idLast, code, func) \
	if(uMsg == WM_COMMAND && code == HIWORD(wParam) && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_RANGE_HANDLER_EX(idFirst, idLast, func) \
	if(uMsg == WM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_RANGE_CODE_HANDLER_EX(idFirst, idLast, cd, func) \
	if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}

// admin\wmi\wbem\winmgmt\esscomp\noncom\testapps\noncomtest\include\atlframe.h
#define CHAIN_COMMANDS(theChainClass) \
	{ \
		if(uMsg == WM_COMMAND && theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_MEMBER(theChainMember) \
	{ \
		if(uMsg == WM_COMMAND && theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_ALT(theChainClass, msgMapID) \
	{ \
		if(uMsg == WM_COMMAND && theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_ALT_MEMBER(theChainMember, msgMapID) \
	{ \
		if(uMsg == WM_COMMAND && theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_CLIENT_COMMANDS() \
	if(uMsg == WM_COMMAND && m_hWndClient != NULL) \
		::SendMessage(m_hWndClient, uMsg, wParam, lParam);
#define CHAIN_MDI_CHILD_COMMANDS() \
	if(uMsg == WM_COMMAND) \
	{ \
		HWND hWndChild = MDIGetActive(); \
		if(hWndChild != NULL) \
			::SendMessage(hWndChild, uMsg, wParam, lParam); \
	}

// base\boot\efi\ia64\halnls.h
#define MSG_DEBUG_ENABLE        "Kernel Debugger Using: COM%x (Port 0x%x, Baud Rate %d)\n"

// base\cluster\ext\atlsnap\inc\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
	{ \
		hr = theChainClass.ProcessCommand(nID, bHandled, pObj, type); \
		if (bHandled) \
			return hr; \
	}

// base\efiutil\diskpart\msg.h
#define MSG_CLEAN       L"[ALL]     - Clean all data off the disk (DESTROY DATA)\n" \
                        L"                  ALL writes 0s to whole disk, without just 1st & last MB"

// base\fs\dfs\driver\dfswml.h
#  define MSG_ID_DfsFsdClose_Entry	 WPP_DEFINE_MSG_ID(0,14)
#  define MSG_ID_DfsFsdClose_Exit	 WPP_DEFINE_MSG_ID(0,15)

// base\fs\mup\mupwml.h
#  define MSG_ID_DfsFsdClose_Entry	 WPP_DEFINE_MSG_ID(0,54)
#  define MSG_ID_DfsFsdClose_Exit	 WPP_DEFINE_MSG_ID(0,55)
#  define MSG_ID_MupCleanup_Error_FileClosed	 WPP_DEFINE_MSG_ID(0,19)
#  define MSG_ID_MupClose_Entry	 WPP_DEFINE_MSG_ID(0,22)
#  define MSG_ID_MupClose_Error1	 WPP_DEFINE_MSG_ID(0,23)
#  define MSG_ID_MupClose_Error2	 WPP_DEFINE_MSG_ID(0,24)
#  define MSG_ID_MupClose_Exit	 WPP_DEFINE_MSG_ID(0,25)

// base\fs\utils\dfrg\inc\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
	{ \
		hr = theChainClass::ProcessCommand(nID, bHandled, pObj, type); \
		if (bHandled) \
			return hr; \
	}

// base\hals\halssc\ia64\simkd.c
#define MSG_DEBUG_ENABLE        "Kernel Debugger Using: COM%x (Port %p, Baud Rate %d)\n"

// base\hals\halx86\i386\halnls.h
#define MSG_DEBUG_ENABLE        "Kernel Debugger Using: COM%x (Port 0x%x, Baud Rate %d)\n"

// com\rpc\perf\postmsg\pmsgtest.h
#define MSG_PERF_MESSAGE2 (WM_USER+1)
#define MSG_PERF_MESSAGE3 (WM_USER+2)

// drivers\ksfilter\msmpu401\private.h
#define	MSG_EVENT(b)		((b) & 0xF0)
#define	MSG_CHAN(b)			((b) & 0x0F)

// drivers\wdm\input\legacy\mshgame\controlitemcollection\actions.h
#define COMMAND_TYPE_RECORDABLE			(0x0002 | COMMAND_TYPE_FLAG_ASSIGNMENT)
#define COMMAND_TYPE_BEHAVIOR			(0x0003 | COMMAND_TYPE_FLAG_ASSIGNMENT)
#define COMMAND_TYPE_FEEDBACK			(0x0004 | COMMAND_TYPE_FLAG_ASSIGNMENT)

// drivers\wdm\input\legacy\mshgame\controlitemcollection\dumpcommandblock.cpp
#define COMMAND_BLOCK_FITS_IN_DIRECTORY(pCommandDirectory, pCommandHeader)\
		(pCommandDirectory->ulEntireSize >=\
				(\
					(reinterpret_cast<PUCHAR>(pCommandDirectory) -	reinterpret_cast<PUCHAR>(pCommandHeader)) +\
					reinterpret_cast<PCOMMAND_HEADER>(pCommandHeader)->ulByteSize\
				)\
		)
#define COMMAND_DIRECTORY_FITS_IN_DIRECTORY(pCommandDirectory, pCommandSubDirectory)\
		(pCommandDirectory->ulEntireSize >=\
				(\
					(reinterpret_cast<PUCHAR>(pCommandDirectory) -	reinterpret_cast<PUCHAR>(pCommandHeader)) +\
					pCommandSubDirectory->ulEntireSize\
				)\
		)

// drivers\wdm\input\legacy\mshgame\gckernel.sys\filter.cpp
#define COMMAND_BLOCK_FITS_IN_DIRECTORY(pCommandDirectory, pCommandHeader)\
		(pCommandDirectory->ulEntireSize >=\
				(\
					(reinterpret_cast<PUCHAR>(pCommandHeader) - reinterpret_cast<PUCHAR>(pCommandDirectory)) +\
					reinterpret_cast<PCOMMAND_HEADER>(pCommandHeader)->ulByteSize\
				)\
		)
#define COMMAND_DIRECTORY_FITS_IN_DIRECTORY(pCommandDirectory, pCommandSubDirectory)\
		(pCommandDirectory->ulEntireSize >=\
				(\
					(reinterpret_cast<PUCHAR>(pCommandSubDirectory) - reinterpret_cast<PUCHAR>(pCommandDirectory)) +\
					pCommandSubDirectory->ulEntireSize\
				)\
		)

// drivers\wdm\usb\hcd\uhcd\uhcd.h
#define COMMAND_REG(deviceExtension)                    \
    ((PUSHORT) (deviceExtension->DeviceRegisters[0]))

// ds\dns\dnsapi\dnsapip.h
#define MSG_REMOTE_IP4(pMsg)  \
        ( (pMsg)->RemoteAddress.In4.sin_addr.s_addr )
#define MSG_REMOTE_IP_PORT(pMsg)  \
        ( (pMsg)->RemoteAddress.In4.sin_port )

// ds\dns\server\server\debug.h
#define MSG_ASSERT( pMsg, expr )  \
{                       \
    if ( !(expr) )      \
    {                   \
        Dbg_DnsMessage( "FAILED MESSAGE:", (pMsg) ); \
        Dbg_Assert( __FILE__, __LINE__, # expr );    \
    }                   \
}

// ds\netapi\svcdlls\msgsvc\server\msgdbg.h
#define MSG_LOG0(level,string)                      \
    if( MsgsvcDebugLevel & (DEBUG_ ## level)){      \
            DbgPrint("[MSGR]");                     \
            DbgPrint(string);                       \
    }
#define MSG_LOG1(level,string,var)                  \
    if( MsgsvcDebugLevel & (DEBUG_ ## level)){      \
        DbgPrint("[MSGR]");                         \
        DbgPrint(string,var);                       \
    }
#define MSG_LOG2(level,string,var1,var2)            \
    if( MsgsvcDebugLevel & (DEBUG_ ## level)){      \
        DbgPrint("[MSGR]");                         \
        DbgPrint(string,var1,var2);                 \
    }
#define MSG_LOG3(level,string,var1,var2,var3)       \
    if( MsgsvcDebugLevel & (DEBUG_ ## level)){      \
        DbgPrint("[MSGR]");                         \
        DbgPrint(string,var1,var2,var3);            \
    }
#define MSG_LOG(level,string,var)                   \
    if( MsgsvcDebugLevel & (DEBUG_ ## level)){      \
        DbgPrint("[MSGR]");                         \
        DbgPrint(string,var);                       \
    }

// ds\netapi\svcimgs\ntrepl\inc\frsalloc.h
#define COMMAND_TRACE(_sev, _cmd, _text)                                      \
    CmdPktTrace(_sev, DEBSUB, __LINE__, (_cmd), _text)
#define COMMAND_SND_COMM_TRACE(_sev, _cmd, _wstatus, _text) \
    SendCmdTrace(_sev, DEBSUB, __LINE__, _cmd, _wstatus, _text)
#define COMMAND_RCV_TRACE(_sev, _cmd, _cxtion, _wstatus, _text) \
    ReceiveCmdTrace(_sev, DEBSUB, __LINE__, _cmd, _cxtion, _wstatus, _text)
#define COMMAND_RCV_AUTH_TRACE(_sev, _comm, _wstatus, _authl, _authn, _client, _princname, _text) \
DPRINT8(_sev, ":SR: Comm %08x, Len %d, WS %d, Lev %d, AuthN %d, From %ws, To %ws [%s]\n", \
       (PtrToUlong(_comm)), \
       (_comm) ? _comm->PktLen : 0, \
       _wstatus, \
       _authl, \
       _authn, \
       _client, \
       _princname, \
       _text)

// ds\security\cryptoapi\pki\certstor\newstor.cpp
#define CHAIN_HASH_PROP_CNT     (sizeof(rgdwChainHashPropId) / \
                                    sizeof(rgdwChainHashPropId[0]))

// ds\security\cryptoapi\pki\certstor\policy.cpp
#define CHAIN_POLICY_FUNC_COUNT (sizeof(ChainPolicyFuncTable) / \
                                    sizeof(ChainPolicyFuncTable[0]))

// ds\security\cryptoapi\pki\certstor\sca.cpp
#define MSG_TYPE_OBJID_CNT (sizeof(MsgTypeObjIdTable)/sizeof(MsgTypeObjIdTable[0]))

// ds\security\cryptoapi\pki\chain\extract.cpp
#define CHAIN_CHAR_LEN(sz)    (sizeof(sz) / sizeof(sz[0]))

// ds\security\cryptoapi\test\capi20\ttrust\ttrust.cpp
#define CHAIN_POLICY_ARG    (DWORD_PTR)0x8765beef

// ds\security\passport\atlmfc\atlperf.h
#define CHAIN_PERF_OBJECT(objectclass) \
			hr = objectclass::CreateMap(pPerf, wLanguage, hResInstance, pSampleRes); \
			if (FAILED(hr)) \
				return hr;

// ds\security\passport\atlmfc\atlwin.h
#define BEGIN_MSG_MAP(theClass) \
public: \
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0) \
	{ \
		BOOL bHandled = TRUE; \
		hWnd; \
		uMsg; \
		wParam; \
		lParam; \
		lResult; \
		bHandled; \
		switch(dwMsgMapID) \
		{ \
		case 0:
#define ALT_MSG_MAP(msgMapID) \
		break; \
		case msgMapID:
#define COMMAND_HANDLER(id, code, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam) && code == HIWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_ID_HANDLER(id, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_CODE_HANDLER(code, func) \
	if(uMsg == WM_COMMAND && code == HIWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == WM_COMMAND && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_RANGE_CODE_HANDLER(idFirst, idLast, code, func) \
	if(uMsg == WM_COMMAND && code == HIWORD(wParam) && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_HANDLER(id, cd, func) \
	if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_ID_HANDLER(id, func) \
	if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_CODE_HANDLER(cd, func) \
	if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == WM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_RANGE_CODE_HANDLER(idFirst, idLast, cd, func) \
	if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP(theChainClass) \
	{ \
		if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_MEMBER(theChainMember) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_ALT(theChainClass, msgMapID) \
	{ \
		if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_DYNAMIC(dynaChainID) \
	{ \
		if(CDynamicChain::CallChain(dynaChainID, hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define END_MSG_MAP() \
			break; \
		default: \
			ATLTRACE(ATL::atlTraceWindowing, 0, _T("Invalid message map ID (%i)\n"), dwMsgMapID); \
			ATLASSERT(FALSE); \
			break; \
		} \
		return FALSE; \
	}

// enduser\netmeeting\av\nac\datapump.h
#define MSG_START_RECV	(WM_USER + 20)
#define MSG_STOP_RECV	(WM_USER + 21)
#define MSG_EXIT_RECV	(WM_USER + 22)
#define MSG_PLAY_SOUND	(WM_USER + 23)

// inetsrv\iis\config\src\wmi\atl30\atldb.h
#define CHAIN_PROPERTY_SET(ChainClass) \
		ULONG cPropSets##ChainClass, cElsSupported##ChainClass; \
		int cSets##ChainClass = (int)ChainClass::_GetPropSet(NULL, &cElsSupported##ChainClass); \
		if (pNumPropSets != NULL) \
		{ \
			UPROPSET* pSetA = (UPROPSET*)_alloca(sizeof(UPROPSET)*cSets##ChainClass); \
			UPROPSET* pSetTemp = ChainClass::_GetPropSet(&cPropSets##ChainClass, &cElsSupported##ChainClass, pSetA); \
			cElemsMax = (cElemsMax < cElsSupported##ChainClass) ? cElsSupported##ChainClass : cElemsMax; \
			ATLASSERT(pSetTemp); \
			for (ULONG iSet = nCurProp; iSet < nCurProp+cPropSets##ChainClass; iSet++) \
			{ \
				pSet[iSet].pPropSet = pSetTemp[iSet-nCurProp].pPropSet; \
				pSet[iSet].dwFlags = pSetTemp[iSet-nCurProp].dwFlags; \
				pSet[iSet].pUPropInfo = pSetTemp[iSet-nCurProp].pUPropInfo; \
				pSet[iSet].cUPropInfo = pSetTemp[iSet-nCurProp].cUPropInfo; \
			} \
		} \
		nCurProp += cSets##ChainClass;

// inetsrv\iis\config\src\wmi\atl30\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
	{ \
		hr = theChainClass::ProcessCommand(nID, bHandled, pObj, type); \
		if (bHandled) \
			return hr; \
	}

// inetsrv\iis\config\src\wmi\atl30\atlwin.h
#define BEGIN_MSG_MAP(theClass) \
public: \
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0) \
	{ \
		BOOL bHandled = TRUE; \
		hWnd; \
		uMsg; \
		wParam; \
		lParam; \
		lResult; \
		bHandled; \
		switch(dwMsgMapID) \
		{ \
		case 0:
#define ALT_MSG_MAP(msgMapID) \
		break; \
		case msgMapID:
#define COMMAND_HANDLER(id, code, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam) && code == HIWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_ID_HANDLER(id, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_CODE_HANDLER(code, func) \
	if(uMsg == WM_COMMAND && code == HIWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == WM_COMMAND && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_HANDLER(id, cd, func) \
	if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_ID_HANDLER(id, func) \
	if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_CODE_HANDLER(cd, func) \
	if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == WM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP(theChainClass) \
	{ \
		if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_MEMBER(theChainMember) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_ALT(theChainClass, msgMapID) \
	{ \
		if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_DYNAMIC(dynaChainID) \
	{ \
		if(CDynamicChain::CallChain(dynaChainID, hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define END_MSG_MAP() \
			break; \
		default: \
			ATLTRACE2(atlTraceWindowing, 0, _T("Invalid message map ID (%i)\n"), dwMsgMapID); \
			ATLASSERT(FALSE); \
			break; \
		} \
		return FALSE; \
	}

// inetsrv\msmq\src\admin\mqsnap\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
	{ \
		hr = theChainClass::ProcessCommand(nID, bHandled, pObj, type); \
		if (bHandled) \
			return hr; \
	}

// inetsrv\msmq\src\trigger\trigserv\cmsgprop.hpp
#define MSG_LABEL_BUFFER_SIZE       ((MQ_MAX_Q_LABEL_LEN * sizeof(TCHAR)) + sizeof(TCHAR))

// multimedia\dshow\filters.ks\drvstubs\msmid32\moddrv.c
#define	MSG_EVENT(b)		((b) & 0xF0)

// multimedia\dshow\vidctl\atl\atlcom.h
#define CHAIN_PROP_MAP(theChainClass) \
        {NULL, 0, reinterpret_cast<CLSID*>(&theChainClass::GetPropertyMap), \
            &__uuidof(IChainPropMapFlagDummy), offsetofclass(theChainClass, _PropMapClass), 0, VT_NULL, &IID_NULL},

// multimedia\dshow\vidctl\msvidctl\vidctl.h
#define MSG_FUNC(func) LRESULT func(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)

// multimedia\media\midimap\midimap.h
#define  MSG_STATUS(dw)      ((BYTE)((dw) & 0xFF))
#define  MSG_PARM1(dw)       ((BYTE)(((dw) >> 8) & 0xFF))
#define  MSG_PARM2(dw)       ((BYTE)(((dw) >> 16) & 0xFF))
#define  MSG_PACK1(bs,b1)    ((DWORD)((((DWORD)(b1)) << 8) | ((DWORD)(bs))))
#define  MSG_PACK2(bs,b1,b2) ((DWORD)((((DWORD)(b2)) << 16) | (((DWORD)(b1)) << 8) | ((DWORD)(bs))))
#define  MSG_EVENT(b)       ((b) & 0xF0)
#define  MSG_CHAN(b)        ((b) & 0x0F)

// net\ias\mmc\atl25\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
   { \
      hr = theChainClass::ProcessCommand(nID, bHandled, pObj, type); \
      if (bHandled) \
         return hr; \
   }

// net\sfm\afp\server\volume.h
#define	NOTIFY_SIZE_TINY_U			NOTIFY_SIZE_TINY*sizeof(WCHAR)		// These are lengths for UNICODE names
#define	NOTIFY_SIZE_SMALL_U			NOTIFY_SIZE_SMALL*sizeof(WCHAR)	//		- ditto -
#define	NOTIFY_SIZE_MEDIUM_U		NOTIFY_SIZE_MEDIUM*sizeof(WCHAR)	//		- ditto -
#define	NOTIFY_SIZE_LARGE_U			NOTIFY_SIZE_LARGE*sizeof(WCHAR)	//		- ditto -	corres. to AFP_FILENAME_LEN
#define	NOTIFY_USIZE_TO_INDEX(_Size)												\
		(((_Size) <= NOTIFY_SIZE_TINY_U) ? NOTIFY_INDEX_TINY :					\
						(((_Size) <= NOTIFY_SIZE_SMALL_U) ? NOTIFY_INDEX_SMALL :	\
						 (((_Size) <= NOTIFY_SIZE_MEDIUM_U) ? NOTIFY_INDEX_MEDIUM : NOTIFY_INDEX_LARGE)))

// printscan\faxsrv\src\admin\inc\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
	{ \
		hr = theChainClass::ProcessCommand(nID, bHandled, pObj, type); \
		if (bHandled) \
			return hr; \
	}

// printscan\ui\wiadebug\wiadebug.cpp
#define MSG_DEBUG_MAP_SIZE (sizeof(s_MsgDebugStrings)/sizeof(s_MsgDebugStrings[0]))

// public\sdk\inc\atl21\atlframe.h
#define CHAIN_COMMANDS(theChainClass) \
	{ \
		if(uMsg == WM_COMMAND && theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_MEMBER(theChainMember) \
	{ \
		if(uMsg == WM_COMMAND && theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_ALT(theChainClass, msgMapID) \
	{ \
		if(uMsg == WM_COMMAND && theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_ALT_MEMBER(theChainMember, msgMapID) \
	{ \
		if(uMsg == WM_COMMAND && theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_CLIENT_COMMANDS() \
	if(uMsg == WM_COMMAND && m_hWndClient != NULL) \
		::SendMessage(m_hWndClient, uMsg, wParam, lParam);
#define CHAIN_MDI_CHILD_COMMANDS() \
	if(uMsg == WM_COMMAND) \
	{ \
		HWND hWndChild = MDIGetActive(); \
		if(hWndChild != NULL) \
			::SendMessage(hWndChild, uMsg, wParam, lParam); \
	}

// public\sdk\inc\atl21\atlwin.h
#define BEGIN_MSG_MAP(theClass) \
public: \
        BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0) \
        { \
                BOOL bHandled = TRUE; \
                hWnd; \
                switch(dwMsgMapID) \
                { \
                case 0:
#define ALT_MSG_MAP(msgMapID) \
                break; \
                case msgMapID:
#define COMMAND_HANDLER(id, code, func) \
        if(uMsg == WM_COMMAND && id == LOWORD(wParam) && code == HIWORD(wParam)) \
        { \
                bHandled = TRUE; \
                lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define COMMAND_ID_HANDLER(id, func) \
        if(uMsg == WM_COMMAND && id == LOWORD(wParam)) \
        { \
                bHandled = TRUE; \
                lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define COMMAND_CODE_HANDLER(code, func) \
        if(uMsg == WM_COMMAND && code == HIWORD(wParam)) \
        { \
                bHandled = TRUE; \
                lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define COMMAND_RANGE_HANDLER(idFirst, idLast, func) \
        if(uMsg == WM_COMMAND && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
        { \
                bHandled = TRUE; \
                lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define NOTIFY_HANDLER(id, cd, func) \
        if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom && cd == ((LPNMHDR)lParam)->code) \
        { \
                bHandled = TRUE; \
                lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define NOTIFY_ID_HANDLER(id, func) \
        if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
        { \
                bHandled = TRUE; \
                lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define NOTIFY_CODE_HANDLER(cd, func) \
        if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
        { \
                bHandled = TRUE; \
                lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define NOTIFY_RANGE_HANDLER(idFirst, idLast, func) \
        if(uMsg == WM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
        { \
                bHandled = TRUE; \
                lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
                if(bHandled) \
                        return TRUE; \
        }
#define CHAIN_MSG_MAP(theChainClass) \
        { \
                if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
                        return TRUE; \
        }
#define CHAIN_MSG_MAP_MEMBER(theChainMember) \
        { \
                if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
                        return TRUE; \
        }
#define CHAIN_MSG_MAP_ALT(theChainClass, msgMapID) \
        { \
                if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
                        return TRUE; \
        }
#define CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID) \
        { \
                if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
                        return TRUE; \
        }
#define CHAIN_MSG_MAP_DYNAMIC(dynaChainID) \
        { \
                if(CDynamicChain::CallChain(dynaChainID, hWnd, uMsg, wParam, lParam, lResult)) \
                        return TRUE; \
        }
#define CHAIN_MSG_MAP_ALT_DYNAMIC(dynaChainID, msgMapID) \
        { \
                if(CDynamicChain::CallChain(dynaChainID, hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
                        return TRUE; \
        }
#define END_MSG_MAP() \
                        break; \
                default: \
                        ATLTRACE(_T("Invalid message map ID (%i)\n"), dwMsgMapID); \
                        _ASSERTE(FALSE); \
                        break; \
                } \
                return FALSE; \
        }

// public\sdk\inc\atl30\atldb.h
#define CHAIN_PROPERTY_SET(ChainClass) \
		ULONG cPropSets##ChainClass, cElsSupported##ChainClass; \
		int cSets##ChainClass = (int)(DWORD_PTR)ChainClass::_GetPropSet(NULL, &cElsSupported##ChainClass); \
		if (pNumPropSets != NULL) \
		{ \
			UPROPSET* pSetA = (UPROPSET*)_alloca(sizeof(UPROPSET)*cSets##ChainClass); \
			UPROPSET* pSetTemp = ChainClass::_GetPropSet(&cPropSets##ChainClass, &cElsSupported##ChainClass, pSetA); \
			cElemsMax = (cElemsMax < cElsSupported##ChainClass) ? cElsSupported##ChainClass : cElemsMax; \
			ATLASSERT(pSetTemp); \
			for (ULONG iSet = nCurProp; iSet < nCurProp+cPropSets##ChainClass; iSet++) \
			{ \
				pSet[iSet].pPropSet = pSetTemp[iSet-nCurProp].pPropSet; \
				pSet[iSet].dwFlags = pSetTemp[iSet-nCurProp].dwFlags; \
				pSet[iSet].pUPropInfo = pSetTemp[iSet-nCurProp].pUPropInfo; \
				pSet[iSet].cUPropInfo = pSetTemp[iSet-nCurProp].cUPropInfo; \
			} \
		} \
		nCurProp += cSets##ChainClass;

// public\sdk\inc\atl30\atlsnap.h
#define CHAIN_SNAPINCOMMAND_MAP(theChainClass) \
	{ \
		hr = theChainClass::ProcessCommand(nID, bHandled, pObj, type); \
		if (bHandled) \
			return hr; \
	}

// public\sdk\inc\atl30\atlwin.h
#define BEGIN_MSG_MAP(theClass) \
public: \
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0) \
	{ \
		BOOL bHandled = TRUE; \
		hWnd; \
		uMsg; \
		wParam; \
		lParam; \
		lResult; \
		bHandled; \
		switch(dwMsgMapID) \
		{ \
		case 0:
#define ALT_MSG_MAP(msgMapID) \
		break; \
		case msgMapID:
#define COMMAND_HANDLER(id, code, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam) && code == HIWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_ID_HANDLER(id, func) \
	if(uMsg == WM_COMMAND && id == LOWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_CODE_HANDLER(code, func) \
	if(uMsg == WM_COMMAND && code == HIWORD(wParam)) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define COMMAND_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == WM_COMMAND && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func(HIWORD(wParam), LOWORD(wParam), (HWND)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_HANDLER(id, cd, func) \
	if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_ID_HANDLER(id, func) \
	if(uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_CODE_HANDLER(cd, func) \
	if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define NOTIFY_RANGE_HANDLER(idFirst, idLast, func) \
	if(uMsg == WM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		bHandled = TRUE; \
		lResult = func((int)wParam, (LPNMHDR)lParam, bHandled); \
		if(bHandled) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP(theChainClass) \
	{ \
		if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_MEMBER(theChainMember) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_ALT(theChainClass, msgMapID) \
	{ \
		if(theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_ALT_MEMBER(theChainMember, msgMapID) \
	{ \
		if(theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_MSG_MAP_DYNAMIC(dynaChainID) \
	{ \
		if(CDynamicChain::CallChain(dynaChainID, hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define END_MSG_MAP() \
			break; \
		default: \
			ATLTRACE2(atlTraceWindowing, 0, _T("Invalid message map ID (%i)\n"), dwMsgMapID); \
			ATLASSERT(FALSE); \
			break; \
		} \
		return FALSE; \
	}

// public\sdk\inc\ftsiface.h
#define MSG_FTS_JUMP_HASH	(WM_USER + 32)  // wParam = index, lParam = HashValue
#define MSG_FTS_JUMP_VA 	(WM_USER + 33)  // wParam = index, lParam = VirtualAddress
#define MSG_FTS_GET_TITLE	(WM_USER + 34)	// wParam = index, lParam = &pszTitle
#define MSG_FTS_JUMP_QWORD  (WM_USER + 35)  // wParam = index, lParam = address of QWordAddress structure
#define MSG_REINDEX_REQUEST (WM_USER + 36)  // wParam = unused,lParam = unused
#define MSG_FTS_WHERE_IS_IT (WM_USER + 37)	// wParam = fStartEnumeration, lParam = &pszFile
#define MSG_GET_DEFFONT 	(WM_USER + 45)	// return default font handle

// public\sdk\inc\wtl10\atlcrack.h
#define BEGIN_MSG_MAP_EX(theClass) \
public: \
	BOOL m_bATL3MsgHandled; \
	/* "handled" management for cracked handlers */ \
	BOOL IsMsgHandled() const \
	{ \
		return m_bATL3MsgHandled; \
	} \
	void SetMsgHandled(BOOL bHandled) \
	{ \
		m_bATL3MsgHandled = bHandled; \
	} \
	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID = 0) \
	{ \
		BOOL bATL3OldMsgHandled = m_bATL3MsgHandled; \
		BOOL bRet = _ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, dwMsgMapID); \
		m_bATL3MsgHandled = bATL3OldMsgHandled; \
		return bRet; \
	} \
	BOOL _ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID) \
	{ \
		BOOL bHandled = TRUE; \
		hWnd; \
		uMsg; \
		wParam; \
		lParam; \
		lResult; \
		bHandled; \
		switch(dwMsgMapID) \
		{ \
		case 0:
#define MSG_WM_CREATE(func) \
	if (uMsg == WM_CREATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPCREATESTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INITDIALOG(func) \
	if (uMsg == WM_INITDIALOG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COPYDATA(func) \
	if (uMsg == WM_COPYDATA) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (PCOPYDATASTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DESTROY(func) \
	if (uMsg == WM_DESTROY) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOVE(func) \
	if (uMsg == WM_MOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SIZE(func) \
	if (uMsg == WM_SIZE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CSize(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ACTIVATE(func) \
	if (uMsg == WM_ACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (BOOL)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETFOCUS(func) \
	if (uMsg == WM_SETFOCUS) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_KILLFOCUS(func) \
	if (uMsg == WM_KILLFOCUS) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENABLE(func) \
	if (uMsg == WM_ENABLE) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PAINT(func) \
	if (uMsg == WM_PAINT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CLOSE(func) \
	if (uMsg == WM_CLOSE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYENDSESSION(func) \
	if (uMsg == WM_QUERYENDSESSION) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (UINT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYOPEN(func) \
	if (uMsg == WM_QUERYOPEN) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ERASEBKGND(func) \
	if (uMsg == WM_ERASEBKGND) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSCOLORCHANGE(func) \
	if (uMsg == WM_SYSCOLORCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENDSESSION(func) \
	if (uMsg == WM_ENDSESSION) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (UINT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SHOWWINDOW(func) \
	if (uMsg == WM_SHOWWINDOW) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (int)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLOREDIT(func) \
	if (uMsg == WM_CTLCOLOREDIT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORLISTBOX(func) \
	if (uMsg == WM_CTLCOLORLISTBOX) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORBTN(func) \
	if (uMsg == WM_CTLCOLORBTN) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORDLG(func) \
	if (uMsg == WM_CTLCOLORDLG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORSCROLLBAR(func) \
	if (uMsg == WM_CTLCOLORSCROLLBAR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CTLCOLORSTATIC(func) \
	if (uMsg == WM_CTLCOLORSTATIC) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETTINGCHANGE(func) \
	if (uMsg == WM_SETTINGCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPCTSTR)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DEVMODECHANGE(func) \
	if (uMsg == WM_DEVMODECHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPCTSTR)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ACTIVATEAPP(func) \
	if (uMsg == WM_ACTIVATEAPP) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (DWORD)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_FONTCHANGE(func) \
	if (uMsg == WM_FONTCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_TIMECHANGE(func) \
	if (uMsg == WM_TIMECHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CANCELMODE(func) \
	if (uMsg == WM_CANCELMODE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETCURSOR(func) \
	if (uMsg == WM_SETCURSOR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEACTIVATE(func) \
	if (uMsg == WM_MOUSEACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHILDACTIVATE(func) \
	if (uMsg == WM_CHILDACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETMINMAXINFO(func) \
	if (uMsg == WM_GETMINMAXINFO) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPMINMAXINFO)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ICONERASEBKGND(func) \
	if (uMsg == WM_ICONERASEBKGND) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SPOOLERSTATUS(func) \
	if (uMsg == WM_SPOOLERSTATUS) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (UINT)LOWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DRAWITEM(func) \
	if (uMsg == WM_DRAWITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDRAWITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MEASUREITEM(func) \
	if (uMsg == WM_MEASUREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPMEASUREITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DELETEITEM(func) \
	if (uMsg == WM_DELETEITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDELETEITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHARTOITEM(func) \
	if (uMsg == WM_CHARTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_VKEYTOITEM(func) \
	if (uMsg == WM_VKEYTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYDRAGICON(func) \
	if (uMsg == WM_QUERYDRAGICON) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COMPAREITEM(func) \
	if (uMsg == WM_COMPAREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (LPCOMPAREITEMSTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COMPACTING(func) \
	if (uMsg == WM_COMPACTING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCCREATE(func) \
	if (uMsg == WM_NCCREATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPCREATESTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCDESTROY(func) \
	if (uMsg == WM_NCDESTROY) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCCALCSIZE(func) \
	if (uMsg == WM_NCCALCSIZE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((BOOL)wParam, lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCHITTEST(func) \
	if (uMsg == WM_NCHITTEST) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCPAINT(func) \
	if (uMsg == WM_NCPAINT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HRGN)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCACTIVATE(func) \
	if (uMsg == WM_NCACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((BOOL)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETDLGCODE(func) \
	if (uMsg == WM_GETDLGCODE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPMSG)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMOUSEMOVE(func) \
	if (uMsg == WM_NCMOUSEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCLBUTTONDOWN(func) \
	if (uMsg == WM_NCLBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCLBUTTONUP(func) \
	if (uMsg == WM_NCLBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCLBUTTONDBLCLK(func) \
	if (uMsg == WM_NCLBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCRBUTTONDOWN(func) \
	if (uMsg == WM_NCRBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCRBUTTONUP(func) \
	if (uMsg == WM_NCRBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCRBUTTONDBLCLK(func) \
	if (uMsg == WM_NCRBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMBUTTONDOWN(func) \
	if (uMsg == WM_NCMBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMBUTTONUP(func) \
	if (uMsg == WM_NCMBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCMBUTTONDBLCLK(func) \
	if (uMsg == WM_NCMBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_KEYDOWN(func) \
	if (uMsg == WM_KEYDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_KEYUP(func) \
	if (uMsg == WM_KEYUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHAR(func) \
	if (uMsg == WM_CHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DEADCHAR(func) \
	if (uMsg == WM_DEADCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSKEYDOWN(func) \
	if (uMsg == WM_SYSKEYDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSKEYUP(func) \
	if (uMsg == WM_SYSKEYUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSCHAR(func) \
	if (uMsg == WM_SYSCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSDEADCHAR(func) \
	if (uMsg == WM_SYSDEADCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		func((TCHAR)wParam, (UINT)lParam & 0xFFFF, (UINT)((lParam & 0xFFFF0000) >> 16)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SYSCOMMAND(func) \
	if (uMsg == WM_SYSCOMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_TCARD(func) \
	if (uMsg == WM_TCARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (DWORD)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_TIMER(func) \
	if (uMsg == WM_TIMER) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (TIMERPROC*)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HSCROLL(func) \
	if (uMsg == WM_HSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_VSCROLL(func) \
	if (uMsg == WM_VSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INITMENU(func) \
	if (uMsg == WM_INITMENU) \
	{ \
		SetMsgHandled(TRUE); \
		func((HMENU)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INITMENUPOPUP(func) \
	if (uMsg == WM_INITMENUPOPUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((HMENU)wParam, (UINT)LOWORD(lParam), (BOOL)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUSELECT(func) \
	if (uMsg == WM_MENUSELECT) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUCHAR(func) \
	if (uMsg == WM_MENUCHAR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((TCHAR)LOWORD(wParam), (UINT)HIWORD(wParam), (HMENU)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NOTIFY(func) \
	if (uMsg == WM_NOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((int)wParam, (LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENTERIDLE(func) \
	if (uMsg == WM_ENTERIDLE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEMOVE(func) \
	if (uMsg == WM_MOUSEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEWHEEL(func) \
	if (uMsg == WM_MOUSEWHEEL) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (short)HIWORD(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_LBUTTONDOWN(func) \
	if (uMsg == WM_LBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_LBUTTONUP(func) \
	if (uMsg == WM_LBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_LBUTTONDBLCLK(func) \
	if (uMsg == WM_LBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RBUTTONDOWN(func) \
	if (uMsg == WM_RBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RBUTTONUP(func) \
	if (uMsg == WM_RBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RBUTTONDBLCLK(func) \
	if (uMsg == WM_RBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MBUTTONDOWN(func) \
	if (uMsg == WM_MBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MBUTTONUP(func) \
	if (uMsg == WM_MBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MBUTTONDBLCLK(func) \
	if (uMsg == WM_MBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PARENTNOTIFY(func) \
	if (uMsg == WM_PARENTNOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MDIACTIVATE(func) \
	if (uMsg == WM_MDIACTIVATE) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RENDERFORMAT(func) \
	if (uMsg == WM_RENDERFORMAT) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RENDERALLFORMATS(func) \
	if (uMsg == WM_RENDERALLFORMATS) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DESTROYCLIPBOARD(func) \
	if (uMsg == WM_DESTROYCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DRAWCLIPBOARD(func) \
	if (uMsg == WM_DRAWCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PAINTCLIPBOARD(func) \
	if (uMsg == WM_PAINTCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (const LPPAINTSTRUCT)::GlobalLock((HGLOBAL)lParam)); \
		::GlobalUnlock((HGLOBAL)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_VSCROLLCLIPBOARD(func) \
	if (uMsg == WM_VSCROLLCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CONTEXTMENU(func) \
	if (uMsg == WM_CONTEXTMENU) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SIZECLIPBOARD(func) \
	if (uMsg == WM_SIZECLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (const LPRECT)::GlobalLock((HGLOBAL)lParam)); \
		::GlobalUnlock((HGLOBAL)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ASKCBFORMATNAME(func) \
	if (uMsg == WM_ASKCBFORMATNAME) \
	{ \
		SetMsgHandled(TRUE); \
		func((DWORD)wParam, (LPTSTR)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CHANGECBCHAIN(func) \
	if (uMsg == WM_CHANGECBCHAIN) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HSCROLLCLIPBOARD(func) \
	if (uMsg == WM_HSCROLLCLIPBOARD) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_QUERYNEWPALETTE(func) \
	if (uMsg == WM_QUERYNEWPALETTE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PALETTECHANGED(func) \
	if (uMsg == WM_PALETTECHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PALETTEISCHANGING(func) \
	if (uMsg == WM_PALETTEISCHANGING) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DROPFILES(func) \
	if (uMsg == WM_DROPFILES) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDROP)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_WINDOWPOSCHANGING(func) \
	if (uMsg == WM_WINDOWPOSCHANGING) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPWINDOWPOS)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_WINDOWPOSCHANGED(func) \
	if (uMsg == WM_WINDOWPOSCHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPWINDOWPOS)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_EXITMENULOOP(func) \
	if (uMsg == WM_EXITMENULOOP) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENTERMENULOOP(func) \
	if (uMsg == WM_ENTERMENULOOP) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_STYLECHANGED(func) \
	if (uMsg == WM_STYLECHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPSTYLESTRUCT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_STYLECHANGING(func) \
	if (uMsg == WM_STYLECHANGING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPSTYLESTRUCT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SIZING(func) \
	if (uMsg == WM_SIZING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPRECT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOVING(func) \
	if (uMsg == WM_MOVING) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPRECT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CAPTURECHANGED(func) \
	if (uMsg == WM_CAPTURECHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DEVICECHANGE(func) \
	if (uMsg == WM_DEVICECHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (DWORD)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COMMAND(func) \
	if (uMsg == WM_COMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_DISPLAYCHANGE(func) \
	if (uMsg == WM_DISPLAYCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, CSize(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_ENTERSIZEMOVE(func) \
	if (uMsg == WM_ENTERSIZEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_EXITSIZEMOVE(func) \
	if (uMsg == WM_EXITSIZEMOVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETFONT(func) \
	if (uMsg == WM_GETFONT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETHOTKEY(func) \
	if (uMsg == WM_GETHOTKEY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETICON(func) \
	if (uMsg == WM_GETICON) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETTEXT(func) \
	if (uMsg == WM_GETTEXT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((int)wParam, (LPTSTR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_GETTEXTLENGTH(func) \
	if (uMsg == WM_GETTEXTLENGTH) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HELP(func) \
	if (uMsg == WM_HELP) \
	{ \
		SetMsgHandled(TRUE); \
		func((LPHELPINFO)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_HOTKEY(func) \
	if (uMsg == WM_HOTKEY) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)wParam, (UINT)LOWORD(lParam), (UINT)HIWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INPUTLANGCHANGE(func) \
	if (uMsg == WM_INPUTLANGCHANGE) \
	{ \
		SetMsgHandled(TRUE); \
		func((DWORD)wParam, (HKL)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_INPUTLANGCHANGEREQUEST(func) \
	if (uMsg == WM_INPUTLANGCHANGEREQUEST) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam, (HKL)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NEXTDLGCTL(func) \
	if (uMsg == WM_NEXTDLGCTL) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)LOWORD(lParam), wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NEXTMENU(func) \
	if (uMsg == WM_NEXTMENU) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)wParam, (LPMDINEXTMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NOTIFYFORMAT(func) \
	if (uMsg == WM_NOTIFYFORMAT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HWND)wParam, (int)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_POWERBROADCAST(func) \
	if (uMsg == WM_POWERBROADCAST) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((DWORD)wParam, (DWORD)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PRINT(func) \
	if (uMsg == WM_PRINT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam, (UINT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PRINTCLIENT(func) \
	if (uMsg == WM_PRINTCLIENT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HDC)wParam, (UINT)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_RASDIALEVENT(func) \
	if (uMsg == WM_RASDIALEVENT) \
	{ \
		SetMsgHandled(TRUE); \
		func((RASCONNSTATE)wParam, (DWORD)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETFONT(func) \
	if (uMsg == WM_SETFONT) \
	{ \
		SetMsgHandled(TRUE); \
		func((HFONT)wParam, (BOOL)LOWORD(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETHOTKEY(func) \
	if (uMsg == WM_SETHOTKEY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((int)LOBYTE(LOWORD(wParam)), (UINT)HIBYTE(LOWORD(wParam))); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETICON(func) \
	if (uMsg == WM_SETICON) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (HICON)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETREDRAW(func) \
	if (uMsg == WM_SETREDRAW) \
	{ \
		SetMsgHandled(TRUE); \
		func((BOOL)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_SETTEXT(func) \
	if (uMsg == WM_SETTEXT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPCTSTR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_USERCHANGED(func) \
	if (uMsg == WM_USERCHANGED) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSEHOVER(func) \
	if (uMsg == WM_MOUSEHOVER) \
	{ \
		SetMsgHandled(TRUE); \
		func(wParam, CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MOUSELEAVE(func) \
	if (uMsg == WM_MOUSELEAVE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENURBUTTONUP(func) \
	if (uMsg == WM_MENURBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func(wParam, (HMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUDRAG(func) \
	if (uMsg == WM_MENUDRAG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(wParam, (HMENU)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUGETOBJECT(func) \
	if (uMsg == WM_MENUGETOBJECT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((PMENUGETOBJECTINFO)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_UNINITMENUPOPUP(func) \
	if (uMsg == WM_UNINITMENUPOPUP) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(lParam), (HMENU)wParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_MENUCOMMAND(func) \
	if (uMsg == WM_MENUCOMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func(wParam, (HMENU)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_APPCOMMAND(func) \
	if (uMsg == WM_APPCOMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((HWND)wParam, GET_APPCOMMAND_LPARAM(lParam), GET_DEVICE_LPARAM(lParam), GET_KEYSTATE_LPARAM(lParam)); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCXBUTTONDOWN(func) \
	if (uMsg == WM_NCXBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func(GET_XBUTTON_WPARAM(wParam), GET_NCHITTEST_WPARAM(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCXBUTTONUP(func) \
	if (uMsg == WM_NCXBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func(GET_XBUTTON_WPARAM(wParam), GET_NCHITTEST_WPARAM(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_NCXBUTTONDBLCLK(func) \
	if (uMsg == WM_NCXBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func(GET_XBUTTON_WPARAM(wParam), GET_NCHITTEST_WPARAM(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_XBUTTONDOWN(func) \
	if (uMsg == WM_XBUTTONDOWN) \
	{ \
		SetMsgHandled(TRUE); \
		func(GET_XBUTTON_WPARAM(wParam), GET_KEYSTATE_WPARAM(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_XBUTTONUP(func) \
	if (uMsg == WM_XBUTTONUP) \
	{ \
		SetMsgHandled(TRUE); \
		func(GET_XBUTTON_WPARAM(wParam), GET_KEYSTATE_WPARAM(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_XBUTTONDBLCLK(func) \
	if (uMsg == WM_XBUTTONDBLCLK) \
	{ \
		SetMsgHandled(TRUE); \
		func(GET_XBUTTON_WPARAM(wParam), GET_KEYSTATE_WPARAM(wParam), CPoint(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam))); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_FORWARDMSG(func) \
	if (uMsg == WM_FORWARDMSG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((LPMSG)lParam, (DWORD)wParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_DM_GETDEFID(func) \
	if (uMsg == DM_GETDEFID) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func(); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_DM_SETDEFID(func) \
	if (uMsg == DM_SETDEFID) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_DM_REPOSITION(func) \
	if (uMsg == DM_REPOSITION) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_COMMAND(func) \
	if (uMsg == OCM_COMMAND) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_NOTIFY(func) \
	if (uMsg == OCM_NOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((int)wParam, (LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_PARENTNOTIFY(func) \
	if (uMsg == OCM_PARENTNOTIFY) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_DRAWITEM(func) \
	if (uMsg == OCM_DRAWITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDRAWITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_MEASUREITEM(func) \
	if (uMsg == OCM_MEASUREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPMEASUREITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_COMPAREITEM(func) \
	if (uMsg == OCM_COMPAREITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)wParam, (LPCOMPAREITEMSTRUCT)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_DELETEITEM(func) \
	if (uMsg == OCM_DELETEITEM) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)wParam, (LPDELETEITEMSTRUCT)lParam); \
		lResult = TRUE; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_VKEYTOITEM(func) \
	if (uMsg == OCM_VKEYTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CHARTOITEM(func) \
	if (uMsg == OCM_CHARTOITEM) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((UINT)LOWORD(wParam), (UINT)HIWORD(wParam), (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_HSCROLL(func) \
	if (uMsg == OCM_HSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_VSCROLL(func) \
	if (uMsg == OCM_VSCROLL) \
	{ \
		SetMsgHandled(TRUE); \
		func((int)LOWORD(wParam), (short)HIWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLOREDIT(func) \
	if (uMsg == OCM_CTLCOLOREDIT) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORLISTBOX(func) \
	if (uMsg == OCM_CTLCOLORLISTBOX) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORBTN(func) \
	if (uMsg == OCM_CTLCOLORBTN) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORDLG(func) \
	if (uMsg == OCM_CTLCOLORDLG) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORSCROLLBAR(func) \
	if (uMsg == OCM_CTLCOLORSCROLLBAR) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_OCM_CTLCOLORSTATIC(func) \
	if (uMsg == OCM_CTLCOLORSTATIC) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = (LRESULT)func((HDC)wParam, (HWND)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CLEAR(func) \
	if (uMsg == WM_CLEAR) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_COPY(func) \
	if (uMsg == WM_COPY) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_CUT(func) \
	if (uMsg == WM_CUT) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_PASTE(func) \
	if (uMsg == WM_PASTE) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define MSG_WM_UNDO(func) \
	if (uMsg == WM_UNDO) \
	{ \
		SetMsgHandled(TRUE); \
		func(); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_HANDLER_EX(id, code, func) \
	if (uMsg == WM_COMMAND && code == HIWORD(wParam) && id == LOWORD(wParam)) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_ID_HANDLER_EX(id, func) \
	if (uMsg == WM_COMMAND && id == LOWORD(wParam)) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_CODE_HANDLER_EX(code, func) \
	if (uMsg == WM_COMMAND && code == HIWORD(wParam)) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_HANDLER_EX(id, cd, func) \
	if (uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_ID_HANDLER_EX(id, func) \
	if (uMsg == WM_NOTIFY && id == ((LPNMHDR)lParam)->idFrom) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_CODE_HANDLER_EX(cd, func) \
	if (uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_RANGE_HANDLER_EX(idFirst, idLast, func) \
	if(uMsg == WM_COMMAND && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define COMMAND_RANGE_CODE_HANDLER_EX(idFirst, idLast, code, func) \
	if(uMsg == WM_COMMAND && code == HIWORD(wParam) && LOWORD(wParam) >= idFirst  && LOWORD(wParam) <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		func((UINT)HIWORD(wParam), (int)LOWORD(wParam), (HWND)lParam); \
		lResult = 0; \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_RANGE_HANDLER_EX(idFirst, idLast, func) \
	if(uMsg == WM_NOTIFY && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}
#define NOTIFY_RANGE_CODE_HANDLER_EX(idFirst, idLast, cd, func) \
	if(uMsg == WM_NOTIFY && cd == ((LPNMHDR)lParam)->code && ((LPNMHDR)lParam)->idFrom >= idFirst && ((LPNMHDR)lParam)->idFrom <= idLast) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = func((LPNMHDR)lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}

// public\sdk\inc\wtl10\atlframe.h
#define CHAIN_COMMANDS(theChainClass) \
	{ \
		if(uMsg == WM_COMMAND && theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_MEMBER(theChainMember) \
	{ \
		if(uMsg == WM_COMMAND && theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_ALT(theChainClass, msgMapID) \
	{ \
		if(uMsg == WM_COMMAND && theChainClass::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_COMMANDS_ALT_MEMBER(theChainMember, msgMapID) \
	{ \
		if(uMsg == WM_COMMAND && theChainMember.ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, msgMapID)) \
			return TRUE; \
	}
#define CHAIN_CLIENT_COMMANDS() \
	if(uMsg == WM_COMMAND && m_hWndClient != NULL) \
		::SendMessage(m_hWndClient, uMsg, wParam, lParam);
#define CHAIN_MDI_CHILD_COMMANDS() \
	if(uMsg == WM_COMMAND) \
	{ \
		HWND hWndChild = MDIGetActive(); \
		if(hWndChild != NULL) \
			::SendMessage(hWndChild, uMsg, wParam, lParam); \
	}

// published\sdk\inc\ftsiface.h
#define MSG_FTS_JUMP_HASH	(WM_USER + 32)  // wParam = index, lParam = HashValue
#define MSG_FTS_JUMP_VA 	(WM_USER + 33)  // wParam = index, lParam = VirtualAddress
#define MSG_FTS_GET_TITLE	(WM_USER + 34)	// wParam = index, lParam = &pszTitle
#define MSG_FTS_JUMP_QWORD  (WM_USER + 35)  // wParam = index, lParam = address of QWordAddress structure
#define MSG_REINDEX_REQUEST (WM_USER + 36)  // wParam = unused,lParam = unused
#define MSG_FTS_WHERE_IS_IT (WM_USER + 37)	// wParam = fStartEnumeration, lParam = &pszFile
#define MSG_GET_DEFFONT 	(WM_USER + 45)	// return default font handle

// sdktools\debuggers\windbg\engine.cpp
#define COMMAND_OVERHEAD (sizeof(ULONG64) + sizeof(UiCommandData))

// shell\osshell\themes\themesw\schedule.cpp
#define MSG_BOX_TSERR(hw,msg) MessageBox(hw, msg, szThemeName,\
                            MB_OK | MB_ICONERROR | MB_APPLMODAL)

// windows\core\ntcon\server\cmdline.h
#define COMMAND_IND_PREV(IND,CMDHIST)               \
{                                                   \
    if (IND <= 0) {                                 \
        IND = (CMDHIST)->NumberOfCommands;          \
    }                                               \
    IND--;                                          \
}
#define COMMAND_IND_NEXT(IND,CMDHIST)               \
{                                                   \
    ++IND;                                          \
    if (IND >= (CMDHIST)->NumberOfCommands){        \
        IND = 0;                                    \
    }                                               \
}
#define COMMAND_IND_DEC(IND,CMDHIST)                \
{                                                   \
    if (IND <= 0) {                                 \
        IND = (CMDHIST)->MaximumNumberOfCommands;   \
    }                                               \
    IND--;                                          \
}
#define COMMAND_IND_INC(IND,CMDHIST)                \
{                                                   \
    ++IND;                                          \
    if (IND >= (CMDHIST)->MaximumNumberOfCommands){ \
        IND = 0;                                    \
    }                                               \
}

// windows\core\wow64win\whwin32\msgthnk.tpl
#define MSG_ENTRY_NOPARAM(entrynumber, id)             {Wow64MsgFncWM_NULL, id, #id},
#define MSG_ENTRY_UNREFERENCED(entrynumber, id)        {Wow64MsgFncWM_NULL, entrynumber, NULL},
#define MSG_ENTRY_KERNELONLY(entrynumber, id)          {Wow64MsgFncWM_NULL, entrynumber, NULL},
#define MSG_ENTRY_EMPTY(entrynumber)                   {Wow64MsgFncWM_NULL, entrynumber, NULL},
#define MSG_ENTRY_RESERVED(entrynumber)                {Wow64MsgFncWM_NULL, entrynumber, NULL},
#define MSG_ENTRY_TODO(entrynumber)                    {Wow64MsgFncWM_NULL, entrynumber, NULL},

// windows\feime\chs\ntabc\winabc\abc95def.h
#define MSG_STATIC_STATE                (MSG_ALREADY_START|MSG_ALREADY_OPEN|MSG_ALREADY_SOFTKBD|MSG_ALREADY_OPEN2)

// windows\feime\cht\imedefs.h
#define MSG_STATIC_STATE                (MSG_ALREADY_START|MSG_ALREADY_OPEN|MSG_ALREADY_SOFTKBD|MSG_ALREADY_OPEN2)

// windows\feime\usa\imedefs.h
#define MSG_STATIC_STATE                (MSG_ALREADY_START|MSG_ALREADY_OPEN|MSG_ALREADY_SOFTKBD|MSG_ALREADY_OPEN2)
```

