<!-- generated-from-dump2 -->
# Memcury — C++ Memory Scan Toolkit

Single-header C++ utility belt for the "scan memory in a target process, follow some pointers, write a few bytes" workflow that every game-internal cheat / modding tool does in its first 30 lines. Provides a fluent API for AOB (array-of-bytes) signature scanning across module text sections, RIP-relative address resolution (for x64 LEA/CALL operands), import/export walking, and a `Scanner::FindBySig("48 8B 05 ?? ?? ?? ?? 48 85 C0")` style sig syntax with wildcards. Header-only so dropping it into a DLL injection project is one `#include`. Sits in the same niche as `darthton-x64-asm-sigscan` and `nepcat-rust-mem` but in modern C++17/20 with a notably tidy chain syntax.

```cpp
#include "Memcury.hpp"

// Find a function by IDA-style signature in the main module's .text
auto addr = Memcury::Scanner::FindPattern("48 8B 05 ? ? ? ? 48 85 C0")
                .ScanFunction()           // step back to function prologue
                .RelativeOffset(3)        // follow the RIP-relative mov
                .GetAs<uintptr_t>();

// Resolve a class virtual fn from a vtable + index
auto vfn = Memcury::PE::Section(".text")
                .FindObjectOf("UWorld::Tick").Get();
```

## References
- <https://github.com/kem0x/Memcury>
