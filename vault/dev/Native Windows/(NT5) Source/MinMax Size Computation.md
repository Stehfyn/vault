# MinMax Size Computation (minmax.c)

`minmax.c` in win32k computes the constrained window size during resize. It clamps `ptMinTrackSize` / `ptMaxTrackSize` in the `MINMAXINFO` structure. Apps respond to `WM_GETMINMAXINFO` to override the defaults before this clamping occurs.

```cpp
case WM_GETMINMAXINFO: {
  MINMAXINFO* mmi = (MINMAXINFO*)lParam;
  mmi->ptMinTrackSize.x = 320;
  mmi->ptMinTrackSize.y = 200;
  // ptMaxTrackSize defaults to screen dimensions
  return 0;
}
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/minmax.c
