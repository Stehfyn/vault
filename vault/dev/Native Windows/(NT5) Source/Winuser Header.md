# Winuser Header (public SDK)

The public `winuser.h` in the XP source tree defines `RegisterClassExW`, `CreateWindowW`, all `WM_*` constants, and the macros that compose `LPARAM` arguments. This is the canonical user32 API surface documented in the Windows SDK.

```cpp
// Minimal window class + creation from winuser.h primitives
WNDCLASSEXW wc = { sizeof(wc) };
wc.lpfnWndProc   = WndProc;
wc.hInstance     = hInst;
wc.hCursor       = LoadCursorW(nullptr, IDC_ARROW);
wc.lpszClassName = L"MyWin32Class";
RegisterClassExW(&wc);
HWND hwnd = CreateWindowW(wc.lpszClassName, L"Win32",
    WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
    400, 300, nullptr, nullptr, hInst, nullptr);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/public/sdk/inc/winuser.h#L11456C1-L11456C62
- https://github.com/wine-mirror/wine/blob/master/include/winuser.h
