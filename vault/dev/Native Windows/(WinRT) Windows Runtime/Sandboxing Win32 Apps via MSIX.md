# Sandboxing Win32 Apps via MSIX

`win32-app-isolation` is Microsoft's attempt to put ordinary desktop apps into an AppContainer-like sandbox through MSIX packaging instead of rewriting them as UWP. The important part is the profiling workflow: run the app, observe file/registry/COM/named-object usage, and generate a manifest capability set narrow enough for isolation but broad enough for the legacy program to function.

This is the packaging counterpart to WinRT/WinUI interop. Xaml Islands and Windows App SDK bring modern UI/API surfaces into Win32; isolated Win32 does the inverse by bringing some UWP-style containment to desktop binaries. The tension is predictable: legacy apps often assume ambient filesystem, registry, COM, and IPC access that a manifest has to broker explicitly.

## References
- <https://github.com/microsoft/win32-app-isolation> - tooling and samples for MSIX/AppContainer-style isolation of Win32 applications.
