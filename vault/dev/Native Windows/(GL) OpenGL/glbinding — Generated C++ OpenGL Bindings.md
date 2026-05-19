# glbinding — Generated C++ OpenGL Bindings

`glbinding` generates modern C++ OpenGL bindings from Khronos `gl.xml`. That gives type-safe function objects, enum wrappers, lazy resolution, and version/extension organization without hand-maintaining a loader. It is a loader/binding layer, not a rendering framework.

Use it when raw function-pointer loaders or `glad` are too C-like for a C++ codebase. On Windows it still sits on top of a real context created by WGL/EGL first; it does not solve pixel format selection or context attributes.

## References
- <https://github.com/cginternals/glbinding>

## Connections
- `WGL Context Attribute Helper (wglarb).md`
