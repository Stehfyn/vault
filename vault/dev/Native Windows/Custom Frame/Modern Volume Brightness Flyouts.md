# Modern Volume Brightness Flyouts

Replaces the Win8-era volume/brightness/media flyout popups with Win11-styled Fluent flyouts. Implementation pattern: hide the system flyouts by detecting their window class (`NativeHWNDHost` / `HardwareCarouselWindow`) and `ShowWindow(SW_HIDE)`, then draw your own WPF window in their place. Receives the same hardware key events via `RegisterHotKey` / raw-input. Good study of how to displace a system-owned window without breaking its underlying state machine.

## References
- <https://github.com/ModernFlyouts-Community/ModernFlyouts>

## Source Code Reading

`ModernFlyouts-Community/ModernFlyouts` suppresses the native flyout and renders a separate WPF/ModernWpf flyout. The relevant files are `ModernFlyouts.Core/Interop/NativeFlyoutHandler.cs`, `ModernFlyouts/FlyoutHandler.cs`, `ModernFlyouts.Core/Interop/BandWindow.cs`, `ModernFlyouts.Core/Interop/NativeMethods.cs`, and `ModernFlyouts.Core/Display/BrightnessController.cs`.

`NativeFlyoutHandler` finds the legacy system flyout by walking top-level windows:

```csharp
hWndHost = FindWindowEx(IntPtr.Zero, hWndHost,
                        "NativeHWNDHost", null);
hWndDUI = FindWindowEx(hWndHost, IntPtr.Zero,
                       "DirectUIHWND", null);
```

When both handles are known, `HideNativeFlyout` minimizes the DirectUI child and hides the host. The permanent hide path also minimizes and force-minimizes the host; restore paths call `ShowWindowAsync(... Restore)`.

`FlyoutHandler` owns policy: when volume, brightness, lock-key, or media state changes, it hides the native flyout, updates the view model, and shows the custom flyout. This is not a paint hook; it is a competing UI state machine that watches the same user-visible events.

`BandWindow` owns the custom HWND. It wraps an `HwndSource`, chooses `Show` versus `ShowNoActivate`, handles taskbar placement, repositions the child source, and manually forwards DPI changes. Brightness backends are split: built-in displays use WMI `WmiMonitorBrightness` / `WmiMonitorBrightnessMethods`; external displays use DXVA2 physical monitor handles and `SetMonitorBrightness`.

### Discussion Claim -> Probe

Claim from the release notes/issues: the flyout must appear above surfaces that reject ordinary topmost windows. Probe by logging the band/window creation path, then testing lock screen, Start menu, always-on-top Task Manager, and fullscreen apps. Interpretation: a normal topmost WPF window is insufficient; placement and band behavior are part of the product, not polish.

Claim: hiding the native flyout is reversible. Probe by logging every `ShowWindowAsync` command for `NativeHWNDHost` and `DirectUIHWND`, then restoring after a synthetic volume event. Interpretation: if the DirectUI child remains minimized or the host remains hidden after shutdown, cleanup is incomplete.
