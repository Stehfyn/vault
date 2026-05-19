# Trackbar

The trackbar (`TRACKBAR_CLASS`) is the stock slider. Range and position are controlled with `TBM_SETRANGE`, `TBM_SETPOS`, and `TBM_GETPOS`; the parent receives `WM_HSCROLL` or `WM_VSCROLL` with `TB_THUMBTRACK`, `TB_THUMBPOSITION`, line/page changes, and end-tracking codes in `LOWORD(wParam)`. If live updates matter, handle thumb tracking, not just final thumb position.

Custom coloring is not a style bit. Use `NM_CUSTOMDRAW` for channel/thumb painting where supported, and expect to preserve tick marks, disabled state, focus cues, and DPI-sized geometry yourself. The linked examples are valuable because they show both ordinary slider wiring and a real audio-player trackbar where continuous update behavior matters.

## References
- <https://github.com/gammasoft71/Examples_Win32/blob/master/Win32.Gui/Controls/TrackBar/TrackBar.cpp> - basic trackbar creation and message handling.
- <https://github.com/MarcoBellini/WinAudio-Player/blob/master/WinAudio/WA_UI_Trackbar.c#L142> - application trackbar integrated with playback state.

## Connections
- `Rendering.md` covers `NM_CUSTOMDRAW` mechanics.
- `Ms Player.md` is the adjacent media-control example.
