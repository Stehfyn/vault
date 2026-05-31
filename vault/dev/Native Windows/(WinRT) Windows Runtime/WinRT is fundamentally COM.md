# WinRT is Fundamentally COM

WinRT is not "managed Windows"; it is a COM-family ABI with metadata, activation factories, `HSTRING`, `IInspectable`, and language projections layered above it. A projected call in C++/WinRT or C# eventually becomes `RoGetActivationFactory`, `QueryInterface`, reference counting, HRESULTs, and vtable calls.

That fact explains both the power and the friction. WinRT can be consumed from C, C++, Rust, Python bindings, and .NET because the ABI is stable; it is painful without projections because every inherited slot, async interface, generic collection interface, and string/lifetime rule must be declared exactly. Read this before assuming WinRT requires UWP or XAML.

## Source Shape

Source pass: `mmozeiko/hello-world-winui3-c/main.c` demonstrates the raw route. The sample initializes WinRT, loads the Windows App Runtime, asks for activation factories by runtime-class `HSTRING`, then calls factory vtables directly.

```c
RoInitialize(RO_INIT_MULTITHREADED);
LoadLibraryW(L"Microsoft.WindowsAppRuntime.dll");

IApplicationStatics *appStatics = NULL;
RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Application),
                       &IID_IApplicationStatics,
                       (void **)&appStatics);

IActivationFactory *factory = NULL;
RoGetActivationFactory(HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Controls_TextBlock),
                       &IID_IActivationFactory,
                       (void **)&factory);

IInspectable *instance = NULL;
factory->lpVtbl->ActivateInstance(factory, &instance);
instance->lpVtbl->QueryInterface(instance, &IID_ITextBlock, (void **)&text);
```

The source-derived lesson is blunt: C++/WinRT removes handwritten declarations and lifetime noise; it does not change the binary path.

## Discussion Claims To Test

Claim: WinRT classes are reached through COM-style runtime activation.
Source/probe: the linked Stack Overflow answer is useful as a pointer to the raw activation contract; the check is `WindowsCreateString(className)` plus `RoGetActivationFactory(className, IID_IActivationFactory, &factory)`. Disassemble the projected C++/WinRT call site or set a breakpoint on `combase!RoGetActivationFactory`; the projection still crosses that boundary.
Interpretation: if the breakpoint hits for both raw C and projected C++/WinRT, the "fundamentally COM" claim is operational, not metaphorical.

Claim: `IInspectable` is the extra WinRT ABI layer over `IUnknown`.
Source/probe: query the same object for `IUnknown`, `IInspectable`, and a type-specific interface, then compare controlling `IUnknown` identity while also calling `GetRuntimeClassName` / `GetTrustLevel` through `IInspectable`.
Interpretation: COM identity rules still apply, but WinRT adds metadata-facing inspection. Code that treats a WinRT object as only `IUnknown` can own lifetime but cannot perform WinRT type inspection.

Minimal identity probe:

```cpp
winrt::Windows::Foundation::IInspectable obj =
    winrt::Windows::Globalization::Calendar();

auto unknownA = obj.as<IUnknown>();
auto inspect = obj.as<IInspectable>();
wil::com_ptr<IUnknown> unknownB;
inspect->QueryInterface(IID_PPV_ARGS(&unknownB));

printf("inspect=%p unkA=%p unkB=%p\n", inspect, unknownA.get(), unknownB.get());
```

Disassembly route: build the equivalent C++/WinRT call with `/Od /Zi`, break on `combase!RoGetActivationFactory`, and then step out into the generated projection thunk. The useful observation is not the C++ syntax; it is that projection code still hands an `HSTRING` runtime class name to COM activation and receives an interface pointer governed by COM lifetime.

Claim: WinAppSDK failures are often package-graph failures, not ABI failures.
Source/probe: activate `Windows.Globalization.Calendar` first, then `Microsoft.UI.Xaml.Controls.TextBlock` before and after bootstrapper/self-contained runtime setup.
Interpretation: OS WinRT class success proves apartment, HSTRING, and vtable mechanics. `Microsoft.UI.*` failure after that points at Windows App Runtime deployment, not at "C cannot call WinRT."

## References
- <https://stackoverflow.com/questions/7436144/using-winrt-from-c/7437006#7437006> - concise explanation of WinRT's COM-style activation and ABI.

## Connections
- `../(COM) Component Object Model/COM in plain C.md` is the prerequisite ABI shape: vtables, `IUnknown`, HRESULTs, and reference counting.
- `Consume Windows Runtime APIs from pure C.md` and `WinUI 3 in Pure C (No cppwinrt).md` prove the point by removing projections entirely.
- `Windows App SDK Bootstrapper.md` is the deployment/runtime binding layer that determines whether WinAppSDK WinRT classes can be activated from an unpackaged Win32 process.
- `Xaml Islands Minimal Win32 Host.md` is the HWND-hosting version of the same activation story.
- `../Game Bar/XboxGameBarSamples - Widget Reference Code.md` is the packaged UWP/Game Bar version: activation still arrives as WinRT objects, but manifest identity drives discovery.

## Experiment Harness

Goal: show that projection syntax and raw ABI activation hit the same factory boundary.

```cpp
RoInitialize(RO_INIT_MULTITHREADED);

HSTRING cls;
WindowsCreateString(L"Windows.Globalization.Calendar", 28, &cls);
IActivationFactory *factory = nullptr;
HRESULT hr = RoGetActivationFactory(cls, IID_PPV_ARGS(&factory));

IInspectable *obj = nullptr;
HRESULT hi = factory ? factory->ActivateInstance(&obj) : E_POINTER;
printf("factory=%08lx instance=%08lx factory=%p obj=%p\n", hr, hi, factory, obj);
```

Procedure: repeat with `Microsoft.UI.Xaml.Controls.TextBlock` before and after Windows App SDK bootstrapper initialization.

Measured signal: factory HRESULT, instance HRESULT, apartment model, class name.

Failure interpretation: OS WinRT classes test ABI/apartment correctness; `Microsoft.UI.*` failures often test deployment/package graph, not COM mechanics. References: <https://learn.microsoft.com/en-us/windows/win32/api/roapi/nf-roapi-rogetactivationfactory> and <https://learn.microsoft.com/en-us/windows/win32/api/activation/nn-activation-iactivationfactory>.
