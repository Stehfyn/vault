<!-- generated-from-dump2 -->
# herebedragons — Same Scene in 30+ Graphics APIs

Wrong subdir — this isn't OpSec, it's a Rosetta-stone graphics demo. Same dragon scene implemented in 30+ different APIs/engines: raw OpenGL 3.3, Vulkan, Metal, DX11, DX12, Unity, Unreal, Three.js, etc. Useful as a side-by-side "what does Hello-Triangle-plus-mesh-plus-shadow look like in each API?" reference. Should be moved to `vault/dev/Graphics/`.

```text
// Each subdir is a standalone build of the same scene:
//   opengl/   vulkan/   directx11/   directx12/   metal/   webgl/
//   unity/    unreal/   threejs/     babylon/     filament/
// Read pairs (e.g. vulkan/ vs. directx12/) to see how the same workload
// maps onto each API's command-buffer / descriptor / pipeline model.
```

## References
- <https://github.com/kosua20/herebedragons>
