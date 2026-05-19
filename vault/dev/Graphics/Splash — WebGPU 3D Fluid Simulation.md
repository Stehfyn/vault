<!-- generated-from-dump2 -->
# Splash — WebGPU 3D Fluid Simulation

WebGPU 3D fluid simulator — runs a particle-based fluid (typically PBF: Position-Based Fluids by Macklin & Mueller, or MPM) in compute shaders, then renders the water surface with screen-space fluid rendering (depth blur + thickness pass to reconstruct normals without meshing). Notable because everything runs in the browser via WebGPU's compute support — no native fallback needed.

```wgsl
// Position-Based Fluids density constraint (sketch).
@compute @workgroup_size(64)
fn pbf_density(@builtin(global_invocation_id) gid : vec3<u32>) {
    let i  = gid.x;
    var rho: f32 = 0.0;
    for (var j : u32 = 0u; j < N_NEIGHBORS; j = j + 1u) {
        let r = positions[i] - positions[neighbors[i*N_NEIGHBORS + j]];
        rho  = rho + mass * poly6(length(r), H);
    }
    densities[i] = rho;
    lambdas[i]   = -(rho / RHO0 - 1.0) / sum_grad_C2;
}
```

## References
- <https://github.com/matsuoka-601/Splash>
