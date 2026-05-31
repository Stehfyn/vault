# msix-packaging — Cross-Platform MSIX/AppX SDK

`msix-packaging` is Microsoft's cross-platform SDK for reading and, in supported configurations, producing MSIX/AppX packages without depending on Windows-only `makeappx.exe` flows. It exposes COM-style package, manifest, and block-map readers plus a C API, which makes it useful in CI systems, signing/validation tools, and non-Windows package inspection.

The package model is still the same: manifest identity, payload files, block map, signature/catalog footprint, and optional bundle layout. This project is about manipulating that structure; it is not the deployment service, Store policy, or runtime container.

## Source Code Reading

The `microsoft/msix-packaging` repository has two useful layers: package-structure APIs and `MsixCore`, which installs/removes packages on downlevel systems.

Files read:
- `MsixCore/msixmgrLib/PackageManager.cpp`
- `MsixCore/Tests/MsixCoreTest/MsixCoreTest.cpp`
- `MsixCore/msixmgr/AppExecutionAlias.cpp`
- `MsixCore/msixmgrLib/MsixTraceLoggingProvider.cpp`
- `Microsoft.MSIX.Packaging.targets`

`PackageManager.cpp` composes the runtime flow. `AddPackageAsync(path)` routes to the Windows 10 redirector on RS3-or-later systems; otherwise it opens the package as an `IStream` and calls the stream overload. The stream overload creates an `MsixRequest` with `OperationType::Add`, sets an optional callback on `MsixResponse`, starts a detached worker thread, and calls `ProcessRequest`.

```cpp
// Pseudocode from MsixCore/msixmgrLib/PackageManager.cpp
AddPackageAsync(path):
  if IsWindows10RS3OrLater():
      Windows10Redirector::AddPackageWithProgress(path, response)
  else:
      stream = CreateStreamOnPackageUrl(path)
      return AddPackageAsync(stream, options, callback)

AddPackageAsync(stream):
  impl = MsixRequest::Make(OperationType::Add, stream, "", FULL)
  impl->GetMsixResponse()->SetCallback(callback)
  thread([impl] { impl->ProcessRequest(); delete impl; }).detach()
```

`MsixCoreTest.cpp` is the best test-driver reference. It calls `MsixCoreLib_CreatePackageManager`, installs `scribble.appx`, queries installed packages, removes the package, tests progress callbacks with `CreateEvent` / `WaitForSingleObject`, and tests installation from an `IStream` including a resource-backed stream via `FindResource`, `LoadResource`, `LockResource`, `CreateStreamOnHGlobal`, and `IStream::Write`.

Practical probe:
1. Call `AddPackage(path)` for a local `.msix` and verify `FindPackages(L"*")`.
2. Repeat with `AddPackageAsync`; wait on an event set by the completion callback.
3. Repeat with an `IStream` from file and one from memory to separate package parsing from path handling.
4. On Windows 10 RS3+, expect redirector behavior; on downlevel, expect `MsixRequest::ProcessRequest` and local file mapping behavior.

## Connections
- `AppX Package API` is the Windows SDK API for the same package concepts.
- `MSIX Package Support Framework` is what you reach for when a valid package still contains an app that assumes MSI-era write locations.

## References
- <https://github.com/microsoft/msix-packaging>
