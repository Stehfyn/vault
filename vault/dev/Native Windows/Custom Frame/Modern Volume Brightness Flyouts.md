# Modern Volume Brightness Flyouts

Replaces the Win8-era volume/brightness/media flyout popups with Win11-styled Fluent flyouts. Implementation pattern: hide the system flyouts by detecting their window class (`NativeHWNDHost` / `HardwareCarouselWindow`) and `ShowWindow(SW_HIDE)`, then draw your own WPF window in their place. Receives the same hardware key events via `RegisterHotKey` / raw-input. Good study of how to displace a system-owned window without breaking its underlying state machine.

## References
- <https://github.com/ModernFlyouts-Community/ModernFlyouts>
