# Text Shaping with Uniscribe

Uniscribe (`usp10.dll`) performs Unicode script itemization, glyph shaping, and placement for complex scripts (Arabic, Hebrew, Indic). The pipeline: `ScriptItemize` → `ScriptShape` (glyph mapping) → `ScriptPlace` (advance widths) → `ScriptTextOut`. DirectWrite supersedes this for new code.

```cpp
// Itemize a Unicode string into script runs
SCRIPT_CONTROL sc = {};
SCRIPT_STATE   ss = {};
SCRIPT_ITEM items[32] = {};
int numItems = 0;
HRESULT hr = ScriptItemize(
    text, (int)wcslen(text),
    ARRAYSIZE(items) - 1,
    &sc, &ss, items, &numItems);

if (SUCCEEDED(hr)) {
  for (int i = 0; i < numItems; ++i) {
    // items[i].iCharPos .. items[i+1].iCharPos = one script run
    // Pass each run to ScriptShape then ScriptPlace
  }
}
```

## References
- https://learn.microsoft.com/en-us/windows/win32/api/usp10/nf-usp10-scriptitemize?redirectedfrom=MSDN
