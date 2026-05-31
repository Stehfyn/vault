# WinUI 3 via cl.exe (No MSBuild)

This sample strips WinUI 3 down to the actual compiler and linker inputs. The important pieces are projection generation from Windows SDK and Windows App SDK metadata, include paths for generated C++/WinRT headers, `windowsapp.lib`/WindowsAppRuntime bootstrap libraries, and a manifest/resource setup that gives `Microsoft.UI.Xaml` a usable activation context.

It is valuable when MSBuild hides the failure. If command-line WinUI cannot activate, inspect the manifest, framework package binding, bootstrapper version, and generated headers before blaming XAML. Pair this with "WinUI 3 Without MIDL" for the source-level simplification and with the bootstrapper note for runtime binding.

## Source Code Reading

`sotanakamura/winui3-command-line` reduces the project to five build facts:

1. Install C++/WinRT and Windows App SDK packages with NuGet.
2. Run `cppwinrt.exe` over Windows App SDK metadata and SDK metadata to generate projection headers.
3. Include Windows App SDK `include` plus `Generated Files`.
4. Link `Microsoft.WindowsAppRuntime.Bootstrap.lib`, `Microsoft.WindowsAppRuntime.lib`, and `WindowsApp.lib`.
5. Copy `Microsoft.WindowsAppRuntime.Bootstrap.dll` beside the EXE.

`main.cpp` is intentionally tiny: `init_apartment(single_threaded)`, `MddBootstrapInitialize2(Release::MajorMinor, Release::VersionTag, PACKAGE_VERSION{Runtime::Version::UInt64}, ...)`, `Application::Start`, create `Application` and `Window`, activate, then `MddBootstrapShutdown`.

```cpp
init_apartment(apartment_type::single_threaded);
MddBootstrapInitialize2(Release::MajorMinor, Release::VersionTag,
    PACKAGE_VERSION{Runtime::Version::UInt64},
    MddBootstrapInitializeOptions_OnNoMatch_ShowUI);
Application::Start([](auto&&) { Application(); Window().Activate(); });
MddBootstrapShutdown();
```

Claim -> source/probe -> interpretation:

Claim: MSBuild is not the essence of WinUI 3; metadata, bootstrapper, libraries, manifest, and runtime DLLs are.
Source/probe: delete one input at a time: generated headers, bootstrap import library, bootstrap DLL, runtime installation, manifest embedding. Record whether failure occurs at compile, link, process load, bootstrap, or activation.
Interpretation: this turns "WinUI failed" into a staged diagnosis. Each missing piece fails at a different boundary.

## References
- <https://github.com/sotanakamura/winui3-command-line> - minimal command-line build recipe for WinUI 3 with C++/WinRT.
