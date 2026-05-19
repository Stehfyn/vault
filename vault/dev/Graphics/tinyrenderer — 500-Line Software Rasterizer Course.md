<!-- generated-from-dump2 -->
# tinyrenderer — 500-Line Software Rasterizer Course

Classic teaching repo: a software 3D rasterizer written from scratch in ~500 lines of C++ across 10 lessons (Bresenham lines, triangle rasterization with barycentric coordinates, Z-buffer, perspective projection, shaders, shadow mapping, ambient occlusion). The point isn't to be fast or featureful — it's to *physically construct* every step the GPU does so OpenGL/Vulkan stop being a black box.

```cpp
// Lesson 2: barycentric triangle rasterization with a Z-buffer.
void triangle(Vec3f* pts, float* zbuffer, TGAImage& image, TGAColor color) {
    Vec2f bbmin( image.get_width()-1, image.get_height()-1), bbmax(0,0);
    for (int i = 0; i < 3; ++i) {
        bbmin.x = std::min(bbmin.x, pts[i].x); bbmin.y = std::min(bbmin.y, pts[i].y);
        bbmax.x = std::max(bbmax.x, pts[i].x); bbmax.y = std::max(bbmax.y, pts[i].y);
    }
    for (int x = bbmin.x; x <= bbmax.x; ++x)
    for (int y = bbmin.y; y <= bbmax.y; ++y) {
        Vec3f bc = barycentric(pts, Vec3f(x, y, 0));
        if (bc.x < 0 || bc.y < 0 || bc.z < 0) continue;
        float z = pts[0].z*bc.x + pts[1].z*bc.y + pts[2].z*bc.z;
        if (zbuffer[x + y*image.get_width()] < z) {
            zbuffer[x + y*image.get_width()] = z;
            image.set(x, y, color);
        }
    }
}
```

## References
- <https://github.com/ssloy/tinyrenderer>
