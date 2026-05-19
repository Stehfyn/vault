# DirectX VS Project Templates

Chuck Walbourn's templates are valuable because they encode the unglamorous production scaffolding missing from most samples: adapter selection, swap-chain flags, HDR/WCG handling, tearing support, DPI changes, device-removed recovery, and the `DeviceResources` lifetime split between device-level and window-size-dependent resources.

Use them as a baseline when starting a Win32 D3D11/D3D12 app or test renderer. They are deliberately more opinionated than a "hello triangle" because the hard bugs in native Windows graphics usually come from resize, present, device loss, and display-mode transitions rather than initial device creation.

## References
- <https://github.com/walbourn/directx-vs-templates>

## Connections
- `(DXGI) Microsoft DirectX Graphics Infrastructure.md`
- `No-Flicker D3D11 Window Resize.md`
- `DXUT — D3D Sample Framework.md`
