# WOW Message Dispatching

WOW (Windows-on-Windows) compatibility code in ntuser client marshals old-format Win16/WOW messages into the standard Win32 message structure. The translation happens transparently as the message is dispatched through the queue.

```cpp
// Seeing a WOW-aware dispatch in action: SendMessage ends up calling the
// WOW stub which re-packs the message before reaching the client wndproc
HWND hwnd = CreateWindowW(L"STATIC", L"Demo", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 240, 80, nullptr, nullptr, hInst, nullptr);
SendMessageW(hwnd, WM_SETTEXT, 0, (LPARAM)L"Wow message");
ShowWindow(hwnd, SW_SHOW);
UpdateWindow(hwnd);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/client/wow.c#L763
