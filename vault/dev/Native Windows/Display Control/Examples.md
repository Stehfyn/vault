# Display Control Examples

Display topology work splits into two unrelated API families. `QueryDisplayConfig` / `SetDisplayConfig` describe logical paths from adapters to targets and are the right tools for clone/extend/internal/external layouts, friendly target names, and mode persistence. `EnumDisplaySettingsEx` / `ChangeDisplaySettingsEx` is the older DEVMODE path; it is still useful for simple resolution changes and for code that must tolerate pre-Vista assumptions, but it does not model modern path topology cleanly. Do not mix the two casually: query the current active paths first, preserve fields you do not understand, and only submit a supplied configuration when you own the full path/mode array.

Monitor control is a separate DDC/CI stack. Start with an `HMONITOR`, call `GetPhysicalMonitorsFromHMONITOR`, and destroy every returned physical handle with `DestroyPhysicalMonitors`; brightness and VCP commands operate on those physical handles, not on `HMONITOR` or display-device names. EDID is yet another path, usually through WMI monitor descriptor methods, and is better treated as identity metadata than as a control channel.

## References
- Microsoft "Enumeration and Display Control": the baseline contract for `GetDisplayConfigBufferSizes`, `QueryDisplayConfig`, `DisplayConfigGetDeviceInfo`, and `SetDisplayConfig` path arrays.
- Raymond Chen, "How do I programmatically change the display configuration?": shows the topology flags (`SDC_TOPOLOGY_INTERNAL`, `CLONE`, `EXTEND`, `EXTERNAL`) that wrap the common cases without hand-building paths.
- Microsoft Display API catalog: useful as the struct index when decoding adapter/target names from `DISPLAYCONFIG_DEVICE_INFO_HEADER`.
- Microsoft Monitor Configuration API catalog: covers the physical-monitor handle lifecycle and high/low-level DDC/CI functions.
- DisplayMagician: a practical example of saving/restoring multi-monitor layouts by collecting topology plus target identity.
- Monitorian: a production brightness controller using the physical monitor APIs, including the ugly cases where monitors reject DDC/CI calls.
- ToggleDisplay: small wrapper around the system display-switch behavior; useful when topology intent matters more than exact mode control.
