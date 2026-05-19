# DXUT — D3D Sample Framework

DXUT is the old Direct3D 9/10/11 sample framework from the DirectX SDK era. It owns the app skeleton: window creation, device selection, lost-device handling, callbacks, settings dialog, cameras, timers, and HUD helpers. That makes it excellent for reading old D3D samples without drowning in WinMain boilerplate, but a poor foundation for new Windows apps.

The modern replacement is not a single framework; it is DirectX Tool Kit, Win32 samples, and project templates that use current DXGI flip-model presentation and device-loss handling. Keep DXUT in the vault as a compatibility/reference note, especially when old SDK samples or papers say "build the DXUT sample."

## References
- <https://github.com/microsoft/DXUT>

## Connections
- `DirectX VS Project Templates.md`
- `DX Examples.md`
