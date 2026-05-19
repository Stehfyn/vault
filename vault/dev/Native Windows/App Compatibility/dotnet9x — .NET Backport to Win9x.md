# dotnet9x - .NET Backport to Win9x

`dotnet9x` backports .NET Framework 2.0/3.x era assumptions onto Windows 95/98/ME, which were never meant to host that runtime. The interesting work is not "install .NET on old Windows"; it is the catalog of NT-only APIs the CLR, installer, and base class libraries quietly assume exist.

Use it as the Win9x counterpart to `VxKex`, `VxKex-NEXT`, `OneCoreAPI`, and `YY-Thunks`. All of them answer the same question at different risk levels: when a binary imports a function the OS does not have, do you patch the app, shim the import, emulate the API, or replace part of the OS surface?

## References
- <https://github.com/itsmattkc/dotnet9x>
