# MSIX Package Support Framework — Compatibility Shims

Microsoft's Package Support Framework is a compatibility shim layer for Win32 desktop apps repackaged as MSIX. It injects fixup DLLs into selected packaged processes and intercepts APIs such as file and registry access so code that expects writable install directories or HKLM state can survive inside the package/container model.

The `config.json` matters because PSF is precise only when scoped precisely. Broad redirection can hide real packaging bugs, while narrow redirection can let a legacy app fail only after deployment. This entry belongs beside installer topics because PSF is a packaging-time compatibility decision, not a general application architecture.

## Connections
- `Fileapifromapp.h` is the AppContainer-compatible file API surface PSF often works around.
- `AppX Package API` and `msix-packaging` handle package structure; PSF handles runtime behavior.

## References
- <https://github.com/microsoft/MSIX-PackageSupportFramework>
