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

## Source Code Reading

The linked Windows classic MSI samples are useful less as one canonical program and more as a table-surface map. Read them by API family:
- install/configure: `MsiInstallProductW`, `MsiConfigureProductEx`, public property strings.
- database query: `MsiOpenDatabase`, `MsiDatabaseOpenView`, `MsiViewExecute`, `MsiViewFetch`, `MsiRecordGetString`.
- product inventory: `MsiEnumProductsEx`, `MsiGetProductInfo`, feature/component APIs.
- custom action boundary: `MSIHANDLE` enters the DLL export; session data is retrieved through MSI APIs, not global process state.

Useful skeleton for any MSI table sample:

```cpp
MSIHANDLE db = 0, view = 0, rec = 0;
MsiOpenDatabaseW(path, MSIDBOPEN_READONLY, &db);
MsiDatabaseOpenViewW(db, L"SELECT `Property`,`Value` FROM `Property`", &view);
MsiViewExecute(view, 0);
while (MsiViewFetch(view, &rec) == ERROR_SUCCESS) {
    // MsiRecordGetStringW(rec, 1/2, ...)
    MsiCloseHandle(rec);
}
MsiCloseHandle(view);
MsiCloseHandle(db);
```

Steps to make a sample prove something:
1. Build both a database-reader EXE and a custom-action DLL.
2. Use the EXE to inspect the MSI before install.
3. Use verbose logging during install: `msiexec /i sample.msi /l*v sample.log`.
4. Compare table values, log properties, and custom-action inputs. If they disagree, the bug is sequencing, property privacy, bitness, or deferred-action data marshalling.

## References
- https://github.com/microsoft/Windows-classic-samples/tree/1d363ff4bd17d8e20415b92e2ee989d615cc0d91/Samples/Win7Samples/sysmgmt/msi
