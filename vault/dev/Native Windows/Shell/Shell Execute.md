# Shell Execute

`ShellExecute` is not "CreateProcess with a shorter name." It asks the shell to resolve a verb against a thing: executable, document, URL, folder, protocol, or registered file type. That resolution can cross App Paths, file associations, elevation broker UI, URL protocol handlers, AppX activation, and Explorer's current policy state. Use `CreateProcessW` when you already know the executable; use `ShellExecuteExW` when the shell owns the verb.

## Process-handle launch
Link: https://learn.microsoft.com/en-us/windows/win32/api/shellapi/ns-shellapi-shellexecuteinfoa

Contribution: `SHELLEXECUTEINFO` is the only shell-launch path that can return a process handle (`SEE_MASK_NOCLOSEPROCESS`). This matters for installers/updaters and file-association launchers that need shell semantics but still need to wait for completion.

```cpp
SHELLEXECUTEINFOW sei = { sizeof(sei) };
sei.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;
sei.lpVerb = L"open";
sei.lpFile = L"notepad.exe";
sei.nShow = SW_SHOWNORMAL;

if (ShellExecuteExW(&sei) && sei.hProcess) {
    WaitForSingleObject(sei.hProcess, INFINITE);
    CloseHandle(sei.hProcess);
}
```

## Verb resolution and elevation
Link: https://learn.microsoft.com/en-us/windows/win32/shell/launch

Contribution: the launch guide is useful because it names the shell's verb model. `runas` is not a command-line switch; it is a shell verb that routes through UAC/elevation policy. The return value from `ShellExecuteW` is an overloaded `HINSTANCE`; values `<= 32` are errors, not handles.

```cpp
HINSTANCE h = ShellExecuteW(
    hwnd,
    L"runas",
    L"cmd.exe",
    L"/c whoami /groups",
    nullptr,
    SW_SHOWNORMAL);

if ((INT_PTR)h <= 32) {
    DWORD shell_error = (DWORD)(INT_PTR)h;
}
```

Connections: `ShellExecute and File Operations.md` covers older shell-file APIs; `Shell Shortcuts.md` covers persisted launch metadata; `Windows Explorer Integration.md` covers shell namespace/dialog integration when the target is not simply a process.

## Experiment Harness

Goal: separate shell verb resolution from process creation.

```cpp
SHELLEXECUTEINFOW sei{ sizeof(sei) };
sei.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;
sei.lpVerb = L"open";
sei.lpFile = L"https://example.com/";
sei.nShow = SW_SHOWNORMAL;

BOOL ok = ShellExecuteExW(&sei);
DWORD exitCode = 0;
if (ok && sei.hProcess) {
    WaitForInputIdle(sei.hProcess, 5000);
    GetExitCodeProcess(sei.hProcess, &exitCode);
    CloseHandle(sei.hProcess);
}
wprintf(L"ok=%d hProcess=%p exit=%lu gle=%lu\n", ok, sei.hProcess, exitCode, GetLastError());
```

Procedure: run against `.txt`, `.html`, URL, folder, and `runas`; record whether a process handle exists and whether UAC/UI appears.

Measured signal: `BOOL`, `GetLastError`, `hProcess`, exit code, associated app launched.

Failure interpretation: no process handle can be normal for brokered/protocol/app activation; `ShellExecuteEx` answers "did the shell accept the verb?", not "did a child process behave like `CreateProcessW`." Reference: <https://learn.microsoft.com/en-us/windows/desktop/api/shellapi/ns-shellapi-shellexecuteinfoa>.
