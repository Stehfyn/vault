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

## Source Code Reading

`mykola2312/win32ctrl` is a wrapper layer, but the teaching value is still the same Win32 contract: controls are HWNDs that communicate through messages. `win32ctrl.cpp` and `win32ctrl.h` define small C++ objects around HWND creation, enumeration, and command routing; `win32util.cpp` contributes utility enumeration such as `_CheckWindow(HWND, LPARAM)`. When a wrapper method says "create a button," decompose it to `CreateWindowEx`, class name, style bits, parent HWND, menu/control ID, instance handle, and optional `lpParam`.

`andlabs/wintable` is the more interesting custom-control source. `api.c` defines `apiHandlers`, which handles private table messages such as `tableAddColumn` and `tableSetModel`, plus stock messages such as `WM_SETFONT` and `WM_GETFONT`. The table does not expose random public C++ methods; it exposes a message API around an HWND.

The key ownership path in `api.c` is:

```cpp
tableSetModel:
    tableModel_tableUnsubscribe(oldModel, hwnd)
    tableModel_Release(oldModel)
    tableModel_AddRef(newModel)
    tableModel_tableSubscribe(newModel, hwnd)
    updateAll(table)
```

That is what "custom control state" means in code: the control owns references, invalidation, and notification timing. The parent owns the model behavior.

The notification path is explicit:

```cpp
tableNM nm = {};
nm.nmhdr.hwndFrom = t->hwnd;
nm.nmhdr.idFrom = GetDlgCtrlID(t->hwnd);
nm.nmhdr.code = code;
nm.row = row;
nm.column = column;
SendMessageW(GetParent(t->hwnd), WM_NOTIFY, nm.nmhdr.idFrom, &nm);
```

A custom control is not finished when it paints. It needs a stable notification struct, parent routing, font handling, model lifetime, redraw policy, keyboard/focus behavior, and teardown. Those are the missing details behind vague helpers like `NotifyParent`, `SetModel`, or `DrawControl`.

## References
- <https://www.codeproject.com/Articles/620045/Custom-Controls-in-Win32-API-Visual-Styles> - themed drawing for custom controls.
- <https://github.com/mykola2312/win32ctrl/blob/master/win32ctrl.cpp> - stock-control subclassing example.
- <https://github.com/andlabs/wintable/blob/master/ModelPlan.h> - owner-drawn item model in real Win32 code.
- <https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles> - common-control initialization and style reference.

## Connections
- `cbClsExtra and cbWndExtra.md` covers state storage.
- `Rendering.md` covers custom-draw notification mechanics.
- `DPI Awareness/Per-Monitor V2 DPI Reference.md` explains why fixed pixel metrics in custom controls age badly.
