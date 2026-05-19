<!-- generated-from-dump2 -->
# just — Command Runner (Rust)

`make` minus the build system — Casey Rodarmor's command runner written in Rust. Reuses the make idiom (recipes in a `justfile`) but throws away the parts that don't apply when you're just orchestrating commands: no implicit rules, no incremental dependency tracking, no `$@`/`$<` magic. Recipes are TAB-or-space indented, take named parameters, support per-recipe shell choice (`#!/usr/bin/env python3` shebangs work), and `just --list` documents them by parsing leading `#` comments. The killer feature for cross-platform projects is `set windows-shell := ["powershell.exe", "-c"]` so the same justfile works on Windows without a separate batch script.

```just
# justfile

# Run the test suite
test:
    cargo test --all-features

# Build a release binary
build target="release":
    cargo build --{{target}}

# Use python for one recipe
weird:
    #!/usr/bin/env python3
    print("multiline recipe runs as one script")

# Cross-platform: choose shell on Windows
set windows-shell := ["powershell.exe", "-NoLogo", "-Command"]
```

```bash
$ just --list
$ just test
$ just build debug
```

## References
- <https://github.com/casey/just>
