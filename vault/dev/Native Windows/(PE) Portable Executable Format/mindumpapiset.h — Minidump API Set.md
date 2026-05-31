# mindumpapiset.h - Minidump API Set

`mindumpapiset.h` is the API-set-facing header around minidump availability and declarations. In practice, most dump-writing code still revolves around DbgHelp's `MiniDumpWriteDump`, but API sets explain how modern Windows decouples import names from concrete DLL implementation details.

The header belongs in the PE area because API sets are a loader and import-resolution topic as much as a debugging topic. A binary importing an API-set contract does not necessarily import the final host DLL name that services the call at runtime.

## Import Route

For dump tools, the common source-level call remains DbgHelp, but the binary may show API-set contracts rather than the old concrete DLL path. That distinction matters when comparing import tables across OS versions.

```c
BOOL ok = MiniDumpWriteDump(process, pid, file,
                            MiniDumpWithFullMemory,
                            NULL, NULL, NULL);
```

## Experiment Harness

Drive dump type by question, not habit. Dump the same target twice and compare size plus presence of a known heap string.

```powershell
.\dump.exe pid MiniDumpNormal normal.dmp
.\dump.exe pid MiniDumpWithFullMemory full.dmp
dir *.dmp
strings full.dmp | findstr "SENTINEL_HEAP_VALUE"
```

Signal: `MiniDumpNormal` is smaller and may omit private heap bytes; `MiniDumpWithFullMemory` should contain the sentinel if access rights permit. Failure interpretation: `MiniDumpWriteDump` failure commonly means insufficient process rights, protected-process policy, cross-bitness tooling limits, or unsafe crash-time code, not a PE parsing error.

## Connections
- `Process Dump Tools` covers the diagnostic workflow that uses minidumps.
- XPEViewer can inspect import tables and API-set-style dependencies in binaries.
- `ProcessSnapshot.h` supplies a stable capture primitive before the dump stage.
- `sdkddkver.h` is the compile-time side of API-set visibility; PE import inspection is the load-time side.

## References
- Windows SDK `mindumpapiset.h`
- <https://learn.microsoft.com/en-us/windows/win32/api/minidumpapiset/nf-minidumpapiset-minidumpwritedump>
