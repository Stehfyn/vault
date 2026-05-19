# minappmodel.h

The "minimal" cut of `appmodel.h` -- the subset of Modern App Model APIs available from `api-ms-win-appmodel-runtime-l1-1-0`, suitable for code that must run on SKUs without the full packaging stack (Server Core, Nano, OneCore). Exposes the core `PackageFullName` / `PackageFamilyName` / `ApplicationUserModelId` getters: `GetCurrentPackageFullName`, `GetCurrentPackageFamilyName`, `GetCurrentApplicationUserModelId`, `GetPackagePathByFullName`. Returns `APPMODEL_ERROR_NO_PACKAGE` (15700) when the caller is an unpackaged desktop EXE -- the canonical way to detect "am I running inside an MSIX/AppX container?". Cluster: `appmodel.h` (full surface incl. dependency / publisher APIs), `appxpackaging.h` (packaging COM), `minwinbase.h` (the wider minwin philosophy).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/appmodel/>
