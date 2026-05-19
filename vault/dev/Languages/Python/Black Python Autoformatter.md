<!-- generated-from-dump2 -->
# Black Python Autoformatter

The "uncompromising" Python autoformatter. Deliberately offers almost no knobs (line length and string quote style are about it) so that arguing about style in code review becomes impossible. Reparses the source into a CST, then re-emits it with a fixed set of rules — notably trailing commas in multi-line collections (which keeps diffs minimal when you add an item) and aggressive line-length-driven splitting that prefers vertical layout over horizontal. Now PSF-owned; competes with `autopep8` (less invasive) and `ruff format` (a Rust reimplementation that is roughly 30x faster and Black-compatible-by-design).

```bash
# Format in place
black src/ tests/

# Check without writing (CI mode)
black --check --diff src/

# Show what would change
black --diff path/to/file.py
```

```toml
# pyproject.toml — Black is configured here, never via CLI in real projects
[tool.black]
line-length = 100
target-version = ["py311"]
skip-string-normalization = false
```

## References
- <https://github.com/psf/black>
