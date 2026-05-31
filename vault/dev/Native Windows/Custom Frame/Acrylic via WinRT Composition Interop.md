# Acrylic via WinRT Composition Interop

Demonstrates that you can get the system Acrylic/Mica backdrop on a plain HWND without dragging in Win2D or the C++/WinRT projection headers — you talk to the `Windows.UI.Composition` interop COM interfaces directly via `RoGetActivationFactory` and `ICompositorDesktopInterop::CreateDesktopWindowTarget`. The payoff is a ~50KB binary instead of pulling cppwinrt + Win2D, and no .winmd processing at build time (cf. wangwenx190/Win32Acrylic, selastingeorge/Win32-Acrylic-Effect, ahmed605/10Mica for the Win10-on-Win11-backport variant; ALTaleX531/OpenGlass for the injection-based alternative on Win10).

## Source Shape

The interop branch keeps the HWND but creates a WinRT composition target for it through COM activation and desktop interop.

```cpp
ComPtr<IActivationFactory> factory;
RoGetActivationFactory(HStringReference(
    RuntimeClass_Windows_UI_Composition_Compositor).Get(),
    IID_PPV_ARGS(&factory));

ComPtr<IInspectable> compositor_object;
factory->ActivateInstance(&compositor_object);

ComPtr<ICompositorDesktopInterop> desktop;
compositor_object.As(&desktop);

ComPtr<IDesktopWindowTarget> target;
desktop->CreateDesktopWindowTarget(hwnd, TRUE, &target);

ComPtr<IVisual> root = CreateRootVisualWithBackdrop();
target->put_Root(root.Get());
```

That makes the link valuable as a deployment/build-shape reference: the hard part is not just the material, it is getting the Composition object model attached to a classic HWND without taking a full XAML dependency.

## Source Code Reading

`ALTaleX531/Win32Acrylic` keeps the whole interop recipe in `Win32Acrylic.h`. The class owns:

- `IDispatcherQueueController` for the current thread.
- `Windows.UI.Composition.Compositor`.
- `IDesktopWindowTarget` bound to the HWND.
- D3D11, DXGI, D2D, and `ICompositionGraphicsDevice` objects for effect surfaces.
- WIC for loading the noise texture.

Constructor shape:

```cpp
CreateDispatcherQueueController(DQTYPE_THREAD_CURRENT, DQTAT_COM_STA);
ActivateInstance(RuntimeClass_Windows_UI_Composition_Compositor, &compositor);
PrepareDevice();
compositor.As<ICompositorDesktopInterop>()
          ->CreateDesktopWindowTarget(hwnd, TRUE, &target);
root = compositor.CreateSpriteVisual();
root.RelativeSizeAdjustment = { 1.0f, 1.0f };
root.Brush = CreateAcrylicBrush();
target.Root = root;
```

The demo creates its HWND with `WS_EX_NOREDIRECTIONBITMAP`, then scopes `Win32Acrylic acrylic(hwnd)` around the message loop. That lifetime is deliberate: the composition target and brush graph must live as long as the window is visible.

`CreateAcrylicBrush` composes a named effect graph:

```text
Backdrop -> GaussianBlur(30)
Blur + LuminosityColor -> Blend(Color)
LuminosityResult + TintColor -> Blend(Luminosity)
ColorResult * NoiseOpacity(0.02) -> acrylic brush
```

`CreateAcrylicBrush_Legacy` adds saturation/exclusion blending for the older recipe. `CreateMicaBrush` replaces live backdrop with `TryCreateBlurredWallpaperBackdropBrush`, then applies tint, luminosity, and noise. This is the practical distinction: Acrylic samples the live host backdrop; Mica samples wallpaper-like backdrop.

### Claim -> Probe

Claim: "the hard part is attaching Composition to a plain HWND." Source confirmation: no XAML island is created; the bridge is `ICompositorDesktopInterop::CreateDesktopWindowTarget`. Probe it by failing each prerequisite independently: omit `RoInitialize`, omit `CreateDispatcherQueueController`, remove `WS_EX_NOREDIRECTIONBITMAP`, or release `Win32Acrylic` before the message loop. Interpretation: failures separate WinRT activation, dispatcher queue, HWND composition ownership, and object lifetime.

## References
- <https://github.com/ALTaleX531/Win32Acrylic>

## Connections
- `Acrylic Three Ways Comparison.md` compares this WinRT interop route against DirectComposition and private accent policy.
- `Acrylic with DirectComposition.md` is the lower-level native composition route.
- `win32mica.md` is the public DWM attribute path when Windows 11 backdrops are sufficient.
- `Mica Backport for Windows 10.md` is the compatibility branch when those public attributes do not exist.
