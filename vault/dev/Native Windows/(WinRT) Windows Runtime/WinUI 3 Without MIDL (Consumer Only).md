# WinUI 3 Without MIDL (Consumer Only)

This repo demonstrates the key boundary: MIDL is required when the app defines WinRT runtime classes, not when it merely consumes existing WinUI 3 classes. If a program builds its UI in C++ using the prebuilt Windows App SDK projection headers, it can skip `.idl`, app-generated `.winmd`, XAML codegen, and the usual `App.xaml` / `MainWindow.xaml` scaffolding.

The cost is that the app gives up the XAML toolchain: no markup-defined trees, no `x:Bind`, no designer/hot-reload path, and less separation between UI declaration and behavior. The benefit is a WinUI 3 consumer that fits non-MSBuild systems and makes projection boundaries obvious. This is the cleanest C++ middle ground between normal WinUI templates and the pure-C sample.

## Source Code Reading

`sotanakamura/winui3-without-midl` is not "without XAML"; it is without app-authored WinRT runtime classes. `winui3-without-midl/main.cpp` defines `App` directly in C++ as `ApplicationT<App, IXamlMetadataProvider>`, initializes a `Window`, then calls `Application::LoadComponent(window, Uri(L"ms-appx:///MainPage.xaml"))`. `MainPage.xaml` is just a `Window` with a centered `StackPanel` and `TextBlock`.

```cpp
window = Window();
Application::LoadComponent(window, Uri(L"ms-appx:///MainPage.xaml"));
window.Activate();
```

The `.vcxproj` includes `MainPage.xaml` as a `Page`, includes `Package.appxmanifest`, and compiles only `main.cpp` / `pch.cpp`; there is no app `.idl` file in the project. The metadata provider forwards to `XamlControlsXamlMetaDataProvider`, so built-in WinUI types still resolve even though the app does not define its own runtime class.

Claim -> source/probe -> interpretation:

Claim: MIDL is required for app-defined WinRT types, not for consuming existing WinUI types.
Source/probe: add a custom XAML page class with `x:Class` and app-defined methods; compare generated files and build requirements against the current `MainPage.xaml` without `x:Class`.
Interpretation: the sample is a consumer-only design. The moment XAML needs to instantiate app-defined runtime classes, MIDL/metadata generation returns.

## References
- <https://github.com/sotanakamura/winui3-without-midl> - C++/WinRT WinUI 3 consumer sample that avoids app-defined MIDL/runtime classes.
