<!-- generated-from-dump2 -->
# Hello ImGui — Cross-Platform Runner Framework

Pascal Thomet's "hello, Dear ImGui in three lines" framework — wraps the SDL/GLFW + GL/Vulkan/Metal backend zoo behind a `HelloImGui::Run(...)` entry point so the same C++ source compiles unchanged on Windows, macOS, Linux, iOS, Android, and Emscripten/WebAssembly. Pair with `pthom/imgui_bundle` for the Python bindings + addons.

```cpp
#include "hello_imgui/hello_imgui.h"

int main() {
    HelloImGui::Run(
        /*guiFunction=*/[]{
            ImGui::Text("Hello, cross-platform world!");
            if (ImGui::Button("Bye")) HelloImGui::GetRunnerParams()->appShallExit = true;
        },
        /*windowTitle=*/"Hello",
        /*windowSizeAuto=*/true);
    return 0;
}
```

## References
- <https://github.com/pthom/hello_imgui>
