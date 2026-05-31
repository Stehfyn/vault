# Fileapifromapp.h — AppContainer File APIs

`Fileapifromapp.h` declares file APIs that packaged apps can call from AppContainer/MSIX contexts, including `CreateFile2FromAppW` and related delete/copy/move variants. The suffix is the point: these APIs enforce the packaged app capability and broker rules instead of pretending the process has unrestricted Win32 file access.

For desktop-bridge and MSIX conversions, failures here usually expose an application assumption about writable install directories, current working directories, or arbitrary user-profile traversal. Do not paper over all of that with shims until you know which path should be package-relative, user-data-relative, or capability-gated.

## Call Shape

The shape mirrors `CreateFile2`; the difference is policy. In a packaged process, success depends on package identity, declared capabilities, brokered locations, and the file namespace being requested.

```c
CREATEFILE2_EXTENDED_PARAMETERS ex = { sizeof(ex) };
HANDLE h = CreateFile2FromAppW(path,
    GENERIC_READ,
    FILE_SHARE_READ | FILE_SHARE_DELETE,
    OPEN_EXISTING,
    &ex);
```

## Experiment Harness

Run the same file probe unpackaged and packaged. Test package install directory, local app data, a picked/user-approved file, and an arbitrary profile path.

```text
for each path:
  CreateFile2FromAppW(path, GENERIC_READ|GENERIC_WRITE, ..., OPEN_ALWAYS, ...)
  log GetLastError(), package identity, and resolved full path
```

Signal: install-directory writes fail, local app-data writes succeed, arbitrary paths depend on capability/brokered access. Failure interpretation: `ERROR_ACCESS_DENIED` in a packaged process is often the expected security model; use PSF only after deciding whether the old write should become local-state, package-relative read-only, or user-mediated access.

## Connections
- `MSIX Package Support Framework` often intercepts file APIs when legacy apps violate these packaged-app rules.
- `AppX Package API` and `msix-packaging` describe the package structure that determines the app's identity and capabilities.
- `DLL Build Config` matters for PSF/fixup DLLs loaded into packaged Win32 processes.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/>
- <https://learn.microsoft.com/en-us/windows/win32/api/fileapifromapp/nf-fileapifromapp-createfile2fromappw>
