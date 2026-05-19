<!-- generated-from-dump2 -->
# ImGuiLuaGen — LuaJIT FFI Binding Generator

BeamNG.drive's ImGui <-> LuaJIT FFI binding generator — parses cimgui's JSON metadata and emits a Lua wrapper that calls into the ImGui DLL via `ffi.cdef` + `ffi.load`. The output is what BeamNG's in-game UI/dev console actually uses. Pattern is reusable: if you have a LuaJIT-hosted game/app and want ImGui, this generator is your shortcut.

```lua
-- Generated wrapper usage:
local ffi = require("ffi")
local imgui = require("imgui_lua")

imgui.Begin("Vehicle Tuning")
local pressure = ffi.new("float[1]", 30.0)
if imgui.SliderFloat("Tire PSI", pressure, 15.0, 45.0) then
    vehicle.setTirePressure(pressure[0])
end
imgui.End()
```

## References
- <https://github.com/BeamNG/ImGuiLuaGen>
