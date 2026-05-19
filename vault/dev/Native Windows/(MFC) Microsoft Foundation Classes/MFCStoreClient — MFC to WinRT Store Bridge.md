# MFCStoreClient - MFC to WinRT Store Bridge

MFCStoreClient shows how a classic MFC desktop app can call `Windows.Services.Store` when distributed through Desktop Bridge/MSIX. The architectural point is isolation: keep WinRT/C++/CX code in a helper DLL and late-load it from the MFC executable, rather than enabling `/ZW` across the whole legacy project and contaminating unrelated translation units with projection rules and compiler switches.

That pattern still matters even if you replace C++/CX with C++/WinRT. The classic app remains a native MFC executable with ordinary startup and fallback behavior; the WinRT-facing module is loaded only when package identity and OS support exist. Connect this to Windows App SDK bootstrapping and Win32-to-WinRT notes: all three are about adding modern Windows APIs without rewriting the host application.

## References
- <https://github.com/microsoft/MFCStoreClient> - Microsoft sample for accessing Store APIs from an MFC desktop app through a WinRT helper component.
