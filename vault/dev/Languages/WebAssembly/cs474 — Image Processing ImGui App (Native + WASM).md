<!-- generated-from-dump2 -->
# cs474 — Image Processing ImGui App (Native + WASM)

Author's own coursework / project for a CS474 "Image Processing and Interpretation" class — a C++/Dear ImGui app for visualizing classic image-processing operations (histogram equalization, convolution kernels, frequency-domain filtering) cross-compiled to both native Windows and WebAssembly using Emscripten. Useful as a small reference for "how do I build the same C++/ImGui app for the browser and the desktop from one source tree" — typically the awkward parts are GLFW/SDL inputs, file dialogs (browser has no `<input type=file>` for the C++ side without JS glue), and threading model differences.

```cpp
// Skeleton typical of these dual-target ImGui apps
#include <imgui.h>
#ifdef __EMSCRIPTEN__
  #include <emscripten.h>
#endif

void frame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (ImGui::Begin("Histogram")) ImGui::PlotHistogram("##h", hist, 256);
    ImGui::End();

    ImGui::Render();
    /* swap buffers */
}

int main() {
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(frame, 0, 1);
#else
    while (!should_quit()) frame();
#endif
}
```

## References
- <https://github.com/Stehfyn/cs474>
