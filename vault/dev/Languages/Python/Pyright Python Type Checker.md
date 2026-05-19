<!-- generated-from-dump2 -->
# Pyright Python Type Checker

Static type checker for Python — the reference implementation that backs Pylance (the default VS Code Python language server). Written in TypeScript so it runs on Node, which is the reason it is faster than mypy for big codebases: it caches per-module analyses keyed on file hashes and re-checks incrementally on save. Pyright is also stricter than mypy by default — it infers types more aggressively, narrows on `assert isinstance`, and supports PEP 695 / 696 (type parameter syntax, type defaults) earlier than mypy historically has. The newer Rust-based `astral-sh/ty` is the planned successor in spirit.

```bash
# One-shot check
pyright src/

# Strict mode (treat any-typed expressions as errors)
pyright --strict src/

# Watch mode for editor-like loop
pyright --watch src/
```

```jsonc
// pyrightconfig.json
{
  "include": ["src"],
  "exclude": ["**/__pycache__"],
  "pythonVersion": "3.12",
  "typeCheckingMode": "strict",
  "reportMissingTypeStubs": "warning"
}
```

## References
- <https://github.com/microsoft/pyright>
