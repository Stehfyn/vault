<!-- generated-from-dump2 -->
# Non-Euclidean Portal Rendering Demo

CodeParade's non-Euclidean rendering demo (the YouTube "Non-Euclidean Worlds Engine" video) — a portal-based renderer that uses stencil buffers and recursive scene rendering to simulate spaces that don't fit in 3D (smaller-on-the-inside rooms, infinite hallways, impossible geometry). The technique is straight portal rendering: each portal binds a stencil mask, transforms the view through the portal's twin, and recurses up to a depth limit.

```cpp
// Stencil-based portal rendering (sketch matching the project's approach).
void RenderPortal(const Portal& p, const Camera& cam, int depthLeft) {
    if (depthLeft == 0) return;
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NEVER, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_KEEP, GL_KEEP);
    DrawPortalQuad(p);                      // write 1s into stencil where portal is.
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    Camera virtualCam = TransformThroughPortal(cam, p);
    RenderScene(virtualCam, depthLeft - 1); // recurse: scene seen through portal.
}
```

## References
- <https://github.com/HackerPoet/NonEuclidean>
