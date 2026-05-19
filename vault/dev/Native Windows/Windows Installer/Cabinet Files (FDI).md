# Cabinet Files (FDI)

FDI is the decompression half of Microsoft's Cabinet API. It can recognize cabinets, enumerate folders/files inside them, and call back into caller-supplied I/O and allocation routines while extracting. That callback model is the important bit: FDI is old C infrastructure designed to fit setup engines, not a modern archive library with path-safety defaults.

Cabinet files still show up in MSI payloads, driver packages, Windows Update plumbing, and legacy setup media. Treat extraction paths, spanning cabinets, and callback error handling as part of the trust boundary.

## Connections
- `Msi.h` and `MsiQuery.h` often encounter CAB streams embedded in MSI databases.
- `SetupAPI.h` consumes driver packages where INF files and CAB-compressed payloads commonly meet.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/fdi/ns-fdi-fdicabinetinfo>
