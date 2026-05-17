# System-Defined Messages

System-defined messages (for example, WM_PAINT and WM_CHAR) are delivered to a window procedure via the message loop.

## Snippet
```cpp
MSG msg{};
while (true)
{
    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
    {
        if (msg.message == WM_QUIT)
            return 0;

        TranslateMessage(&msg); // generates WM_CHAR from key input
        DispatchMessage(&msg);
    }

    // Idle work here
}
```

## References
- https://learn.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues#system-defined-messages
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms711436(v=vs.85)
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms705252(v=vs.85)
