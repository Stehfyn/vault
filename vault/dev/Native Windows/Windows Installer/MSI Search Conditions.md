# MSI Search Conditions

Windows Installer's `AppSearch` action sets public properties by consulting the `AppSearch`, `Signature`, `RegLocator`, `IniLocator`, `DrLocator`, and `CompLocator` tables. This is how an MSI detects prior installs, upgrade locations, prerequisite files, registry values, or legacy INI settings before conditions and directory resolution run.

The nuance is sequencing and trust. Searches run inside the MSI action graph, not at arbitrary authoring time, and the property values they set can drive installation paths, feature states, launch conditions, and repair behavior. A loose search can be hijacked by an unrelated file or stale registry value; a narrow search can break upgrades when bitness, per-user/per-machine context, or registry redirection changes.

## Audit Shape

Search routes worth checking in a built MSI: public property in `AppSearch`, key path or filename in `Signature`, registry hive/root in `RegLocator`, INI section/key in `IniLocator`, and directory depth in `DrLocator`.

```sql
SELECT `Property`, `Signature_` FROM `AppSearch`
SELECT `Signature_`, `Root`, `Key`, `Name`, `Type` FROM `RegLocator`
SELECT `Signature_`, `FileName`, `Section`, `Key`, `Field` FROM `IniLocator`
```

## Experiment Harness

Create one MSI property backed by registry and one backed by INI, then install with verbose logging and mutate the inputs between runs.

```powershell
reg add HKCU\Software\Harness /v InstallRoot /t REG_SZ /d C:\Harness /f
msiexec /i probe.msi /l*v appsearch.log /qn
findstr /i "AppSearch PROPERTY INSTALLROOT" appsearch.log
```

Table probes to run before installation:

```sql
SELECT `Property`,`Signature_` FROM `AppSearch`
SELECT `Signature_`,`Root`,`Key`,`Name`,`Type` FROM `RegLocator`
SELECT `Signature_`,`FileName`,`Section`,`Key`,`Type` FROM `IniLocator`
```

Signal: public properties appear in the verbose log after `AppSearch` and before conditions that consume them. Failure interpretation: absent property means the locator did not match; wrong value usually means registry view, per-user/per-machine context, INI mapping, or table sequencing is wrong. A successful MSI build does not prove detection correctness.

## Discussion Claim To Verify

Claim from installer folklore and migration videos: an installer "detects the old app" because the authoring project contains a search condition.

Why it matters: the built MSI database and the runtime action sequence are the truth. Authoring UI screenshots, `.vdproj` settings, and WiX fragments can all diverge from the final tables consumed by `msiexec`.

Verification route:

```powershell
msiexec /i probe.msi /qn /l*v appsearch.log
findstr /i "Action start.*AppSearch AppSearch PROPERTY" appsearch.log
```

Database assertions:

```sql
SELECT `Property`,`Signature_` FROM `AppSearch`
SELECT `Signature_`,`Root`,`Key`,`Name`,`Type` FROM `RegLocator`
SELECT `Action`,`Condition`,`Sequence` FROM `InstallExecuteSequence`
```

Interpretation:
- Search rows exist but verbose log never runs `AppSearch`: sequencing or condition suppressed the detection.
- Log runs `AppSearch` but property is absent: locator did not match the live machine state.
- Property is set from an unexpected view/path: bitness, HKCU/HKLM context, or INI file mapping is the claim to test next.

## Connections
- `INI File API` explains why MSI INI searches may interact with registry-backed profile mapping.
- `MsiQuery.h` is useful when auditing the actual search tables in a built MSI.
- `RegStr.h` and `KnownFolders.h` help distinguish brittle hardcoded shell paths from identity-based folder discovery.
- `App Compat Cache` is the testing caveat after changing detection/shim inputs: compatibility state may be cached outside the MSI database.

## References
- <https://learn.microsoft.com/en-us/windows/win32/msi/searching-for-existing-applications-files-registry-entries-or--ini-file-entries>
- <https://learn.microsoft.com/en-us/windows/win32/msi/appsearch-table>
- <https://learn.microsoft.com/en-us/windows/win32/msi/appsearch-action>
- <https://learn.microsoft.com/en-us/windows/win32/msi/reglocator-table>
- <https://learn.microsoft.com/en-us/windows/win32/msi/inilocator-table>
- <https://youtu.be/xzIeQWLDSu4?si=A0l3-D_urNPBWldO&t=2462>
