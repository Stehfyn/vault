# MSI Samples

Windows Installer sample projects covering package installation, querying, and configuration tasks. The snippet below installs an MSI package with a property string.

```cpp
#include <windows.h>
#include <msi.h>
#pragma comment(lib, "msi.lib")

UINT rc = MsiInstallProductW(L"C:\\path\\sample.msi",
                             L"REBOOT=ReallySuppress ALLUSERS=1");
if (rc != ERROR_SUCCESS) {
    // handle error
}
```

## References
- https://github.com/microsoft/Windows-classic-samples/tree/1d363ff4bd17d8e20415b92e2ee989d615cc0d91/Samples/Win7Samples/sysmgmt/msi
