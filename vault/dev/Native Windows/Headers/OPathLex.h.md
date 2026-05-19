# OPathLex.h

OPath / WQL lexer table -- keyword set, operator precedence, and token-class encoding consumed by the generic engine in `GenLex.h`. "OPath" is the WMI query language's path syntax (`Win32_Process.Handle="1234"`, plus relational `WHERE` clauses), which is a strict subset of WQL -- itself a strict subset of SQL-92. OPath is what `IWbemServices::GetObject(L"\\\\.\\root\\cimv2:Win32_LogicalDisk.DeviceID='C:'", ...)` is parsing. SDK-internal; no part of the public Win32 headers exposes it. Cluster: `GenLex.h` (engine), `wbemcli.h` (consumer-facing WMI COM API), `wmiutils.h` (`IWbemPath` does the same job as a runtime object model).

## References
- <https://learn.microsoft.com/en-us/windows/win32/wmisdk/querying-with-wql>
