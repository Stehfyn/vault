<!-- generated-from-dump2 -->
# ImGui Xbox 360 Platform + Renderer Backend

Dear ImGui platform + renderer backends for the **Xbox 360** (homebrew / dev-kit context — uses the XEX/libxenon style API). The renderer is D3D9-flavored (Xenos GPU's API is a variant of D3D9 with Xbox-specific extensions); the platform side reads controller input via XInput-equivalents and synthesizes ImGui's NavInput so gamepad navigation through ImGui windows works out of the box.

```cpp
ImGui::CreateContext();
ImGui_ImplXbox360_Init();          // controller / system-link plumbing
ImGui_ImplXenosD3D9_Init(d3dDev);  // Xenos D3D9 renderer

// Per-frame
ImGui_ImplXenosD3D9_NewFrame();
ImGui_ImplXbox360_NewFrame();
ImGui::NewFrame();
ImGui::ShowDemoWindow();
ImGui::Render();
ImGui_ImplXenosD3D9_RenderDrawData(ImGui::GetDrawData());
```

## References
- <https://github.com/ClementDreptin/imgui-xbox360>
