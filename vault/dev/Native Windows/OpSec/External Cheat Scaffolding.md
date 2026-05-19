# External Cheat Scaffolding

External cheat scaffolds are useful to defenders because they show the lowest-friction path: enumerate processes/modules, obtain a target handle, read state, write state if permitted, and synthesize input. They avoid injection, which means fewer in-process artifacts but stronger dependence on handle rights and predictable target memory layouts.

Detection thinking should start with process access patterns, repeated reads against game processes, foreground/input anomalies, and unsigned tools that combine ToolHelp snapshots with VM access. Pair this with `Mouse Input`, `Win32 Process Snippet Utilities`, and kernel-driver entries that appear when user-mode rights are blocked.

## References
- <https://github.com/nbqofficial/norsefire>
