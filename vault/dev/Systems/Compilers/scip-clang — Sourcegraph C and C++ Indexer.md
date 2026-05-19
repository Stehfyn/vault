<!-- generated-from-dump2 -->
# scip-clang — Sourcegraph C and C++ Indexer

Clang-based indexer that emits SCIP (Sourcegraph Code Intelligence Protocol) protobufs for C/C++ codebases. Consumes a `compile_commands.json`, drives `libclang`/`clang-tidy`-style traversal, and produces a single `.scip` blob that Sourcegraph (or `scip-cli` -> LSIF) ingests for cross-repo go-to-def, find-refs, and call hierarchy on huge C/C++ trees.

```bash
# Generate compile_commands.json (cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ...).
scip-clang --compdb-path build/compile_commands.json \
           --index-output index.scip \
           --show-progress
src code-intel upload -file=index.scip
```

## References
- <https://github.com/sourcegraph/scip-clang>
