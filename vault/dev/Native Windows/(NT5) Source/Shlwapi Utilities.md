# Shlwapi Utilities

`shlwapi` is the shell lightweight utility DLL. `color.c` provides color conversion helpers used throughout the shell UI; `mime.cpp` maps file extensions to MIME content types via the registry. The `AssocQueryString` API wraps the same registry lookup.

```cpp
// Query MIME type for a file extension via shlwapi
WCHAR mime[64] = {};
DWORD cch = ARRAYSIZE(mime);
HRESULT hr = AssocQueryStringW(ASSOCF_NONE, ASSOCSTR_CONTENTTYPE,
    L".png", nullptr, mime, &cch);
if (SUCCEEDED(hr)) {
  OutputDebugStringW(mime);  // "image/png"
}

// Adjust a color's luminance for theme tints
COLORREF base = RGB(0, 120, 215);
COLORREF lighter = ColorAdjustLuma(base, 30, TRUE);
HBRUSH brush = CreateSolidBrush(lighter);
FillRect(hdc, &rc, brush);
DeleteObject(brush);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/shell/shlwapi/color.c#L157
- https://github.com/tongzx/nt5src/blob/master/Source/XPSP1/NT/shell/shlwapi/mime.cpp
