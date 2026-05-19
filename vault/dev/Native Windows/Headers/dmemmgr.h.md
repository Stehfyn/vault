# dmemmgr.h

Legacy DirectDraw video-memory-manager definitions from the XP display-driver model era. This belongs to the old user/kernel DirectDraw stack where drivers exposed heaps, surface capabilities, and blitability to `ddraw.dll`; WDDM replaced that world with allocations owned by the graphics kernel and DXGI/D3D runtime contracts. You do not include this for application graphics work. It matters when reading old miniport/DDI code, DirectDraw compatibility shims, or ReactOS/Wine implementations trying to emulate the pre-WDDM heap model.

Connections: pair with `(DX) DirectX/DirectDraw and D3D9 Proxy DLL (dxwrapper).md`, `(DX) DirectX/DirectDraw GDI (ddrawgdi).md`, and `ddrawgdi.h.md`; together they explain why old games hit driver paths that modern D3D11/12 code never sees.

## References
- dmemmgr.h
