# Borderless Window (Aero Shadow)

The reference implementation everyone cites when they want a clean, MIT-licensed borderless window with working Aero shadows, Snap, and a resize border. The whole technique fits in one .cpp: keep `WS_OVERLAPPEDWINDOW` (don't switch to `WS_POPUP` — you lose Snap and Aero), eat the frame in `WM_NCCALCSIZE` by returning 0 with `wParam==TRUE` while leaving a one-pixel top edge so DWM still considers the window framed (so the shadow renders), and call `DwmExtendFrameIntoClientArea({0,0,0,1})` to push the shadow back in. `WM_NCHITTEST` synthesizes the resize zones manually. This is the pattern adapted by Stehfyn/imgui-borderless-win32 (#60), grassator/win32-window-custom-titlebar (#1) and the Win32 backend of zhiyiYo/PyQt-Frameless-Window (#70).

## Source Shape

BorderlessWindow's reusable lesson is the triangle of shadow state, frame recalculation, and custom hit testing. If one side is missing, the window looks right but fails Snap/resize/maximize edge cases.

```cpp
void SetAeroShadow(HWND hwnd, bool enabled) {
    MARGINS margins = enabled ? MARGINS{1, 1, 1, 1} : MARGINS{0, 0, 0, 0};
    DwmExtendFrameIntoClientArea(hwnd, &margins);
}

void RefreshNonClient(HWND hwnd) {
    SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
                 SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE |
                 SWP_NOZORDER | SWP_NOACTIVATE);
}
```

```cpp
case WM_NCCALCSIZE:
    if (wParam && borderless) {
        auto *calc = reinterpret_cast<NCCALCSIZE_PARAMS *>(lParam);
        AdjustMaximizedClientRect(hwnd, calc->rgrc[0]);
        return 0;
    }
    break;

case WM_NCHITTEST:
    if (borderless) {
        return HitTestResizeAndCaption(hwnd, GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
    }
    break;
```

## References
- <https://github.com/melak47/BorderlessWindow>

## Connections
- `Custom Chrome Sample (NCCALCSIZE).md` is the minimal frame-removal recipe behind this more complete Aero-shadow pattern.
- `../Common Controls/Window Sizing.md` and `../DPI Awareness/Per-Window DPI Awareness.md` are required reading before shipping maximize/restore behavior on mixed-DPI monitors.
- `ImGui Borderless Win32 (Custom Frame + Viewports).md` shows the same constraints when Dear ImGui owns multiple platform HWNDs.
