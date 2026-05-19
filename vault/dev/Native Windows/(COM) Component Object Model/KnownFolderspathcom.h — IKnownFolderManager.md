# KnownFolderspathcom.h - IKnownFolderManager

`KnownFolderspathcom.h` is the COM side of the known-folder system. `KnownFolders.h` gives the `FOLDERID_*` GUIDs; `IKnownFolderManager` and `IKnownFolder` give code a way to enumerate, resolve, redirect, and inspect the shell's registered known folders without hard-coding paths or old CSIDL constants.

This is the bridge between registry-backed shell state and COM-based shell APIs. Use it when a note needs to explain why `SHGetKnownFolderPath` is only the convenient endpoint: the manager exposes category, definition, canonical name, path, redirection support, and folder identity in a way that matters for installers, profile migration, sandboxing, and shell replacement tools.

## References
- `KnownFolderspathcom.h` - Windows SDK header declaring `IKnownFolderManager` and related known-folder COM interfaces.
