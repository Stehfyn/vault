# cfgmgr32.h

PnP Configuration Manager -- the in-process API set (`cfgmgr32.dll`) that exposes the device tree, device-interface enumeration, and device properties without going through SetupAPI. Functions are `CM_*` prefixed mirrors of older `SetupDi*` calls, but they don't require an `HDEVINFO` set and are usable from inside services and drivers' user-mode companions. Key entry points: `CM_Get_Device_Interface_List_SizeW` / `CM_Get_Device_Interface_ListW` to enumerate device interfaces by class GUID, `CM_Locate_DevNodeW` to walk the device tree, `CM_Get_DevNode_PropertyW` / `CM_Get_Device_Interface_PropertyW` to read DEVPROPKEY-based properties (`DEVPKEY_Device_FriendlyName`, `DEVPKEY_Device_InstanceId`, `DEVPKEY_NAME`), `CM_Register_Notification` to subscribe to arrival/removal events without a window. Modern kernel-driver-companion code and WinUSB tooling are written against `cfgmgr32.h` rather than `setupapi.h`.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/cfgmgr32/>
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/install/overview-of-the-pnp-configuration-manager>
