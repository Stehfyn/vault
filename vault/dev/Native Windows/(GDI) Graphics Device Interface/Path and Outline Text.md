# Path and Outline Text

GDI paths let you trace glyph outlines with `BeginPath`/`TextOut`/`EndPath`. After `EndPath`, call `StrokePath`, `FillPath`, or `StrokeAndFillPath`. World transforms (`SetWorldTransform`, `GM_ADVANCED`) allow arbitrary scaling and rotation of the path before stroking.

```cpp
// Outline text using GDI paths
HFONT font = CreateFontW(64, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
    DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
    ANTIALIASED_QUALITY, FF_DONTCARE, L"Segoe UI");
SelectObject(hdc, font);
HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
SelectObject(hdc, pen);
SelectObject(hdc, GetStockObject(HOLLOW_BRUSH));

BeginPath(hdc);
TextOutW(hdc, 20, 20, L"Outlined", 8);
EndPath(hdc);
StrokePath(hdc);   // or StrokeAndFillPath for filled+outlined

// 3D-style via world transform rotation
SetGraphicsMode(hdc, GM_ADVANCED);
XFORM xf = { 1.0f, 0.1f, -0.1f, 1.0f, 0.0f, 0.0f };  // shear
SetWorldTransform(hdc, &xf);
Rectangle(hdc, 0, 0, 60, 40);
```

## References
- https://github.com/shaovoon/outline-text
- https://github.com/thenanisore/gdi-3d-renderer
