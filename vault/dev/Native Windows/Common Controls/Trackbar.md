# Trackbar

The trackbar (`TRACKBAR_CLASS`) is the stock slider. Range and position are controlled with `TBM_SETRANGE`, `TBM_SETPOS`, and `TBM_GETPOS`; the parent receives `WM_HSCROLL` or `WM_VSCROLL` with `TB_THUMBTRACK`, `TB_THUMBPOSITION`, line/page changes, and end-tracking codes in `LOWORD(wParam)`. If live updates matter, handle thumb tracking, not just final thumb position.

Custom coloring is not a style bit. Use `NM_CUSTOMDRAW` for channel/thumb painting where supported, and expect to preserve tick marks, disabled state, focus cues, and DPI-sized geometry yourself. The linked examples are valuable because they show both ordinary slider wiring and a real audio-player trackbar where continuous update behavior matters.

## Source Code Reading

`gammasoft71/Examples_Win32/.../TrackBar.cpp` is a compact wiring sample. It creates three common controls: `TRACKBAR_CLASS`, `PROGRESS_CLASS`, and `WC_STATIC`. Then it subclasses the top-level window with `SetWindowLongPtr(window, GWLP_WNDPROC, WndProc)`, storing the old procedure in `defWndProc`.

The setup path is:

```cpp
trackBar = CreateWindowEx(0, TRACKBAR_CLASS, nullptr,
    WS_CHILD | TBS_HORZ | TBS_NOTICKS | WS_VISIBLE, ...);

SendMessage(trackBar, TBM_SETRANGEMIN, TRUE, 0);
SendMessage(trackBar, TBM_SETRANGEMAX, TRUE, 200);
SendMessage(trackBar, TBM_SETPOS, TRUE, 100);
```

`WndProc` filters scroll notifications by both parent message and source HWND:

```cpp
if (message == WM_HSCROLL &&
    hwnd == window &&
    (HWND)lParam == trackBar) {
    value = SendMessage(trackBar, TBM_GETPOS, 0, 0);
    SendMessage(progressBar, PBM_SETPOS, value, 0);
    SendMessage(staticText, WM_SETTEXT, 0, text);
}
```

That source-HWND check is the detail to preserve when a dialog has several sliders. `LOWORD(wParam)` tells you why the slider moved (`TB_THUMBTRACK`, line/page, end track); `lParam` tells you which trackbar sent the notification. A helper named `OnSliderChanged` should expose both pieces, because live scrubbing and final commit are different behaviors in media apps.

## References
- <https://github.com/gammasoft71/Examples_Win32/blob/master/Win32.Gui/Controls/TrackBar/TrackBar.cpp> - basic trackbar creation and message handling.
- <https://github.com/MarcoBellini/WinAudio-Player/blob/master/WinAudio/WA_UI_Trackbar.c#L142> - application trackbar integrated with playback state.

## Connections
- `Rendering.md` covers `NM_CUSTOMDRAW` mechanics.
- `Ms Player.md` is the adjacent media-control example.
