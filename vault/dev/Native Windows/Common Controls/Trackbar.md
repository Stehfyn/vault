# Trackbar (Slider) Control

The trackbar (`TRACKBAR_CLASS`, formerly `msctls_trackbar32`) is the Win32 slider. Key messages: `TBM_SETRANGE`, `TBM_SETPOS`, `TBM_GETPOS`, `TBM_SETTICFREQ`. Parent receives `WM_HSCROLL`/`WM_VSCROLL` with `TB_THUMBPOSITION` or `TB_THUMBTRACK` in `LOWORD(wParam)`.

```cpp
// Create and configure a horizontal trackbar
HWND hTrack = CreateWindowW(TRACKBAR_CLASS, L"",
    WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_TOOLTIPS,
    10, 10, 220, 30, hwnd, (HMENU)IDC_SLIDER, hInst, nullptr);
SendMessageW(hTrack, TBM_SETRANGE, TRUE, MAKELPARAM(0, 100));
SendMessageW(hTrack, TBM_SETTICFREQ, 10, 0);
SendMessageW(hTrack, TBM_SETPOS, TRUE, 25);

// Read position in WM_HSCROLL
case WM_HSCROLL:
  if ((HWND)lParam == hTrack) {
    int pos = (int)SendMessageW(hTrack, TBM_GETPOS, 0, 0);
    // use pos (0..100)
  }
  break;
```

## References
- https://github.com/gammasoft71/Examples_Win32/blob/master/Win32.Gui/Controls/TrackBar/TrackBar.cpp
- https://github.com/MarcoBellini/WinAudio-Player/blob/master/WinAudio/WA_UI_Trackbar.c#L142
