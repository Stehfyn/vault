<!-- generated-from-dump2 -->
# ImPlot3D — 3D Plotting Addon for ImGui

3D plotting addon for Dear ImGui in the spirit of epezent's ImPlot (2D). Provides `Begin/EndPlot3D`, scatter/line/surface/triangle-mesh series, and an orbit camera with mouse drag/pan/zoom. Useful for visualizing point clouds, trajectories, and mathematical surfaces without pulling in a full 3D engine.

```cpp
if (ImPlot3D::BeginPlot("scatter")) {
    ImPlot3D::SetupAxes("x", "y", "z");
    float xs[100], ys[100], zs[100];
    for (int i = 0; i < 100; ++i) {
        xs[i] = i * 0.1f;
        ys[i] = sinf(xs[i]);
        zs[i] = cosf(xs[i]);
    }
    ImPlot3D::PlotScatter("helix", xs, ys, zs, 100);
    ImPlot3D::EndPlot();
}
```

## References
- <https://github.com/brenocq/implot3d>
