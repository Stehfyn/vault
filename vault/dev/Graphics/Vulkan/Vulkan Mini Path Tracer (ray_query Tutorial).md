<!-- generated-from-dump2 -->
# Vulkan Mini Path Tracer (ray_query Tutorial)

Beginner Vulkan ray-tracing tutorial — a *compute-shader* path tracer in ~300 lines that uses `VK_KHR_ray_query` (not the ray-tracing pipeline). Easier than `vk_raytrace` because there's no shader binding table: the compute shader directly issues `rayQueryEXT` traversal against a TLAS, gathers hit attributes inline, and writes to a storage image. The right starting point if you want to *learn* the ext, before you fight raygen/miss/closest-hit dispatch.

```glsl
#extension GL_EXT_ray_query : require
layout(set=0, binding=0) uniform accelerationStructureEXT tlas;

rayQueryEXT rq;
rayQueryInitializeEXT(rq, tlas, gl_RayFlagsOpaqueEXT, /*mask*/ 0xFF,
                      origin, /*tmin*/ 0.001, dir, /*tmax*/ 10000.0);
while (rayQueryProceedEXT(rq)) {}
if (rayQueryGetIntersectionTypeEXT(rq, true)
    == gl_RayQueryCommittedIntersectionTriangleEXT) {
    float t = rayQueryGetIntersectionTEXT(rq, true);
    vec2 bary = rayQueryGetIntersectionBarycentricsEXT(rq, true);
    // shade...
}
```

## References
- <https://github.com/nvpro-samples/vk_mini_path_tracer>
