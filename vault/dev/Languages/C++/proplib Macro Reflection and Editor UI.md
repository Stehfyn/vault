<!-- generated-from-dump2 -->
# proplib Macro Reflection and Editor UI

C++11 reflection-via-macro library for serializing config/property structs to YAML and auto-generating editor GUIs in Qt or ImGui from the same declaration. The non-obvious value is that each field declaration carries a docstring (`SERIALIZE(field, "human description")`), and that docstring becomes a tooltip in the generated editor — so the same source declares (a) the serialized shape, (b) the editor UI, and (c) the help text, with no code generation step. Trade-off: like all macro-reflection libs in C++ it forces you to inherit from a base class and list every field twice (declaration + SERIALIZE call).

```cpp
#include <proplib/Serializable.h>

class Box : public proplib::Serializable {
public:
  float height;
  float width;
  std::string name;
private:
  SERIALIZE(height, "height of the box");
  SERIALIZE(width,  "width of the box");
  SERIALIZE(name,   "name of the box");
};

Box box{1.0f, 1.4f, "small box"};
YAML::Emitter out;
box.serialize(out, /*write_docs=*/false);          // -> YAML string
box.deserialize(YAML::LoadFile("box.prop.yml"));   // <- YAML file
// proplib::QtEditor / proplib::ImGuiEditor can take any Serializable&
// and render a property panel from the same metadata.
```

## References
- <https://github.com/Lishen1/proplib>
