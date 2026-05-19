# Metro Flat Custom Titlebar

Custom-titlebar Win32 window that fakes the Windows 8 "Metro" look: flat, brightly colored caption with three text-button system controls (minimize / maximize / close) drawn by the app, not DWM. The actual technique is the usual one (cf. `grassator/win32-window-custom-titlebar`, `melak47/BorderlessWindow`): handle `WM_NCCALCSIZE` to zero out the non-client area, then handle `WM_NCHITTEST` yourself so the OS still recognizes resize borders and the caption-drag region. Distinguishing feature vs. `Grabacr07/MetroRadiance`: no blur, no DWM extension into client area, purely a flat painted rectangle, which is the actual "Metro" aesthetic rather than the Aero-with-tint look people often conflate with it.

## References
- <https://github.com/avlee/MetroWindow>
