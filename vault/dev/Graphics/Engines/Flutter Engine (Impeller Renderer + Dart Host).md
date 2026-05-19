<!-- generated-from-dump2 -->
# Flutter Engine (Impeller Renderer + Dart Host)

The C++ heart of Flutter: a portable rendering, text-shaping, and Dart-VM-hosting engine that's compiled to native libraries for iOS/Android/macOS/Windows/Linux/Web. The interesting architectural choice is that Flutter does **not** use platform widgets — it ships its own retained-mode scene graph and rasterizes everything itself, originally through Skia and now via **Impeller** (their custom renderer targeting Metal/Vulkan/OpenGL ES) for predictable jank-free frame times. The engine exposes a low-level scene API to Dart; the Flutter framework (the Dart side, separate repo) builds widgets on top of that. Worth reading even if you don't write Flutter apps: the embedder API, the shell architecture (Platform/UI/Raster/IO threads), and Impeller's tessellation-based 2D pipeline are state-of-the-art reference designs.

```text
# Engine threading model (canonical reference):
#   Platform thread - hosts the embedder + native UI events
#   UI thread       - runs the Dart isolate that owns the widget tree
#   Raster thread   - takes the recorded display list, rasterizes to GPU
#   IO thread       - decodes images, uploads textures
#
# Dart -> Engine flow:
#   Widgets -> RenderObjects -> Layer tree -> Engine.scheduleFrame()
#   -> Engine builds DisplayList -> Impeller rasterizes -> swap.
```

## References
- <https://github.com/flutter/engine>
