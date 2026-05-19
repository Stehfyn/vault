# win32-ldpreload — AppInit_DLLs Preload Demo

This repo demonstrates the closest old Windows analogue to `LD_PRELOAD`: configure `AppInit_DLLs` under `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Windows` so `user32.dll` loads a listed DLL into GUI processes. The limitations are the lesson. It only reaches processes that load User32, is gated by `LoadAppInit_DLLs`, is constrained by `RequireSignedAppInit_DLLs` and Secure Boot-era signing behavior, and is frequently neutralized by modern code-integrity and application-control policy.

That makes AppInit useful for studying legacy injection and compatibility shims, not for new instrumentation. Modern choices are usually supported extension points, ETW, Detours-style explicit injection, accessibility/UI Automation hooks, or process-specific plugin APIs. Registry preload is global, noisy, and security-hostile.

## Connections
- `AccessMask Decoder` and `RegStr.h` help when auditing the HKLM key and its permissions.
- `DLL Build Config` and `CRT Linkage (MD MT DLL)` matter because a preloaded DLL brings its loader, CRT, and dependency choices into every target process.

## References
- <https://github.com/sengelha/win32-ldpreload>
