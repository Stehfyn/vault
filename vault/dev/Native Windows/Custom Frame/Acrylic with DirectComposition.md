# Acrylic with DirectComposition

Stitches together the two halves nobody wants to write themselves: a `DwmEnableBlurBehindWindow` / `SetWindowCompositionAttribute(ACCENT_ENABLE_ACRYLICBLURBEHIND)` call to get the OS to blur whatever is behind the window, plus a DirectComposition visual tree on top so your own content composes against that blur without the GDI artifacts you get if you just `BeginPaint` over an acrylic surface (cf. ALTaleX531/Win32Acrylic, wangwenx190/Win32Acrylic, ahmed605/10Mica). The `ACCENT_ENABLE_ACRYLICBLURBEHIND` path is undocumented and was deliberately throttled in 1903+ for unfocused windows — that perf regression is the reason every modern acrylic implementation either accepts the throttle or moves to the DComp `CreateBackdropBrush` route used by ALTaleX531/TranslucentFlyouts (#63).

## Source Shape

The DirectComposition route is explicit visual-tree ownership. The app creates a target for the HWND, attaches visuals/effects, and commits changes on the DComp device.

```cpp
DCompositionCreateDevice3(dxgi_device, IID_PPV_ARGS(&dcomp));
dcomp->CreateTargetForHwnd(hwnd, TRUE, &target);
dcomp->CreateVisual(&root);

root->SetContent(surface_or_swapchain);
target->SetRoot(root.Get());
dcomp->Commit();
```

If the window also uses private accent blur, keep the responsibilities separate: accent/backdrop chooses what is behind the HWND; DComp controls how your own content composes over it.

## Source Code Reading

`selastingeorge/Win32-Acrylic-Effect` shows the DirectComposition path as named stages in `Acrylic Window/AcrylicCompositor.cpp`:

1. `InitLibs` resolves `SetWindowCompositionAttribute` and private DWM shared-visual exports.
2. `CreateCompositionDevice` builds a D3D11 BGRA device, queries `IDXGIDevice`, then calls `DCompositionCreateDevice3`.
3. `CreateCompositionTarget(hwnd)` binds the DComp target with `CreateTargetForHwnd`.
4. `CreateCompositionVisual(hwnd)` creates root, fallback, desktop, and top-level visuals.
5. `CreateBackdrop(hwnd, source)` creates desktop-only or host-backdrop source visuals.
6. `CreateEffectGraph` creates blur, saturation, transform, and clip effects.
7. `Commit`, `SyncCoordinates`, and `Flush` update geometry and call `DwmFlush`.

Reduced shape:

```cpp
DCompositionCreateDevice3(dxgi, IID_PPV_ARGS(&device3));
device->CreateTargetForHwnd(hwnd, FALSE, &target);
device3->CreateVisual(&root);
device3->CreateGaussianBlurEffect(&blur);
root->AddVisual(backdropVisual, FALSE, nullptr);
root->SetEffect(blur.Get());
target->SetRoot(root.Get());
device->Commit();
```

The source-material boundary is the interesting part. The sample uses private DWM thumbnail/virtual-desktop visuals to get either desktop-only backdrop or host backdrop. DirectComposition gives you the visual tree and effect graph; it does not magically provide "what is behind my window."

### Discussion Claim -> Probe

Claim from the README: SWCA acrylic becomes laggy on drag/resize on Windows 10 1903-era builds. Probe it with two windows: one using `SetWindowCompositionAttribute(ACCENT_ENABLE_ACRYLICBLURBEHIND)`, one using a DComp visual/fallback path. Record drag frame times with ETW (`Microsoft-Windows-Dwm-Core`, present events) or high-resolution timestamps around `WM_MOVING` / `WM_WINDOWPOSCHANGED`. Interpretation: if only the SWCA window stalls during move/resize, the problem is in DWM's accent path rather than your app's paint loop.

Claim from the README: WPF/WinForms Composition acrylic hits the "airspace" boundary. Probe it by placing a WPF control over a native composition child/visual and using screenshots plus HWND tree inspection. Interpretation: if WPF content and DComp content cannot z-order as expected, the issue is separate HWND/composition ownership, not blur math.

## References
- <https://github.com/selastingeorge/Win32-Acrylic-Effect>

## Connections
- `Acrylic Three Ways Comparison.md` positions this as the native composition branch.
- `Acrylic via WinRT Composition Interop.md` reaches a similar visual-tree model through WinRT COM interop.
- `../(DX) DirectX/Windows Composition Engine.md` is the deeper route for visual lifetime and commit behavior.
- `Custom Chrome Sample (NCCALCSIZE).md` matters when the acrylic surface is also a borderless top-level window.
