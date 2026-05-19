# infstr.h

String / token constants that appear inside Windows INF setup files (the `.inf` driver-package format consumed by `SetupAPI`, `pnputil`, `DriverStore`). Numeric `DIRID_*` codes (`DIRID_SYSTEM = 11`, `DIRID_DRIVERS = 12`, `DIRID_INF = 17`, `DIRID_PROGRAM_FILES = 16422`, ...) get substituted into `[DestinationDirs]` to name well-known paths; section-name literals (`INFSTR_SECT_VERSION`, `INFSTR_SECT_MFG`, `INFSTR_SECT_SOURCEDISKSNAMES`) match exactly what the INF parser scans for. The header is included almost exclusively by tools that author or analyze INFs -- `pnputil`, `devcon`, OEM packaging build chains, third-party driver installers -- and never by application code.

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/install/inf-files>
