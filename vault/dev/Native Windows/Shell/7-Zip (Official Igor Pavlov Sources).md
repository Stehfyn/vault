# 7-Zip (Official Igor Pavlov Sources)

Igor Pavlov's official 7-Zip repo (mirror of 7-zip.org sources). The C/C++ codebase exposes a stable streaming-archive API (`ISequentialInStream`/`ISequentialOutStream`, `IInArchive`/`IOutArchive`) implemented against COM-style `IUnknown` without OLE, which third parties can link to (cf. mcmilk/7-Zip-zstd, myfreeer/7z-build-nsis). The shell extension (`7-zip.dll`) is a textbook example of an `IShellFolder`/`IContextMenu` implementation, useful as a reference even if you don't ship the archiver itself.

## References
- <https://github.com/ip7z/7zip>
