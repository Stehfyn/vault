# Emscripten C++ CMake Template (GLES)

This template is useful as a portability scaffold: C++20, CMake, SDL2, GLAD, ImGui, and an OpenGL ES/WebGL-shaped rendering path that can target both native builds and Emscripten. The Native Windows relevance is constraint discipline: if you keep the renderer inside the GLES/WebGL subset, the same code can run in a browser and under desktop GL/ANGLE-like environments.

Do not read it for Windows-specific WGL or DXGI behavior; read it when deciding how much GL feature surface to give up for a web/native shared codebase.

Code contribution: the relevant constraints are `CMakeLists.txt`, SDL2 window creation, GLAD loading, ImGui integration, and the GLES/WebGL subset rather than `wglCreateContext` or DXGI presentation.

## References
- <https://github.com/Zephilinox/emscripten-cpp-cmake-template>
