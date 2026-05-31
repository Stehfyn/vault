# Microsoft IPC — Shared Memory IPC Library

Microsoft's shared-memory IPC library for Windows: a C++ implementation plus a `.NET` (managed C++/CLI) wrapper. Lets a process group share typed records over named-file-mapping segments with sync provided by `Mutex`/`Event` kernel objects rather than pipes/sockets. Useful as a reference of the "right" way to lay out a header + ring/blob in shared memory and to use `CreateFileMapping(... INVALID_HANDLE_VALUE ...)` for non-backed page-file-backed sections.

Call-shape worth carrying into adjacent IPC notes:

```cpp
HANDLE section = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr,
                                    PAGE_READWRITE, 0, bytes,
                                    L"Local\\AppSharedState");
void* view = MapViewOfFile(section, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, bytes);
HANDLE ready = CreateEventW(nullptr, FALSE, FALSE, L"Local\\AppSharedStateReady");
```

The boundary is object namespace plus access mask, not a socket endpoint. Connect this to `Shared Memory Double Map` for virtual-layout tricks and to OpSec driver notes only when shared memory is used as a user/kernel or helper-process command channel.

## Verification Route

Claim to verify: named shared memory plus named events/mutexes gives a process group an IPC channel without pipes or sockets.

Why it matters: the mechanism is simple, but the bugs are in namespace selection, access masks, security descriptors, record layout, and wakeup/lifetime ordering.

Probe:

```cpp
HANDLE section = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr,
                                    PAGE_READWRITE, 0, sizeof(Header) + payload,
                                    L"Local\\IpcProbe.Section");
DWORD create_err = GetLastError(); // ERROR_ALREADY_EXISTS means peer created it.

auto* view = (Header*)MapViewOfFile(section, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
HANDLE ready = CreateEventW(nullptr, FALSE, FALSE, L"Local\\IpcProbe.Ready");
```

Verification commands:

```powershell
Get-Process -Id $pid | Select-Object Id,ProcessName,SessionId
# Sysinternals WinObj: inspect \Sessions\<n>\BaseNamedObjects\IpcProbe.*
```

Interpretation:
- One process sees `ERROR_ALREADY_EXISTS` and reads the peer's header: object namespace and mapping identity work.
- Service and desktop app cannot see each other: `Local\`/`Global\`, session isolation, or security descriptor is the claim to test.
- Event fires but record header is torn/stale: synchronization exists, but memory-ordering/protocol design is wrong.

## References
- <https://github.com/microsoft/IPC>
