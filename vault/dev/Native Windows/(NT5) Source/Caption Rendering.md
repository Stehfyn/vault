# Caption Rendering (caption.c)

`caption.c` in win32k handles `WM_NCPAINT` for the title bar area: computing height from `SM_CYFRAME` + `SM_CYCAPTION`, drawing buttons, and hit-testing with `HTCAPTION`. Custom-frame apps intercept `WM_NCCALCSIZE` and `WM_NCHITTEST` to replace this entirely.

```cpp
// Intercept non-client messages to implement a custom title bar
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  if (msg == WM_NCCALCSIZE) return 0;            // shrink NC area to zero
  if (msg == WM_NCHITTEST)  return HTCAPTION;    // whole client is draggable
  return DefWindowProcW(hwnd, msg, wParam, lParam);
}
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/caption.c#L1011
