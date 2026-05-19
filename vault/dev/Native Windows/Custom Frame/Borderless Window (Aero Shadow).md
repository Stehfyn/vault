# Borderless Window (Aero Shadow)

The reference implementation everyone cites when they want a clean, MIT-licensed borderless window with working Aero shadows, Snap, and a resize border. The whole technique fits in one .cpp: keep `WS_OVERLAPPEDWINDOW` (don't switch to `WS_POPUP` — you lose Snap and Aero), eat the frame in `WM_NCCALCSIZE` by returning 0 with `wParam==TRUE` while leaving a one-pixel top edge so DWM still considers the window framed (so the shadow renders), and call `DwmExtendFrameIntoClientArea({0,0,0,1})` to push the shadow back in. `WM_NCHITTEST` synthesizes the resize zones manually. This is the pattern adapted by Stehfyn/imgui-borderless-win32 (#60), grassator/win32-window-custom-titlebar (#1) and the Win32 backend of zhiyiYo/PyQt-Frameless-Window (#70).

## References
- <https://github.com/melak47/BorderlessWindow>
