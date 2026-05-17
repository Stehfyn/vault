Windows shows an `IDC_APPSTARTING` busy-spinner cursor when a process is launched and removes it once the application begins pumping messages. To suppress the feedback cursor, pass `STARTF_FORCEOFFFEEDBACK` in `STARTUPINFO.dwFlags`, or call `PeekMessage` early to satisfy `WaitForInputIdle`.

```cpp
// Option A: suppress feedback cursor at launch (set by parent/launcher process)
STARTUPINFOW si = { sizeof(si) };
si.dwFlags = STARTF_FORCEOFFFEEDBACK;   // no busy spinner on child process
PROCESS_INFORMATION pi{};
CreateProcessW(L"myapp.exe", nullptr, nullptr, nullptr,
               FALSE, 0, nullptr, nullptr, &si, &pi);

// Option B: show wait cursor during heavy init, then restore
HCURSOR hPrev = SetCursor(LoadCursor(NULL, IDC_WAIT));
// ... long initialisation work ...
SetCursor(hPrev);

// Option C: dismiss feedback cursor by entering message loop early
// (OS removes it automatically once GetMessage/PeekMessage is first called)
MSG msg;
PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE); // triggers WaitForInputIdle completion
```

## References
- https://stackoverflow.com/questions/75087602/duration-of-the-busy-cursor-when-launching-a-windows-desktop-application
- https://github.com/myfreeer/nop
