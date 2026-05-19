<!-- generated-from-dump2 -->
# 3D ASCII Viewer — Software OBJ Rasterizer in Terminal

Pure-C terminal app that loads OBJ files, rasterizes them to a 2D character grid, and renders with terminal escape sequences — no OpenGL, no SDL, no curses dependency for the rendering itself. The non-obvious work is the rasterizer: it does software triangle rasterization with a 1D z-buffer the size of the terminal cell grid, picks an ASCII glyph by mapping the lit intensity into the standard `" .,-~:;=!*#$@"` ramp, and uses 256-color or truecolor ANSI when the terminal supports it. Spins the model with timed escape redraws. Great reading for anyone who wants to understand how a software rasterizer fits in ~500 LOC.

```c
// Triangle rasterization core (concept; real code: src/render.c):
//   for each triangle (a,b,c) projected to screen-space (sx,sy,sz):
//     compute bounding box on the char grid
//     for each (x,y) in bbox:
//         (w0,w1,w2) = barycentric_(x,y, a,b,c);
//         if (any < 0) continue;
//         z = w0*az + w1*bz + w2*cz;
//         if (z < zbuf[y*W+x]) {
//             zbuf[y*W+x] = z;
//             intensity = dot(interp_normal, light_dir);
//             cells[y*W+x] = ramp[(int)(intensity * 12)];
//         }
//
//   // After the frame: ANSI cursor home + reprint cells[].
//   fputs("\x1b[H", stdout);
//   for (int y=0; y<H; y++) { fwrite(&cells[y*W], 1, W, stdout); fputc('\n', stdout); }
```

## References
- <https://github.com/autopawn/3d-ascii-viewer>
