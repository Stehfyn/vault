<!-- generated-from-dump2 -->
# Premake Visual Studio Platform Toolset Module

Premake5 module that adds support for arbitrary Visual Studio "platform toolsets" (e.g. clang-cl, Intel C++, custom WDK toolsets) so generated `.vcxproj` files target the right `PlatformToolset`/`WindowsTargetPlatformVersion` without a fork of Premake itself.

```lua
-- premake5.lua
require "vstool"
workspace "App"
    configurations { "Debug", "Release" }
project "App"
    kind "ConsoleApp"
    language "C++"
    toolset "msc-ClangCL"   -- routed through premake-vstool
    files { "src/**.cpp" }
```

## References
- <https://github.com/TurkeyMan/premake-vstool>
