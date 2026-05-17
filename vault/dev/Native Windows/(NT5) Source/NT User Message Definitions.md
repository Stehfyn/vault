# NT User Message Definitions

The internal ntuser messages.h defines private message ranges used between user32 and win32k. WM_USER + ranges are carefully partitioned so app-defined messages don't collide with internal notifications.

```cpp
// WM_APP is the safe base for app messages; WM_USER is control-internal
constexpr UINT WM_APP_PING = WM_APP + 1;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  if (msg == WM_APP_PING) { SetWindowTextW(hwnd, L"Pong"); return 0; }
  return DefWindowProcW(hwnd, msg, wParam, lParam);
}
```

## References
- https://github.com/tongzx/nt5src/blob/master/Source/XPSP1/NT/windows/core/ntuser/inc/messages.h
