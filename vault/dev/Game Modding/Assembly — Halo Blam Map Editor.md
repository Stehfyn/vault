<!-- generated-from-dump2 -->
# Assembly — Halo Blam Map Editor

Multi-generation Halo / Blam engine map editor — the standard tool for poking at `.map` files across Halo 1/2/3/Reach/4 (Xbox/360/MCC) and earlier Blam-engine titles. Decodes Bungie's tag system (each map is a graph of tagged binary blobs: bipeds, weapons, shaders, scenarios) and lets you swap fields, retarget asset references, and patch bytes with the layout schemas inferred from real maps. Sister project to the legacy Adjutant.

```text
# Typical workflow (GUI):
File > Open Cache   -> select a .map file
Tag Tree            -> drill into [biped] / spartan_mp / spartan_mp.biped
Meta Editor pane    -> change "running speed" 4.5 -> 6.0
File > Save Changes -> patches the cache in place (or to a copy)
```

## References
- <https://github.com/XboxChaos/Assembly>
