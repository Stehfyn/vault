<!-- generated-from-dump2 -->
# Drawing — GNOME MS-Paint-Style Raster Editor

GNOME-native MS-Paint-style raster editor — pencil, eraser, fill, lines, shapes, simple text, crop, scale, brightness/contrast. The point is **not** to be GIMP: no layers, no curves, no nondestructive editing, just the basic edits you do to a screenshot before sending it. Written in Python + PyGObject + GTK 4 with Cairo as the drawing surface, so every tool is a small subclass of a base `Tool` class implementing motion/release handlers that paint into a Cairo `ImageSurface`. Useful read both as a working modern PyGObject app and as a reference for "what's the minimum a usable paint program needs."

```python
# Conceptual: each tool subclasses ToolBase and paints into a Cairo surface.
import cairo

class TPencil:
    def on_press(self, x, y):
        self.prev = (x, y)
    def on_motion(self, ctx: cairo.Context, x, y):
        px, py = self.prev
        ctx.set_source_rgba(*self.color)
        ctx.set_line_width(self.size)
        ctx.set_line_cap(cairo.LINE_CAP_ROUND)
        ctx.move_to(px, py)
        ctx.line_to(x, y)
        ctx.stroke()
        self.prev = (x, y)

# Save: backing ImageSurface -> png/jpg/bmp via Cairo writers.
# Undo: snapshot of the ImageSurface in a stack at each tool commit.
```

## References
- <https://github.com/maoschanz/drawing>
