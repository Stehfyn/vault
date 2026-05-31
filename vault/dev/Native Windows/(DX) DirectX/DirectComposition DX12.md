# DirectComposition DX12

DirectComposition with D3D12 is mostly a swap-chain ownership problem. The app renders with D3D12, presents through a DXGI swap chain, and gives that swap chain to a DComp visual. DComp then schedules the visual tree into DWM rather than letting the HWND own presentation directly.

The distinction from `DirectComposition + D3D12 Interop.md` is editorial, not technical; keep both notes only if one tracks the sample and the other tracks the minimal API pattern. The useful nearby topics are DComp clock timing, transparent windows, and DWM shared thumbnail visuals.

## Source Walkthrough

The linked sample is the same source as `DirectComposition + D3D12 Interop.md`, but this note should carry the shortest "what code do I write?" version:

```cpp
// Init:
CreateDXGIFactory1(&factory);
D3D12CreateDevice(adapter, ...);
device->CreateCommandQueue(&queue);
factory->CreateSwapChainForComposition(queue, &swap_desc, nullptr, &swap);
DCompositionCreateDevice(nullptr, IID_PPV_ARGS(&dcomp));
dcomp->CreateTargetForHwnd(hwnd, true, &target);
dcomp->CreateVisual(&visual);
visual->SetContent(swap);
target->SetRoot(visual);
dcomp->Commit();

// Frame:
record command list against swap back buffer;
queue->ExecuteCommandLists(...);
swap->Present(1, 0);
wait or rotate fence for back-buffer lifetime;
```

Lifetime rule: keep the command queue, swap chain, DComp device, target, and visual alive for as long as the HWND should present. Destroying the visual or setting content to null removes the retained visual; destroying D3D resources only affects the pixel producer. That split is the fastest way to debug black windows.

## References
- <https://github.com/PJayB/DirectCompositionDirectX12Sample>

## Connections
- `Windows Composition Engine.md`
- `../(DWM) Desktop Window Manager/DWM Thumbnail - VirtualDesktop IDCompositionVisual.md`
