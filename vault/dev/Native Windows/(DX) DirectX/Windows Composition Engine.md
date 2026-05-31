# Windows Composition Engine

DirectComposition is the user-mode composition API that sits between app-rendered DXGI surfaces and DWM. The core move is simple: create a DComp device, create a target for an HWND, attach an `IDCompositionVisual` tree, set a swap chain or surface as visual content, then `Commit`. The nuance is that DComp composes visuals; it does not magically make Win32 hit testing, alpha, or DWM non-client behavior correct.

## Visual Tree

The transparent-window link contributes the correct shape: the HWND owns the target, the visual owns content, and transparency is a swap-chain/alpha/window-style contract, not a magic DComp flag.

```cpp
wil::com_ptr<IDCompositionDevice> dcomp;
DCompositionCreateDevice(dxgi_device.get(), IID_PPV_ARGS(&dcomp));

wil::com_ptr<IDCompositionTarget> target;
dcomp->CreateTargetForHwnd(hwnd, TRUE, &target);

wil::com_ptr<IDCompositionVisual> visual;
dcomp->CreateVisual(&visual);
visual->SetContent(swap_chain.get());
target->SetRoot(visual.get());
dcomp->Commit();
```

## Effects and Timing

The blur-effect link contributes the device-graph rule: create effects from the same DComp device graph and attach them to visuals. `DCompositionBoostCompositorClock` is timing policy for animation bursts, adjacent to explicit compositor-clock waits.

```cpp
wil::com_ptr<IDCompositionGaussianBlurEffect> blur;
dcomp->CreateGaussianBlurEffect(&blur);
blur->SetStandardDeviation(24.0f);
visual->SetEffect(blur.get());
dcomp->Commit();
```

## Swap Chain and Alpha Contract

For transparent or shaped Win32 composition, DComp is only the visual tree. The swap chain still has to be a composition-compatible DXGI object, and the pixels still need the alpha mode the compositor expects.

```cpp
DXGI_SWAP_CHAIN_DESC1 desc = {};
desc.Width = width;
desc.Height = height;
desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
desc.SampleDesc.Count = 1;
desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
desc.BufferCount = 2;
desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
desc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;

wil::com_ptr<IDXGISwapChain1> swap_chain;
factory->CreateSwapChainForComposition(
    d3d_device.get(), &desc, nullptr, &swap_chain);

visual->SetContent(swap_chain.get());
dcomp->Commit();
swap_chain->Present(1, 0);
```

`Commit` submits visual-tree changes to the compositor; `Present` submits new pixels to the swap chain. If animation phase matters, route to `../(DWM) Desktop Window Manager/DCompositionWaitForCompositorClock — Decompiled.md`; if physical scanout matters, route to `../(DWM) Desktop Window Manager/VBlank Wait.md`.

## Experiment Harness

Goal: verify what DirectComposition owns: visual-tree state, alpha, effects, and commit timing, while DXGI still owns pixel production.

Procedure:
1. Create two visuals: a swap-chain-backed visual and a solid-color/effect visual.
2. Toggle `SetContent(nullptr)`, transform/offset, alpha mode, and blur; call `Commit` after each state change.
3. Independently vary `Present(0,0)` versus `Present(1,0)` and record whether pixels update without visual changes and whether visual changes appear without new pixels.

```cpp
visual->SetOffsetX(x);
visual->SetContent(swap_chain.get());
dcomp->Commit();                 // visual state
RenderNextColor();
swap_chain->Present(sync, flags); // pixel state
```

Metric: commit-to-visible latency, present-to-visible latency, alpha correctness over a known checkerboard, and DWM timing counters from `DwmGetCompositionTimingInfo`.

Failure interpretation: black/opaque output usually means incompatible swap-chain alpha/format or no root visual. Movement without new pixels proves DComp is moving retained content. New pixels without moved visual proves DXGI content and DComp graph state are separate submissions.

## Source Code Reading

`PJayB/DirectCompositionDirectX12Sample` gives the DComp + D3D12 ownership sequence in `DirectCompositeSample.cpp` and the HWND setup in `Win32Application.cpp`. The useful detail is that the swap chain is created for composition from a D3D12 command queue, then attached to a DComp visual; DComp owns visual placement, while D3D12 owns command recording, resource states, and fences.

```cpp
// Source-shaped from DirectCompositeSample.cpp.
CreateDXGIFactory1(&factory);
D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, &device);
device->CreateCommandQueue(&queue_desc, &queue);

DXGI_SWAP_CHAIN_DESC1 desc = {};
desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
desc.BufferCount = FrameCount;
desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
desc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
factory->CreateSwapChainForComposition(queue, &desc, nullptr, &swap1);

DCompositionCreateDevice(nullptr, IID_PPV_ARGS(&dcomp));
dcomp->CreateTargetForHwnd(hwnd, true, &target);
dcomp->CreateVisual(&visual);
visual->SetContent(swap1.Get());
target->SetRoot(visual.Get());
dcomp->Commit();
```

The render loop is pure D3D12 after that: reset allocator/list, transition current back buffer from `PRESENT` to `RENDER_TARGET`, draw, transition back to `PRESENT`, close and execute the list, `Present(1,0)`, then signal/wait a fence. The split is the main lesson. `Commit` is for visual-tree mutations; `Present` is for new pixels; fences are for GPU completion; none of those implies the others.

`Win32Application.cpp` also uses `WS_EX_NOREDIRECTIONBITMAP` and a region-shaped top-level window. That matters for probes: when a DComp-backed HWND appears black or fails to blend, log extended styles, swap-chain `AlphaMode`, and whether the HWND still has a normal DWM redirection bitmap. A transparent DComp window is a three-part contract: HWND style, premultiplied swap-chain content, and DComp visual root.

## Discussion Claim To Verify

The transparent-window Stack Overflow code accidentally gives a precise failure matrix: `WS_EX_NOREDIRECTIONBITMAP`, `CreateSwapChainForComposition`, premultiplied BGRA, `visual->SetContent`, `target->SetRoot`, and `Commit` all have to line up. The blur-effect thread adds a COM-shape claim: `CreateGaussianBlurEffect` must receive a valid address for an `IDCompositionGaussianBlurEffect*`, and the effect object must come from the same DComp device graph that owns the visual.

```cpp
struct DCompProbe {
    bool no_redirection_bitmap;
    DXGI_ALPHA_MODE alpha_mode;
    bool set_content_once_at_init;
    bool set_root_once_at_init;
    bool commit_after_graph_change;
    HRESULT create_blur_hr;
    HRESULT present_hr;
    HRESULT commit_hr;
};

// Variant A: set content/root once, then only Present pixels.
// Variant B: set content/root every paint.
// Variant C: change only visual opacity/offset, then Commit without Present.
// Variant D: change only pixels, then Present without Commit.
```

Expected interpretation: D proves DXGI owns pixels; C proves DComp owns retained visual state; B working while A fails usually means initialization/order or lifetime is wrong. Opaque output points first to alpha mode or premultiplication. No output with successful `Present` points first to missing root/content/commit or a style mismatch. An access violation creating a blur effect is not an "effect algorithm" problem until the pointer/address and COM interface version are proven correct.

## References

- <https://stackoverflow.com/questions/64966632/transparent-window-using-windows-composition-engine-in-c> - transparent HWND backed by a DComp visual tree.
- <https://stackoverflow.com/questions/63381368/direct-composition-idcompositiongaussianblureffect-throwing-access-violation-ex/63384511#63384511> - correct Gaussian blur effect construction.
- <https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock> - compositor clock boost API.
- <https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-idcompositionvisual-setcontent> - legal content objects for a visual.

## Connections

- `DirectComposition + D3D12 Interop.md`
- `DirectComposition DX12.md`
- `../(DWM) Desktop Window Manager/DCompositionWaitForCompositorClock — Decompiled.md`
- `../(GDI) Graphics Device Interface/Transparent Window GDI.md`
- `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md`
