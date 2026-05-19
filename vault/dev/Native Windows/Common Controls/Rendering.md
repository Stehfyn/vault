# Rendering

Common-control rendering customizations usually choose among three levers. `NM_CUSTOMDRAW` asks the control for staged intervention (`CDDS_PREPAINT`, `CDDS_ITEMPREPAINT`, `CDDS_POSTPAINT`) and returns `CDRF_*` flags to continue, skip, or request deeper notifications. Owner-draw moves whole item painting to the parent. Full custom painting means the control owns `WM_PAINT`, buffering, invalidation, and visual states.

Flicker is often a contract bug, not a fill-rate problem. Suppress redundant background erase when you repaint the entire client, use double buffering for GDI-heavy surfaces, and batch child-window moves during resize. For GDI/Direct2D interop, `ID2D1DCRenderTarget::BindDC` is the intended bridge when the output must land in a `BeginPaint` HDC; it does not turn stock controls into Direct2D controls.

## Custom Draw

The `NM_CUSTOMDRAW` and `CDRF_*` references contribute the staged-notification contract. Returning the wrong flag is the usual bug: the parent must explicitly request item-level callbacks or the control will never ask.

```cpp
case WM_NOTIFY: {
    auto* nm = reinterpret_cast<NMHDR*>(lParam);
    if (nm->code == NM_CUSTOMDRAW) {
        auto* cd = reinterpret_cast<NMCUSTOMDRAW*>(lParam);
        if (cd->dwDrawStage == CDDS_PREPAINT) {
            return CDRF_NOTIFYITEMDRAW;
        }
        if (cd->dwDrawStage == CDDS_ITEMPREPAINT) {
            return CDRF_DODEFAULT;
        }
    }
    break;
}
```

## Paint and Interop Boundary

The flicker and D2D answers contribute the actual boundary: erase less, paint once, and bind D2D to the paint HDC when the output must participate in GDI invalidation.

```cpp
case WM_ERASEBKGND:
    return 1;

case WM_PAINT: {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    d2d_dc_target->BindDC(hdc, &ps.rcPaint);
    d2d_dc_target->BeginDraw();
    d2d_dc_target->Clear(D2D1::ColorF(D2D1::ColorF::White));
    d2d_dc_target->EndDraw();
    EndPaint(hwnd, &ps);
    return 0;
}
```

## References

- <https://learn.microsoft.com/en-us/windows/win32/controls/nm-customdraw> - staged custom-draw notification contract.
- <https://learn.microsoft.com/en-us/windows/win32/controls/cdrf-constants> - return flags that control default drawing and notification depth.
- <https://stackoverflow.com/questions/26700236/flicker-when-moving-resizing-window/53017156#53017156> - resize flicker discussion around valid rects and background erasure.
- <https://stackoverflow.com/questions/61915005/force-win32-common-controls-to-draw-on-id2d1hwndrendertarget/62775968#62775968> - explains the GDI/DC render target interop boundary.

## Connections

- `Flicker-Free Drawing.md` in GDI covers the raw double-buffering pattern.
- `Custom Controls.md` describes when to escalate from custom draw to a real custom control.
