<!-- generated-from-dump2 -->
# plasma Portability Macros

Portability macros for compiler and hardware micro-operations: branch-prediction hints, atomic memory-ordering wrappers that work on pre-C11 compilers, pause/yield, prefetch, cache-line size, `__builtin_expect` shims, etc. Used by `lighttpd` and Glue Logic's high-perf C codebase. Worth a look as a working reference of "everything you need to write portable inner-loop C without the C11 atomics header" — every macro has a fallback chain across gcc/clang/msvc/sunpro.

```c
#include "plasma/plasma_attr.h"
#include "plasma/plasma_membar.h"

PLASMA_ATTR_HOT
static int hot_path(int* p) {
    plasma_membar_ld_acq();          // load-acquire barrier (LL/SC on POWER, lwsync, etc.)
    int v = __atomic_load_n(p, __ATOMIC_RELAXED);
    if (PLASMA_PREDICT_FALSE(v < 0)) return -1;
    return v;
}
```

## References
- <https://github.com/gstrauss/plasma>
