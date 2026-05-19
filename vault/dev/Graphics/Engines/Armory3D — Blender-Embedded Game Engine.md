<!-- generated-from-dump2 -->
# Armory3D — Blender-Embedded Game Engine

3D game engine that lives *inside* Blender as an add-on — your scenes, materials, and animations are Blender data; Armory compiles them down through the Kha framework into HTML5/WebGL, native desktop, or Android/iOS. Logic is built with Blender-style visual node graphs (Armory's "Logic Nodes") or Haxe scripts. The non-obvious win: PBR materials authored in Blender's node editor map ~1:1 onto the runtime shader graph.

```haxe
// Iron / Armory game logic (Haxe) — a simple rotator trait.
package arm;
class Rotator extends iron.Trait {
    public function new() {
        super();
        notifyOnUpdate(update);
    }
    function update() {
        object.transform.rotate(new iron.math.Vec4(0, 0, 1), 0.01);
    }
}
```

## References
- <https://github.com/armory3d/armory>
