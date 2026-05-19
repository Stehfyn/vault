<!-- generated-from-dump2 -->
# XFCE Windows XP Theme + Utilities

XFCE theme + helper-program suite that recreates the Windows XP "Luna" look on Linux: matching window borders, panel applets that look like the XP taskbar/start menu, Bliss wallpaper, and tiny rewrites of utilities (Notepad, Paint, etc.) styled to match. More than a GTK theme - actual XAML-style chrome rendering done with XFCE's compositor and custom widget paint handlers. Worth a look as a serious case study of how far a Linux desktop can be skinned to mimic another OS pixel-for-pixel.

```text
# Layout:
themes/         # GTK + xfwm + icon themes (Luna Blue/Silver/Olive)
src/            # custom C utilities: start menu, taskbar, file picker
   xpstart/     # the Start Menu, drawing user pic + recent docs
   xpexplorer/  # an Explorer-skinned thunar replacement
build/          # cmake / autotools wrappers
# Install with the provided shell script, then chmod a session that runs
# xfwm with the Luna theme set as default decorator.
```

## References
- <https://github.com/rozniak/xfce-winxp-tc>
