<!-- generated-from-dump2 -->
# ty — Astral Rust-Native Python Type Checker

Astral's (uv / ruff / rye author) Rust-written Python type checker. Aim: be to pyright/mypy what `ruff` is to flake8 — same checks, dramatically faster, dramatically less memory. Built on the same Salsa-style incremental computation engine ruff uses, so the first run does a full project scan and subsequent runs only re-check the slice of the dependency graph that actually changed. Still pre-1.0 as of 2026 but already a credible alternative to mypy for CI use. Long-term Astral wants `ty` to be the *defining* implementation of Python type semantics (matching mypy's role today) plus the LSP backend for editor integrations.

```bash
# Install
uv tool install ty            # or: pipx install ty

# One-shot check on a project
ty check src/

# LSP mode for editors that wire it up
ty server --stdio

# Pin Python version explicitly
ty check --python-version 3.12 src/
```

```toml
# pyproject.toml
[tool.ty]
python-version = "3.12"
strict = true
exclude = ["build/", "tests/fixtures/"]
```

## References
- <https://github.com/astral-sh/ty>
