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

## Source Shape

The sample repeatedly does the same ABI move: convert a runtime-class name into an `HSTRING`, ask for a factory or static interface, then invoke the vtable directly. That is the useful portable pattern to steal.

```c
IActivationFactory *factory = NULL;
HRESULT hr = RoGetActivationFactory(
    HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Controls_TextBlock),
    &IID_IActivationFactory,
    (void **)&factory);

IInspectable *instance = NULL;
factory->lpVtbl->ActivateInstance(factory, &instance);
```

Application startup is the same idea against the `Application` static interface:

```c
IApplicationStatics *app_statics = NULL;
RoGetActivationFactory(
    HSTRING_CSTR(RuntimeClass_Microsoft_UI_Xaml_Application),
    &IID_IApplicationStatics,
    (void **)&app_statics);

app_statics->lpVtbl->Start(app_statics, callback);
```

## Source Code Reading

`main.c` is more than a factory demo. It hand-builds the minimum WinUI app object model:

- `STATIC_HSTRING` and `HSTRING_CSTR` fake fast-pass HSTRING references for literal runtime class names.
- `DEFINE_GUID` declarations pin the ABI interface IDs that C++/WinRT would normally hide.
- `MyButtonClicker` implements `IRoutedEventHandler` as a C struct whose first field is the interface vtable.
- `MyApplication` implements `IApplicationOverrides`, keeps pointers to the inner WinUI `IApplication`, `IXamlMetadataProvider`, and created `IWindow`.
- `MyApplicationInitializationCallback` implements `IApplicationInitializationCallback` and is passed to `IApplicationStatics::Start`.

The application object is a COM aggregation-shaped bridge. `MyApplication_IApplicationOverrides_QueryInterface` returns the override interface for `IUnknown` / `IApplicationOverrides`, returns the inner `IApplication` for `IInspectable` / `IApplication`, returns the metadata provider for `IXamlMetadataProvider`, and forwards unknown interfaces to the inner application. That forwarding is the detail a reader needs: WinUI asks the app object for metadata, not just launch callbacks.

```c
if (riid == IID_IApplicationOverrides) return &app->overrides;
if (riid == IID_IApplication) return app->instance;
if (riid == IID_IXamlMetadataProvider) return app->metadata;
return app->inner->lpVtbl->QueryInterface(app->inner, riid, ppv);
```

`OnLaunched` constructs the visual tree by explicit interface hops. It activates `XamlControlsResources`, appends it to `Application.Resources().MergedDictionaries()`, activates `Window`, `TextBlock`, `Button`, and `StackPanel`, queries each object for the interface that owns the next method, sets dependency-property-like values through ABI methods, appends children to `Panel.Children`, then calls `Window.Content(stackPanel)` and activates the window.

```c
factory(TextBlock)->ActivateInstance(&i);
i->QueryInterface(&IID_ITextBlock, &text);
text->put_Text(text, HSTRING_CSTR(L"Hello, World!"));
text->QueryInterface(&IID_IUIElement, &textElement);
children->Append(children, textElement);
window->put_Content(window, panelElement);
```

`build.cmd` is just as important as `main.c`: it downloads Windows App SDK NuGets, runs `winmdidl.exe` over `Microsoft.UI.Xaml.winmd`, patches include gaps, copies runtime framework DLLs including `Microsoft.WindowsAppRuntime.dll`, builds `main.pri`, embeds a manifest generated from the Windows App Runtime MSIX inputs, then invokes `cl.exe` directly. That is the self-contained package-graph answer to "why does `Microsoft.UI.Xaml.*` activate from a plain C executable?"

## References
- <https://github.com/mmozeiko/hello-world-winui3-c> - plain-C WinUI 3 sample that hand-declares the needed ABI interfaces.

## Connections
- `WinRT is fundamentally COM.md` explains why this is possible rather than just a stunt.
- `Windows App SDK Bootstrapper.md` explains the runtime-package binding that must succeed before `Microsoft.UI.Xaml.Application` activation works in an unpackaged EXE.
- `WinUI 3 Without MIDL (Consumer Only).md` and `WinUI 3 Without XAML.md` are less extreme variants when the goal is build-system simplification, not full ABI hand-declaration.

## Experiment Harness

Goal: isolate ABI declaration bugs from Windows App Runtime deployment bugs.

```c
/* Phase 1: activate an OS WinRT class. */
probe_factory(L"Windows.Globalization.Calendar", &IID_IActivationFactory);

/* Phase 2: after bootstrap/runtime load, activate a WinUI class. */
probe_factory(L"Microsoft.UI.Xaml.Controls.TextBlock", &IID_IActivationFactory);
```

Measured signal: factory HRESULTs, module load list, class name, and whether the same class activates through C++/WinRT.

Failure interpretation: OS class succeeds but WinUI class fails means package/runtime binding; both fail means apartment/HSTRING/IID/vtable declaration; C++/WinRT succeeds while pure C fails means the handwritten ABI is wrong. References: <https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.controls.textblock> and <https://learn.microsoft.com/en-us/windows/windows-app-sdk/api/win32/mddbootstrap/nf-mddbootstrap-mddbootstrapinitialize>.
