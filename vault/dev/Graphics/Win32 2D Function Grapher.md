<!-- generated-from-dump2 -->
# Win32 2D Function Grapher

Function grapher; simple 2D plotting reference (axes, gridlines, polyline rendering).

```cpp
std::vector<POINT> pts;
for (int x = 0; x < width; ++x)
  pts.push_back({x, (LONG)(midY - amplitude * sinf(x * freq))});
Polyline(hdc, pts.data(), (int)pts.size());
```

## References
- <https://github.com/cmh25/grapher>
