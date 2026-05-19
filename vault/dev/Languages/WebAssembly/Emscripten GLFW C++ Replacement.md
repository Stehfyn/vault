<!-- generated-from-dump2 -->
# Emscripten GLFW C++ Replacement

Drop-in replacement for Emscripten's bundled `library_glfw.js` — a more complete GLFW 3.x implementation for the browser, written in C++ rather than Emscripten's older JS-only shim. Why it matters: the upstream Emscripten port lags real GLFW (no proper multi-window, partial gamepad, no Hi-DPI support, incomplete cursor APIs), so any non-trivial C++ app cross-compiled to WASM hits gaps the upstream port quietly stubs out. This fork wires GLFW calls to modern browser APIs (Pointer Lock, Gamepad API, ResizeObserver, devicePixelRatio) so the same C++ code that runs natively under GLFW behaves identically in the browser. Routinely used by Dear ImGui / GLFW demos shipping to WASM.

```cpp
// Standard GLFW code — emscripten-glfw makes this work in the browser
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* w = glfwCreateWindow(960, 540, "WASM GLFW", nullptr, nullptr);
    glfwMakeContextCurrent(w);
    while (!glfwWindowShouldClose(w)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(w);
        glfwPollEvents();
    }
}
```

```bash
# Build with:
emcc main.cpp --use-port=contrib.glfw3 -sUSE_WEBGL2=1 -o app.html
```

## References
- <https://github.com/pongasoft/emscripten-glfw>
