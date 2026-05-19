<!-- generated-from-dump2 -->
# ned — GPU Code Editor on Dear ImGui

Code editor built on Dear ImGui with custom GLSL shaders for text rendering, syntax highlighting, and post-processing effects (CRT scanlines, glow). Single-window editor reminiscent of 4coder/Zed in spirit; aimed at developers who want full GPU-driven text and don't care about plugin ecosystems.

```cpp
// ned uses ImGui's render layer; the host loop is the standard imgui sample shape.
ImGui::CreateContext();
ImGui_ImplGlfw_InitForOpenGL(window, true);
ImGui_ImplOpenGL3_Init("#version 410");
while (!glfwWindowShouldClose(window)) {
    ImGui_ImplOpenGL3_NewFrame(); ImGui_ImplGlfw_NewFrame(); ImGui::NewFrame();
    ned::DrawEditor();   // text buffer + shader pipeline
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
}
```

## References
- <https://github.com/nealmick/ned>
