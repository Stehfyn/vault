# Display Control Examples

Display topology work splits into two unrelated API families. `QueryDisplayConfig` / `SetDisplayConfig` describe logical paths from adapters to targets and are the right tools for clone/extend/internal/external layouts, friendly target names, and mode persistence. `EnumDisplaySettingsEx` / `ChangeDisplaySettingsEx` is the older DEVMODE path; it is still useful for simple resolution changes and for code that must tolerate pre-Vista assumptions, but it does not model modern path topology cleanly. Do not mix the two casually: query the current active paths first, preserve fields you do not understand, and only submit a supplied configuration when you own the full path/mode array.

Monitor control is a separate DDC/CI stack. Start with an `HMONITOR`, call `GetPhysicalMonitorsFromHMONITOR`, and destroy every returned physical handle with `DestroyPhysicalMonitors`; brightness and VCP commands operate on those physical handles, not on `HMONITOR` or display-device names. EDID is yet another path, usually through WMI monitor descriptor methods, and is better treated as identity metadata than as a control channel.

## Topology API Shape

DisplayConfig owns logical paths: which adapter source is connected to which target, with what mode and topology. Query first, then either submit a known topology flag or modify a complete path/mode set deliberately.

```cpp
UINT32 path_count = 0;
UINT32 mode_count = 0;
GetDisplayConfigBufferSizes(QDC_ONLY_ACTIVE_PATHS, &path_count, &mode_count);

std::vector<DISPLAYCONFIG_PATH_INFO> paths(path_count);
std::vector<DISPLAYCONFIG_MODE_INFO> modes(mode_count);
QueryDisplayConfig(QDC_ONLY_ACTIVE_PATHS,
    &path_count, paths.data(),
    &mode_count, modes.data(),
    nullptr);

// Common intent wrapper: internal, clone, extend, or external.
SetDisplayConfig(0, nullptr, 0, nullptr,
    SDC_APPLY | SDC_TOPOLOGY_EXTEND);
```

## Physical Monitor API Shape

DDC/CI owns panel controls, not desktop topology. The handle lifecycle is the part to copy exactly: enumerate from an `HMONITOR`, perform the high-level or VCP operation, then destroy every physical handle.

```cpp
DWORD count = 0;
GetNumberOfPhysicalMonitorsFromHMONITOR(hmonitor, &count);

std::vector<PHYSICAL_MONITOR> monitors(count);
GetPhysicalMonitorsFromHMONITOR(hmonitor, count, monitors.data());

for (auto& monitor : monitors) {
    DWORD min_brightness = 0, cur_brightness = 0, max_brightness = 0;
    GetMonitorBrightness(monitor.hPhysicalMonitor,
        &min_brightness, &cur_brightness, &max_brightness);

    SetMonitorBrightness(monitor.hPhysicalMonitor, desired_brightness);
}

DestroyPhysicalMonitors(count, monitors.data());
```

## Connection Routes

- `Virtual-Display-Driver — Virtual Monitor.md` and `IddSampleDriver — Virtual Monitor (Win10).md` create targets that later show up in DisplayConfig.
- `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` chooses adapters/outputs for rendering and capture; DisplayConfig chooses desktop path topology above the driver stack.
- `../(DWM) Desktop Window Manager/VBlank Wait.md` and `../(DX) DirectX/DXGI Output Duplication Capture.md` care which output/source is active; topology changes can invalidate cached output handles.
- `physicalmonitorenumerationapi.h — Per-Monitor Handles.md`, `highlevelmonitorconfigurationapi.h — DDC CI Helpers.md`, and `lowlevelmonitorconfigurationapi.h — Raw VCP Codes.md` are the monitor-control branch, not the topology branch.

## Experiment Harness

Goal: distinguish topology control, output identity, and physical-panel control without bricking the user's layout.

Procedure:
1. Snapshot active paths with `QueryDisplayConfig(QDC_ONLY_ACTIVE_PATHS)` and log source adapter LUID/id, target id, output technology, friendly names, and mode indexes.
2. Run dry intent checks first: call `SetDisplayConfig` with topology flags only when the user explicitly chooses internal/clone/extend/external; otherwise do read-only snapshots.
3. After any topology change, recreate cached DXGI outputs, duplication objects, vblank wait state, and physical monitor handles.
4. Separately enumerate `HMONITOR -> PHYSICAL_MONITOR` and perform a read-only brightness/capability query before any write.

```cpp
QueryDisplayConfig(QDC_ONLY_ACTIVE_PATHS, &pc, paths, &mc, modes, nullptr);
log_paths(paths, modes);
// Only in an explicit restore/apply test:
SetDisplayConfig(0, nullptr, 0, nullptr, SDC_APPLY | SDC_TOPOLOGY_EXTEND);
```

Metric: path count, stable adapter/target identity across reboot/dock/undock, API return codes, time to restore a saved topology, and DDC/CI query/write latency.

Failure interpretation: `ERROR_INSUFFICIENT_BUFFER` means display state changed between buffer sizing and query; retry. `ERROR_ACCESS_DENIED` usually means session/desktop/permission context. A topology change invalidating DXGI capture is expected. DDC/CI timeouts usually mean monitor firmware or transport, not DisplayConfig.

## Source Code Reading

The linked display-driver repos explain why DisplayConfig snapshots matter. `IddSampleDriver/Driver.cpp` and `Virtual-Display-Driver/.../Driver.cpp` create synthetic targets through IDDCX. Once those targets appear, `QueryDisplayConfig` should see them as ordinary active/inactive paths with adapter/source and target identities. `RestartDisplayAdapters/WinMain.c` sits below this layer: it restarts display device nodes with SetupAPI, which can invalidate every cached path, DXGI output, duplication object, vblank source, and physical monitor handle.

Turn the route into a reusable probe:

```cpp
SnapshotDisplayState(tag):
    QueryDisplayConfig(QDC_ALL_PATHS, paths, modes)
    for each path:
        DisplayConfigGetDeviceInfo(GET_SOURCE_NAME)
        DisplayConfigGetDeviceInfo(GET_TARGET_NAME)
        log(adapterId, sourceId, targetId, outputTechnology,
            friendlyName, modeInfoIdx, pathFlags)

AfterTopologyOrDriverChange:
    discard cached IDXGIOutput / duplication / physical monitor handles
    SnapshotDisplayState("after")
    re-enumerate DXGI adapters/outputs and compare LUID/source/target
```

That probe gives every other graphics note a stable identity layer. If Output Duplication starts returning `DXGI_ERROR_ACCESS_LOST` after a virtual monitor is enabled, this note tells you what changed. If DDC/CI brightness writes suddenly target the wrong panel, this note tells you whether physical monitor handles were reused after topology changed.

## Discussion Claim To Verify

Raymond Chen's display-configuration guidance, DisplayMagician-style profile tools, and monitor-brightness apps all imply the same rule: topology, DXGI output identity, and physical monitor handles are related but not interchangeable. Verify that before writing code that restores layouts or controls brightness.

```cpp
struct DisplayJoin {
    LUID adapter_id;
    UINT32 source_id;
    UINT32 target_id;
    wchar_t gdi_device_name[32];
    wchar_t target_friendly_name[128];
    HMONITOR hmonitor;
    DWORD physical_monitor_count;
};

SnapshotDisplayConfig();
SnapshotEnumDisplayMonitors();
SnapshotPhysicalMonitors();
SnapshotDxgiOutputs();
join_by_luid_source_target_and_rect_overlap();
```

Expected interpretation: DisplayConfig path identity should survive ordinary mode queries better than raw rectangles, but docking, virtual displays, driver restarts, and Win+P changes can invalidate cached joins. Physical monitor handles must be destroyed and reacquired after topology changes. If a brightness app writes the wrong panel after display rearrangement, the likely bug is stale physical handles or rectangle-only matching, not DDC/CI itself.

## References
- Microsoft "Enumeration and Display Control": the baseline contract for `GetDisplayConfigBufferSizes`, `QueryDisplayConfig`, `DisplayConfigGetDeviceInfo`, and `SetDisplayConfig` path arrays.
- <https://learn.microsoft.com/en-us/windows/win32/gdi/enumeration-and-display-control> - Microsoft guide for active display paths and display configuration.
- Raymond Chen, "How do I programmatically change the display configuration?": shows the topology flags (`SDC_TOPOLOGY_INTERNAL`, `CLONE`, `EXTEND`, `EXTERNAL`) that wrap the common cases without hand-building paths.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setdisplayconfig> - `SetDisplayConfig` flags, including topology modes.
- Microsoft Display API catalog: useful as the struct index when decoding adapter/target names from `DISPLAYCONFIG_DEVICE_INFO_HEADER`.
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-querydisplayconfig> - `QueryDisplayConfig` reference.
- Microsoft Monitor Configuration API catalog: covers the physical-monitor handle lifecycle and high/low-level DDC/CI functions.
- <https://learn.microsoft.com/en-us/windows/win32/monitor/monitor-configuration> - Monitor Configuration API overview.
- <https://learn.microsoft.com/en-us/windows/win32/api/physicalmonitorenumerationapi/> - physical monitor enumeration header and functions.
- DisplayMagician: a practical example of saving/restoring multi-monitor layouts by collecting topology plus target identity.
- Monitorian: a production brightness controller using the physical monitor APIs, including the ugly cases where monitors reject DDC/CI calls.
- ToggleDisplay: small wrapper around the system display-switch behavior; useful when topology intent matters more than exact mode control.
