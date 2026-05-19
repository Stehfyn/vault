# physicalmonitorenumerationapi.h - Per-Monitor Handles

The physical monitor API bridges USER's logical `HMONITOR` to DDC/CI handles. `GetNumberOfPhysicalMonitorsFromHMONITOR` tells you how many physical panels are represented by a monitor handle, and `GetPhysicalMonitorsFromHMONITOR` returns `PHYSICAL_MONITOR` records with a human-readable description plus an opaque handle used by the high- and low-level monitor configuration APIs.

The cleanup rule is the point of this header: every physical handle must be destroyed, even if later brightness or VCP calls fail. Also do not assume one `HMONITOR` maps to one physical panel forever; mirroring, docking, virtual displays, MST hubs, and driver bugs can all make identity unstable. For persistent identity, combine this layer with DisplayConfig target names or EDID metadata.

## Connections
- `highlevelmonitorconfigurationapi.h - DDC/CI Helpers` and `lowlevelmonitorconfigurationapi.h - Raw VCP Codes` both consume these handles.
- `Examples.md` notes how to pair monitor handles with DisplayConfig target identity.
