# WinUI 3 Without MIDL (Consumer Only)

This repo demonstrates the key boundary: MIDL is required when the app defines WinRT runtime classes, not when it merely consumes existing WinUI 3 classes. If a program builds its UI in C++ using the prebuilt Windows App SDK projection headers, it can skip `.idl`, app-generated `.winmd`, XAML codegen, and the usual `App.xaml` / `MainWindow.xaml` scaffolding.

The cost is that the app gives up the XAML toolchain: no markup-defined trees, no `x:Bind`, no designer/hot-reload path, and less separation between UI declaration and behavior. The benefit is a WinUI 3 consumer that fits non-MSBuild systems and makes projection boundaries obvious. This is the cleanest C++ middle ground between normal WinUI templates and the pure-C sample.

## References
- <https://github.com/sotanakamura/winui3-without-midl> - C++/WinRT WinUI 3 consumer sample that avoids app-defined MIDL/runtime classes.
