# WinUI 3 in Pure C (No cppwinrt)

Martins Mozeiko's sample is the extreme version of the "WinRT is COM" claim: a WinUI 3 application bootstrapped from C without C++/WinRT, XAML markup, MIDL-generated app classes, or .NET. Every WinRT type needed by the program is represented as a handwritten COM-style vtable, and runtime classes are reached through activation factories.

The sample is not a recommendation for application architecture. It is a diagnostic scalpel for Windows App SDK activation, ABI layout, and projection behavior. If this works, the runtime and activation context are sound; if a higher-level C++/WinRT project fails, the bug is likely in generated code, build inputs, manifests, or app structure.

```c
/* The non-obvious lesson: WinUI statics are just ABI interfaces. */
HSTRING name;
WindowsCreateString(L"Microsoft.UI.Xaml.Application", 29, &name);

IApplicationStatics *statics = NULL;
RoGetActivationFactory(name, &IID_IApplicationStatics, (void **)&statics);
statics->lpVtbl->Start(statics, my_initialization_callback);
```

## References
- <https://github.com/mmozeiko/hello-world-winui3-c> - plain-C WinUI 3 sample that hand-declares the needed ABI interfaces.
