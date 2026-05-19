# MSI Search Conditions

Windows Installer's `AppSearch` action sets public properties by consulting the `AppSearch`, `Signature`, `RegLocator`, `IniLocator`, `DrLocator`, and `CompLocator` tables. This is how an MSI detects prior installs, upgrade locations, prerequisite files, registry values, or legacy INI settings before conditions and directory resolution run.

The nuance is sequencing and trust. Searches run inside the MSI action graph, not at arbitrary authoring time, and the property values they set can drive installation paths, feature states, launch conditions, and repair behavior. A loose search can be hijacked by an unrelated file or stale registry value; a narrow search can break upgrades when bitness, per-user/per-machine context, or registry redirection changes.

## Connections
- `INI File API` explains why MSI INI searches may interact with registry-backed profile mapping.
- `MsiQuery.h` is useful when auditing the actual search tables in a built MSI.

## References
- <https://learn.microsoft.com/en-us/windows/win32/msi/searching-for-existing-applications-files-registry-entries-or--ini-file-entries>
- <https://youtu.be/xzIeQWLDSu4?si=A0l3-D_urNPBWldO&t=2462>
