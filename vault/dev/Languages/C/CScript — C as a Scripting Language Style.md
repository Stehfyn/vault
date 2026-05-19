<!-- generated-from-dump2 -->
# CScript — C as a Scripting Language Style

Domenico Cerasuolo's style guide for writing C as if it were a scripting language: opinionated rules that keep you in a valid C subset but feel more like Python/Go. Examples of rules: no header files (use `unity build` — one `#include` per translation unit), no forward declarations (just `static` in source order), strings via a tagged-pointer string library, dynamic arrays via `stb_ds.h`-style macros, no manual `malloc`/`free` (only arena allocators), no `int` (use `size_t`/`intN_t`). The thesis: most of what's painful about C is convention, not the language, and a tighter convention plus a few macros yields a productive scripting-style C dialect. Useful read whether or not you adopt the rules.

```c
// "CScript"-style hello world: single translation unit, arena alloc,
// dynamic-array macros, no explicit free.
#include <stb_ds.h>      // dynamic arrays / hashmaps
#include "arena.h"       // bump allocator

static Arena g_arena;

int main(void) {
    int* xs = NULL;       // stb_ds dynamic array
    arrput(xs, 1);
    arrput(xs, 2);
    arrput(xs, 3);

    char* s = arena_sprintf(&g_arena, "len=%zd", arrlen(xs));
    puts(s);

    arena_free(&g_arena); // drops everything in one call; no free(s)
    arrfree(xs);
}
```

## References
- <https://github.com/domenukk/CScript>
