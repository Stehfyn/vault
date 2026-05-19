<!-- generated-from-dump2 -->
# GIMP D-Bus Python Client

Python client that drives a running GIMP process out-of-band over D-Bus, rather than as an in-process plugin. The trick is that GIMP exports a D-Bus service when started with the right command-line flag, exposing the PDB (Procedural DataBase) as remote methods — so an external Python script can open an image, run filters, save, all without `gimpfu` and without loading inside GIMP's own Python interpreter. Useful for batch processing from a CI script, or for talking to GIMP from a Python you control (PEP 668 venv with numpy, etc.) that GIMP's bundled Python can't host. Contrast with `bootchk/GimpFu-v3` (in-process) and the official GI bindings (in-process, no shim).

```python
# Pseudo-API; check repo for exact module name
from gimp_dbus import GimpDbusClient

gimp = GimpDbusClient()                  # auto-finds the session bus service
img = gimp.file_load("/tmp/in.png", "/tmp/in.png")
drw = gimp.image_get_active_drawable(img)
gimp.plug_in_gauss(img, drw, 10.0, 10.0, 0)
gimp.file_png_save(img, drw, "/tmp/out.png", "out", 0, 9, 1, 1, 1, 1, 1)
gimp.image_delete(img)
```

## References
- <https://github.com/GlimmerLabs/python-gimp-dbus>
