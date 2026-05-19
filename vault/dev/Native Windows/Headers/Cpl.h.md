# Cpl.h

The ABI for Control Panel applets -- `.cpl` files, which are just DLLs renamed with a `.cpl` extension and exporting a single function `CPlApplet`. `control.exe` (and any caller of `Shell_ControlPanelW`) `LoadLibrary`s the file, finds `CPlApplet`, and drives it with a state machine of `CPL_INIT` -> `CPL_GETCOUNT` -> `CPL_INQUIRE` (per applet icon/string) -> `CPL_DBLCLK` (user picked an icon) -> `CPL_STOP` -> `CPL_EXIT`. Defines `CPL_INIT` / `CPL_INQUIRE` / `CPL_NEWINQUIRE` / `CPL_DBLCLK` / `CPL_STOP` / `CPL_EXIT` message codes and the `CPLINFO` / `NEWCPLINFOW` structures. The model is essentially frozen in 1995 -- Vista layered the `IControlPanel` shell-namespace model on top, and Windows 10 replaced most of Control Panel with the Settings app -- but `desk.cpl`, `inetcpl.cpl`, `appwiz.cpl`, `timedate.cpl`, etc. all still ship using this ABI, so any tooling that opens specific Control Panel pages depends on it.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/cpl/>
