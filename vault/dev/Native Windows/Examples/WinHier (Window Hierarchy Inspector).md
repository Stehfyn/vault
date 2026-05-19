# WinHier (Window Hierarchy Inspector)

A lighter, mixed C/C++ window-hierarchy inspector by katahiromz — pop a target, walk the tree, view styles, class names, and message traffic. Distinct from strobejb/winspy (#3) (the canonical small Spy++ clone) in that WinHier is maintained against current Windows (releases through 2025, supports up through Windows 11) and uses a TreeView-rooted UI rather than winspy's list view. The non-obvious gotcha when writing one of these: `EnumChildWindows` only returns immediate children of the supplied parent unless you recurse yourself (the docs claim it descends, but it actually iterates all descendants by repeatedly calling the callback at every level — fine for enumeration, wrong if you want to preserve depth). For depth-preserving walks you want `GetWindow(GW_CHILD)` + `GetWindow(GW_HWNDNEXT)` recursion as below.

## References
- <https://github.com/katahiromz/WinHier>
