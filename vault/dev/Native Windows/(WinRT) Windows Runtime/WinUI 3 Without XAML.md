# WinUI 3 Without XAML

WinUI 3 can create its UI entirely in code because the runtime surface is an object model. XAML files are convenient declarative input to that object model; they are not a requirement for `Application::Start`, `Window`, `StackPanel`, `Button`, or event wiring. That makes code-only WinUI useful for tiny repros, generated UIs, non-MSBuild experiments, and cases where XAML compilation is the problem being isolated.

This entry intentionally overlaps the sotanakamura sample but should stay as the conceptual note. Link to the sample when the reader needs a buildable repo; use this note when distinguishing XAML markup from WinRT/WinUI activation itself.

## References
- <https://github.com/sotanakamura/winui3-without-xaml> - buildable C++/WinRT sample for constructing WinUI 3 controls without `.xaml` files.
