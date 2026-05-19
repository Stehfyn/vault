# AppX Package API

The AppX packaging APIs in `appxpackaging.h` are COM interfaces for inspecting and building AppX/MSIX packages: package readers, manifest readers, block maps, encrypted-package variants, and bundle support. They matter when a tool needs package structure rather than installation behavior; deployment, registration, and user entitlement are handled elsewhere.

The key distinction is that an AppX/MSIX package is a signed ZIP-like payload with manifest and block-map contracts. The packaging API can validate and enumerate that payload, while `PackageManager`, MSIX deployment, and PSF shims decide how desktop apps behave once installed.

## Connections
- `msix-packaging` is the cross-platform SDK cousin of this Windows COM API.
- `MSIX Package Support Framework` handles runtime compatibility after packaging.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/_appxpkg/>
