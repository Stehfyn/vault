<!-- generated-from-dump2 -->
# Premake to CMake Exporter

Premake5 module that emits `CMakeLists.txt` from a `premake5.lua` script, so projects can author once in Lua and export to CMake for downstream consumers who insist on it. Unmaintained but still a reasonable reference for how a Premake action plugin maps `project`, `kind`, `files`, and `links` into CMake commands.

```lua
-- premake5.lua
require "cmake"
workspace "App"
    configurations { "Debug", "Release" }
project "App"
    kind "ConsoleApp"
    language "C++"
    files { "src/**.cpp", "src/**.h" }
    -- premake5 cmake => produces CMakeLists.txt
```

## References
- <https://github.com/Enhex/premake-cmake>
