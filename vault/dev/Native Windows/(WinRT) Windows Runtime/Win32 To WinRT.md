# Win32 To WinRT

This small sample is a C++ desktop-to-WinRT bridge: initialize the runtime, get an activation factory for a WinRT class, and call it from a normal Win32 process. It is less radical than the pure-C notes because it can use WRL/C++ helpers such as `ComPtr`, `HStringReference`, and `RoInitializeWrapper`, but it still demonstrates the essential point: a Win32 process can be a WinRT consumer when it respects the apartment and activation rules.

Use this as the middle rung between raw ABI samples and full Windows App SDK/WinUI projects. It is the right shape for code that wants one WinRT feature from a classic executable without adopting XAML, MSIX, or a generated app framework.

## References
- <https://github.com/tgraupmann/Cpp_Win32_To_WinRT/blob/main/main.cpp> - minimal C++ Win32 process consuming a WinRT runtime class.
