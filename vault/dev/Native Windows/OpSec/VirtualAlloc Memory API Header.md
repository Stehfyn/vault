# VirtualAlloc Memory API Header

`memoryapi.h` is not inherently offensive, but it is central to both benign runtime systems and malware analysis because allocation, protection changes, and region queries define the executable-memory lifecycle. `VirtualAlloc`, `VirtualProtect`, and `VirtualQuery` are the vocabulary for JITs, loaders, debuggers, unpackers, and injection detectors.

Keep this page as a neutral anchor for memory-permission discussions. It connects to process manipulation, PE loading, shellcode analysis, and defensive rules that look for unusual writable-to-executable transitions rather than assuming every allocation is suspicious.

Minimal call-shape for benign and suspicious loaders alike:

```cpp
void* base = VirtualAlloc(nullptr, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
// bytes are produced by a loader, decompressor, JIT, unpacker, or test harness.
DWORD old_protect = 0;
BOOL changed = VirtualProtect(base, size, PAGE_EXECUTE_READ, &old_protect);

MEMORY_BASIC_INFORMATION mbi = {};
SIZE_T got = VirtualQuery(base, &mbi, sizeof(mbi));
```

Use the shape to ask better questions: who produced the bytes, whether the transition was private memory or mapped image memory, whether the region is later referenced by a thread start/callback, and whether this was in the local process or a remote target.

## Experiment Harness

Goal: verify page-state and page-protection rules in the current process only.

Procedure:

```cpp
SYSTEM_INFO si = {};
GetSystemInfo(&si);

void* reserved = VirtualAlloc(nullptr, si.dwPageSize * 2, MEM_RESERVE, PAGE_NOACCESS);
void* committed = VirtualAlloc(reserved, si.dwPageSize, MEM_COMMIT, PAGE_READWRITE);

DWORD old = 0;
BOOL ok_rw_rx = VirtualProtect(committed, si.dwPageSize, PAGE_READONLY, &old);
BOOL ok_uncommitted = VirtualProtect((BYTE*)reserved + si.dwPageSize,
                                     si.dwPageSize, PAGE_READONLY, &old);

MEMORY_BASIC_INFORMATION mbi = {};
VirtualQuery(reserved, &mbi, sizeof(mbi));
```

Signals to record: allocation granularity, page size, base address, `MEMORY_BASIC_INFORMATION.State`, `Protect`, `RegionSize`, `VirtualProtect` result, old protection, and `GetLastError`. Expected baseline: protection changes succeed on committed pages and fail when the range includes uncommitted pages. If a tiny range straddles a page boundary, both touched pages are in scope; test this deliberately with `dwSize = 2` at `page_end - 1`.

## References
- `memoryapi.h`
- <https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualalloc>
- <https://learn.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotect>
