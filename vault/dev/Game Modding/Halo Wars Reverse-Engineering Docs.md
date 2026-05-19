<!-- generated-from-dump2 -->
# Halo Wars Reverse-Engineering Docs

Community-maintained reverse-engineering documentation of *Halo Wars* — file formats (`.ugx` models, `.uia` animations, scn scenario, blueprint XML), asset-database layouts, scripting opcodes used in mission triggers, and the savegame/replay binary structure. The kind of repo where a single markdown table is worth a thousand hours of IDA, because it captures field-by-field interpretations someone else already paid for.

```text
# Sample entry shape from the docs:
struct UGXHeader {
  uint32_t magic;      // 'UGX1'
  uint32_t version;    // observed: 0x0F (DE), 0x0A (original X360)
  uint32_t mesh_count;
  uint32_t bone_count;
  // ... extends across version-specific tails ...
};
```

## References
- <https://github.com/HaloMods/HaloWarsDocs>
