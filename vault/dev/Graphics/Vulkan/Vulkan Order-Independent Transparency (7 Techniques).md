<!-- generated-from-dump2 -->
# Vulkan Order-Independent Transparency (7 Techniques)

Seven OIT techniques in one sample: depth peeling, dual depth peeling, weighted blended OIT (McGuire & Bavoil), linked-list (per-pixel A-buffer using `VK_EXT_fragment_shader_interlock` or atomic counters), spinlock, loop64, and moment-based OIT. The point of having all seven side-by-side is the speed/quality tradeoff is highly scene-dependent — WBOIT is cheap but tints whites brown on heavy overdraw; per-pixel linked lists are exact but eat bandwidth.

```glsl
// Weighted blended OIT — McGuire/Bavoil.
// Two render targets: accum (RGBA16F, additive) and reveal (R8, multiplicative).
float w = clamp(0.03 / (1e-5 + pow(z / 200.0, 4.0)), 0.01, 3000.0);
outAccum  = vec4(color.rgb * color.a, color.a) * w;
outReveal = color.a;
// Resolve in a fullscreen pass: final = accum.rgb / max(accum.a, 1e-5) * (1 - reveal)
//                                        + background * reveal;
```

## References
- <https://github.com/nvpro-samples/vk_order_independent_transparency>
