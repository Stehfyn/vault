# RestartDisplayAdapters - SetupAPI Driver Reset

`RestartDisplayAdapters` walks present display adapters with SetupAPI and sends a `DIF_PROPERTYCHANGE` disable/enable cycle. That is heavier than the familiar `Win+Ctrl+Shift+B` compositor reset: it asks Plug and Play to restart the display device stack, so windows may move, monitors may vanish briefly, and elevated rights are expected. It is useful when the display miniport or user-mode driver is wedged badly enough that DWM-only recovery does not help.

The implementation matters because display adapters are device nodes, not windows or monitors. The tool uses `SetupDiGetClassDevs(GUID_DEVCLASS_DISPLAY)`, `SetupDiEnumDeviceInfo`, and `SetupDiCallClassInstaller` with `SP_PROPCHANGE_PARAMS`; none of the DisplayConfig APIs can replace that because they operate above the driver installation layer.

## Source Code Reading

`Aetopia/RestartDisplayAdapters/WinMain.c` is compact enough to treat as executable pseudocode. It calls `SetupDiGetClassDevsW(&GUID_DEVCLASS_DISPLAY, ..., DIGCF_PRESENT)`, initializes one `SP_DEVINFO_DATA`, initializes `SP_PROPCHANGE_PARAMS` with `DIF_PROPERTYCHANGE`, `DICS_FLAG_GLOBAL`, and `HwProfile = 0`, then loops `SetupDiEnumDeviceInfo`.

For each display device node it performs two property changes:

```c
params.StateChange = DICS_DISABLE;
SetupDiSetClassInstallParamsW(set, &dev, &params.ClassInstallHeader,
                              sizeof(SP_PROPCHANGE_PARAMS));
SetupDiChangeState(set, &dev);

params.StateChange = DICS_ENABLE;
SetupDiSetClassInstallParamsW(set, &dev, &params.ClassInstallHeader,
                              sizeof(SP_PROPCHANGE_PARAMS));
SetupDiChangeState(set, &dev);
```

The probe version should be read-only first: enumerate the same `GUID_DEVCLASS_DISPLAY` set, log instance IDs with `SetupDiGetDeviceInstanceId`, class description/friendly name, and whether the device is present. Only a deliberate reset test should issue `DICS_DISABLE`/`DICS_ENABLE`, and it should snapshot `QueryDisplayConfig` before and after because topology may change while the adapter stack restarts.

## References
- <https://github.com/Aetopia/RestartDisplayAdapters> - compact SetupAPI reset utility for present display adapters.

## Connections
- `Examples.md` handles topology after the driver stack is alive again.
- `dxgkernel Overview.md` is lower-level graphics-kernel plumbing, but it is not the right layer for PnP adapter restart.
