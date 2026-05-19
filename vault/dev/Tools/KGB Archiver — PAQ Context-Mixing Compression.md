<!-- generated-from-dump2 -->
# KGB Archiver — PAQ Context-Mixing Compression

Maintenance fork of KGB Archiver, a 2000s-era compression utility using PAQ6-class context-mixing models. Achieves notably better ratio than 7z/xz on text at the cost of glacial speed (MB/s, not GB/s) and large RAM use. AES-256 encryption on top. Mostly of historical interest now — `zstd -22 --long` plus modern PAQ derivatives (`paq8px`, `cmix`) eclipse it on both axes.

```text
# Compress (slow; uses model level 9).
kgb a -m9 archive.kgb file1 file2 dir/

# Decompress.
kgb x archive.kgb -o out_dir/
```

## References
- <https://github.com/RandallFlagg/kgbarchiver>
