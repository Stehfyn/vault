# Acrylic Three Ways Comparison

Archived (Sep 2022) side-by-side comparison of *three* ways to put acrylic behind a Win32 window — UWP XAML Island hosting a `Microsoft.UI.Xaml.Controls.AcrylicBrush`, raw `IDCompositionDevice`/`IDCompositionVisual` trees, and the undocumented `SetWindowCompositionAttribute(WCA_ACCENT_POLICY)` path. The pedagogical value is in seeing them in one tree: the DComp variant is the only one that actually composes correctly on Win11 with rounded corners, the SWCA variant is the smallest and the one Microsoft would prefer you never used, the XAML Island variant is the most "supported" but drags in the entire WinRT toolchain. Sibling to ALTaleX531/Win32Acrylic (#14) and the cluster at ahmed605/10Mica (#61), Maplespe/DWMBlurGlass (#54), selastingeorge/Win32-Acrylic-Effect (#68), krlvm/AcrylicMenus (#69).

## Source Shape

The Win32/SWCA branch is the compact, undocumented path: construct an accent policy, put it inside `WINDOWCOMPOSITIONATTRIBDATA`, call the private user32 export, then invalidate the whole client area.

```cpp
ACCENT_POLICY accent = {};
accent.State = ACCENT_ENABLE_ACRYLICBLURBEHIND;
accent.Flags = 2;
accent.GradientColor = abgr_tint;

WINDOWCOMPOSITIONATTRIBDATA data = {};
data.Attrib = WCA_ACCENT_POLICY;
data.pvData = &accent;
data.cbData = sizeof(accent);

SetWindowCompositionAttribute(hwnd, &data);
InvalidateRect(hwnd, nullptr, TRUE);
```

The DirectComposition branch is heavier but more explicit: the visual owns an effect graph and commit boundary.

```cpp
DCompositionCreateDevice3(dxgi_device, IID_PPV_ARGS(&dcomp));
dcomp->CreateTargetForHwnd(hwnd, FALSE, &target);
dcomp->CreateVisual(&root);

dcomp->CreateGaussianBlurEffect(&blur);
blur->SetStandardDeviation(30.0);
blur->SetBorderMode(D2D1_BORDER_MODE_HARD);

root->SetEffect(blur.Get());
target->SetRoot(root.Get());
dcomp->Commit();
```

## Source Code Reading

`wangwenx190/Win32Acrylic` is arranged as three demo applications plus a shared helper library:

- `Win32/MainWindow.cpp`: private `SetWindowCompositionAttribute` acrylic.
- `DirectComposition/MainWindow.cpp`: DComp device, private DWM shared visuals, blur/saturation graph.
- `UWP/MainWindow.cpp`: `DesktopWindowXamlSource` plus `AcrylicBrush`.
- `Win32AcrylicHelper/*`: window utilities, version checks, thunked API loading, and common error reporting.

The Win32 branch's `SetBlurBehindParameters` fills `ACCENT_POLICY`, wraps it in `WINDOWCOMPOSITIONATTRIBDATA`, calls `SetWindowCompositionAttribute`, and logs failure. Its activation/theme paths reapply the policy because accent material is stateful.

The XAML branch creates a `DesktopWindowXamlSource`, queries `IDesktopWindowXamlSourceNative2`, attaches it to the parent HWND, creates a root `Grid`, and assigns an `AcrylicBrush` with `BackgroundSource = HostBackdrop`. Geometry synchronization is explicit: the child island must track the parent on resize, move, and DPI changes.

The DirectComposition branch creates D3D/DComp devices, obtains private DWM shared visuals for the backdrop source, applies blur/saturation, and commits the tree.

The useful comparison is ownership:

```text
SWCA owns an HWND attribute.
XAML owns a child island and XAML brush.
DComp owns a visual tree and effect graph.
```

### Claim -> Probe

Claim: "the three approaches are not interchangeable." Probe it by logging HWND tree, DWM attributes, and graphics API calls for each demo. Interpretation: SWCA should show no child XAML HWND and no explicit DComp graph; XAML should show an island child HWND; DComp should show no XAML island but should execute `DCompositionCreateDevice3` and `Commit`.

## References
- <https://github.com/wangwenx190/Win32Acrylic>

## Connections
- `Acrylic with DirectComposition.md` is the lowest-level supported-ish path; it keeps the effect in the DComp/DWM visual pipeline.
- `Acrylic via WinRT Composition Interop.md` trades native minimalism for WinRT activation and Windows App SDK deployment concerns.
- `../(DX) DirectX/Windows Composition Engine.md` and `../(DWM) Desktop Window Manager/DWM Internals Documentation.md` explain why the three approaches differ in lifetime, commit timing, and OS-version fragility.
