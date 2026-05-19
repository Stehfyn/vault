# KnownFolders.h — FOLDERID GUIDs Header

`KnownFolders.h` defines the `FOLDERID_*` GUIDs consumed by `SHGetKnownFolderPath`, replacing CSIDL integer constants with stable identifiers for shell locations such as LocalAppData, RoamingAppData, ProgramData, Desktop, Documents, and per-user libraries. The distinction matters for registry work because many apparent folder paths are policy-redirected, profile-relative, or localized; hardcoding `%USERPROFILE%\AppData\Roaming` is weaker than asking the shell for `FOLDERID_RoamingAppData`.

The API returns COM-allocated strings and can resolve per-user, default-user, or token-specific locations depending on flags and token use. Installer custom actions and legacy setup code often misuse these values by writing absolute paths into registry keys that should instead be expanded strings or resolved at run time.

## Connections
- `userenv.h` handles profile loading and environment expansion around the same user-profile boundary.
- `RegStr.h` contains older shell/setup registry path constants; known folders are the newer identity layer above those paths.

## References
- <https://learn.microsoft.com/en-us/windows/win32/shell/knownfolderid>
- <https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/nf-shlobj_core-shgetknownfolderpath>
