# Shell App Manager (IShellApp)

`shappmgr.h` exposes the old Add/Remove Programs shell abstraction around `IShellApp` and `IPublishedApp`. It is mostly legacy now, but it captures the moment when installed applications were represented as shell-published objects with commands, icons, and uninstall metadata rather than only registry rows or Settings app entries.

Keep it near `Shell Items and Folders`, `Known Folders`, and app-compat notes. If you encounter it in code, you are probably reading an installer/control-panel integration path from the XP/Vista era, not a modern app-management API.

## References
- `shappmgr.h`
