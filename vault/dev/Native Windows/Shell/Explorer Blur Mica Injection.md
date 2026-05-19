# Explorer Blur Mica Injection

Injects into explorer.exe and hot-patches its window-frame painting so File Explorer windows (and the shell's various host windows) get DWM blur or Win11 Mica on both Win10 and Win11 — i.e., it skips the public `DWMWA_SYSTEMBACKDROP_TYPE` path because explorer doesn't opt into it. Same author and same general playbook as Maplespe/DWMBlurGlass (#54), but DWMBlurGlass patches dwm.exe to restore the backdrop pipeline globally, whereas ExplorerBlurMica is a surgical explorer-only injection that leaves DWM alone.

## References
- <https://github.com/Maplespe/ExplorerBlurMica>
