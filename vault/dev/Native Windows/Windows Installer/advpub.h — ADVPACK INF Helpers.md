# advpub.h — ADVPACK INF Installer Helpers

`advpub.h` is the header for ADVPACK setup helpers such as `RegInstall`, `RunSetupCommand`, and related INF-era publishing utilities. It sits between raw registry/file writes and a real installer engine: useful for legacy components that ship INF sections or self-registration scripts, but without MSI's component accounting.

The important maintenance signal is provenance. If code uses ADVPACK, expect Internet Explorer-era setup assumptions, process-global side effects, and weak rollback semantics. Audit elevation, quoting, and working-directory behavior carefully when `RunSetupCommand` is involved.

## Connections
- `Registry Setup (RegInstallW)` is the concrete registry helper from this header.
- `SetupAPI.h` is the more durable INF/device-install neighbor.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/advpub/>
