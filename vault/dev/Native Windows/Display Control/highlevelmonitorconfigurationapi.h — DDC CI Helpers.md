# highlevelmonitorconfigurationapi.h - DDC/CI Helpers

`highlevelmonitorconfigurationapi.h` exposes the friendly layer over MCCS/DDC-CI: brightness, contrast, color temperature, factory defaults, and capability queries. The functions take `PHYSICAL_MONITOR.hPhysicalMonitor`, so the real entry point is still `physicalmonitorenumerationapi.h`; passing an `HMONITOR` is the common conceptual mistake. Handles are scarce kernel resources and must be released with `DestroyPhysicalMonitor` or `DestroyPhysicalMonitors`.

The high-level calls are convenient but not universal. Many internal laptop panels are controlled through vendor ACPI/WMI paths rather than DDC/CI, and some external monitors lie about supported capabilities or time out under rapid polling. For robust UI, cache capability strings, rate-limit writes, and fall back to `lowlevelmonitorconfigurationapi.h` VCP commands only when the high-level helper does not expose the control you need.

## Connections
- `physicalmonitorenumerationapi.h - Per-Monitor Handles` supplies the required handles.
- `lowlevelmonitorconfigurationapi.h - Raw VCP Codes` is the escape hatch for unsupported high-level controls.
