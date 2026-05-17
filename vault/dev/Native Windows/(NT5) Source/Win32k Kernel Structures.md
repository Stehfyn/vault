# Win32k Kernel Structures (userk.h)

The kernel-mode `userk.h` defines the internal WND, THREADINFO, and related structures that back every visible window. Fields like `style`, `exStyle`, `windowRect`, and `clientRect` are accessible from user mode via `GetWindowLongPtr` and `GetWindowRect` but live here in kernel space.

```cpp
// Kernel window style flags are mirrored to user mode via GetWindowLongPtr
LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_STYLE);
style |= WS_MINIMIZEBOX;
SetWindowLongPtrW(hwnd, GWL_STYLE, style);
// FRAMECHANGED forces DWM/user32 to re-query the NC metrics
SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
    SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/userk.h#L3580
