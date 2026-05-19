# ddrawgdi.h

DirectDraw/GDI bridge definitions from the old display-driver stack. This is the plumbing for paths where GDI and DirectDraw had to coordinate surfaces, palettes, mode switches, and driver callbacks before WDDM/DXGI normalized presentation. Application code should not depend on it; its value is forensic and compatibility-oriented: old games, DirectDraw wrappers, ReactOS/Wine, and driver archaeology need to know where GDI stopped and the DirectDraw HAL/DDI began.

Connections: pair with `(DX) DirectX/DirectDraw GDI (ddrawgdi).md`, `dmemmgr.h.md`, and the GDI DIB notes. It explains why some Win9x/XP-era rendering bugs are neither "pure GDI" nor "pure Direct3D."

## References
- ddrawgdi.h
