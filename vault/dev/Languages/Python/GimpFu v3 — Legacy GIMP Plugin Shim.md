<!-- generated-from-dump2 -->
# GimpFu v3 — Legacy GIMP Plugin Shim

Compatibility shim that brings back GIMP 2.10's `gimpfu` Python plugin API on top of GIMP 3.x. Necessary because GIMP 3 dropped the legacy `gimpfu` module entirely — plugins now have to use GIMP's GObject-Introspection bindings directly (verbose, with explicit `Gimp.Image`, `Gimp.Drawable`, `GObject.Value` boxing), which broke every `gimpfu`-based plugin written between 2002 and 2022. `GimpFu-v3` reimplements the `register()` / `pdb.gimp_*` surface on top of GI so legacy plugins keep running. Adjacent to `GlimmerLabs/python-gimp-dbus` (D-Bus rather than in-process) for a totally different approach.

```python
# Legacy gimpfu plugin that GimpFu-v3 keeps working on GIMP 3:
#!/usr/bin/env python3
from gimpfu import *   # provided by GimpFu-v3 on GIMP 3

def my_filter(image, drawable, radius):
    pdb.plug_in_gauss(image, drawable, radius, radius, 0)

register(
    "python_fu_my_filter",
    "Apply gaussian blur",
    "Quick gaussian blur",
    "you", "you", "2025",
    "<Image>/Filters/Blur/My Filter...",
    "RGB*, GRAY*",
    [(PF_FLOAT, "radius", "Radius", 5.0)],
    [],
    my_filter,
)
main()
```

## References
- <https://github.com/bootchk/GimpFu-v3>
