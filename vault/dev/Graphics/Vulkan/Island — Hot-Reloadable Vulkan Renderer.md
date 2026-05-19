<!-- generated-from-dump2 -->
# Island — Hot-Reloadable Vulkan Renderer

Experimental Vulkan renderer with *hot-reloadable* modules — you can edit a render pass's C++ code and it rebuilds and re-links into the running process without losing GPU state. The trick: each module is a shared library with a stable C ABI, the engine reloads it on file change, and module state is serialized through versioned POD structs. Also implements a rendergraph similar to vuk for automatic barrier insertion.

```cpp
// A render module exposes a C entry point that the host loads at runtime.
ISL_API_ATTR void register_my_module(void* api_) {
    auto* api = static_cast<le_module_api*>(api_);
    api->setup = &my_setup;
    api->draw  = &my_draw;
}
```

## References
- <https://github.com/tgfrerer/island>
