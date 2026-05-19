<!-- generated-from-dump2 -->
# Dear PyGui Example Scripts

Companion example-script repo for Dear PyGui — small, focused, single-file demos covering the bits the official DPG docs are thin on: custom drawing on `add_drawlist`, real-time plot streaming, theme/font setup, asyncio integration, tabs/docking layout, hot-reloading of widgets, plus several mini-apps (chart playgrounds, GUI front-ends for ML inference). More useful than the official examples folder for "how do I do *X* concrete thing" searches because each file is intentionally narrow. Worth grepping before posting questions on the DPG Discord.

```python
# Each file is independently runnable. Typical shape:
import dearpygui.dearpygui as dpg
import collections, time

dpg.create_context()
dpg.create_viewport(title="Plot streaming demo", width=800, height=400)

data = collections.deque(maxlen=200)

with dpg.window(label="Live"):
    with dpg.plot(height=300, width=-1):
        dpg.add_plot_axis(dpg.mvXAxis, label="t")
        ya = dpg.add_plot_axis(dpg.mvYAxis, label="value")
        line = dpg.add_line_series([], [], parent=ya)

dpg.setup_dearpygui(); dpg.show_viewport()
while dpg.is_dearpygui_running():
    data.append(time.time() % 10)
    dpg.configure_item(line, x=list(range(len(data))), y=list(data))
    dpg.render_dearpygui_frame()
dpg.destroy_context()
```

## References
- <https://github.com/my1e5/dpg-examples>
