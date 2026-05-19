# WinUI 3 via cl.exe (No MSBuild)

This sample strips WinUI 3 down to the actual compiler and linker inputs. The important pieces are projection generation from Windows SDK and Windows App SDK metadata, include paths for generated C++/WinRT headers, `windowsapp.lib`/WindowsAppRuntime bootstrap libraries, and a manifest/resource setup that gives `Microsoft.UI.Xaml` a usable activation context.

It is valuable when MSBuild hides the failure. If command-line WinUI cannot activate, inspect the manifest, framework package binding, bootstrapper version, and generated headers before blaming XAML. Pair this with "WinUI 3 Without MIDL" for the source-level simplification and with the bootstrapper note for runtime binding.

## References
- <https://github.com/sotanakamura/winui3-command-line> - minimal command-line build recipe for WinUI 3 with C++/WinRT.
