# Microsoft IPC — Shared Memory IPC Library

Microsoft's shared-memory IPC library for Windows: a C++ implementation plus a `.NET` (managed C++/CLI) wrapper. Lets a process group share typed records over named-file-mapping segments with sync provided by `Mutex`/`Event` kernel objects rather than pipes/sockets. Useful as a reference of the "right" way to lay out a header + ring/blob in shared memory and to use `CreateFileMapping(... INVALID_HANDLE_VALUE ...)` for non-backed page-file-backed sections.

## References
- <https://github.com/microsoft/IPC>
