<!-- generated-from-dump2 -->
# cr.h — Single-Header Live Reload

`cr.h` — a single-header live-reload library by Danny Grein (fungos). Splits your app into a thin host (`cr_plugin_open`, `cr_plugin_update`) and a guest DLL/SO/dylib; on every update the host stat()s the plugin file, and when its mtime changes it copies the new image to a side-by-side temp path (avoiding the file lock), `LoadLibrary`s it, calls the guest's exported `cr_main`, and transfers a `void* userdata` block from old to new so plugin state survives the reload. Crash isolation is best-effort — the host installs a top-level vectored exception handler that, on AV inside the plugin, rolls back to the previous image. Standard hot-reload caveats apply: any vtable / function pointer / `static` address inside the old image becomes dangling, so the public API between host and plugin must be address-stable (data-only POD + a single `cr_main` entry).

```c
// Host (recompiled once)
#define CR_HOST CR_SAFEST
#include "cr.h"
int main() {
    cr_plugin ctx = {};
    cr_plugin_open(ctx, "myplugin.dll");
    while (running) {
        cr_plugin_update(ctx);   // reloads if the dll changed on disk
    }
    cr_plugin_close(ctx);
}

// Guest (myplugin.dll — rebuild while host is running)
#include "cr.h"
CR_EXPORT int cr_main(struct cr_plugin* ctx, enum cr_op operation) {
    switch (operation) {
        case CR_LOAD:   /* restore state from ctx->userdata */ break;
        case CR_STEP:   /* per-frame work */                  break;
        case CR_UNLOAD: /* save state to ctx->userdata */     break;
        case CR_CLOSE:  /* final teardown */                  break;
    }
    return 0;
}
```

## References
- <https://github.com/fungos/cr>
