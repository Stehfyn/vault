<!-- generated-from-dump2 -->
# RAD Debugger — Native Windows Debugger

The RAD Debugger (Allen Webster et al., now under Epic's RAD umbrella). Native Windows user-mode debugger with a custom UI written from scratch, a hand-rolled RDI debug-info format (replacing PDB), and a strong focus on responsive stepping in large native codebases. Still alpha but already usable in place of Visual Studio's debugger for many C/C++ workflows.

```bash
# Build with the included build scripts.
build.bat msvc release raddbg
# Launch and attach to a target exe.
raddbg.exe -- your_app.exe arg1 arg2
```

## References
- <https://github.com/EpicGamesExt/raddebugger>
