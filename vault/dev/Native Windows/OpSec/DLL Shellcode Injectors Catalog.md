# DLL Shellcode Injectors Catalog

`Injectors` is a survey repo for process-injection families: remote thread plus DLL load, shellcode allocation/execution, APC-style delivery, mapping tricks, and related variants. The page should be used as a classification index, not as implementation guidance.

For defenders, classify by required privileges, target handle rights, memory protections, thread-creation artifacts, module visibility, and whether the payload becomes a normal loader-known image. Connect this to `Blackbone Process Manipulation Library` for a production-grade library and `Win32 Process Snippet Utilities` for simple ToolHelp/process plumbing.

## References
- <https://github.com/rootm0s/Injectors>
