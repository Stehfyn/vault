# Display Control Examples

Per-link quick references with a brief note and a focused snippet.

## Enumeration and display control (MS docs)
Link: https://learn.microsoft.com/en-us/windows/win32/gdi/enumeration-and-display-control
Brief: Enumerate active paths and modes before changing topology.
```cpp
UINT32 pathCount = 0, modeCount = 0;
GetDisplayConfigBufferSizes(QDC_ONLY_ACTIVE_PATHS, &pathCount, &modeCount);
std::vector<DISPLAYCONFIG_PATH_INFO> paths(pathCount);
std::vector<DISPLAYCONFIG_MODE_INFO> modes(modeCount);
QueryDisplayConfig(QDC_ONLY_ACTIVE_PATHS, &pathCount, paths.data(),
                   &modeCount, modes.data(), nullptr);
```

## Old New Thing display config note
Link: https://devblogs.microsoft.com/oldnewthing/20211222-00/?p=106048
Brief: Apply a topology change with SetDisplayConfig and check status.
```cpp
UINT32 flags = SDC_TOPOLOGY_EXTEND | SDC_APPLY | SDC_ALLOW_PATH_ORDER_CHANGES;
LONG status = SetDisplayConfig(0, nullptr, 0, nullptr, flags);
if (status == ERROR_SUCCESS) {
  // applied
} else {
  // handle error
}
```

## Display API catalog
Link: https://learn.microsoft.com/en-us/windows/win32/api/_display/
Brief: Query a target's friendly name with DisplayConfigGetDeviceInfo.
```cpp
DISPLAYCONFIG_TARGET_DEVICE_NAME name = {};
name.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME;
name.header.size = sizeof(name);
name.header.adapterId = path.targetInfo.adapterId;
name.header.id = path.targetInfo.id;
DisplayConfigGetDeviceInfo(&name.header);
```

## Monitor API catalog
Link: https://learn.microsoft.com/en-us/windows/win32/api/_monitor/
Brief: Enumerate physical monitors and read brightness.
```cpp
HMONITOR hm = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
DWORD count = 0;
GetNumberOfPhysicalMonitorsFromHMONITOR(hm, &count);
std::vector<PHYSICAL_MONITOR> phys(count);
GetPhysicalMonitorsFromHMONITOR(hm, count, phys.data());
DWORD minB = 0, curB = 0, maxB = 0;
GetMonitorBrightness(phys[0].hPhysicalMonitor, &minB, &curB, &maxB);
```

## Presentation display mode (Stack Overflow)
Link: https://stackoverflow.com/questions/16790287/programmatically-changing-the-presentation-display-mode?rq=3
Brief: Switch to an internal-only topology using SetDisplayConfig.
```cpp
UINT32 flags = SDC_TOPOLOGY_INTERNAL | SDC_APPLY;
LONG status = SetDisplayConfig(0, nullptr, 0, nullptr, flags);
if (status == ERROR_SUCCESS) {
  // internal-only mode
} else {
  // handle error
}
```

## Multi-monitor SetDisplayConfig example
Link: https://stackoverflow.com/questions/57136638/how-to-properly-use-setdisplayconfig-with-multiple-monitors/62038912#62038912
Brief: Apply a supplied path/mode array.
```cpp
UINT32 flags = SDC_USE_SUPPLIED_DISPLAY_CONFIG | SDC_APPLY;
LONG status = SetDisplayConfig(pathCount, paths.data(),
                               modeCount, modes.data(), flags);
if (status != ERROR_SUCCESS) {
  // handle error
}
```

## ToggleDisplay sample tool
Link: https://github.com/sgrottel/tiny-tools-collection/tree/ToggleDisplay-v1.0
Brief: Use DisplaySwitch.exe to toggle external-only mode.
```cpp
STARTUPINFO si = { sizeof(si) };
PROCESS_INFORMATION pi = {};
CreateProcessW(L"C:\\Windows\\System32\\DisplaySwitch.exe",
               L" /external", nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi);
CloseHandle(pi.hThread);
CloseHandle(pi.hProcess);
```

## DisplayMagician layouts
Link: https://github.com/terrymacdonald/DisplayMagician
Brief: Capture a simple layout signature using target names.
```cpp
std::wstring layout;
for (const auto& p : paths) {
  DISPLAYCONFIG_TARGET_DEVICE_NAME name = {};
  name.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME;
  name.header.size = sizeof(name);
  name.header.adapterId = p.targetInfo.adapterId;
  name.header.id = p.targetInfo.id;
  DisplayConfigGetDeviceInfo(&name.header);
  layout += name.monitorFriendlyDeviceName;
}
```

## Monitorian brightness control
Link: https://github.com/emoacht/Monitorian
Brief: Read and set brightness with physical monitor APIs.
```cpp
DWORD minB = 0, curB = 0, maxB = 0;
GetMonitorBrightness(phys[0].hPhysicalMonitor, &minB, &curB, &maxB);
DWORD newB = (minB + maxB) / 2;
if (newB != curB) {
  SetMonitorBrightness(phys[0].hPhysicalMonitor, newB);
}
```

## WMI raw EDID access
Link: https://learn.microsoft.com/en-us/windows/win32/wmicoreprov/wmigetmonitorraweedidv1block-wmimonitordescriptormethods
Brief: Query WMI for monitor descriptors and raw EDID.
```cpp
BSTR query = SysAllocString(L"SELECT * FROM WmiMonitorDescriptorMethods");
IEnumWbemClassObject* enumerator = nullptr;
HRESULT hr = services->ExecQuery(SysAllocString(L"WQL"), query,
    WBEM_FLAG_FORWARD_ONLY, nullptr, &enumerator);
if (SUCCEEDED(hr)) {
  // call WmiGetMonitorRawEEdidV1Block on each instance
}
```

## Get monitor display device names
Link: https://stackoverflow.com/questions/458011/how-to-get-monitor-display-device-names-using-winapi-c
Brief: Enumerate display devices and read active names.
```cpp
DISPLAY_DEVICEW dd = { sizeof(dd) };
for (DWORD i = 0; EnumDisplayDevicesW(NULL, i, &dd, 0); ++i) {
  if (dd.StateFlags & DISPLAY_DEVICE_ACTIVE) {
    // dd.DeviceName, dd.DeviceString
  }
  dd.cb = sizeof(dd);
}
```

## GetMonitorInfo overview
Link: https://learn.microsoft.com/en-us/windows/win32/gdi/getting-information-on-a-display-monitor
Brief: Use MonitorFromPoint + GetMonitorInfo for device details.
```cpp
HMONITOR hm = MonitorFromPoint(pt, MONITOR_DEFAULTTONEAREST);
MONITORINFOEXW mi = {};
mi.cbSize = sizeof(mi);
if (GetMonitorInfoW(hm, &mi)) {
  // mi.szDevice, mi.rcMonitor
}
```

## DEVMODEW structure
Link: https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-devmodew
Brief: Read and apply a display mode with DEVMODEW.
```cpp
DEVMODEW dm = {};
dm.dmSize = sizeof(dm);
EnumDisplaySettingsExW(L"\\\\.\\DISPLAY1", ENUM_CURRENT_SETTINGS, &dm, 0);
dm.dmPelsWidth = 1920;
dm.dmPelsHeight = 1080;
ChangeDisplaySettingsExW(L"\\\\.\\DISPLAY1", &dm, NULL, CDS_UPDATEREGISTRY, NULL);
```
