<!-- generated-from-dump2 -->
# Changelog to GitHub Release Action

Taiki Endoh's GitHub Action that turns the leading entry of your `CHANGELOG.md` into a GitHub Release: parses Keep-A-Changelog format, extracts the section matching the tag being pushed, and creates the release with that body. Used pervasively across Taiki's well-engineered Rust crates (`tokio`-adjacent, `cargo-hack`, `cargo-llvm-cov`, etc.). Distinguishing feature: handles the awkward "version is in `[Unreleased]` until tagged" workflow without manual editing - set `changelog: CHANGELOG.md` and it does the right thing on tag push.

```yaml
# .github/workflows/release.yml
name: release
on:
  push:
    tags: [ 'v*' ]
jobs:
  release:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4
      - uses: taiki-e/create-gh-release-action@v1
        with:
          changelog: CHANGELOG.md
          token: ${{ secrets.GITHUB_TOKEN }}
```

## References
- <https://github.com/taiki-e/create-gh-release-action>
