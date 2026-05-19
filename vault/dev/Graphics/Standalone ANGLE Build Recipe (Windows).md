<!-- generated-from-dump2 -->
# Standalone ANGLE Build Recipe (Windows)

Standalone Windows build recipe for **ANGLE**, Google's OpenGL ES / EGL implementation that translates GLES2/3/3.1 calls onto D3D11/D3D9/Vulkan/Metal. ANGLE is what Chrome/Firefox use to back WebGL on Windows (since there's no native ES on desktop Windows), but Google's official build is buried in Chromium's depot_tools and GN; mmozeiko's repo strips that to a single batch script + a vendored ANGLE source snapshot that produces `libEGL.dll` / `libGLESv2.dll` you can drop next to your exe. Use it when you need ES on Windows for: porting Android/iOS GL code unchanged, shipping a WebGL-like renderer without WebView2, or having a GLES path that doesn't depend on the wildly variable desktop GL ICDs. The build script itself is the artifact.

```text
# Result of running the build script:
#   out/
#     libEGL.dll
#     libGLESv2.dll
#     d3dcompiler_47.dll    (HLSL compiler ANGLE shells out to)
#     include/
#       EGL/egl.h ...
#       GLES2/gl2.h ...
#       GLES3/gl3.h ...
#
# Linking pattern in your app: call eglGetDisplay / eglInitialize as usual.
# ANGLE picks the best backend (D3D11 by default) at runtime; you can force
# the backend by setting the right EGL display attribute:
#   eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, ..., {
#       EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
#       EGL_NONE });
```

## References
- <https://github.com/mmozeiko/build-angle>
