# DirectComposition + D3D12 Interop

This sample demonstrates the D3D12 version of a DirectComposition presentation path: render into a DXGI swap chain, set that swap chain as an `IDCompositionVisual`'s content, attach the visual to an HWND target, and commit the visual tree. The important point is that DirectComposition consumes DXGI content; it does not care whether the producer was D3D11 or D3D12 as long as the device/swap-chain setup is compatible.

Use this when a plain HWND swap chain is too rigid: transparent overlays, visual transforms, blur/effects, or multiple composed surfaces inside one window. Pair it with the DWM thumbnail notes when the visual content comes from another window, and with `Windows Composition Engine.md` for the DComp mental model.

## Source Code Reading

`PJayB/DirectCompositionDirectX12Sample/DirectCompositeSample.cpp` provides the actual minimal chain. It creates the D3D12 device and command queue, calls `CreateSwapChainForComposition` with a flip-model swap chain and `DXGI_ALPHA_MODE_PREMULTIPLIED`, creates a DirectComposition device/target/visual, sets the swap chain as visual content, sets the visual as root, and commits. The D3D12 render path still uses normal resource barriers and fences.

```cpp
factory->CreateSwapChainForComposition(command_queue, &desc, nullptr, &swap1);
DCompositionCreateDevice(nullptr, IID_PPV_ARGS(&dcomp));
dcomp->CreateTargetForHwnd(hwnd, true, &target);
dcomp->CreateVisual(&visual);
visual->SetContent(swap1.Get());
target->SetRoot(visual.Get());
dcomp->Commit();

// Each frame:
barrier(PRESENT -> RENDER_TARGET);
draw;
barrier(RENDER_TARGET -> PRESENT);
queue->ExecuteCommandLists(...);
swap->Present(1, 0);
signal_and_wait_fence();
```

The probe should log DComp HRESULTs separately from D3D12 HRESULTs. If `Commit` succeeds but nothing changes, inspect `Present`, resource state, alpha, and back-buffer contents. If `Present` succeeds but the visual is missing, inspect `SetContent`, `SetRoot`, HWND target creation, and window styles.

## References
- <https://github.com/PJayB/DirectCompositionDirectX12Sample>
