Very Large Image Viewer for Windows — a Win32 application that uses tiling and multi-level pyramids (similar to a map tile system) to interactively display gigapixel images on modest hardware. Memory usage stays proportional to the visible screen area via load-on-demand. Supports a plugin API for custom image formats (PNG, TIFF, JPEG, WebP, QOI, AVI). Has displayed a 717-gigapixel (925696×775168) image interactively from a 120 GB pyramidal TIFF.

```cpp
// Conceptual tile-based load-on-demand pattern used by vliv
// Each zoom level is a separate set of fixed-size tiles (e.g. 256x256)
struct TileKey { int level, col, row; };

void RequestTile(TileKey key, TileCache& cache) {
    if (cache.Contains(key)) return;
    // Async: seek to tile offset in pyramidal TIFF, decompress, store;
    // evict LRU tiles to bound total memory usage.
    QueueAsyncLoad(key, [&](void* data, size_t sz) {
        HBITMAP bmp = CreateBitmapFromPixels(data, TILE_W, TILE_H);
        cache.Insert(key, bmp);
    });
}

void RenderViewport(HDC hdc, Viewport vp, TileCache& cache) {
    for (auto& key : TilesInView(vp)) {
        HBITMAP bmp = cache.Get(key);
        if (bmp)
            BitBlt(hdc, destX, destY, TILE_W, TILE_H,
                   CreateCompatibleDC_with(bmp), 0, 0, SRCCOPY);
    }
}
```

## References

- <https://github.com/delhoume/vliv>
