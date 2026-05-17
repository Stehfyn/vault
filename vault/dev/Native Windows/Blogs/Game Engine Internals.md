# Game Engine Internals

Fabien Sanglard's reverse-engineered Game Engine Black Books document the internals of Wolfenstein 3D, Doom, and Quake. Essential for understanding raycasting, BSP trees, software rasterization, and fixed-point arithmetic as practiced in the 1990s.

```cpp
// Wolfenstein 3D-style raycaster (DDA algorithm)
for (int col = 0; col < screenW; ++col) {
    // Ray direction in camera space: -1.0 (left) to +1.0 (right)
    float rayDir = camDirX + camPlaneX * (2.0f * col / screenW - 1.0f);
    float deltaDistX = fabsf(1.0f / rayDir);

    // DDA step until wall hit
    float sideDistX = /* ... */ 0.0f;
    int hit = 0, side = 0;
    while (!hit) {
        // advance ray to next map square
        if (sideDistX < sideDistY) { sideDistX += deltaDistX; side = 0; }
        else                        { sideDistY += deltaDistY; side = 1; }
        if (map[mapX][mapY] > 0) hit = 1;
    }
    float wallDist = (side == 0) ? sideDistX - deltaDistX : sideDistY - deltaDistY;
    int lineH = (int)(screenH / wallDist);
    DrawVerticalLine(col, (screenH - lineH) / 2, lineH, side ? 0xAAAAAA : 0xFFFFFF);
}
```

## References
- https://fabiensanglard.net/gebb/
