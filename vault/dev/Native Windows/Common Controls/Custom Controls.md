# Custom Controls

Win32 custom controls fall into three buckets. A subclassed stock control keeps the original implementation and intercepts messages with `SetWindowSubclass`; use this when you want to alter painting, input, or validation without reimplementing selection, keyboard, IME, accessibility, and scrolling. Owner-draw/custom-draw keeps the control but moves item painting to the parent through `WM_DRAWITEM` or `NM_CUSTOMDRAW`. A true custom control registers its own class, owns state through `cbWndExtra` or `GWLP_USERDATA`, and must implement focus, sizing, painting, hit testing, and notifications itself.

The links here matter because they show different points on that spectrum. The CodeProject visual-styles article demonstrates drawing with UxTheme parts instead of hard-coded colors. `win32ctrl.cpp` is a subclassing pattern. `andlabs/wintable` uses owner-draw for item rendering. The Microsoft desktop docs and common-control examples provide the boring but necessary initialization layer: comctl32 v6 manifest, `InitCommonControlsEx`, and notifications through the parent window.

## Subclassed Stock Control

`win32ctrl.cpp` contributes the safest extension pattern: keep the stock window class and intercept only the messages you actually need. `DefSubclassProc` preserves the original behavior.

```cpp
LRESULT CALLBACK EditSubclass(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp,
                              UINT_PTR id, DWORD_PTR ref) {
    if (msg == WM_NCDESTROY) {
        RemoveWindowSubclass(hwnd, EditSubclass, id);
    }
    if (msg == WM_KEYDOWN && wp == VK_RETURN) {
        SendMessageW(GetParent(hwnd), WM_COMMAND, MAKEWPARAM(id, EN_CHANGE), (LPARAM)hwnd);
        return 0;
    }
    return DefSubclassProc(hwnd, msg, wp, lp);
}

SetWindowSubclass(edit_hwnd, EditSubclass, control_id, 0);
```

## Owner Draw and True Custom Classes

`wintable` contributes the owner-draw/model split; the visual-styles article contributes themed painting inside a custom class. A true control owns state, painting, and notifications.

```cpp
case WM_NCCREATE: {
    auto* create = reinterpret_cast<CREATESTRUCTW*>(lParam);
    SetWindowLongPtrW(hwnd, GWLP_USERDATA, (LONG_PTR)create->lpCreateParams);
    return TRUE;
}
case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    // Draw state, focus rect, and themed background here.
    EndPaint(hwnd, &ps);
    return 0;
}
```

## References
- <https://www.codeproject.com/Articles/620045/Custom-Controls-in-Win32-API-Visual-Styles> - themed drawing for custom controls.
- <https://github.com/mykola2312/win32ctrl/blob/master/win32ctrl.cpp> - stock-control subclassing example.
- <https://github.com/andlabs/wintable/blob/master/ModelPlan.h> - owner-drawn item model in real Win32 code.
- <https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles> - common-control initialization and style reference.

## Connections
- `cbClsExtra and cbWndExtra.md` covers state storage.
- `Rendering.md` covers custom-draw notification mechanics.
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` explains why fixed pixel metrics in custom controls age badly.
