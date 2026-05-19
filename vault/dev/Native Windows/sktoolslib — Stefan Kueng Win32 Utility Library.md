# sktoolslib - Stefan Kueng Win32 Utility Library

Stefan Kueng's shared C++ utility library backs practical Windows tools such as TortoiseSVN/TortoiseGit-adjacent components, grepWin, and BowPad. The library is a good counterweight to framework-heavy desktop code: RAII wrappers for HANDLE/HKEY/GDI objects, registry and path helpers, MRU/menu utilities, thread-pool glue, file-system watching, and thumbnail/diff-cache infrastructure gathered from shipping shell tools.

The important connection is to WTL, WIL, and Win32xx. All three try to make raw Win32 less error-prone, but sktoolslib is application-maintainer code rather than a public abstraction layer: its APIs reflect years of Explorer integration, filesystem edge cases, and native UI plumbing rather than a clean teaching sample.

Code contribution: mine it for RAII around `HANDLE`, `HKEY`, and GDI objects, plus shell/file helpers that show how shipping tools wrap raw Win32 failure paths.

## References
- <https://github.com/stefankueng/sktoolslib> - production-oriented helper library for native Windows desktop utilities.
