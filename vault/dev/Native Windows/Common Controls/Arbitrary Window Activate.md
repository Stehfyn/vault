To reliably bring another process's window to the foreground, inject a DLL via `SetWindowsHookEx(WH_CBT)` into the target process's thread so that `SetForegroundWindow` executes from within that process context, bypassing Windows' foreground lock. Also restore minimized windows and force a redraw to prevent blank frames.

```cpp
// --- In the injected DLL (runs inside target process) ---

extern "C" __declspec(dllexport) void activateWindow(HWND hwnd) {
    if (IsIconic(hwnd))
        SendMessage(hwnd, WM_SYSCOMMAND, SC_RESTORE, 0);

    SetForegroundWindow(hwnd);
    SetActiveWindow(hwnd);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0,
                 SWP_SHOWWINDOW | SWP_NOMOVE | SWP_NOSIZE);

    // Prevent blank window after activation
    RedrawWindow(hwnd, NULL, 0, RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
}

// Called from the host process to inject and activate
extern "C" __declspec(dllexport) BOOL CALLBACK SetHook(HWND hwnd) {
    hWndTarget  = hwnd;
    hGetMsgHook = SetWindowsHookExA(WH_CBT, (HOOKPROC)GetMsgProc, hInst, 0);
    if (!hGetMsgHook) return FALSE;
    activateWindow(hwnd);  // immediate attempt; hook provides the real injection
    return TRUE;
}

// WH_CBT hook: once the DLL is in the target process, subclass and unhook
LRESULT CALLBACK GetMsgProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && (HWND)wParam == hWndTarget) {
        SetWindowSubclass(hWndTarget, SubclassProc, 0, 0);
        UnhookWindowsHookEx(hGetMsgHook);  // remove hook to avoid OS lag
    }
    return CallNextHookEx(hGetMsgHook, nCode, wParam, lParam);
}
```

## References
- https://github.com/jredfox/EConHostProc/blob/e0b34e8fe9a05028201904bb5ab533a3e2b08b59/src/DLLMain.cpp#L44
