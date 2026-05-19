<!-- generated-from-dump2 -->
# Skribidi — Text Layout (Bidi, Shaping, Breaking)

Mikko Mononen's (NanoVG, NanoSVG, Recast/Detour) text layout stack — the missing piece that lets a small immediate-mode UI handle real i18n text without dragging in HarfBuzz+ICU+Pango. Covers the rendering pipeline a typical UI library skips: **bidi reordering** (per Unicode UAX #9 for mixed RTL Arabic/Hebrew with LTR Latin/numbers), **shaping** (mapping codepoints to GSUB-substituted glyph IDs with positioning), **line breaking** (UAX #14), and **font fallback** (per-script font choice when a single font doesn't cover all characters in a string). Stays small by leaning on the standalone bidi/breaking libraries (SheenBidi, libunibreak) and FreeType/stb_truetype for glyph data. Practical pick if you're building a tools UI in raw OpenGL/WebGPU and need to display Arabic comments correctly.

```cpp
// Conceptual pipeline (real API in skribidi.h):
// 1. Input: a UTF-8 string + a "base direction" (LTR/RTL).
// 2. Bidi resolve to a run list (each run has direction + script + glyphs).
// 3. For each run: pick a font (with fallback), shape into glyph clusters.
// 4. Break into lines on width constraint using UAX #14 break opportunities.
// 5. Emit positioned glyph quads ready for your renderer.
SkLayout layout;
sk_layout_init(&layout, font_table, fallback_chain);
sk_layout_add_text(&layout, u8"Hello مرحبا 123", base_dir=LTR);
sk_layout_set_max_width(&layout, 320.0f);
sk_layout_run(&layout);
for (int i = 0; i < layout.glyph_count; ++i) {
    // layout.glyphs[i].x, .y, .glyph_id, .font_id
}
```

## References
- <https://github.com/memononen/Skribidi>
