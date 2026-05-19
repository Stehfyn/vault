# GetOEMCP — Console OEM Code Page

`GetOEMCP` returns the system OEM code page, the historical DOS/console byte encoding used by functions that still distinguish OEM from ANSI code pages. It is not the active console input/output code page (`GetConsoleCP`, `GetConsoleOutputCP`) and it is not the Windows ANSI code page (`GetACP`). That distinction matters when porting no-CRT or assembly tools that parse `argv` manually: byte strings from the process command line, console APIs, and files can all imply different legacy encodings unless the program converts at the boundary.

Prefer UTF-16 Win32 APIs or explicit UTF-8 conversion with `MultiByteToWideChar(CP_UTF8, ...)`. `GetOEMCP` is mainly useful when maintaining old tools that must interpret OEM-encoded filenames, batch-file input, or console text produced before UTF-8 console modes became viable.

## Connections
- `processenv.h` covers command-line/environment retrieval; use wide APIs there to avoid OEM/ANSI ambiguity.
- `utf8.h` is the opposite approach: keep internal strings as UTF-8 and widen only for Win32 calls.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/winnls/nf-winnls-getoemcp>
