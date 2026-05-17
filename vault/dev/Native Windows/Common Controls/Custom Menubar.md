Windows sends undocumented messages `WM_UAHDRAWMENU` (0x0091) and `WM_UAHDRAWMENUITEM` (0x0092) to the main window for menubar rendering via uxtheme in `DefWindowProc`. Intercepting these lets you custom-draw the menubar background and items—useful for dark themes, since dark mode only affects popup menus, not the menubar.

```cpp
#include "UAHMenuBar.h"   // structs from adzm/win32-custom-menubar-aero-theme

#define WM_UAHDRAWMENU     0x0091
#define WM_UAHDRAWMENUITEM 0x0092

// In WndProc:
case WM_UAHDRAWMENU: {
    UAHMENU *pUDM = (UAHMENU *)lParam;
    // Calculate menubar rect relative to window client area
    MENUBARINFO mbi = { sizeof(mbi) };
    GetMenuBarInfo(hwnd, OBJID_MENU, 0, &mbi);
    RECT rcWin; GetWindowRect(hwnd, &rcWin);
    RECT rc = mbi.rcBar;
    OffsetRect(&rc, -rcWin.left, -rcWin.top);
    FillRect(pUDM->hdc, &rc, hbrMenubarBg);
    return TRUE;
}
case WM_UAHDRAWMENUITEM: {
    UAHDRAWMENUITEM *pUDMI = (UAHDRAWMENUITEM *)lParam;
    // Pick background based on item state
    HBRUSH hbr = (pUDMI->dis.itemState & ODS_HOTLIGHT) ? hbrMenuHot : hbrMenubarBg;
    FillRect(pUDMI->um.hdc, &pUDMI->dis.rcItem, hbr);
    // Draw item text
    WCHAR szText[256] = {};
    MENUITEMINFOW mii  = { sizeof(mii), MIIM_STRING };
    mii.dwTypeData     = szText;
    mii.cch            = _countof(szText);
    GetMenuItemInfoW(pUDMI->um.hmenu, pUDMI->umi.iPosition, TRUE, &mii);
    SetTextColor(pUDMI->um.hdc, RGB(220, 220, 220));
    SetBkMode(pUDMI->um.hdc, TRANSPARENT);
    DrawTextW(pUDMI->um.hdc, szText, -1, &pUDMI->dis.rcItem,
              DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    return TRUE;
}
```

## References
- https://github.com/adzm/win32-custom-menubar-aero-theme
