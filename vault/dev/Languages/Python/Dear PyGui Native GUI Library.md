<!-- generated-from-dump2 -->
# Dear PyGui Native GUI Library

Python GUI library that wraps a heavily modified Dear ImGui C++ core with native rendering (DirectX 11 / Metal / OpenGL3). Critically, it is *not* a binding to plain Dear ImGui — the upstream IMGUI is immediate-mode and the Python wrapper layer adds a retained-mode scene graph, async dispatcher, and the docking/multi-viewport branch, so you describe widgets once in Python and DPG diffs / redraws each frame in C++ without per-frame Python callbacks. Result: real-time plots (50k+ points) and heavy data UIs that stay smooth despite Python in the loop. Competes with PyQt (heavy, retained) and tkinter (lightweight, ugly); closer in spirit to imgui-bundle but with batteries included.

```python
import dearpygui.dearpygui as dpg

dpg.create_context()

def on_btn():
    dpg.set_value("status", f"clicked: {dpg.get_value('name')}")

with dpg.window(label="Hello", width=400, height=200):
    dpg.add_input_text(label="name", tag="name", default_value="world")
    dpg.add_button(label="Greet", callback=on_btn)
    dpg.add_text("", tag="status")

dpg.create_viewport(title="DPG demo", width=600, height=300)
dpg.setup_dearpygui()
dpg.show_viewport()
dpg.start_dearpygui()
dpg.destroy_context()
```

## References
- <https://github.com/hoffstadt/DearPyGui>
