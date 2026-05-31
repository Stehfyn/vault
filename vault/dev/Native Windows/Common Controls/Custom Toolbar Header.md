# Custom Toolbar Header

`Win32CustomToolbarHeader` is useful as a combined toolbar/header customization reference: create the toolbar with `TOOLBARCLASSNAME`, size buttons with `TB_BUTTONSTRUCTSIZE` and `TB_ADDBUTTONS`, then customize header-style painting through parent `WM_NOTIFY` handling. The point is not the creation boilerplate; it is how comctl32 controls split ownership between control state and parent-supplied drawing.

When customizing a toolbar or header, preserve the control's layout and command semantics unless you are deliberately replacing it. Let comctl32 manage button state, tooltips, and keyboard behavior, and intervene only at the custom-draw stages you need. Full owner painting should also account for DPI-scaled image lists and visual-state changes on hover, press, disabled, and hot tracking.

## Source Code Reading

In `Win32CustomToolbarHeader/Win32CustomToolbarHeader.c`, the stock app skeleton is not the interesting part. The instructive routes are `WndProc`, `OnCreate`, `OnSize`, and the toolbar/header helper functions that `OnCreate` calls.

`WndProc` splits command routing from layout:

```cpp
WM_COMMAND:
    switch LOWORD(wParam) for menu/toolbar command IDs
WM_CREATE:
    OnCreate(hwnd)
WM_SIZE:
    OnSize(hwnd)
WM_PAINT:
    OnDraw(hwnd)
```

`OnCreate` creates the status bar with `CreateWindowEx(0, STATUSCLASSNAME, ...)`, stores it under `IDC_MAIN_STATUS`, sets text with `SetWindowText`, then calls `CreateCustomToolbar(hwnd)`. `OnSize` sends `WM_SIZE` to the status bar and recreates or resizes the toolbar path. The observable behavior is that status bars and toolbars are children that must be resized when the frame client size changes; they do not magically follow the parent.

When reading the toolbar code, reduce helpers to these primitives:

```cpp
InitCommonControlsEx(ICC_BAR_CLASSES | ICC_COOL_CLASSES)
CreateWindowEx(..., TOOLBARCLASSNAME, ..., WS_CHILD | WS_VISIBLE | TBSTYLE_...)
SendMessage(toolbar, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0)
ImageList_Create / ImageList_Add / TB_SETIMAGELIST
SendMessage(toolbar, TB_ADDBUTTONS, count, (LPARAM)buttons)
SendMessage(toolbar, TB_AUTOSIZE, 0, 0)
```

If the header is custom drawn, the parent receives `WM_NOTIFY`, casts `lParam` to `NMHDR`, then to `NMCUSTOMDRAW` for `NM_CUSTOMDRAW`. The return value is not decoration: `CDRF_NOTIFYITEMDRAW` asks for per-item callbacks; `CDRF_DODEFAULT` gives control back to comctl32; `CDRF_SKIPDEFAULT` means you painted the item and own the visual result.

## References
- <https://github.com/Alexandre-Carpentier/Win32CustomToolbarHeader> - practical toolbar/header custom drawing sample.

## Connections
- `Toolbar and Status Bar.md` covers the stock controls.
- `Rendering.md` covers the `NM_CUSTOMDRAW` stage/return-code model.
