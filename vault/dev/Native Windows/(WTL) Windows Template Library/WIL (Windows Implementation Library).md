# WIL (Windows Implementation Library)

WIL is Microsoft's header-only C++ library for making ordinary Windows API code survivable. It is not a UI framework. Its core contribution is resource and error discipline: `wil::unique_handle`, `wil::unique_hkey`, `wil::com_ptr`, `unique_cotaskmem_string`, scope-exit helpers, registry wrappers, and the `THROW_IF_FAILED` / `RETURN_IF_FAILED` / `LOG_IF_FAILED` families that standardize HRESULT and last-error handling.

Place it near COM, WTL, Win32xx, and sktoolslib. WTL/Win32xx wrap windows; WIL wraps the failure-prone substrate underneath them. The practical rule is simple: modern C++ Win32 code should have a reason not to use WIL for lifetime and error paths, especially around COM, handles, registry, and cleanup-on-failure code.

## Source Shape

Source pass: `microsoft/wil/include/wil/com.h`, `resource.h`, and `registry.h` exposes the pattern: make ownership explicit at the variable type and let failure macros preserve the HRESULT/last-error route. This is why Explorer++ source reads as shell code instead of cleanup code.

```cpp
wil::com_ptr<IFileOpenDialog> dlg;
RETURN_IF_FAILED(CoCreateInstance(CLSID_FileOpenDialog, nullptr,
    CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dlg)));

wil::unique_cotaskmem_string path;
RETURN_IF_FAILED(item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &path));

wil::unique_handle process(OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid));
RETURN_LAST_ERROR_IF_NULL(process);
```

## Connections

- `../Shell/Explorer++ (Tabbed Win32 Explorer).md` is a strong real-world consumer of `wil::com_ptr_nothrow`, `unique_hmenu`, `unique_cotaskmem_string`, and `RETURN_IF_FAILED`.
- `../(COM) Component Object Model/COM in plain C.md` explains the ABI that `wil::com_ptr` manages.
- `sktoolslib - Stefan Kueng Win32 Utility Library.md` is a production utility-library comparison: WIL is general substrate hygiene; sktoolslib is application-maintainer utility code.

## Experiment Harness

Goal: prove cleanup-on-failure paths are real, not style preferences.

```cpp
auto probe = []() -> HRESULT {
    wil::unique_handle file(CreateFileW(L"Z:\\missing\\x.txt", GENERIC_READ, 0,
        nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr));
    RETURN_LAST_ERROR_IF_NULL(file);

    wil::com_ptr<IFileOpenDialog> dlg;
    RETURN_IF_FAILED(CoCreateInstance(CLSID_FileOpenDialog, nullptr,
        CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dlg)));
    return S_OK;
};
printf("probe=%08lx\n", probe());
```

Measured signal: returned HRESULT, destructor/log callback count, handle count before/after via Process Explorer or `GetProcessHandleCount`.

Failure interpretation: if handle count grows during failure injection, the code has ownership bugs that WIL types should make visible. Reference: <https://github.com/microsoft/wil/wiki>.

## References
- <https://github.com/microsoft/wil> - Microsoft-maintained Windows C++ helper library for RAII resources, COM pointers, registry helpers, and error macros.
