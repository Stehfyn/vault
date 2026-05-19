<!-- generated-from-dump2 -->
# Isometric City — Browser City Builder

Browser-based isometric city + theme-park builder (IsoCity / IsoCoaster) written in TypeScript on Next.js, rendering on a raw HTML5 Canvas with no Three.js / Babylon / Phaser dependency. Worth reading specifically because of that constraint: the project rolls its own `CanvasIsometricGrid` doing painter's-algorithm depth sort over tile + entity sprites, with autonomous traffic agents (cars/trains/planes) doing signal-respecting pathfinding, and pedestrians on a separate path grid. Good reference for how far you can get with a 2D canvas + sprite atlas before reaching for a real engine.

```typescript
// Conceptual painter's-algorithm depth sort for an isometric grid.
// Each tile/entity has a (x, y, z) world position; isometric screen-Y
// determines draw order. Real code lives in components/CanvasIsometricGrid.
interface Drawable { x: number; y: number; z: number; sprite: HTMLImageElement; }

function frame(ctx: CanvasRenderingContext2D, items: Drawable[]) {
  // Sort back-to-front: higher (x+y) is "in front" in iso projection.
  items.sort((a, b) => (a.x + a.y + a.z) - (b.x + b.y + b.z));
  for (const it of items) {
    const sx = (it.x - it.y) * TILE_W / 2;
    const sy = (it.x + it.y) * TILE_H / 2 - it.z * TILE_H;
    ctx.drawImage(it.sprite, sx, sy);
  }
}
```

## References
- <https://github.com/amilich/isometric-city>
