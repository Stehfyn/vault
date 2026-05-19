<!-- generated-from-dump2 -->
# foreign-dlopen — Static-to-Dynamic Loader

Tiny library that gives a statically-linked binary the ability to `dlopen` a shared library - including one linked against a *different* libc - at runtime. The use-case: you have a statically linked toy (e.g. a Go binary, or a musl-built tool) and you want to load a dynamic plugin that was built against glibc. Normally that's a non-starter because the static binary has no dynamic loader image to share. foreign-dlopen embeds a minimal ELF dynamic-loader stub and runs it to load the library into a fresh address-space region using its own libc.

```c
// API roughly:
#include "foreign_dlopen.h"

void* h = fdlopen("/usr/lib/libfoo.so.1", RTLD_NOW);
void (*foo)() = fdlsym(h, "foo");
foo();
fdlclose(h);
```

## References
- <https://github.com/pfalcon/foreign-dlopen>
