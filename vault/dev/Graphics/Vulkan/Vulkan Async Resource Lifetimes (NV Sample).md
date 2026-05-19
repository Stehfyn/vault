<!-- generated-from-dump2 -->
# Vulkan Async Resource Lifetimes (NV Sample)

NVIDIA sample on *correctly* managing Vulkan resource lifetimes under async submission — the bug everyone hits is freeing a `VkBuffer` while a command buffer that still references it is in flight. The pattern: track per-frame deletion queues keyed off the value of a timeline semaphore, and only run the destructors once the GPU has signaled past the kill-frame's value. Worth reading for the staging-upload pipeline too (host visible -> device local copy via a transfer queue).

```cpp
struct PendingDelete { uint64_t frameValue; std::function<void()> fn; };
std::vector<PendingDelete> pending;

uint64_t completed = 0;
vkGetSemaphoreCounterValue(dev, timeline, &completed);
pending.erase(std::remove_if(pending.begin(), pending.end(),
    [&](PendingDelete& p){
        if (p.frameValue <= completed) { p.fn(); return true; }
        return false;
    }), pending.end());
```

## References
- <https://github.com/nvpro-samples/vk_async_resources>
