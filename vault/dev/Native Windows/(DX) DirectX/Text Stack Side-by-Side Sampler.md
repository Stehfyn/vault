# Text Stack Side-by-Side Sampler

Dwayne Robinson's sampler renders the same text through the Windows text stacks side by side: GDI, GDI+, Uniscribe, DirectWrite bitmap targets, DirectWrite through Direct2D, and related font paths. Its value is diagnostic: it makes metric differences, antialiasing differences, ClearType behavior, and glyph positioning mismatches visible at the pixel level.

The negative result is the point. You should not expect GDI and DirectWrite to agree exactly, so porting an MFC/GDI UI to D2D/DWrite requires layout tolerance and visual QA rather than a blind renderer swap. This is the companion note for Direct2D text and MFC integration.

## References
- <https://github.com/fdwr/TextLayoutSampler>

## Connections
- `(D2D) Direct2D.md`
- `Direct2D and DirectWrite in MFC.md`
