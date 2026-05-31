# WinUI 3 Without XAML

WinUI 3 can create its UI entirely in code because the runtime surface is an object model. XAML files are convenient declarative input to that object model; they are not a requirement for `Application::Start`, `Window`, `StackPanel`, `Button`, or event wiring. That makes code-only WinUI useful for tiny repros, generated UIs, non-MSBuild experiments, and cases where XAML compilation is the problem being isolated.

This entry intentionally overlaps the sotanakamura sample but should stay as the conceptual note. Link to the sample when the reader needs a buildable repo; use this note when distinguishing XAML markup from WinRT/WinUI activation itself.

## Source Code Reading

`sotanakamura/winui3-without-xaml/main.cpp` keeps XAML out but still keeps WinUI's metadata contract. `MainWindow` derives from `WindowT<MainWindow>` and creates `StackPanel`, `TextBlock`, `HyperlinkButton`, and `Button` directly in the constructor. `App` derives from `ApplicationT<App, IXamlMetadataProvider>`, appends `XamlControlsResources`, creates the window with `make<MainWindow>()`, and activates it.

```cpp
class App : public ApplicationT<App, IXamlMetadataProvider> {
  void OnLaunched(LaunchActivatedEventArgs const&) {
    Resources().MergedDictionaries().Append(XamlControlsResources());
    window = make<MainWindow>();
    window.Activate();
  }
};
```

The important detail is `IXamlMetadataProvider`. Even without `.xaml` files, WinUI controls may still ask the app for type metadata, so the sample forwards `GetXamlType` and `GetXmlnsDefinitions` to `XamlControlsXamlMetaDataProvider`. "No XAML" does not mean "no XAML metadata layer."

Claim -> source/probe -> interpretation:

Claim: XAML markup is optional; WinUI activation and metadata are not.
Source/probe: remove the `.xaml` file path entirely and construct controls in code, then remove `XamlControlsResources` or metadata forwarding and observe style/resource/type failures.
Interpretation: code-only UI removes markup compilation, but still depends on the WinUI runtime package, resource dictionaries, and metadata provider.

## References
- <https://github.com/sotanakamura/winui3-without-xaml> - buildable C++/WinRT sample for constructing WinUI 3 controls without `.xaml` files.
