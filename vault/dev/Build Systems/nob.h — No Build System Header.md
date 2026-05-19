<!-- generated-from-dump2 -->
# nob.h — No Build System Header

`nob.h` — single-header "no build system" library by Alexey Kutepov (Tsoding). The philosophy: instead of CMake/Meson/Make, ship a `nob.c` source file alongside your project; the user runs `cc -o nob nob.c && ./nob`, and from then on `nob` rebuilds itself (`NOB_GO_REBUILD_URSELF(argc, argv)`) whenever `nob.c` is newer than the `nob` binary. The library provides cross-platform process spawning (`nob_cmd_run_sync`), file-modtime checks (`nob_needs_rebuild`), a `Nob_String_Builder` / `Nob_String_View`, dynamic-array macros (`nob_da_append`), logging, and path helpers — enough to express "compile this set of files into that binary, link this dll" without any external tooling.

```c
// nob.c
#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char** argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);   // self-recompile if nob.c changed

    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "cc", "-Wall", "-O2",
                   "-o", "build/app",
                   "src/main.c", "src/util.c");
    if (!nob_cmd_run_sync(cmd)) return 1;

    // Incremental: only relink if any input is newer than the output.
    const char* inputs[] = { "src/main.c", "src/util.c" };
    if (nob_needs_rebuild("build/app", inputs, NOB_ARRAY_LEN(inputs)) > 0) {
        // re-run cc...
    }
    return 0;
}
```

## References
- <https://github.com/tsoding/nob.h>
