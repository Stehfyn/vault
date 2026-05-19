<!-- generated-from-dump2 -->
# bawr — SVG Icons to ImGui Font and Header

Pre-build asset pipeline that turns a folder of SVG icon files into (a) a compiled TTF icon font, (b) a PNG texture atlas, and (c) a generated C++ header with embedded binary data + `constexpr` codepoint constants. Aimed specifically at Dear ImGui workflows where you want icons in your UI without runtime SVG parsing — you `#include "bawr_icons.h"`, get `ICONS::SAVE`, `ICONS::OPEN` as char constants, and the font/texture data is already in your binary. Shells out to **FontForge** for SVG-to-TTF conversion and **Inkscape** for rasterization; bawr itself is Python orchestration + a small templating step. Config in `config.py` controls per-icon-set transformations (color recolor, rotation, padding).

```python
# config.py shape — what bawr reads:
sets = [
  {
    "name": "material",
    "input": "icons/material/*.svg",
    "transforms": ["recolor=#FFFFFF", "pad=10%"],
    "output_ttf": "out/material.ttf",
    "output_atlas": "out/material.png",
    "output_header": "out/material.h",   # generates ICONS_MATERIAL::* constants
  },
]
```

```cpp
// In your ImGui code, after bawr has run:
#include "bawr_icons.h"

ImFont* iconFont = io.Fonts->AddFontFromMemoryTTF(
    bawr::material_ttf, bawr::material_ttf_size, 16.0f);

if (ImGui::Button(ICONS_MATERIAL::SAVE " Save")) { /* ... */ }
```

## References
- <https://github.com/mnesarco/bawr>
