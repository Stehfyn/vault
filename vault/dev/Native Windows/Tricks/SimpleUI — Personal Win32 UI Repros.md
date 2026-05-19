# SimpleUI — Personal Win32 UI Repros

Personal sandbox of small UI test cases — the upstream description (Chinese) translates roughly to "some UI code for quickly verifying a particular problem." Not a library, not aimed at consumers; each subdirectory is a minimal repro for some specific Win32/MFC/Qt rendering or input edge case the author was investigating. Browse only if a directory name matches a problem you're hitting. Not a stable dependency.

```text
# Useful only as standalone repros. Typical contents might include:
#   - WM_SIZE / WM_PAINT timing experiments
#   - Custom-drawn list view behaviour tests
#   - HiDPI per-monitor v2 scaling edge cases
# Don't depend on individual subprojects compiling cleanly across versions.
```

## References
- <https://github.com/meizhitu/SimpleUI>
