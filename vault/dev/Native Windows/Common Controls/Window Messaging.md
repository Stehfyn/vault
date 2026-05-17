# Window Messaging

## COPYDATASTRUCT definition
https://learn.microsoft.com/en-us/windows/win32/api/Winuser/ns-winuser-copydatastruct
Package a payload for WM_COPYDATA with a type tag and byte count.
```cpp
COPYDATASTRUCT cds = {};
cds.dwData = 100;
cds.cbData = (DWORD)((wcslen(text) + 1) * sizeof(wchar_t));
cds.lpData = (PVOID)text;
SendMessage(hwndTarget, WM_COPYDATA, (WPARAM)hwndSelf, (LPARAM)&cds);
```

## WM_COPYDATA handling
https://learn.microsoft.com/en-us/windows/win32/dataxchg/wm-copydata
Handle the message and copy the data before returning.
```cpp
case WM_COPYDATA:
{
    const COPYDATASTRUCT* cds = (const COPYDATASTRUCT*)lParam;
    if (cds->lpData && cds->cbData)
        OutputDebugStringW((const wchar_t*)cds->lpData);
    return TRUE;
}
```

https://learn.microsoft.com/en-us/windows/win32/winmsg/messages-and-message-queues
The message queue is per-thread. GetMessage blocks; PeekMessage does not. Use PeekMessage in game/render loops to avoid stalling the thread.
```cpp
// Non-blocking render loop with message draining
MSG msg = {};
while (running) {
  while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
    if (msg.message == WM_QUIT) { running = false; break; }
    TranslateMessage(&msg);
    DispatchMessageW(&msg);
  }
  if (running) RenderFrame();
}
```

https://devblogs.microsoft.com/oldnewthing/20110516-00/?p=10663
Raymond Chen's Old New Thing posts explain subtle Win32 dispatch behaviors. PostMessage is asynchronous and returns immediately; the message may arrive well after the function returns.
```cpp
// PostMessage to self — processed next pump iteration
PostMessageW(hwnd, WM_APP + 5, (WPARAM)someData, 0);
// Always drain the queue before waiting
while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
  TranslateMessage(&msg);
  DispatchMessageW(&msg);
}
WaitForSingleObject(hEvent, INFINITE);
```
