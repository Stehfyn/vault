# msix-packaging — Cross-Platform MSIX/AppX SDK

`msix-packaging` is Microsoft's cross-platform SDK for reading and, in supported configurations, producing MSIX/AppX packages without depending on Windows-only `makeappx.exe` flows. It exposes COM-style package, manifest, and block-map readers plus a C API, which makes it useful in CI systems, signing/validation tools, and non-Windows package inspection.

The package model is still the same: manifest identity, payload files, block map, signature/catalog footprint, and optional bundle layout. This project is about manipulating that structure; it is not the deployment service, Store policy, or runtime container.

## Connections
- `AppX Package API` is the Windows SDK API for the same package concepts.
- `MSIX Package Support Framework` is what you reach for when a valid package still contains an app that assumes MSI-era write locations.

## References
- <https://github.com/microsoft/msix-packaging>
