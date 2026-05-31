# Custom Menubar

Classic menus are awkward to theme because the top menubar is not a normal common control. The `adzm/win32-custom-menubar-aero-theme` technique handles undocumented `WM_UAHDRAWMENU` and `WM_UAHDRAWMENUITEM` messages that `DefWindowProc` uses while drawing the themed menu bar. Intercepting them lets an app paint dark or custom menubar backgrounds without replacing the whole menu system.

This is useful but brittle. The structures are reverse-engineered, the messages are not a stable public contract, and popup menus still have their own theming path. For a controlled desktop tool the trade can be acceptable; for a library, prefer documented owner-draw menus or a full custom frame/menu implementation where the compatibility boundary is explicit.

## Source Shape

The linked sample's contribution is a window-proc branch for undocumented UAH draw messages, then themed drawing into the provided DC/rect instead of replacing the whole menu system.

```cpp
case WM_UAHDRAWMENU:
    DrawCustomMenuBarBackground(hwnd, reinterpret_cast<UAHDRAWMENU *>(lParam));
    return 0;

case WM_UAHDRAWMENUITEM:
    DrawCustomMenuBarItem(hwnd, reinterpret_cast<UAHDRAWMENUITEM *>(lParam));
    return 0;
```

Keep this as a narrow menu-bar skinning route. Popup menus, context menus, and flyouts use different windows and different interception points.

## Source Code Reading

Read `win32-custom-menubar-aero-theme.cpp` first only to see integration: its `WndProc` calls `UAHWndProc(hWnd, message, wParam, lParam, &lr)` before the normal `WM_COMMAND`, `WM_PAINT`, and `WM_DESTROY` branches. The useful code lives in `UAHMenuBar.h` and `UAHMenuBar.cpp`.

`UAHMenuBar.h` defines the undocumented message constants and the reverse-engineered payloads. `WM_UAHDRAWMENU` carries a `UAHMENU` with `hmenu` and `hdc`. `WM_UAHDRAWMENUITEM` carries `UAHDRAWMENUITEM`, which embeds a `DRAWITEMSTRUCT`, `UAHMENU`, and `UAHMENUITEM`. `WM_UAHMEASUREMENUITEM` carries a `MEASUREITEMSTRUCT`-like payload. That is the hidden contribution: the menubar can be painted because USER32 is already passing an HDC, item rectangle, item state, menu handle, and item position through this private path.

`UAHWndProc` decomposes into four branches:

```cpp
WM_UAHDRAWMENU:
    GetMenuBarInfo(hwnd, OBJID_MENU, 0, &mbi)
    GetWindowRect(hwnd, &rcWindow)
    rc = mbi.rcBar adjusted into window coordinates
    FillRect(payload->hdc, &rc, barBrush)

WM_UAHDRAWMENUITEM:
    GetMenuItemInfo(payload->um.hmenu, payload->umi.iPosition, TRUE, &mii)
    inspect payload->dis.itemState for ODS_HOTLIGHT, ODS_SELECTED, ODS_DISABLED
    OpenThemeData(hwnd, L"Menu") once
    FillRect / FrameRect the item rect
    DrawThemeTextEx(MENU_BARITEM, MBI_NORMAL, text, flags, rect, DTTOPTS)

WM_UAHMEASUREMENUITEM:
    DefWindowProc first to get the system's width
    mutate itemWidth afterward

WM_THEMECHANGED:
    CloseThemeData and force the next draw to reopen the theme
```

`UAHDrawMenuNCBottomLine` is not cosmetic trivia. It shows the coordinate problem you hit when the menubar participates in non-client painting: `GetMenuBarInfo` returns a screen-space-ish `rcBar`, `GetWindowRect` gives the origin to subtract, and `GetWindowDC` paints the one-pixel line outside the client area. If your custom menubar leaves a stale separator after activation changes, this is the branch to study.

## References
- <https://github.com/adzm/win32-custom-menubar-aero-theme> - reverse-engineered UAH menubar draw-message handling.

## Connections
- `Darkmode.md` explains why menu bars lag behind the rest of Windows dark mode.
- `Modify Context Menu.md` is the popup-menu counterpart, using a different interception technique.
- `../Custom Frame/Acrylic Popup Menus.md` watches menu popup creation with `WH_CBT`.
- `../Hooks/SetWindowsHookEx.md` explains the hook branch when the menu window is not directly owned by your code.
