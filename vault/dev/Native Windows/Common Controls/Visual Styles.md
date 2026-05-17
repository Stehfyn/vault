# Visual Styles

## Custom Controls with Visual Styles (CodeProject)
https://www.codeproject.com/Articles/620045/Custom-Controls-in-Win32-API-Visual-Styles
Use theme parts to render text and backgrounds with system styles.
```cpp
HTHEME hTheme = OpenThemeData(hwnd, L"EDIT");
if (hTheme)
{
    RECT rc; GetClientRect(hwnd, &rc);
    DrawThemeText(hTheme, hdc, EP_EDITTEXT, ETS_NORMAL, L"Sample", -1, 0, 0, &rc);
    CloseThemeData(hTheme);
}
```

## win32ctrl.cpp (theme a control)
https://github.com/mykola2312/win32ctrl/blob/master/win32ctrl.cpp
Apply an Explorer theme to a common control for modern visuals.
```cpp
HWND hList = CreateWindowEx(0, WC_LISTVIEW, L"", WS_CHILD | WS_VISIBLE,
    0, 0, 200, 120, hwnd, 0, hInst, 0);
SetWindowTheme(hList, L"Explorer", NULL);
ListView_SetExtendedListViewStyle(hList, LVS_EX_DOUBLEBUFFER);
ListView_SetTextBkColor(hList, CLR_NONE);
```

## Win32-Window sample (theme change handling)
https://github.com/jkopa/Win32-Window
Refresh a custom UI when system theme settings change.
```cpp
case WM_THEMECHANGED:
{
    SetWindowTheme(hwnd, NULL, NULL);
    InvalidateRect(hwnd, NULL, TRUE);
    return 0;
}
```

## MFC Feature Pack samples
https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/Visual%20C%2B%2B%202008%20Feature%20Pack
Choose an MFC visual manager to align with the OS theme.
```cpp
BOOL CMyApp::InitInstance()
{
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
    CMFCVisualManagerWindows::m_b3DTabsXPTheme = TRUE;
    return CWinApp::InitInstance();
}
```

## Win32 docs desktop-src
https://github.com/MicrosoftDocs/win32/tree/docs/desktop-src
Initialize common controls so visual styles apply at startup.
```cpp
INITCOMMONCONTROLSEX icc = { sizeof(icc) };
icc.dwICC = ICC_STANDARD_CLASSES | ICC_WIN95_CLASSES;
InitCommonControlsEx(&icc);
HWND hButton = CreateWindowEx(0, WC_BUTTON, L"OK", WS_CHILD | WS_VISIBLE,
    0, 0, 80, 24, hwnd, 0, hInst, 0);
```

## StackOverflow: Button background color
https://stackoverflow.com/questions/18745447/how-can-i-change-the-background-color-of-a-button-winapi-c
Custom draw the background and let Windows draw the text.
```cpp
case WM_NOTIFY:
{
    LPNMCUSTOMDRAW cd = (LPNMCUSTOMDRAW)lParam;
    if (cd->hdr.code == NM_CUSTOMDRAW && cd->dwDrawStage == CDDS_PREPAINT)
    {
        HBRUSH b = CreateSolidBrush(RGB(40, 140, 220));
        FillRect(cd->hdc, &cd->rc, b);
        DeleteObject(b);
        return CDRF_DODEFAULT;
    }
    break;
}
```

https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles
InitCommonControlsEx with ICC_* flags loads the desired control class implementations from comctl32. Without this the listview, treeview, and other v6 controls may not be available.
```cpp
INITCOMMONCONTROLSEX icc = { sizeof(icc),
    ICC_LISTVIEW_CLASSES | ICC_TREEVIEW_CLASSES | ICC_BAR_CLASSES };
InitCommonControlsEx(&icc);
```

https://learn.microsoft.com/en-us/windows/win32/controls/aero-style-classes-parts-and-states
UxTheme part and state IDs map to the visual elements defined in the current theme. Use OpenThemeData / DrawThemeBackground / CloseThemeData for themed drawing.
```cpp
HTHEME theme = OpenThemeData(hwnd, L"Button");
if (theme) {
  RECT rc = { 10, 10, 110, 40 };
  DrawThemeBackground(theme, hdc, BP_PUSHBUTTON, PBS_HOT, &rc, nullptr);
  DrawThemeText(theme, hdc, BP_PUSHBUTTON, PBS_HOT, L"Hot", -1,
                DT_CENTER | DT_VCENTER | DT_SINGLELINE, 0, &rc);
  CloseThemeData(theme);
}
```

https://grep.app/search?q=GetThemeTimingFunction
GetThemeTimingFunction is an undocumented/unexported UxTheme API used by WinUI and DWM for animation curve parameters. Load it by ordinal or name at runtime.
```cpp
HMODULE ux = LoadLibraryW(L"uxtheme.dll");
// Exported name varies; GetProcAddress by name if available
typedef HRESULT (WINAPI *GetThemeTimingFn)(HTHEME, int, int, int, float*);
auto fn = (GetThemeTimingFn)GetProcAddress(ux, "GetThemeTimingFunction");
float params[4] = {};
if (fn) fn(nullptr, 0, 0, 0, params);
FreeLibrary(ux);
```

https://learn.microsoft.com/en-us/previous-versions/windows/embedded/ms927620(v=msdn.10)
SetWindowTheme forces a specific visual style subkey onto a control (e.g. "Explorer" for tree views). CCM_SETVERSION negotiates the comctl32 version for a control instance.
```cpp
SetWindowTheme(hTreeView, L"Explorer", nullptr);
SetWindowTheme(hListView, L"Explorer", nullptr);
// Force modern scrollbars on a listbox
SetWindowTheme(hList, L"", L"");
```
