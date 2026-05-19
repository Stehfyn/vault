<!-- generated-from-dump2 -->
# imgui_bundle — Python ImGui + Addons Pack

Companion to `hello_imgui` — a single pip-installable Python package (and C++ amalgamation) that bundles Dear ImGui + ImPlot + imgui-node-editor + ImGuiFileDialog + ImCoolBar + a dozen other addons under one consistent build. The Python bindings are real (pybind11), not RPC, so per-frame UI is fast enough for tools.

```python
from imgui_bundle import imgui, hello_imgui, implot
import math

def gui():
    imgui.text("Plot from Python:")
    if implot.begin_plot("##plt"):
        xs = [i * 0.1 for i in range(100)]
        ys = [math.sin(x) for x in xs]
        implot.plot_line("sin", xs, ys)
        implot.end_plot()

hello_imgui.run(gui, window_title="bundle demo")
```

## References
- <https://github.com/pthom/imgui_bundle>
