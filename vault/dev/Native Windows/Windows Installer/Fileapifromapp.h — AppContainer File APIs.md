# Fileapifromapp.h — AppContainer File APIs

`Fileapifromapp.h` declares file APIs that packaged apps can call from AppContainer/MSIX contexts, including `CreateFile2FromAppW` and related delete/copy/move variants. The suffix is the point: these APIs enforce the packaged app capability and broker rules instead of pretending the process has unrestricted Win32 file access.

For desktop-bridge and MSIX conversions, failures here usually expose an application assumption about writable install directories, current working directories, or arbitrary user-profile traversal. Do not paper over all of that with shims until you know which path should be package-relative, user-data-relative, or capability-gated.

## Connections
- `MSIX Package Support Framework` often intercepts file APIs when legacy apps violate these packaged-app rules.
- `AppX Package API` and `msix-packaging` describe the package structure that determines the app's identity and capabilities.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/>
