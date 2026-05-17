# Flicker-Free Drawing

GDI double-buffering: create a compatible DC and bitmap, draw into it, then BitBlt to the window DC. Return 1 from WM_ERASEBKGND to suppress the default background erase (which causes the flash). The layered window approach (`WS_EX_LAYERED` + `UpdateLayeredWindow`) is the alternative for transparent UIs.

```cpp
case WM_ERASEBKGND:
  return 1;   // suppress erase — we'll paint everything in WM_PAINT

case WM_PAINT: {
  PAINTSTRUCT ps;
  HDC hdc = BeginPaint(hwnd, &ps);
  RECT rc;
  GetClientRect(hwnd, &rc);
  int w = rc.right, h = rc.bottom;

  // Back buffer
  HDC mem = CreateCompatibleDC(hdc);
  HBITMAP bmp = CreateCompatibleBitmap(hdc, w, h);
  HBITMAP old = (HBITMAP)SelectObject(mem, bmp);

  // Draw into back buffer
  FillRect(mem, &rc, (HBRUSH)(COLOR_WINDOW + 1));
  DrawContent(mem, &rc);

  // Blit to screen in one shot
  BitBlt(hdc, 0, 0, w, h, mem, 0, 0, SRCCOPY);
  SelectObject(mem, old);
  DeleteObject(bmp);
  DeleteDC(mem);
  EndPaint(hwnd, &ps);
  return 0;
}

// Layered transparent window approach:
LONG_PTR ex = GetWindowLongPtrW(hwnd, GWL_EXSTYLE);
SetWindowLongPtrW(hwnd, GWL_EXSTYLE, ex | WS_EX_LAYERED);
SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 220, LWA_ALPHA);
```

## References
- https://stackoverflow.com/a/20959649
- https://learn.microsoft.com/en-us/dotnet/desktop/winforms/advanced/using-double-buffering?view=netframeworkdesktop-4.8
