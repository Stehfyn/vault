# Rendering

## Flicker-free resize via WM_NCCALCSIZE
https://stackoverflow.com/questions/26700236/flicker-when-moving-resizing-window/53017156#53017156
Collapse the copy-bits rects so Windows skips the stretched blit.
```cpp
case WM_NCCALCSIZE:
{
    if (wParam)
    {
        NCCALCSIZE_PARAMS* np = (NCCALCSIZE_PARAMS*)lParam;
        np->rgrc[1] = np->rgrc[0];
        np->rgrc[2] = np->rgrc[0];
        return WVR_VALIDRECTS;
    }
    break;
}
```

## GDI + D2D interop with ID2D1DCRenderTarget
https://stackoverflow.com/questions/61915005/force-win32-common-controls-to-draw-on-id2d1hwndrendertarget/62775968#62775968
Bind a D2D DC render target to the WM_PAINT HDC so both APIs share it.
```cpp
case WM_PAINT:
{
    PAINTSTRUCT ps; HDC hdc = BeginPaint(hwnd, &ps);
    RECT rc; GetClientRect(hwnd, &rc);
    g_dcrt->BindDC(hdc, &rc);
    g_dcrt->BeginDraw();
    g_dcrt->Clear(D2D1::ColorF(D2D1::ColorF::White));
    g_dcrt->EndDraw();
    EndPaint(hwnd, &ps);
    return 0;
}
```

https://stackoverflow.com/questions/7473226/c-win32-change-trackbar-background-color
NM_CUSTOMDRAW on trackbars lets you paint the channel and thumb manually. Return CDRF_NOTIFYITEMDRAW from CDDS_PREPAINT, then handle CDDS_ITEMPREPAINT per drawing stage.
```cpp
case WM_NOTIFY: {
  LPNMCUSTOMDRAW cd = (LPNMCUSTOMDRAW)lParam;
  if (cd->hdr.hwndFrom != hTrack) break;
  if (cd->dwDrawStage == CDDS_PREPAINT)
    return CDRF_NOTIFYITEMDRAW;
  if (cd->dwDrawStage == CDDS_ITEMPREPAINT) {
    // TBCD_CHANNEL, TBCD_THUMB etc. in cd->dwItemSpec
    FillRect(cd->hdc, &cd->rc, CreateSolidBrush(RGB(30, 30, 30)));
    return CDRF_SKIPDEFAULT;
  }
  break;
}
```

https://learn.microsoft.com/en-us/windows/win32/controls/nm-customdraw
NM_CUSTOMDRAW is the notification code sent to a control's parent during custom draw. The draw stage (CDDS_PREPAINT, CDDS_ITEMPREPAINT, CDDS_POSTPAINT) controls granularity.
```cpp
case WM_NOTIFY: {
  auto* cd = (LPNMCUSTOMDRAW)lParam;
  if (cd->hdr.code != NM_CUSTOMDRAW) break;
  if (cd->dwDrawStage == CDDS_PREPAINT)
    return CDRF_NOTIFYITEMDRAW;
  if (cd->dwDrawStage == CDDS_ITEMPREPAINT) {
    SetTextColor(cd->hdc, RGB(255, 255, 255));
    SetBkColor(cd->hdc, RGB(0, 80, 160));
    return CDRF_DODEFAULT;
  }
  return CDRF_DODEFAULT;
}
```

https://learn.microsoft.com/en-us/windows/win32/controls/cdrf-constants
CDRF_* return values from WM_NOTIFY/NM_CUSTOMDRAW control what the control draws itself. CDRF_SKIPDEFAULT skips the control's drawing entirely; CDRF_DODEFAULT lets it proceed normally.
```cpp
// Return values for NM_CUSTOMDRAW:
// CDRF_DODEFAULT   — let the control draw normally
// CDRF_SKIPDEFAULT — suppress default drawing (owner takes over)
// CDRF_NOTIFYITEMDRAW — request per-item notifications
// CDRF_NOTIFYPOSTPAINT — request post-paint notification
case WM_NOTIFY: {
  auto* cd = (LPNMCUSTOMDRAW)lParam;
  if (cd->dwDrawStage == CDDS_ITEMPREPAINT)
    return cd->dwItemSpec % 2 ? CDRF_SKIPDEFAULT : CDRF_DODEFAULT;
  return CDRF_DODEFAULT;
}
```
