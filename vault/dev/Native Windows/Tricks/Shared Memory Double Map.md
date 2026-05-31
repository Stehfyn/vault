# Shared Memory Double Map

Raymond Chen's note explains a deceptively useful VM trick: map the same file-mapping object more than once and you get distinct virtual addresses backed by the same physical pages. Writes through either view are immediately visible through the other because the aliasing happens below the virtual address layer.

This is useful for ring buffers, wraparound-free parsers, and IPC designs where pointer arithmetic is simpler if the same storage appears twice contiguously. Connect it to `Microsoft IPC - Shared Memory Library` and any memory-mapped file notes; the trick is about virtual layout, not persistence.

Structure-level view:

```cpp
HANDLE section = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr,
                                    PAGE_READWRITE, 0, ring_bytes, nullptr);
void* first = MapViewOfFile(section, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, ring_bytes);
void* second = MapViewOfFile(section, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, ring_bytes);
```

Real contiguous double-mapping requires address-space reservation and explicit placement APIs such as `MapViewOfFileEx`/`MapViewOfFile3`; the snippet only shows the aliasing contract. The important connection is that both views name the same section object, so synchronization and lifetime rules are those of shared memory, not copied buffers.

## Discussion Claim To Verify

Claim from the Old New Thing post: two views of one file-mapping object are aliases over the same backing storage.

Why it matters: this can simplify ring buffers and wraparound parsers, but only if the code proves both aliasing and contiguity. Two arbitrary `MapViewOfFile` calls prove aliasing; they do not prove adjacent placement.

Verification route:

```cpp
HANDLE section = CreateFileMappingW(INVALID_HANDLE_VALUE, nullptr,
                                    PAGE_READWRITE, 0, bytes, nullptr);
BYTE* a = (BYTE*)MapViewOfFile(section, FILE_MAP_WRITE, 0, 0, bytes);
BYTE* b = (BYTE*)MapViewOfFile(section, FILE_MAP_READ, 0, 0, bytes);

a[0] = 0x5a;
printf("a=%p b=%p b[0]=0x%02x contiguous=%d\n",
       a, b, b[0], a + bytes == b);
```

Contiguity probe:

```text
reserve 2 * bytes with VirtualAlloc2/MEM_RESERVE_PLACEHOLDER
split placeholder into two equal placeholders
map the same section into both placeholders with MapViewOfFile3
write at offset bytes - 1 and read at the alias boundary
```

Interpretation:
- Writes through `a` appear through `b`: the aliasing claim is verified.
- `a + bytes != b`: the blog claim is not a contiguous ring-buffer guarantee; placement APIs are the missing step.
- `VirtualQuery` shows two separate regions backed by mapped views: address-space layout is virtual; storage identity belongs to the section object.

## References
- <https://devblogs.microsoft.com/oldnewthing/20231229-00/?p=109204>
