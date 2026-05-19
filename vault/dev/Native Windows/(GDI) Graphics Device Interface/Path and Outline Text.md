# Path and Outline Text

GDI paths can turn text into geometry: call `BeginPath`, emit glyphs with `TextOut` or `ExtTextOut`, `EndPath`, then `StrokePath`, `FillPath`, or `StrokeAndFillPath`. With `GM_ADVANCED`, world transforms can scale, rotate, or shear that geometry before stroking. This is useful for outline text, decals, simple vector effects, and teaching how text output becomes paths.

The limitation is text quality. Path conversion is not a shaping engine, and complex scripts still require shaping before glyph output. For modern high-quality text, DirectWrite is the successor; for legacy GDI effects, paths remain a compact trick.

## References
- <https://github.com/shaovoon/outline-text> - outline text rendered through GDI path operations.
- <https://github.com/thenanisore/gdi-3d-renderer> - adjacent use of GDI transforms/projection for geometry.

## Connections
- `Text Shaping (Uniscribe).md` covers shaping before drawing text.
- `gdi-3d-renderer - Pure GDI Software 3D.md` covers transform-heavy GDI experiments.
