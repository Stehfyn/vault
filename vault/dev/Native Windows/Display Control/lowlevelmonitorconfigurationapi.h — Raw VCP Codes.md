# lowlevelmonitorconfigurationapi.h - Raw VCP Codes

`lowlevelmonitorconfigurationapi.h` is the direct MCCS/DDC-CI path: `GetVCPFeatureAndVCPFeatureReply`, `SetVCPFeature`, save/restore settings, and raw capability probing. VCP `0x10` is brightness, `0x12` contrast, and `0x60` input source, but the valid set is monitor-specific and should be discovered or guarded by a capability check. A successful call only means the monitor accepted the command; it does not guarantee the panel visibly changed.

Prefer the high-level API for brightness/contrast when it exists, then drop to raw VCP for input switching, audio volume, power mode, or vendor-specific controls. Expect latency. DDC/CI is a slow sideband protocol, so aggressive sliders should coalesce writes instead of sending a command for every mouse move.

## Connections
- `highlevelmonitorconfigurationapi.h - DDC/CI Helpers` wraps common VCP operations.
- `physicalmonitorenumerationapi.h - Per-Monitor Handles` owns handle discovery and cleanup.
