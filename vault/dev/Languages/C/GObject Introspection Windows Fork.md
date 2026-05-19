<!-- generated-from-dump2 -->
# GObject Introspection Windows Fork

Personal fork of GNOME's gobject-introspection — the toolchain that scans C libraries decorated with GObject metadata and emits `.gir` / `.typelib` files that language runtimes (PyGObject, gjs, gir-rs) load at startup so they can call into the C library without hand-written bindings. This particular fork carried Windows-build patches that hadn't landed upstream; the README warns the `windows` branch is force-pushed (a "shared topic branch") so consumers should pin to a tag rather than track the tip. Mostly historical interest now that upstream MSYS2 packaging caught up.

```bash
# Build a typelib from an annotated C library
g-ir-scanner GtkExample-1.0.gir \
    --library=gtkexample \
    --include=Gtk-4.0 \
    --pkg=gtk4 \
    src/*.c src/*.h

g-ir-compiler GtkExample-1.0.gir -o GtkExample-1.0.typelib
```

```python
# Consume it from Python with no hand-written binding
import gi
gi.require_version("GtkExample", "1.0")
from gi.repository import GtkExample
```

## References
- <https://github.com/dieterv/gobject-introspection>
