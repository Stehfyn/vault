<!-- generated-from-dump2 -->
# BDE Bloomberg Development Environment

Bloomberg's foundational C++ libraries — what they ship internally and use across millions of lines of trading-infrastructure code. The reason it's culturally important: BDE is the canonical reference for **polymorphic allocators** (`bslma::Allocator`), the design that eventually got proposed and standardized as `std::pmr` in C++17. Their model is per-object, run-time-polymorphic allocators stored as the *last* constructor parameter (not template parameter, à la `std::allocator<T>`), enabling memory pools/arenas/test allocators without recompiling the world. The repo also ships their package-group structure (`bsl`/`bdl`/`bal`/`bbl`) and rigorously documented coding standards — read those even if you never link the library.

```cpp
#include <bslma_testallocator.h>
#include <bsl_vector.h>

void f() {
    // Stack-scoped test allocator that detects leaks at destruction.
    bslma::TestAllocator ta("vec");

    // Allocator is the *last* ctor argument (BDE convention, mirrored by std::pmr).
    bsl::vector<int> v(&ta);
    v.push_back(1);
    v.push_back(2);

    // ta destructor asserts all blocks are returned -> leak detector.
}
```

## References
- <https://github.com/bloomberg/bde>
