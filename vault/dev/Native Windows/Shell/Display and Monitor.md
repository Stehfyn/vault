# Display and Monitor

Display code is split across power state, logical display configuration, and physical monitor control. Do not treat these as interchangeable layers. `IsSystemResumeAutomatic` answers whether the machine resumed without user interaction; display-configuration APIs describe the desktop topology; monitor-configuration APIs operate on physical panels reached through an `HMONITOR`.

## Resume State

`IsSystemResumeAutomatic` is useful before expensive display work. If the wake was automatic, a service or background agent can skip UI-facing monitor changes until real input arrives.

```cpp
if (IsSystemResumeAutomatic()) {
    // The system woke for a timer/device, not for a user at the console.
    // Defer display UI, brightness prompts, or monitor re-layout work.
    return;
}
```

## Logical Display Topology

The display catalog is the right place for paths, modes, and friendly target names. Use it when the question is "what is Windows presenting as the desktop?" rather than "what does this physical panel support?"

```cpp
UINT32 path_count = 0;
UINT32 mode_count = 0;
GetDisplayConfigBufferSizes(QDC_ONLY_ACTIVE_PATHS, &path_count, &mode_count);

std::vector<DISPLAYCONFIG_PATH_INFO> paths(path_count);
std::vector<DISPLAYCONFIG_MODE_INFO> modes(mode_count);
QueryDisplayConfig(QDC_ONLY_ACTIVE_PATHS, &path_count, paths.data(), &mode_count, modes.data(), nullptr);

DISPLAYCONFIG_TARGET_DEVICE_NAME name = {};
name.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME;
name.header.size = sizeof(name);
name.header.adapterId = paths[0].targetInfo.adapterId;
name.header.id = paths[0].targetInfo.id;
DisplayConfigGetDeviceInfo(&name.header);
```

## Physical Monitor Handles

The monitor catalog matters after you already have an `HMONITOR`, usually from `EnumDisplayMonitors` or a window query. Physical handles must be destroyed; leaking them is easy in tooling that polls brightness or capabilities.

```cpp
MONITORINFOEXW mi = { sizeof(mi) };
GetMonitorInfoW(hmon, &mi);

DWORD count = 0;
GetNumberOfPhysicalMonitorsFromHMONITOR(hmon, &count);

std::vector<PHYSICAL_MONITOR> monitors(count);
if (GetPhysicalMonitorsFromHMONITOR(hmon, count, monitors.data())) {
    for (const auto& monitor : monitors) {
        // monitor.szPhysicalMonitorDescription is the panel-facing name.
    }
    DestroyPhysicalMonitors(count, monitors.data());
}
```

## Connections

- `Notification Area (Tray).md` uses monitor/power state to avoid showing stale status UI after automatic resume.
- `Windows Explorer Integration.md` is the shell-facing side: it reacts to windows and folders, not physical display devices.
- `DXGI (Microsoft DirectX Graphics Infrastructure).md` is the graphics-facing side: outputs/adapters must still be reconciled with Win32 monitor handles.

## References

- <https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-issystemresumeautomatic>
- <https://learn.microsoft.com/en-us/windows/win32/api/_display/>
- <https://learn.microsoft.com/en-us/windows/win32/api/_monitor/>
