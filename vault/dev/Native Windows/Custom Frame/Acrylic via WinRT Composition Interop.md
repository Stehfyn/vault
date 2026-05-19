# Acrylic via WinRT Composition Interop

Demonstrates that you can get the system Acrylic/Mica backdrop on a plain HWND without dragging in Win2D or the C++/WinRT projection headers — you talk to the `Windows.UI.Composition` interop COM interfaces directly via `RoGetActivationFactory` and `ICompositorDesktopInterop::CreateDesktopWindowTarget`. The payoff is a ~50KB binary instead of pulling cppwinrt + Win2D, and no .winmd processing at build time (cf. wangwenx190/Win32Acrylic, selastingeorge/Win32-Acrylic-Effect, ahmed605/10Mica for the Win10-on-Win11-backport variant; ALTaleX531/OpenGlass for the injection-based alternative on Win10).

## References
- <https://github.com/ALTaleX531/Win32Acrylic>
