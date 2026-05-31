# Per-Monitor V2 DPI Reference

Per-Monitor V2 is the first Win32 DPI mode that makes non-client scaling, child-window notifications, and dialog behavior coherent enough for serious multi-monitor apps. The trap is load compatibility: functions such as `SetProcessDpiAwarenessContext`, `GetDpiForWindow`, `AdjustWindowRectExForDpi`, and `EnableNonClientDpiScaling` do not exist on older systems, so robust code resolves them dynamically and degrades without preventing the binary from loading.

Correct handling centers on `WM_DPICHANGED`. Use the `RECT*` in `lParam` for the new window bounds, rebuild DPI-derived fonts and metrics, and resize child controls immediately. Per-Monitor V2 does not magically scale owner-drawn content; it merely tells you when the scale changed and makes the OS-managed pieces less wrong.

## Source Shape

The reference pattern is load-compatible opt-in plus `WM_DPICHANGED` relayout. The suggested rectangle is part of the message contract; ignoring it is how mixed-monitor windows drift or resize incorrectly.

```cpp
auto user32 = GetModuleHandleW(L"user32.dll");
auto set_process_dpi = reinterpret_cast<decltype(&SetProcessDpiAwarenessContext)>(
    GetProcAddress(user32, "SetProcessDpiAwarenessContext"));
if (set_process_dpi) {
    set_process_dpi(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);
}

case WM_DPICHANGED: {
    UINT dpi = HIWORD(wParam);
    RECT *suggested = reinterpret_cast<RECT *>(lParam);

    SetWindowPos(hwnd, nullptr,
                 suggested->left, suggested->top,
                 suggested->right - suggested->left,
                 suggested->bottom - suggested->top,
                 SWP_NOZORDER | SWP_NOACTIVATE);

    RebuildFontsAndMetrics(hwnd, dpi);
    LayoutChildrenForDpi(hwnd, dpi);
    return 0;
}
```

Window-frame math should use the DPI-specific helpers when available.

```cpp
RECT rc = { 0, 0, client_width, client_height };
AdjustWindowRectExForDpi(&rc, style, has_menu, ex_style, GetDpiForWindow(hwnd));
```

## Verification Route

Claim: Per-Monitor V2 does not scale your custom UI; it gives you the notification and suggested rectangle needed to do your own scaling at the correct boundary.

Why it matters for new code: owner-drawn controls, borderless hit-test bands, image lists, cached bitmaps, and dialog-derived geometry all need explicit rebuild paths. A manifest or `SetProcessDpiAwarenessContext` call only changes the rules under which Windows delivers coordinates and non-client behavior.

How to verify:

- Run the same window across two monitors with different DPI and log `WM_DPICHANGED`, `GetDpiForWindow`, and the suggested rectangle in `lParam`.
- Comment out the `SetWindowPos` that applies the suggested rectangle; the window should visibly drift or keep stale bounds.
- Keep a cached font/image-list size and log when it is rebuilt. If the cache survives a DPI transition unchanged, the custom UI is not Per-Monitor V2-correct.

Minimal code/pseudocode:

```text
case WM_DPICHANGED:
    dpi = HIWORD(wParam)
    suggested = (RECT*)lParam
    SetWindowPos(hwnd, 0, suggested->left, suggested->top,
                 suggested->right - suggested->left,
                 suggested->bottom - suggested->top,
                 SWP_NOZORDER | SWP_NOACTIVATE)
    DestroyCachedFontsAndBitmaps()
    BuildMetricsForDpi(dpi)
    LayoutChildrenForDpi(dpi)
    return 0
```

Interpretation: if only the top-level window moves but child controls, owner-drawn text, or resize grips remain at old sizes, the app is DPI-aware only at the declaration layer. The fix is not another manifest setting; it is a rebuild path for every cached pixel metric.

## References
- <https://github.com/tringi/win32-dpi> - focused sample for runtime-resolved DPI APIs across old and new Windows.

## Connections
- `Per-Window DPI Awareness.md` covers temporary thread-context changes for mixed-DPI HWND creation.
- `emphasize - Tringi Win32 Utility Snippets.md` shows the same patterns inside practical Win32 utility code.
- `../Common Controls/Window Sizing.md` is where DPI-derived minimums and maximize bounds surface.
- `../Custom Frame/Borderless Window (Aero Shadow).md` depends on DPI-correct resize borders and maximized client rects.
- `../Common Controls/Dialog Units.md` is the legacy font-relative sizing layer that still coexists with Per-Monitor V2.
