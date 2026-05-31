# win32-ldpreload — AppInit_DLLs Preload Demo

This repo demonstrates the closest old Windows analogue to `LD_PRELOAD`: configure `AppInit_DLLs` under `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows` so `user32.dll` loads a listed DLL into GUI processes. The limitations are the lesson. It only reaches processes that load User32, is gated by `LoadAppInit_DLLs`, is constrained by `RequireSignedAppInit_DLLs` and Secure Boot-era signing behavior, and is frequently neutralized by modern code-integrity and application-control policy.

That makes AppInit useful for studying legacy injection and compatibility shims, not for new instrumentation. Modern choices are usually supported extension points, ETW, Detours-style explicit injection, accessibility/UI Automation hooks, or process-specific plugin APIs. Registry preload is global, noisy, and security-hostile.

## Connections
- `AccessMask Decoder` and `RegStr.h` help when auditing the HKLM key and its permissions.
- `DLL Build Config` and `CRT Linkage (MD MT DLL)` matter because a preloaded DLL brings its loader, CRT, and dependency choices into every target process.

## Discussion Claim To Verify

Claim implied by the repo name: `AppInit_DLLs` is Windows `LD_PRELOAD`.

Why it matters: that claim is only directionally useful. AppInit is a legacy USER32 load hook, so treating it as universal preload leads to broken instrumentation and unsafe global side effects.

Verification route:

```powershell
reg query "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows" /v AppInit_DLLs
reg query "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows" /v LoadAppInit_DLLs
reg query "HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows" /v RequireSignedAppInit_DLLs

dumpbin /imports .\target.exe | findstr /i user32.dll
```

Benign probe DLL shape:

```cpp
BOOL APIENTRY DllMain(HMODULE module, DWORD reason, void*) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module);
        OutputDebugStringW(L"appinit_probe attached\n");
    }
    return TRUE;
}
```

Observe with ProcMon:

```text
Operation: Load Image
Path: appinit_probe.dll
Process Name: target GUI process
```

Interpretation:
- Target imports/loads USER32 and the DLL appears in ProcMon: the AppInit route is active for that process class.
- Console/service process never loads USER32: the source does not support a general preload claim.
- `RequireSignedAppInit_DLLs`, Secure Boot, WDAC, AppContainer, PPL, or protected processes block the load: the repo demonstrates a legacy mechanism, not a modern instrumentation substrate.

## References
- <https://github.com/sengelha/win32-ldpreload>
