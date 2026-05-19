# DbgHelp.h

The headline header for `dbghelp.dll`, the Windows debug helper library. Three loosely related subsystems live here: the PDB symbol engine (`SymInitialize`, `SymFromAddr`, `SymGetLineFromAddr64`), x86/x64/ARM64 stack walking (`StackWalk64`, `StackWalkEx`), and minidump production / consumption (`MiniDumpWriteDump`, `MiniDumpReadDumpStream`). Gotcha: `dbghelp.dll` is shipped both with Windows (in `system32`) and with the Debugging Tools for Windows (`C:\Program Files\Debugging Tools for Windows (x64)\dbghelp.dll`) -- the in-box copy is usually several years behind and is missing newer PDB/portable-PDB support, so production debuggers ship and load a side-by-side copy. The API is not thread-safe: serialize calls per process.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/>
- <https://learn.microsoft.com/en-us/windows/win32/debug/about-dbghelp>
