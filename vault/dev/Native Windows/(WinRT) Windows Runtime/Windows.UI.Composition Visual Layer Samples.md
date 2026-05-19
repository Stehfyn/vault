# Windows.UI.Composition Visual Layer Samples

The archived WindowsCompositionSamples repository is still a good map of the composition visual layer: `Compositor`, `ContainerVisual`, `SpriteVisual`, brushes, animations, effects, and expression animations that run independently of UI-thread ticks. The technique to remember is not "draw a rectangle"; it is pushing movement, parallax, lighting, and effects into the compositor so the UI thread does less work.

This entry belongs between DirectComposition/DWM and XAML/WinUI. Windows.UI.Composition is the WinRT-facing composition layer that XAML itself uses heavily, while DirectComposition is the lower native API. When a sample moves to WindowsAppSDK's SceneGraph material, keep the old repo for historical API shape and migration context.

## References
- <https://github.com/microsoft/WindowsCompositionSamples> - archived Microsoft samples for the WinRT visual layer and compositor animations.
