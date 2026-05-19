<!-- generated-from-dump2 -->
# Helium Engine (Insomniac Nocturnal-Derived)

C++ game engine started from the public release of Insomniac Games' "Nocturnal Initiative" toolset (the same lineage that produced parts of the Resistance / Ratchet & Clank tools). Notable for its reflection system (`Helium::Reflect`), property-driven editor/inspector, and tag-based asset pipeline. Long-running open-source project, *not* actively shipped, but the reflection code is interesting reading on its own.

```cpp
// Reflection-registered class: fields show up automatically in the editor.
class HELIUM_FRAMEWORK_API Camera : public Helium::Entity {
    HELIUM_DECLARE_OBJECT(Camera, Entity);
public:
    static void PopulateMetaType(Helium::Reflect::MetaStruct& t) {
        t.AddField(&Camera::m_Fov,    "Fov");
        t.AddField(&Camera::m_NearZ,  "NearZ");
        t.AddField(&Camera::m_FarZ,   "FarZ");
    }
    float m_Fov, m_NearZ, m_FarZ;
};
```

## References
- <https://github.com/HeliumProject/Engine>
