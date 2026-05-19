<!-- generated-from-dump2 -->
# Pixlet — Tidbyt App Runtime

Pixlet - the Starlark-based runtime that drives Tidbyt apps. Open-source so you can run apps on any 64x32 RGB matrix (or just preview them as PNG/GIF in a browser). The architecture is interesting: Starlark scripts return a declarative tree of render primitives (`Box`, `Row`, `Column`, `Text`, `Image`), Pixlet rasterizes that into a sequence of 64x32 frames, optionally encodes as a WebP animation, and pushes it to a device or saves it locally. Trade-off: limited expressiveness vs hard real-time guarantees on tiny hardware.

```text
# Develop locally with the CLI:
$ pixlet serve app.star          # live-reload preview in a browser
$ pixlet render app.star         # writes PNG/GIF
$ pixlet push <device-id> app.star  # to a Tidbyt
```

## References
- <https://github.com/tidbyt/pixlet>
