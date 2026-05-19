# mrmresourceindexer.h

Modern Resource Technology indexing interfaces for building PRI resource maps: the package/resource-index layer behind UWP, WinUI, and packaged Win32 localization/assets. A PRI is not just a string table; it is a compiled decision tree over qualifiers such as language, scale, contrast, theme, and device family. The indexer is what turns loose `.resw`, images, and manifest-declared assets into a resource map the runtime can query through MRT APIs. You usually reach it through MSBuild/makepri, but the header matters when diagnosing why packaged resources resolve differently from classic Win32 `LoadString`/`FindResource`.

Connections: compare with `(WinRT) Windows Runtime/Windows App SDK Bootstrapper.md`, `(WinRT) Windows Runtime/WinUI 3 via cl.exe (No MSBuild).md`, and Installer/MSIX notes; resource identity and package identity are coupled in this stack.

## References
- mrmresourceindexer.h
