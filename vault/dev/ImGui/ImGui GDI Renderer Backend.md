<!-- generated-from-dump2 -->
# ImGui GDI Renderer Backend

Dear ImGui renderer backend that draws via plain Windows **GDI** — no D3D/GL/Vulkan. Useful for very old machines, RDP sessions, kiosk-style apps where you don't want the GPU/driver dependency, or when shipping an ImGui-based tool inside a process that already only has a GDI HDC (e.g. a printer driver UI). Performance is fine for typical tool UIs because ImGui's draw lists are small.

```cpp
// Backend init/teardown is symmetric with the standard ImGui backends.
ImGui::CreateContext();
ImGui_ImplWin32_Init(hwnd);
ImGui_ImplGDI_Init();              // creates HDC-backed font texture etc.

// Per-frame:
ImGui_ImplGDI_NewFrame();
ImGui_ImplWin32_NewFrame();
ImGui::NewFrame();
ImGui::ShowDemoWindow();
ImGui::Render();
ImGui_ImplGDI_RenderDrawData(ImGui::GetDrawData(), hdc);
```

## References
- <https://github.com/MickeyMeowMeowHouse/imgui-gdi>
