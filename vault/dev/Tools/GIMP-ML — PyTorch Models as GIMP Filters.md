<!-- generated-from-dump2 -->
# GIMP-ML — PyTorch Models as GIMP Filters

Pack of GIMP plugins that wire pretrained PyTorch models into GIMP menus — deep-learning operations as filters. Examples: MiDaS depth estimation, Mask R-CNN segmentation, semantic colorization (DeOldify), super-resolution, dehazing, monocular 3D estimation, deepfake-style face filters. Each plugin is a Python-Fu script that shells out to a separate Python subprocess (because GIMP's bundled Python doesn't have PyTorch); inputs/outputs cross the boundary as PNG files in `/tmp/gimp-ml-*/`. Useful both as a tool (it's the easiest way to get DL filters into a real raster editor) and as a reference for "how do you call modern ML from inside GIMP without breaking its Python ABI."

```python
# Conceptual structure of one plugin (see <gimp>/plug-ins/gimp-ml/).
# 1. Python-Fu plugin (runs in GIMP's Python) exports the current drawable to PNG.
# 2. Spawns separate Python interpreter (the one with PyTorch installed):
#    subprocess.run([VENV_PY, "depth_midas.py", "input.png", "output.png"])
# 3. Reads output PNG back, creates a new layer.

#!/usr/bin/env python2
from gimpfu import *
import subprocess, os, tempfile
def depth_estimation(image, drawable):
    tmp = tempfile.mkdtemp()
    pdb.file_png_save(image, drawable, tmp + "/in.png", "x", 0, 9, 1,1,1,1,1)
    subprocess.run(["python3", "/path/to/depth.py", tmp + "/in.png", tmp + "/out.png"])
    layer = pdb.gimp_file_load_layer(image, tmp + "/out.png")
    pdb.gimp_image_add_layer(image, layer, -1)
    pdb.gimp_displays_flush()
register("depth-estimation", ..., depth_estimation,
        "<Image>/Filters/GIMP-ML", "*", [(PF_IMAGE,"i",""),(PF_DRAWABLE,"d","")])
main()
```

## References
- <https://github.com/kritiksoman/GIMP-ML>
