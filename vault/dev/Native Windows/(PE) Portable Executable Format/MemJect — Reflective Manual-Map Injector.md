# MemJect - Reflective Manual-Map Injector

MemJect is a compact reflective/manual-map specimen: it places a PE image into another process and performs enough relocation/import/initialization work for the module to execute without normal file-backed loading. Its value in this vault is as a checklist of loader semantics that adversarial loaders tend to approximate or skip.

The notable forensic angle is image identity. If headers are modified, sections are private, imports are resolved manually, and the loader list is not populated normally, the memory region can look like executable code without a clean file-backed module identity. That is exactly where PE parsing, dump tools, ETW image-load gaps, and memory scanners intersect.

## Connections
- `ManualMap` covers the general technique family.
- `DMA_PE_Dumper` and `Process Dump Tools` cover ways to recover or inspect memory-resident PE images.

## References
- <https://github.com/danielkrupinski/MemJect>
