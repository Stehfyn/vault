# WinUI 3 Without XAML (sotanakamura)

This is the object-graph lesson: XAML markup is a serializer and code generator for `Microsoft.UI.Xaml` objects, not the only way to create them. The sample constructs `Window`, panels, text, buttons, handlers, and layout imperatively with C++/WinRT, which removes XAML compilation from the build and makes control lifetime explicit.

Keep this separate from "Without MIDL." No-XAML removes markup; no-MIDL removes app-defined WinRT type generation. A project can do either, both, or neither. This distinction matters when debugging build systems because XAML compiler failures, MIDL failures, and WinRT activation failures have different causes.

## References
- <https://github.com/sotanakamura/winui3-without-xaml> - C++/WinRT sample that builds a WinUI 3 visual tree entirely in code.
