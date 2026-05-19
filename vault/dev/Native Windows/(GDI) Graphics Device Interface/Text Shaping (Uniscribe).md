# Text Shaping (Uniscribe)

Uniscribe (`usp10.dll`) is the legacy complex-text engine for GDI-era applications. The pipeline is itemization (`ScriptItemize`), shaping (`ScriptShape`), placement (`ScriptPlace`), then output (`ScriptTextOut`). It handles script runs, bidirectional behavior, glyph substitution, and advances for text that cannot be drawn correctly by naive `TextOut` over Unicode code points.

DirectWrite supersedes Uniscribe for new code, but Uniscribe remains relevant when maintaining old GDI renderers or custom controls that cannot move to DirectWrite. The key lesson is that font selection and glyph drawing are not enough for Arabic, Indic scripts, combining marks, or bidi text; shaping is a required stage.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/usp10/nf-usp10-scriptitemize?redirectedfrom=MSDN> - entry point for Uniscribe itemization.

## Connections
- `Path and Outline Text.md` covers geometric text effects after text is drawable.
- DirectWrite entries in the DirectX area are the modern path.
