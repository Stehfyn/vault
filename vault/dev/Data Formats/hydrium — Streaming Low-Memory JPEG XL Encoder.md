<!-- generated-from-dump2 -->
# hydrium — Streaming Low-Memory JPEG XL Encoder

Streaming, ultra-low-memory JPEG XL *encoder* in portable C — designed for embedded/constrained environments where libjxl is too heavy. Notably misfiled if you only ever look at the directory name: it's a JPEG XL codec implementation, *not* a Vulkan project (the dump2 categorizer caught the "graphics-adjacent" signal but this would arguably fit better in a data-formats slot). Stays here because JPEG XL is image-codec territory.

```c
// Streaming encode: feed rows, get JXL bytes out incrementally.
HYDStatusCode hydrium_send_tile(HYDEncoder* e, const uint8_t* rgb,
                                size_t tile_x, size_t tile_y);
HYDStatusCode hydrium_flush(HYDEncoder* e);
```

## References
- <https://github.com/Traneptora/hydrium>
