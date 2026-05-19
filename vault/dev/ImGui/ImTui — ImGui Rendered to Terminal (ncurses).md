<!-- generated-from-dump2 -->
# ImTui — ImGui Rendered to Terminal (ncurses)

ImGui-style immediate-mode UI rendered to a *terminal* (ncurses backend). Same API as Dear ImGui, but draw commands resolve to cell glyphs instead of textured quads — buttons become bracketed strings, windows become box-drawing characters. The fun thing is you can take an existing ImGui app and swap the backend; most logic ports unchanged. By the author of llama.cpp / whisper.cpp.

```cpp
auto screen = ImTui_ImplNcurses_Init(/*mouse*/ true);
ImTui_ImplText_Init();

while (!quit) {
    ImTui_ImplNcurses_NewFrame();
    ImTui_ImplText_NewFrame();
    ImGui::NewFrame();

    ImGui::SetNextWindowPos({4, 2}, ImGuiCond_Once);
    ImGui::Begin("hello");
    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);
    ImGui::End();

    ImGui::Render();
    ImTui_ImplText_RenderDrawData(ImGui::GetDrawData(), screen);
    ImTui_ImplNcurses_DrawScreen();
}
```

## References
- <https://github.com/ggerganov/imtui>
