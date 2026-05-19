<!-- generated-from-dump2 -->
# cimgui — Auto-Generated C API for Dear ImGui

Auto-generated C API for Dear ImGui (which is C++) — the substrate that every non-C++ binding (cimgui-go, imgui-rs alt, LuaJIT FFI, Odin, Zig, etc.) sits on. Generated from ImGui's `imgui.h` by a Lua parser into a C header + JSON metadata describing every function signature, default argument, and overload set. The JSON is the actual deliverable for downstream binding generators.

```c
#include "cimgui.h"

igCreateContext(NULL);
igNewFrame();

igBegin("hello", NULL, 0);
igText("from C, no C++ runtime");
ImVec2 sz = {0, 0};
if (igButton("OK", sz)) { /* clicked */ }
igEnd();

igRender();
```

## References
- <https://github.com/cimgui/cimgui>
