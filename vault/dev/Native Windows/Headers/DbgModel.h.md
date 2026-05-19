# DbgModel.h

The Debugger Data Model -- the modern, JavaScript-friendly object hierarchy that backs WinDbg Preview's `dx` command, the `!hostsmsg`/`!model` extensions, and the JavaScript / NatVis-extensibility surface. Replaces (without removing) the legacy `dbgeng.h` IDebug* interfaces. Core COM types: `IDebugHost`, `IDebugHostContext`, `IModelObject` (the universal "object in the data model"), `IModelMethod`, `IDataModelManager`. Lets you write an extension DLL that registers a new object type -- say, a model representation of a custom kernel structure -- and have `dx myobj.MyField.MyMethod(arg)` Just Work in the debugger and in scripts. Cluster: `dbgeng.h` (legacy interfaces), `dbghelp.h` (symbols, see other file), `wdbgexts.h` (very legacy kd-extension surface).

## References
- <https://learn.microsoft.com/en-us/windows-hardware/drivers/debugger/data-model-cpp-overview>
