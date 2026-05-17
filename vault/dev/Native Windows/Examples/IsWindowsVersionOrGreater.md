# IsWindowsVersionOrGreater

Use `RtlGetVersion` for an accurate OS version check (not affected by application manifesting).

```cpp
#include <windows.h>
#include <winternl.h>

bool IsWindowsVersionOrGreater(DWORD major, DWORD minor, DWORD build)
{
    HMODULE ntdll = GetModuleHandleW(L"ntdll.dll");
    auto RtlGetVersion =
        reinterpret_cast<decltype(&::RtlGetVersion)>(GetProcAddress(ntdll, "RtlGetVersion"));
    if (!RtlGetVersion) return false;

    OSVERSIONINFOEXW os = {};
    os.dwOSVersionInfoSize = sizeof(os);
    if (RtlGetVersion(&os) != 0) return false;

    if (os.dwMajorVersion != major) return os.dwMajorVersion > major;
    if (os.dwMinorVersion != minor) return os.dwMinorVersion > minor;
    return os.dwBuildNumber >= build;
}
```

## References
- https://github.com/gangelo/GetVerInfo
