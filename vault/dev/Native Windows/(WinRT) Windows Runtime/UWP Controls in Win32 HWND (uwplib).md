# UWP Controls in Win32 HWND (uwplib)

`uwplib` sits in the same problem space as Xaml Islands: put UWP XAML controls into an ordinary HWND tree so a Win32/MFC app can host controls such as InkCanvas or MapControl without becoming a full UWP app. The interesting part is not the visible control; it is the interop seam where XAML owns rendering/input/focus inside a child HWND while the outer application still runs a classic message loop.

Use it as a comparison point rather than a primary recommendation. Official Xaml Islands and later WinUI/Windows App SDK hosting paths explain the supported model; `uwplib` is useful because it exposes the frictions those wrappers hide: STA initialization, lifetime ordering, accelerator routing, CoreWindow assumptions, and controls that refuse to behave outside their expected app model.

## References
- <https://github.com/WindowsNT/uwplib> - experimental library for using UWP controls from Win32 hosts.
