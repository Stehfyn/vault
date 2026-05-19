# dxgkernel Overview

The dxgkernel low-level client APIs are the user-mode entry points that talk to the graphics kernel for adapter/device/resource operations historically needed by DirectDraw, D3D runtime layers, and display-driver plumbing. They return handles and NTSTATUS-style results rather than friendly Win32 abstractions. `D3DKMTOpenAdapterFromHdc` is the classic bridge from a GDI DC to a graphics adapter handle.

These are not ordinary application graphics APIs. Use documented Direct3D, DXGI, DisplayConfig, or monitor-configuration APIs unless you are building diagnostics, compatibility layers, drivers-adjacent tools, or reverse-engineering graphics behavior. The value of the Microsoft page is taxonomy: it names the boundary between GDI32/user-mode clients and dxgkrnl.

## References
- <https://learn.microsoft.com/en-us/windows/win32/devnotes/-dxgkernel-low-level-client-support> - Microsoft devnote listing low-level graphics-kernel client support.

## Connections
- `D3DKMTQueryVidPnExclusiveOwnership - Fullscreen Detector.md` is a concrete diagnostic use.
- `Display Control/Examples.md` is the higher-level topology API layer.
