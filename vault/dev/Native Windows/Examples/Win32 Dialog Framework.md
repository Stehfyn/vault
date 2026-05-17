```cpp
int lib::runMain(DialogMain& dlgObj, HINSTANCE hInst, WORD dlgId, int cmdShow, WORD iconId, WORD accelTblId)
{
	InitCommonControls();
	try {
		_setTimerSafety();

		HWND hWnd = CreateDialogParamW(hInst, MAKEINTRESOURCEW(dlgId), nullptr,
			Dialog::_DlgProc, reinterpret_cast<LPARAM>(&dlgObj));
		if (!hWnd) [[unlikely]] {
			throw std::system_error(GetLastError(), std::system_category(), "CreateDialogParam failed");
		}

		HACCEL hAccel = _loadAccelTbl(hInst, accelTblId);
		_setIcon(hInst, hWnd, iconId);
		ShowWindow(hWnd, cmdShow);
		return _mainLoop(hWnd, hAccel);
	} catch (...) {
		Dialog::_Lippincott();
	}
	return 1;
}
```
https://github.com/rodrigocfd/windlg/blob/master/windlg/DialogMain.cpp
