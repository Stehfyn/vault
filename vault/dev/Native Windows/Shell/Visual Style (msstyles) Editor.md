# Visual Style (msstyles) Editor

Editor for `.msstyles` / `.theme` files — the visual style resources that uxtheme.dll consumes. Decodes the proprietary VSF (Visual Style Format) container: a custom variant-record stream of part/state/property triples ("Button.PushButton[Hot].BgType = ImageFile", "ImageFile1 = <PNG blob>", "ContentMargins = (3,3,3,3)"). Useful for theme authors and for anyone reverse-engineering Aero/Frutiger Aero/Win11 internals — the source documents the on-disk schema better than any MS doc.

```text
# VSF property record layout (paraphrased from the source)
[16-bit nameID]   # uxtheme part/property enum, e.g. TMT_FILLCOLOR
[16-bit type ]    # TMT_COLOR, TMT_FONT, TMT_BITMAP, TMT_RECT, ...
[32-bit length]   # bytes of payload following
[payload     ]    # interpretation depends on type:
                  #   TMT_COLOR  -> COLORREF
                  #   TMT_BITMAP -> resource ID + optional image-file blob
                  #   TMT_ENUM   -> int from TMT enum table
                  #   TMT_FONT   -> LOGFONT
                  #   ... ~50 types total
```

## References
- <https://github.com/nptr/msstyleEditor>
