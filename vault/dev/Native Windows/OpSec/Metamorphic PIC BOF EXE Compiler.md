# Metamorphic PIC BOF EXE Compiler

`dittobytes` is interesting because it treats output format and byte identity as compiler concerns. From similar source it can produce payload-shaped artifacts such as position-independent code, Beacon Object Files, or normal PE executables while applying semantics-preserving variation so simple byte signatures become brittle.

Keep the analysis at the build-artifact level. For defenders, the implication is that family detection must lean on behavior, imports, control-flow features, metadata, and staging context rather than hashes alone. Connect this to `MoVfuscator`, anti-debug catalogs, and PE-format notes.

## References
- <https://github.com/tijme/dittobytes>
