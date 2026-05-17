A dedicated message-pump thread must call `PeekMessage` first to force the OS to create a thread message queue, then signal the main thread before entering its `GetMessage` loop. Using `MsgWaitForMultipleObjects` lets the pump also wait on kernel objects while remaining message-responsive.

```cpp
// Thread function: force queue creation, signal ready, then pump
DWORD WINAPI MsgThreadProc(LPVOID param)
{
    HANDLE hReady = static_cast<HANDLE>(param);

    // Force the system to create this thread's message queue
    MSG msg;
    PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);

    // Signal the creating thread that the queue is ready
    SetEvent(hReady);

    // Standard message loop
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

// Combine with kernel-object waits:
HANDLE hObjects[] = { hWorkItem };
while (true)
{
    DWORD dw = MsgWaitForMultipleObjects(1, hObjects, FALSE, INFINITE, QS_ALLINPUT);
    if (dw == WAIT_OBJECT_0)
        ; // handle hWorkItem
    else if (dw == WAIT_OBJECT_0 + 1)
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
}
```

## References
- https://stackoverflow.com/questions/39895561/winapi-i-would-like-to-have-the-message-pump-ongoing-in-a-separate-thread/39909192#39909192
