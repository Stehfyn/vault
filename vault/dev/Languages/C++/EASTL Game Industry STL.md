<!-- generated-from-dump2 -->
# EASTL Game Industry STL

Electronic Arts' open-source partial reimplementation of the STL with the rules changed for game-development reality. The two big departures: (1) **allocators are NOT template parameters but stored references** (now-standard in `std::pmr` C++17, but EASTL got there in 2007), which means a single `vector<T, EASTLAllocator>` type can speak different arenas without recompile-storm; (2) explicit support for **fixed-size containers** (`fixed_vector<T,N>`, `fixed_hash_map`) that allocate inline up to N elements then optionally spill — critical for hot paths on consoles where you'd rather assert than `malloc`. Also ships better iterator-debug tooling, faster sorts (radix for trivial types), and the famous Paul Pedriana "EASTL design rationale" paper as the README. Worth reading even if you never link it.

```cpp
#include <EASTL/vector.h>
#include <EASTL/fixed_vector.h>

// Allocator argument is a regular constructor parameter, not a template arg.
eastl::vector<int> v(eastl::allocator("audio_arena"));
v.push_back(1);
v.push_back(2);

// Inline-storage container: no heap alloc unless > 32 elements.
eastl::fixed_vector<int, 32, /*bEnableOverflow=*/false> stack_only;
stack_only.push_back(42);   // never touches malloc
```

## References
- <https://github.com/electronicarts/EASTL>
