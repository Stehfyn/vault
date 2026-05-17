# Hook Examples

## EventGhost
EventGhost’s hook implementation spins up dedicated threads and runs a message loop while hooks are active, then tears down hooks on thread exit.  

Short excerpt from `hooks.c` (EventGhost) showing hook setup + message loop:
```c
hMod = LoadLibrary("cFunctions.pyd");
SetKeyboardHook(hMod);
SetMouseHook(hMod);
PeekMessage(&msg, NULL, WM_USER, WM_USER, PM_NOREMOVE);
SetEvent(startupEvent);
while ((bRet = GetMessage(&msg, NULL, 0, 0)) != 0)
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
```

TaskHook.dll also shows `SetWindowsHookEx`/`UnhookWindowsHookEx` usage for CBT/Shell hooks.  

References:
- EventGhost hooks.c (raw)  
  https://raw.githubusercontent.com/EventGhost/EventGhost/177be516849e74970d2e13cda82244be09f277ce/_build/extensions/cFunctions/hooks.c
- EventGhost TaskHook hook.cpp (raw)  
  https://raw.githubusercontent.com/EventGhost/EventGhost/177be516849e74970d2e13cda82244be09f277ce/_build/extensions/TaskHook.dll/hook.cpp

## DxWnd
DxWnd.reloaded contains a broad set of Windows hooking and injection examples for DirectX/window management.  
Reference: https://github.com/DxWnd/DxWnd.reloaded/tree/7235efb7388b25a5dd1192b74df3c4860435ff65

https://github.com/katahiromz/CBTHooker
CBT (Computer-Based Training) hooks fire before window manager events: HCBT_CREATEWND, HCBT_DESTROYWND, HCBT_ACTIVATE, HCBT_MINMAX. They run synchronously in the thread that triggered the event and can cancel creation or modify parameters.
```cpp
// CBT hook to intercept window creation
HHOOK g_hCbt = nullptr;

LRESULT CALLBACK CbtProc(int code, WPARAM wParam, LPARAM lParam) {
  if (code == HCBT_CREATEWND) {
    CBT_CREATEWNDW* cw = (CBT_CREATEWNDW*)lParam;
    // Inspect or modify cw->lpcs->style before the window exists
    if (cw->lpcs->style & WS_POPUP)
      cw->lpcs->x = 100;   // reposition popup
  }
  if (code == HCBT_ACTIVATE) {
    // wParam = HWND being activated
    HWND hwndActivating = (HWND)wParam;
    OutputDebugStringW(L"Window activated");
  }
  return CallNextHookEx(g_hCbt, code, wParam, lParam);
}

g_hCbt = SetWindowsHookExW(WH_CBT, CbtProc, nullptr, GetCurrentThreadId());
// ... later:
UnhookWindowsHookEx(g_hCbt);
```

https://github.com/decafcode/capnhook
Capnhook is a Win32 API hooking framework using IAT or inline patching. The pattern: resolve the target function, overwrite its first bytes with a JMP to a trampoline, save the original bytes for the trampoline.
```cpp
// Minimal inline hook concept (x64 — 14 bytes for absolute JMP)
#pragma pack(push, 1)
struct JmpAbsolute { uint16_t jmpOp; uint32_t rip; uint64_t target; uint8_t ffE0; };
#pragma pack(pop)
// Actual implementation requires VirtualProtect + FlushInstructionCache
void* orig = GetProcAddress(GetModuleHandleA("user32.dll"), "MessageBoxW");
DWORD old;
VirtualProtect(orig, 14, PAGE_EXECUTE_READWRITE, &old);
// Write JMP [RIP+0] / target addr
VirtualProtect(orig, 14, old, &old);
FlushInstructionCache(GetCurrentProcess(), orig, 14);
```

https://github.com/AzureGreen/InjectCollection
DLL injection collection covering CreateRemoteThread, NtCreateThreadEx, APC queue injection, and manual map. Each technique has different detection signatures and privilege requirements.
```cpp
// Classic CreateRemoteThread DLL injection
HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetPid);
SIZE_T sz = (wcslen(dllPath) + 1) * sizeof(wchar_t);
LPVOID remote = VirtualAllocEx(hProcess, nullptr, sz, MEM_COMMIT, PAGE_READWRITE);
WriteProcessMemory(hProcess, remote, dllPath, sz, nullptr);
HANDLE hThread = CreateRemoteThread(hProcess, nullptr, 0,
    (LPTHREAD_START_ROUTINE)GetProcAddress(
        GetModuleHandleA("kernel32.dll"), "LoadLibraryW"),
    remote, 0, nullptr);
WaitForSingleObject(hThread, 5000);
VirtualFreeEx(hProcess, remote, 0, MEM_RELEASE);
CloseHandle(hThread);
CloseHandle(hProcess);
```
