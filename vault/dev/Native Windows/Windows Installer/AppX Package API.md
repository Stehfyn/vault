# AppX Package API

The AppX packaging APIs in `appxpackaging.h` are COM interfaces for inspecting and building AppX/MSIX packages: package readers, manifest readers, block maps, encrypted-package variants, and bundle support. They matter when a tool needs package structure rather than installation behavior; deployment, registration, and user entitlement are handled elsewhere.

The key distinction is that an AppX/MSIX package is a signed ZIP-like payload with manifest and block-map contracts. The packaging API can validate and enumerate that payload, while `PackageManager`, MSIX deployment, and PSF shims decide how desktop apps behave once installed.

## Packaging Boundary

The COM writer/reader APIs operate on streams and package footprint files. They do not grant runtime file/registry access to the packaged app; that belongs to identity, capabilities, and deployment policy.

```cpp
ComPtr<IAppxPackageWriter> writer;
// writer->AddPayloadFile(...);
HRESULT hr = writer->Close(manifestStream.Get());
```

## Experiment Harness

Separate package structure from runtime behavior. Read a known package, enumerate manifest identity and payload files, then compare that to what the installed process can access.

```text
IAppxFactory::CreatePackageReader(stream)
  -> GetManifest()
  -> GetPayloadFiles()
  -> compare names against AppxManifest.xml and package layout
```

Signal: manifest identity, architecture, and payload list match the package contents before deployment. Failure interpretation: package-reader success proves the package shape is readable; it does not prove installability, capability access, PSF behavior, or AppContainer file permissions.

## Connections
- `msix-packaging` is the cross-platform SDK cousin of this Windows COM API.
- `MSIX Package Support Framework` handles runtime compatibility after packaging.
- `Fileapifromapp.h` is the packaged-process file API boundary once identity and capabilities are active.
- `mrmresourceindexer.h` is the resource-index side of the same package identity story.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/_appxpkg/>
- <https://learn.microsoft.com/en-us/windows/win32/api/appxpackaging/nf-appxpackaging-iappxpackagewriter-close>
