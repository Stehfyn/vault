# mindumpapiset.h - Minidump API Set

`mindumpapiset.h` is the API-set-facing header around minidump availability and declarations. In practice, most dump-writing code still revolves around DbgHelp's `MiniDumpWriteDump`, but API sets explain how modern Windows decouples import names from concrete DLL implementation details.

The header belongs in the PE area because API sets are a loader and import-resolution topic as much as a debugging topic. A binary importing an API-set contract does not necessarily import the final host DLL name that services the call at runtime.

## Connections
- `Process Dump Tools` covers the diagnostic workflow that uses minidumps.
- XPEViewer can inspect import tables and API-set-style dependencies in binaries.

## References
- Windows SDK `mindumpapiset.h`
