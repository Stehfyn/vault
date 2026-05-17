# Custom Controls

## Custom Controls with Visual Styles (CodeProject)
https://www.codeproject.com/Articles/620045/Custom-Controls-in-Win32-API-Visual-Styles
Use UxTheme parts so a custom control matches system visual styles.
```cpp
HTHEME theme = OpenThemeData(hwnd, L"BUTTON");
if (theme)
{
    RECT rc; GetClientRect(hwnd, &rc);
    DrawThemeBackground(theme, hdc, BP_PUSHBUTTON, PBS_NORMAL, &rc, NULL);
    CloseThemeData(theme);
}
```

## win32ctrl.cpp (subclassing example)
https://github.com/mykola2312/win32ctrl/blob/master/win32ctrl.cpp
Subclass a stock control to override paint behavior without reimplementing it.
```cpp
HWND hCtrl = CreateWindowEx(0, WC_STATIC, L"", WS_CHILD | WS_VISIBLE,
    0, 0, 120, 24, hwnd, 0, hInst, 0);
SetWindowSubclass(hCtrl, CustomProc, 0, 0);
LRESULT CALLBACK CustomProc(HWND h, UINT m, WPARAM w, LPARAM l, UINT_PTR, DWORD_PTR)
{
    if (m == WM_PAINT) return 0;
    return DefSubclassProc(h, m, w, l);
}
```

## Win32-Window sample
https://github.com/jkopa/Win32-Window
Owner-draw lets you render common control items directly with GDI.
```cpp
case WM_DRAWITEM:
{
    DRAWITEMSTRUCT* di = (DRAWITEMSTRUCT*)lParam;
    FillRect(di->hDC, &di->rcItem, (HBRUSH)(COLOR_WINDOW + 1));
    SetBkMode(di->hDC, TRANSPARENT);
    TextOutW(di->hDC, di->rcItem.left + 4, di->rcItem.top + 2, L"Item", 4);
    return TRUE;
}
```

## MFC Feature Pack samples
https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/Visual%20C%2B%2B%202008%20Feature%20Pack
Pick an MFC visual manager to align custom UI with system themes.
```cpp
BOOL CMyApp::InitInstance()
{
    CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
    CMFCToolBar::EnableQuickCustomization();
    return CWinApp::InitInstance();
}
```

## Win32 docs desktop-src
https://github.com/MicrosoftDocs/win32/tree/docs/desktop-src
Register a custom window class and reserve extra bytes for control state.
```cpp
WNDCLASSEX wc = { sizeof(wc) };
wc.lpfnWndProc   = CustomWndProc;
wc.hInstance     = hInst;
wc.lpszClassName = L"MyCustomCtrl";
wc.cbWndExtra    = sizeof(LONG_PTR);
RegisterClassEx(&wc);
```

## StackOverflow: Button background color
https://stackoverflow.com/questions/18745447/how-can-i-change-the-background-color-of-a-button-winapi-c
Use NM_CUSTOMDRAW to paint the background while leaving text to the system.
```cpp
case WM_NOTIFY:
{
    LPNMCUSTOMDRAW cd = (LPNMCUSTOMDRAW)lParam;
    if (cd->hdr.code == NM_CUSTOMDRAW && cd->dwDrawStage == CDDS_PREPAINT)
    {
        HBRUSH b = CreateSolidBrush(RGB(30, 120, 200));
        FillRect(cd->hdc, &cd->rc, b);
        DeleteObject(b);
        return CDRF_DODEFAULT;
    }
    break;
}
```

https://github.com/suschuk/cpp-lessons/blob/master/SavchukSasha/WinApiControls/CppWindowsCommonControls/CppWindowsCommonControls.cpp
Sample showing multiple Win32 common controls created and wired together. Demonstrates LB_ADDSTRING, LB_SETCURSEL, and LB_GETCOUNT for a listbox.
```cpp
HWND hList = CreateWindowW(WC_LISTBOX, L"",
    WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_SORT,
    10, 10, 140, 100, hwnd, (HMENU)IDC_LISTBOX, hInst, nullptr);
SendMessageW(hList, LB_ADDSTRING, 0, (LPARAM)L"Alpha");
SendMessageW(hList, LB_ADDSTRING, 0, (LPARAM)L"Beta");
SendMessageW(hList, LB_SETCURSEL, 0, 0);
int count = (int)SendMessageW(hList, LB_GETCOUNT, 0, 0);
```

https://www.codeproject.com/Articles/744603/Custom-Controls-in-Win-API-Encapsulation-of-Cust
Subclassing is the cleanest way to extend a standard control. Store the old proc with GWLP_USERDATA or SetProp, forward unhandled messages to it.
```cpp
// Subclass a button to intercept WM_PAINT
WNDPROC g_oldProc = nullptr;
LRESULT CALLBACK BtnSubclass(HWND h, UINT m, WPARAM w, LPARAM l) {
  if (m == WM_PAINT) {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(h, &ps);
    RECT rc;
    GetClientRect(h, &rc);
    FillRect(hdc, &rc, CreateSolidBrush(RGB(30, 144, 255)));
    DrawTextW(hdc, L"Custom", -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    EndPaint(h, &ps);
    return 0;
  }
  return CallWindowProcW(g_oldProc, h, m, w, l);
}
g_oldProc = (WNDPROC)SetWindowLongPtrW(hBtn, GWLP_WNDPROC, (LONG_PTR)BtnSubclass);
```

https://github.com/andlabs/wintable/blob/master/ModelPlan.h
Owner-draw (ODS_DRAWENTIRE) lets a control pass all painting responsibility to the parent via WM_DRAWITEM. Used for listboxes, buttons, and menus.
```cpp
case WM_DRAWITEM: {
  auto* dis = (DRAWITEMSTRUCT*)lParam;
  if (dis->hwndItem != hList) break;
  COLORREF bg = (dis->itemState & ODS_SELECTED) ? RGB(0,120,215) : RGB(255,255,255);
  FillRect(dis->hDC, &dis->rcItem, CreateSolidBrush(bg));
  SetBkMode(dis->hDC, TRANSPARENT);
  DrawTextW(dis->hDC, (LPCWSTR)dis->itemData, -1, &dis->rcItem,
            DT_LEFT | DT_VCENTER | DT_SINGLELINE);
  return TRUE;
}
```
