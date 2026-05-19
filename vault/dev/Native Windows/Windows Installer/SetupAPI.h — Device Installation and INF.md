# SetupAPI.h — Device Installation and INF Parsing

`SetupAPI.h` is the central user-mode API for device installation, device-interface enumeration, and INF processing. It is where installers meet Plug and Play: class GUIDs, device information sets, interface detail paths, driver packages, co-installers, and registry-backed device properties all flow through this layer.

The biggest trap is treating SetupAPI as a generic file installer. Device install state is machine-global and PnP-owned; INF sections, catalog signing, class installers, architecture decorations, and driver-store behavior determine whether an operation is valid. For non-device application installers, MSI or MSIX is usually the wrong comparison point; SetupAPI solves a different problem.

## Connections
- `infstr.h` provides INF string constants used by setup/device code.
- `Cabinet Files (FDI)` and `LoadPerf.h` are nearby setup-era APIs that also mutate machine-global state.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/setupapi/>
