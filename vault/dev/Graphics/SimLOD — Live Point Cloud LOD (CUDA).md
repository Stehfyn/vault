<!-- generated-from-dump2 -->
# SimLOD — Live Point Cloud LOD (CUDA)

Markus Schuetz's "Simultaneous LOD Generation and Rendering for Point Clouds" — builds the octree-LOD structure *on the fly* in CUDA while you're rendering, so you can stream raw LAS/LAZ files and start visualizing within seconds instead of waiting for an offline Potree-style preprocess. Companion to the author's earlier Potree work. The core idea: each frame, append new points to the device-side octree, and pick the right LOD level per node based on screen-space size.

```cuda
// Sketch: each thread inserts a point into the device-side octree.
__global__ void insertPoints(Octree* tree, Point* pts, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx >= n) return;
    OctreeNode* node = traverseToLeaf(tree, pts[idx].pos);
    int slot = atomicAdd(&node->count, 1);
    if (slot < NODE_CAPACITY) node->points[slot] = pts[idx];
    else                       splitAndReinsert(tree, node, pts[idx]);
}
```

## References
- <https://github.com/m-schuetz/SimLOD>
