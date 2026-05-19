<!-- generated-from-dump2 -->
# py2exe — Windows Python Freezer

Windows-only Python "freezer" — bundles a CPython interpreter plus a tree of .pyc files and their C-extension DLLs into a single .exe (or an .exe + sidecar zip) so end users don't need Python installed. Older than PyInstaller and Nuitka; survives because it produces genuinely small distributions and is the only freezer that historically produced real Windows .exes with proper version resources and manifest embedding from day one. Pure repackaging — does not transpile or compile to native code (that's Nuitka). For modern projects PyInstaller is the more common choice; py2exe stays relevant for legacy Win32-centric distributions.

```python
# setup.py
from setuptools import setup
import py2exe   # registers the py2exe command with setuptools

setup(
    name="myapp",
    windows=[{"script": "main.py"}],     # GUI app (no console)
    # console=[{"script": "main.py"}],   # alternative: console app
    options={
        "py2exe": {
            "bundle_files": 1,           # 1 = single exe, 2 = exe + lib, 3 = exe + dlls
            "compressed": True,
            "optimize": 2,
            "includes": ["pkg_resources.py2_warn"],
        }
    },
    zipfile=None,
)
# build: python setup.py py2exe
```

## References
- <https://github.com/py2exe/py2exe>
