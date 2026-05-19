# sdkddkver.h

The header that decides which APIs your TU sees. Defines `_WIN32_WINNT_*` (NT version constants -- `_WIN32_WINNT_WINXP=0x0501`, `_WIN32_WINNT_VISTA=0x0600`, `_WIN32_WINNT_WIN7=0x0601`, `_WIN32_WINNT_WIN8=0x0602`, `_WIN32_WINNT_WINBLUE=0x0603`, `_WIN32_WINNT_WIN10=0x0A00`) and `NTDDI_*` (a finer-grained 32-bit "major.minor.servicepack.subversion" code: `NTDDI_WIN10_RS5`, `NTDDI_WIN10_19H1`, `NTDDI_WIN10_VB`, `NTDDI_WIN10_NI`, `NTDDI_WIN11_*`, ...). The SDK headers gate API declarations with `#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)` -- set the target version too low and a perfectly-shipping API simply doesn't exist as far as the compiler is concerned. Set it too high and you get binaries that fail to load on the older OS. The convention: define `WINVER`, `_WIN32_WINNT`, and `NTDDI_VERSION` before *any* SDK include, ideally in the project / preprocessor settings rather than per-file.

## References
- <https://learn.microsoft.com/en-us/windows/win32/winprog/using-the-windows-headers>
- <https://learn.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt>
