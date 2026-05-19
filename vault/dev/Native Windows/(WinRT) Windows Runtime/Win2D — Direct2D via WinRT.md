# Win2D - Direct2D via WinRT

Win2D is a WinRT projection over Direct2D/DirectWrite-style immediate-mode drawing. The repository describes it as a Windows Runtime API for GPU-accelerated 2D rendering, currently aimed at WinUI 3 while historically serving UWP. Its practical value is the `CanvasControl` family: XAML-hosted drawing surfaces that handle device lifetime, DPI, swap-chain integration, and drawing-session setup so app code can focus on rendering commands.

The tradeoff is ceiling versus ergonomics. Raw Direct2D gives full device/context control and cleaner interop with D3D/DXGI-heavy code; Win2D is faster to ship inside XAML apps and pairs naturally with WinRT async, resources, effects, and text APIs. Keep it beside Direct2D, Windows.UI.Composition, and Xaml Islands notes.

## References
- <https://github.com/microsoft/Win2D> - Microsoft WinRT/WinUI wrapper over Direct2D-style 2D rendering.
