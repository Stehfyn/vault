<!-- generated-from-dump2 -->
# windiff — Windows Binary Diff Tool

Rust-built web app that diffs Windows binary metadata across OS versions: exports, imports, syscall numbers, and (via PDB symbols) struct layouts and function signatures. Hosted instance lets you pick two builds of `ntoskrnl.exe` / `win32k.sys` / etc. and see what got added, removed, or renumbered between Insider builds. The unique value vs. running `dumpbin`/`pdbex` yourself: it has scraped and indexed Microsoft's symbol server for hundreds of Windows builds, so you can compare 1607 to 22H2 in a click. Useful for anyone tracking syscall renumbering, undocumented struct churn, or which builds shipped which patch — the same data Geoff Chappell and 0xrepnz publish manually but on demand.

```text
# Workflow:
#   1. Pick OS Build A (e.g. Windows 10 22H2 19045.4717)
#   2. Pick OS Build B (e.g. Windows 11 24H2 26100.1742)
#   3. Pick file/binary (e.g. ntoskrnl.exe)
#   4. windiff shows diffs across:
#        - exports / imports
#        - syscall numbers (for win32k/ntoskrnl)
#        - struct layouts and field offsets from PDBs
#        - inline / function signatures
#
# Hosted: https://winbindex.m417z.com  (binaries) +  windiff renders the diff.
```

## References
- <https://github.com/ergrelet/windiff>
