<!-- generated-from-dump2 -->
# CoD World at War Zombies Internal Cheat

Internal DLL injected into Call of Duty: World at War (specifically the Nazi Zombies mode) that overlays a Dear ImGui menu. Demonstrates the standard internal-cheat pattern: DLL maps into the game's address space, hooks `IDirect3DDevice9::EndScene` (this title is D3D9), uses the existing device/swapchain to draw an ImGui overlay, and exposes game-state edits (god mode, weapon spawning, point editing) by writing to pattern-scanned addresses in the engine.

```cpp
// Common pattern for internal D3D9 overlays:
//  1. Locate IDirect3DDevice9 via vtable scan of d3d9.dll.
//  2. Detour EndScene; from inside the detour, on first call:
//     ImGui_ImplWin32_Init(hwndFromGame); ImGui_ImplDX9_Init(device);
//  3. Per frame inside the detour:
//        ImGui_ImplDX9_NewFrame(); ImGui_ImplWin32_NewFrame();
//        ImGui::NewFrame(); DrawMenu();
//        ImGui::Render();
//        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
//  4. Call originalEndScene.
typedef HRESULT (WINAPI *EndScene_t)(IDirect3DDevice9*);
static EndScene_t oEndScene;
HRESULT WINAPI HookedEndScene(IDirect3DDevice9* dev) {
    static bool init = false;
    if (!init) { /* ImGui_ImplDX9_Init(dev); */ init = true; }
    DrawMenu();
    return oEndScene(dev);
}
```

## References
- <https://github.com/NightFyre/COD-WAW-INTERNAL-ZOMBIES>
