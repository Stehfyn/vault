<!-- generated-from-dump2 -->
# WebGPU-Cpp — Idiomatic C++ WebGPU Header

Single-header idiomatic C++ wrapper over the `webgpu.h` C API (Dawn/wgpu-native) — turns the C struct/function soup into RAII handles with member-function syntax. Companion to the author's *Learn WebGPU for C++* book. Zero-overhead: it's a header that wraps each opaque handle in a thin struct and forwards calls, so the generated code is identical to hand-written C.

```cpp
#include <webgpu/webgpu.hpp>
using namespace wgpu;

Instance instance = createInstance(InstanceDescriptor{});
Adapter adapter = instance.requestAdapter(RequestAdapterOptions{});
Device  device  = adapter.requestDevice(DeviceDescriptor{});

Queue queue = device.getQueue();
CommandEncoder enc = device.createCommandEncoder(CommandEncoderDescriptor{});
CommandBuffer cmd = enc.finish(CommandBufferDescriptor{});
queue.submit(cmd);
```

## References
- <https://github.com/eliemichel/WebGPU-Cpp>
