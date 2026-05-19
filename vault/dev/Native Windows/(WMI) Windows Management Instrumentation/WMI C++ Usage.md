# WMI C++ Usage

Native WMI code is COM code with a query language bolted on: initialize COM security, create `IWbemLocator`, connect to a namespace such as `ROOT\CIMV2`, then issue WQL through `IWbemServices::ExecQuery` and enumerate `IWbemClassObject` results. Most failures in real programs come from COM security being initialized too late, using the wrong impersonation level, or assuming a provider is cheap because the query syntax looks like SQL.

The Twinkle Tray bridge link matters because it shows WMI used as a practical subsystem bridge rather than a toy OS-caption query: monitor/brightness utilities often have to combine WMI provider data with display-control APIs and vendor behavior. Keep WMI entries tied to their namespace/provider and latency profile; polling WMI from a UI thread is a common Native Windows footgun.

## Connections
- `HWID Composition Reference` uses WMI classes for machine identifiers.
- Display-control and monitor entries often need WMI only as one piece of an inventory path.
- `Win32 Service Template` is relevant when WMI polling/eventing is moved out of an interactive process.

## References
- <https://learn.microsoft.com/en-us/windows/win32/wmisdk/wmi-c---application-examples>
- <https://github.com/xanderfrangos/twinkle-tray/blob/674039980ad5a7331dfd6b3d060204f377b89550/src/modules/wmi-bridge/wmi-bridge.cc#L4>
