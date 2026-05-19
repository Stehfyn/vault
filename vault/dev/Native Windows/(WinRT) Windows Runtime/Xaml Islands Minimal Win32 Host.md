# Xaml Islands Minimal Win32 Host

Xaml Islands is the supported bridge for hosting UWP XAML controls inside a classic desktop HWND tree. The minimum sequence is deceptively small: initialize the WinRT/XAML apartment, create `WindowsXamlManager`, create `DesktopWindowXamlSource`, attach it to the host HWND, size the island HWND, and assign XAML content. The hard parts are focus, keyboard accelerators, DPI, lifetime, and controls that assume more of the UWP app model than the island provides.

Use this note as the official counterpart to `uwplib`. The sample is valuable because it keeps the boilerplate visible, which makes hybrid-app failures easier to classify: message-loop integration, parent HWND sizing, XAML lifetime, or unsupported control behavior.

## References
- <https://github.com/MarkIngramUK/XamlIslands> - minimal Win32 C++ demonstration of `DesktopWindowXamlSource` hosting.
