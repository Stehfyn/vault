# Minimal GL and Vulkan App Framework

`dw-sample-framework` is a compact C++ framework for OpenGL and Vulkan demos. Its useful boundary is sample hygiene: window/input setup, shader/resource helpers, and app lifecycle are handled once so individual rendering techniques can stay visible.

This is not a production engine and should not hide platform questions. For Windows-specific OpenGL context creation, use the WGL notes; for cross-API rendering architecture, compare with AMD Cauldron in the DirectX folder.

## References
- <https://github.com/diharaw/dw-sample-framework>

## Connections
- `../(DX) DirectX/Cauldron — D3D12 and Vulkan Prototyping.md`
- `WGL Context Attribute Helper (wglarb).md`
