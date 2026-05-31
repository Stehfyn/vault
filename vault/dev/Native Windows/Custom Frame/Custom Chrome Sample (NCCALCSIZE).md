# Custom Chrome Sample (NCCALCSIZE)

Tiny Win32 sample that strips the standard non-client area and reconstructs window chrome (caption, system menu, min/max/close, resize borders) entirely in the client area using `WM_NCCALCSIZE` and `WM_NCHITTEST`. The non-obvious part: returning 0 from `WM_NCCALCSIZE` collapses the non-client frame to nothing, but to keep the DWM shadow / snap / animation behaviour you also need to extend the frame via `DwmExtendFrameIntoClientArea`. Useful baseline for any custom titlebar (VS Code, Slack, etc).

## Source Shape

The important pattern in the sample is not drawing tabs; it is the message order. Let DWM handle caption-button behavior first, then take the non-client rectangle and hit-test math only when DWM declines the message.

```cpp
LRESULT result = 0;
if (DwmDefWindowProc(hwnd, msg, wParam, lParam, &result)) {
    return result;
}

switch (msg) {
case WM_NCCALCSIZE:
    if (wParam) {
        auto *calc = reinterpret_cast<NCCALCSIZE_PARAMS *>(lParam);
        calc->rgrc[0].top += caption_extent;
        return 0;
    }
    break;

case WM_NCHITTEST:
    result = HitTestCustomFrame(hwnd, lParam, caption_extent);
    if (result != HTNOWHERE) {
        return result;
    }
    break;
}
return DefWindowProcW(hwnd, msg, wParam, lParam);
```

Frame extension is still part of the recipe:

```cpp
MARGINS margins = { 0, 0, caption_extent, 0 };
THROW_IF_FAILED(DwmExtendFrameIntoClientArea(hwnd, &margins));
```

## References
- <https://github.com/oberth/custom-chrome>

## Connections
- Compare with `../Common Controls/Borderless Window.md` for the same style/hit-test problem explained from the Win32 control side.
- `Borderless Window (Aero Shadow).md` is the practical shadow/Snap version of this NCCALCSIZE technique.
- `../(DWM) Desktop Window Manager/Title Bar Customization.md` and `Dark Mode (Uxtheme Ordinals).md` cover the modern titlebar attributes that usually get layered on top.
