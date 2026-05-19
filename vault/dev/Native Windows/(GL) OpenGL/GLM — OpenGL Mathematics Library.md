# GLM — OpenGL Mathematics Library

GLM is a header-only C++ math library modeled after GLSL types and functions: `vec*`, `mat*`, quaternions, transforms, projection helpers, and optional alignment/precision policies. Its value is semantic match with shader code, not Windows specificity.

The caveat is convention management. GLM can express OpenGL-style clip space, DirectX-style depth ranges, left/right-handed matrices, and row/column-major layout depending on macros and helper choice. When sharing code with D3D/DXGI notes, be explicit about depth range and matrix packing instead of assuming "GLM means OpenGL convention."

## References
- <https://github.com/g-truc/glm>
