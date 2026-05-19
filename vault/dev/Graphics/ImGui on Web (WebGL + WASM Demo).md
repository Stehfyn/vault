<!-- generated-from-dump2 -->
# ImGui on Web (WebGL + WASM Demo)

An example demo of IMGUI (Immediate Mode GUI) on the web. Using only WebGL, GLFW and ImGui. Suitable for being compiled to web assembly (WASM).

```cpp
ImGui::CreateContext();
ImGui::NewFrame();
ImGui::Begin("win"); ImGui::Text("hi"); ImGui::End();
ImGui::Render();
```

## References
- <https://github.com/jnmaloney/WebGui>
