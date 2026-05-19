<!-- generated-from-dump2 -->
# Iridescence — Lightweight 3D Viz for Robotics/SLAM

Lightweight C++17 3D visualization library aimed at rapid prototyping of robotics / SLAM / point-cloud algorithms — point clouds, line sets, meshes, primitives, with Dear ImGui overlays for parameter knobs. Distinguishes itself from PCL's Visualizer (slow, heavy, dated VTK backend) and Open3D (Python-first, less ergonomic from C++) by being thin, fast, and embeddable: it's the visualization library Kenji Koide (the GLIM SLAM author) uses in his own research, and is designed to drop into a research codebase without bringing in VTK or PCL. Python bindings available. Backed by OpenGL 3.x + GLFW; per-frame redraw on dirty.

```cpp
#include <guik/viewer/light_viewer.hpp>

auto viewer = guik::LightViewer::instance();

// Draw a point cloud and a coordinate axis
viewer->update_drawable("points",
    glk::create_point_cloud_buffer(points),
    guik::Rainbow().set_point_scale(2.0f));

viewer->update_drawable("origin",
    glk::Primitives::coordinate_system(),
    guik::VertexColor());

viewer->register_ui_callback("ui", []{
    ImGui::Text("Hello iridescence");
});

viewer->spin();   // blocks until window closed
```

## References
- <https://github.com/koide3/iridescence>
