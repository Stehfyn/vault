# libuiohook - Cross-Platform Global Input Hook

`libuiohook` wraps global keyboard and mouse capture behind one C API across Windows, macOS, and X11. On Windows that means low-level hook procedures rather than Raw Input, so it is convenient for hotkey daemons, accessibility tooling, and telemetry prototypes, but it inherits the latency, trust, and desktop-session limits of `SetWindowsHookEx`.

The repo is worth keeping because it gives a portable abstraction while still exposing the native compromise: hooks observe translated input after the OS has already interpreted device packets. Compare it with `InputEventFlags.h` and `Mouse Input` when deciding between raw device state, foreground window messages, and global observation.

## References
- <https://github.com/kwhat/libuiohook>
