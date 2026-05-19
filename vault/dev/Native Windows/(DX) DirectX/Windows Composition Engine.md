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

## References

- <https://stackoverflow.com/questions/64966632/transparent-window-using-windows-composition-engine-in-c> - transparent HWND backed by a DComp visual tree.
- <https://stackoverflow.com/questions/63381368/direct-composition-idcompositiongaussianblureffect-throwing-access-violation-ex/63384511#63384511> - correct Gaussian blur effect construction.
- <https://learn.microsoft.com/en-us/windows/win32/api/dcomp/nf-dcomp-dcompositionboostcompositorclock> - compositor clock boost API.

## Connections

- `DirectComposition + D3D12 Interop.md`
- `DirectComposition DX12.md`
- `../(DWM) Desktop Window Manager/DCompositionWaitForCompositorClock - Decompiled.md`
