# Display and Monitor

Per-link references with focused snippets.

## IsSystemResumeAutomatic
Link: https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-issystemresumeautomatic
Brief: Detect automatic resume without user input.
```cpp
BOOL autoResume = IsSystemResumeAutomatic();
if (autoResume) {
  // system resumed without user input
} else {
  // user initiated resume
}
```

## _display API catalog
Link: https://learn.microsoft.com/en-us/windows/win32/api/_display/
Brief: Retrieve a target's friendly monitor name.
```cpp
DISPLAYCONFIG_TARGET_DEVICE_NAME name = {};
name.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME;
name.header.size = sizeof(name);
name.header.adapterId = path.targetInfo.adapterId;
name.header.id = path.targetInfo.id;
DisplayConfigGetDeviceInfo(&name.header);
```

## _monitor API catalog
Link: https://learn.microsoft.com/en-us/windows/win32/api/_monitor/
Brief: Enumerate physical monitors from an HMONITOR.
```cpp
HMONITOR hm = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
DWORD count = 0;
GetNumberOfPhysicalMonitorsFromHMONITOR(hm, &count);
std::vector<PHYSICAL_MONITOR> phys(count);
GetPhysicalMonitorsFromHMONITOR(hm, count, phys.data());
```

