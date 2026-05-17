# Control Flow Graph

Build a CFG by parsing the PE headers, locating the `.text` section, and decoding control-flow instructions to emit edges.

```cpp
#include <windows.h>

BYTE* base = reinterpret_cast<BYTE*>(mappedImage);
auto dos = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
auto nt = reinterpret_cast<IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
auto sec = IMAGE_FIRST_SECTION(nt);

for (WORD i = 0; i < nt->FileHeader.NumberOfSections; ++i) {
    if (memcmp(sec[i].Name, ".text", 5) == 0) {
        BYTE* code = base + sec[i].PointerToRawData;
        DWORD size = sec[i].SizeOfRawData;
        // decode instructions; add edges for jmp/call/ret
        break;
    }
}
```

## References
- https://github.com/z4p4n/ControlFlowGraph-Win32-x86
- https://raw.githubusercontent.com/z4p4n/ControlFlowGraph-Win32-x86/master/main.cpp
