# WinUI 3 Without XAML

WinUI 3 can create UI entirely in code — no `.xaml` files required. The `Application::Start` lambda receives the `IApplicationActivationFactory` and can construct a `Window` programmatically with any `UIElement` as its content.

```cpp
// C++/WinRT — WinUI 3 minimal code-only window
#include <winrt/Microsoft.UI.Xaml.h>
#include <winrt/Microsoft.UI.Xaml.Controls.h>

winrt::init_apartment();
winrt::Microsoft::UI::Xaml::Application::Start([](auto&&) {
  winrt::Microsoft::UI::Xaml::Window win;
  winrt::Microsoft::UI::Xaml::Controls::TextBlock tb;
  tb.Text(L"Hello WinUI3");
  win.Content(tb);
  win.Activate();
});
```

## References
- https://github.com/sotanakamura/winui3-without-xaml
