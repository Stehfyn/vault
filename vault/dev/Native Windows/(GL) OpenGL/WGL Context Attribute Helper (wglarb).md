# WGL Context Attribute Helper (wglarb)

`wglarb` is a helper for creating Windows OpenGL contexts with extended WGL attributes. That solves the classic bootstrap problem: Windows only exposes OpenGL 1.1 entry points directly, so you create a temporary legacy context, load WGL extension functions, choose an extended pixel format, then create the real core/debug/forward-compatible context with `wglCreateContextAttribsARB`.

This note belongs beside every Win32 OpenGL integration sample. Loaders such as glbinding resolve GL functions after a context exists; they do not solve WGL pixel format or context creation.

## References
- <https://github.com/datenwolf/wglarb>

## Connections
- `glbinding — Generated C++ OpenGL Bindings.md`
- `OpenGL in MFC CView (KB Q127071).md`
