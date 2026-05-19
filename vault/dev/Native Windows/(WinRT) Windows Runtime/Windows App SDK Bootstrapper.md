# Windows App SDK Bootstrapper

The Windows App SDK is the successor to the UWP-only platform story: modern Windows UI and platform APIs are delivered through NuGet/framework packages so Win32, WPF, WinForms, and WinUI 3 apps can use them. The bootstrapper is the unpackaged-app mechanism: call `MddBootstrapInitialize*` early, bind the process to an installed Windows App Runtime package matching the requested major/minor version, then shut it down on exit.

This is not just a loader detail. It is the deployment contract that decides whether an unpackaged EXE can activate `Microsoft.UI.Xaml`, app notifications, app lifecycle APIs, MRT Core, and other WinAppSDK components. Failure modes are operational: missing runtime packages, version mismatch, preview tags, architecture mismatch, or apps that should instead ship self-contained.

```cpp
PACKAGE_VERSION minVersion{};
minVersion.Major = 1;
minVersion.Minor = 5;

HRESULT hr = MddBootstrapInitialize2(
    0x00010005, L"", minVersion,
    MddBootstrapInitializeOptions_OnNoMatch_ShowUI);
if (FAILED(hr)) {
    // Missing or incompatible Windows App Runtime; handle setup explicitly.
    return hr;
}

// Use WinAppSDK APIs here.
MddBootstrapShutdown();
```

## References
- <https://github.com/microsoft/WindowsAppSDK> - source and documentation hub for Windows App SDK / Windows App Runtime.
