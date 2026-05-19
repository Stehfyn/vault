# GenLex.h

Internal SDK header for a generic, table-driven lexer used by the WMI / OPath / WQL parser infrastructure (`wbemcli`, `provifc`). Pairs with `OPathLex.h`: `GenLex.h` is the lexer engine -- token classes, state-table transitions, lookahead buffering -- and `OPathLex.h` plugs in the OPath/WQL keyword and operator table. Not in the public Windows SDK documentation; you'll only encounter it when reverse-engineering WMI provider internals or building a third-party WQL parser. Almost no code outside WMI ever includes it directly.

## References
- <https://learn.microsoft.com/en-us/windows/win32/wmisdk/wmi-start-page>
