<!-- generated-from-dump2 -->
# ValveFileVDF — Steam KeyValues Parser

Header-only C++ parser/writer for Valve's KeyValues / VDF format — the nested-quoted-string config format Steam uses for `appmanifest_*.acf`, `libraryfolders.vdf`, `loginusers.vdf`, and game configs. The format is whitespace-tolerant and supports `#include`/`#base` directives; this implementation handles both. Useful when you're reading Steam metadata from a tool and don't want to bring in all of `node-vdf` via a runtime.

```cpp
#include <vdf_parser.hpp>
#include <fstream>

std::ifstream f("appmanifest_730.acf");
auto root = tyti::vdf::read(f);
// root is a vdf::object with .name, .attribs, .childs
std::string installDir = root.attribs["installdir"];
std::string name       = root.attribs["name"];
```

## References
- <https://github.com/TinyTinni/ValveFileVDF>
