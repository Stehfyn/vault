# UWP Controls in Win32 HWND (uwplib)

`uwplib` sits in the same problem space as Xaml Islands: put UWP XAML controls into an ordinary HWND tree so a Win32/MFC app can host controls such as InkCanvas or MapControl without becoming a full UWP app. The interesting part is not the visible control; it is the interop seam where XAML owns rendering/input/focus inside a child HWND while the outer application still runs a classic message loop.

Use it as a comparison point rather than a primary recommendation. Official Xaml Islands and later WinUI/Windows App SDK hosting paths explain the supported model; `uwplib` is useful because it exposes the frictions those wrappers hide: STA initialization, lifetime ordering, accelerator routing, CoreWindow assumptions, and controls that refuse to behave outside their expected app model.

## References
- <https://github.com/WindowsNT/uwplib> - experimental library for using UWP controls from Win32 hosts.

## Experiment Harness

Goal: compare unsupported `uwplib` behavior against supported XAML Islands behavior.

Procedure:
1. Host the same simple control in `uwplib` and `DesktopWindowXamlSource`.
2. Record child HWND presence, focus traversal, DPI resize behavior, and teardown result.
3. Repeat with a control that uses more app-model assumptions, such as map/ink/media if available.

Measured signal: attach HRESULT, child HWND, keyboard focus transitions, leaked windows after destroy, crash/exception on teardown.

Failure interpretation: if XAML Islands succeeds and `uwplib` fails, the missing piece is the unsupported hosting contract, not the control itself. Reference: <https://learn.microsoft.com/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.hosting.desktopwindowxamlsource>.
