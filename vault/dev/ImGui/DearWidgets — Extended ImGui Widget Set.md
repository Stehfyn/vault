<!-- generated-from-dump2 -->
# DearWidgets — Extended ImGui Widget Set

Extended widget set on top of Dear ImGui - the things ImGui omits: color-wheel + HSV/Lab pickers, histogram displays, advanced sliders (bezier curve editor, multi-knob curves), gradient editors, ROI selection on images. Useful as a "ImGuiAddons but maintained" alternative: drops into any project already using imgui.h, no separate viewport/render-backend code.

```cpp
#include "DearWidgets.h"

if (ImGui::Begin("editor")) {
    static float color[4] = { 1, 0.5f, 0.2f, 1 };
    DW::ColorWheel("##wheel", color);                 // HSV wheel
    static ImVec2 pts[4] = {{0,0},{0.3f,0.7f},{0.7f,0.4f},{1,1}};
    DW::BezierCurveEditor("##curve", pts, 4);
}
ImGui::End();
```

## References
- <https://github.com/soufianekhiat/DearWidgets>
