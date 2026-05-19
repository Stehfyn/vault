<!-- generated-from-dump2 -->
# glChAoS.P — GPU Strange Attractor Explorer

GPU-accelerated explorer for strange attractors (Lorenz, Aizawa, etc.) and quaternion/hypercomplex fractals (Mandelbulb-adjacent). The clever bit is that it sidesteps marching-cubes / SDF rendering: it iterates the attractor on the GPU as a 256M-particle point cloud with each particle integrating its own trajectory, then does deferred shading with screen-space ambient occlusion and post-fx on a G-buffer of point splats. Net effect is real-time exploration of objects that would otherwise need a dense voxel grid or expensive ray marcher.

```cpp
// Conceptual: per-frame, advance N particles by one iteration of the map
// in a compute shader, then render them as splats into a deferred G-buffer.
// (Real entry points live in src/src/glWindow.cpp / attractorsBase.cpp.)
//
// GLSL pseudocode for the Lorenz step in the compute shader:
//   vec3 p = particles[id];
//   float dx = sigma * (p.y - p.x);
//   float dy = p.x * (rho - p.z) - p.y;
//   float dz = p.x * p.y - beta * p.z;
//   particles[id] = p + dt * vec3(dx, dy, dz);
```

## References
- <https://github.com/BrutPitt/glChAoS.P>
