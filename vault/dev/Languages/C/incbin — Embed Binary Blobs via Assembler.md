<!-- generated-from-dump2 -->
# incbin — Embed Binary Blobs via Assembler

Single-header macro for embedding binary blobs (shaders, fonts, sample data) into a C/C++ executable at build time without needing `xxd -i` or a build-system codegen step. Works by emitting an inline asm `.incbin` directive — the same one GAS/ML64 has had for decades — so the actual bytes are stitched in by the assembler and the symbol shows up in the final binary with no copy/parse cost at runtime. Caveat: MSVC has no inline `.incbin` equivalent, so the header ships a pre-built `incbin.exe` that runs as a pre-build step and generates a `.c` with the bytes as a C array (the same trick as `xxd -i`). On clang/gcc you get the truly elegant version.

```c
#include "incbin.h"

INCBIN(IconPNG,     "assets/icon.png");
INCBIN(ShaderVert,  "shaders/main.vert.spv");

void show(void) {
    // gIconPNGData / gIconPNGSize / gIconPNGEnd are generated
    upload_texture(gIconPNGData, gIconPNGSize);
    create_shader_module(gShaderVertData, gShaderVertSize);
}
```

## References
- <https://github.com/graphitemaster/incbin>
