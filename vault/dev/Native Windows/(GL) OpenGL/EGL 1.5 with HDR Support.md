# EGL 1.5 with HDR Support

McNopper's EGL project is a portable EGL 1.5 implementation with explicit HDR goals. On Windows the interesting layer is translation: EGL color-space choices such as BT.2020/PQ or scRGB have to become DXGI swap-chain metadata and platform-specific presentation behavior, while the same app-facing EGL calls should also route to Wayland/Vulkan paths on Linux.

This matters because classic WGL has no satisfying modern HDR story. EGL is often treated as "the GLES context API", but this project uses it as a cross-platform window-system and color-management abstraction. Read it beside `OpenGL on DXGI Swapchain.md` when the problem is not drawing GL, but presenting it through a modern Windows display pipeline.

## References
- <https://github.com/McNopper/EGL>
