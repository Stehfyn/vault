# RestartDisplayAdapters - SetupAPI Driver Reset

`RestartDisplayAdapters` walks present display adapters with SetupAPI and sends a `DIF_PROPERTYCHANGE` disable/enable cycle. That is heavier than the familiar `Win+Ctrl+Shift+B` compositor reset: it asks Plug and Play to restart the display device stack, so windows may move, monitors may vanish briefly, and elevated rights are expected. It is useful when the display miniport or user-mode driver is wedged badly enough that DWM-only recovery does not help.

The implementation matters because display adapters are device nodes, not windows or monitors. The tool uses `SetupDiGetClassDevs(GUID_DEVCLASS_DISPLAY)`, `SetupDiEnumDeviceInfo`, and `SetupDiCallClassInstaller` with `SP_PROPCHANGE_PARAMS`; none of the DisplayConfig APIs can replace that because they operate above the driver installation layer.

## References
- <https://github.com/Aetopia/RestartDisplayAdapters> - compact SetupAPI reset utility for present display adapters.

## Connections
- `Examples.md` handles topology after the driver stack is alive again.
- `dxgkernel Overview.md` is lower-level graphics-kernel plumbing, but it is not the right layer for PnP adapter restart.
