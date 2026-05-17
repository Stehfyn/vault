# System Command Processing (syscmd.c)

`syscmd.c` in win32k routes `WM_SYSCOMMAND` messages to internal handlers for `SC_MINIMIZE`, `SC_MAXIMIZE`, `SC_CLOSE`, `SC_MOVE`, `SC_SIZE`, and others. The low 4 bits of `wParam` carry mouse position info and should be masked off before comparing.

```cpp
case WM_SYSCOMMAND:
  switch (wParam & 0xFFF0) {
    case SC_CLOSE:
      DestroyWindow(hwnd);
      return 0;
    case SC_MINIMIZE:
      ShowWindow(hwnd, SW_MINIMIZE);
      return 0;
    case SC_MAXIMIZE:
      ShowWindow(hwnd, SW_MAXIMIZE);
      return 0;
  }
  break;
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/syscmd.c
