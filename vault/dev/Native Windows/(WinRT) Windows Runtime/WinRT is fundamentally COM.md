# WinRT is Fundamentally COM

WinRT is not "managed Windows"; it is a COM-family ABI with metadata, activation factories, `HSTRING`, `IInspectable`, and language projections layered above it. A projected call in C++/WinRT or C# eventually becomes `RoGetActivationFactory`, `QueryInterface`, reference counting, HRESULTs, and vtable calls.

That fact explains both the power and the friction. WinRT can be consumed from C, C++, Rust, Python bindings, and .NET because the ABI is stable; it is painful without projections because every inherited slot, async interface, generic collection interface, and string/lifetime rule must be declared exactly. Read this before assuming WinRT requires UWP or XAML.

## References
- <https://stackoverflow.com/questions/7436144/using-winrt-from-c/7437006#7437006> - concise explanation of WinRT's COM-style activation and ABI.
