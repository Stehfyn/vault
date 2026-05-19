<!-- generated-from-dump2 -->
# Premake Emscripten Toolchain Module

Premake5 toolchain module adding an Emscripten target so Lua-authored projects can compile to WebAssembly via `emcc` / `em++`. Wires up `EMSDK`, the wasm linker, and the `.html`/`.js` shell outputs without hand-editing Makefiles.

```lua
-- premake5.lua
require "emscripten"
workspace "Web"
    configurations { "Release" }
    platforms { "Emscripten" }
project "App"
    kind "WindowedApp"
    language "C++"
    files { "src/**.cpp" }
    filter "platforms:Emscripten"
        toolset "emcc"
        targetextension ".html"
```

## References
- <https://github.com/TurkeyMan/premake-emscripten>
