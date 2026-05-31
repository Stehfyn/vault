# XboxGameBarSamples — Widget Reference Code

Microsoft's reference widgets for the Xbox Game Bar on Win10/11. Game Bar widgets are MSIX-packaged UWP apps that declare an `xbox.gamebar.widget` extension in their `Package.appxmanifest` and expose `IXboxGameBarWidget` via the `Microsoft.Gaming.XboxGameBar` SDK. The samples cover widget lifecycle (`OnDarkThemeChanged`, `OnPinnedChanged`), pinning hints, and the keyboard/gamepad input forwarding model.

## Source Shape

Source pass: `Samples/WidgetSample/App.cpp` shows activation as a protocol/WinRT object route. A widget is not discovered by scanning top-level windows; Game Bar activates a packaged app through `ms-gamebarwidget`, the app casts activation args to `XboxGameBarWidgetActivatedEventArgs`, and the initial launch creates an `XboxGameBarWidget` bound to the current `CoreWindow`.

```cpp
void App::OnActivated(IActivatedEventArgs const& e)
{
    XboxGameBarWidgetActivatedEventArgs args{ nullptr };
    if (e.Kind() == ActivationKind::Protocol) {
        auto protocol = e.try_as<IProtocolActivatedEventArgs>();
        if (protocol && protocol.Uri().SchemeName() == L"ms-gamebarwidget") {
            args = e.try_as<XboxGameBarWidgetActivatedEventArgs>();
        }
    }

    if (args && args.IsLaunchActivation()) {
        Frame root;
        Window::Current().Content(root);
        widget = XboxGameBarWidget(args, Window::Current().CoreWindow(), root);
        root.Navigate(xaml_typename<Widget1>());
        Window::Current().Activate();
    }
}
```

Source pass: `Samples/WidgetAdvSample/Package.appxmanifest` is equally important: widget identity, settings widgets, and Game Bar host interfaces are manifest-declared. The C++ object is the runtime endpoint; the manifest is the discovery contract.

## Connections

- `Game Bar Presence Writer.md` is the desktop-HWND/presence bridge outside normal widget UI.
- `xbox-live-api - Official Xbox Live Bindings.md` is the service/data side; widgets are the overlay UI side.
- `../(WinRT) Windows Runtime/WinRT is fundamentally COM.md` explains why the widget activation types are normal projected WinRT objects.
- `../(WinRT) Windows Runtime/Sandboxing Win32 Apps via MSIX.md` explains why package identity and manifest extensions matter.

## Experiment Harness

Goal: verify widget discovery is package/manifest-driven, not window-driven.

```powershell
Get-AppxPackage *YourWidget* |
  Select Name, PackageFamilyName, InstallLocation
Select-String -Path "$manifest" -Pattern "GameBar", "uap3:Extension", "ms-gamebarwidget"
```

Runtime probe:

```cpp
void App::OnActivated(IActivatedEventArgs const& e) {
    printf("kind=%d protocol=%ls isWidget=%d launch=%d\n",
           (int)e.Kind(), protocol.Uri().SchemeName().c_str(),
           (bool)args, args ? args.IsLaunchActivation() : false);
}
```

Measured signal: package family name, manifest extension presence, activation kind, protocol scheme, `IsLaunchActivation`.

Failure interpretation: if Game Bar cannot discover it, fix MSIX identity/manifest first; C++ widget code is unreachable until activation happens. Reference: <https://learn.microsoft.com/gaming/game-bar/overview>.

## Discussion Claim To Verify

Claim often inferred from widget samples: implementing the widget class is the core work.

Why it matters: the sample source says the opposite. Discovery and activation are manifest/package problems first; widget code executes only after Game Bar accepts the package identity and extension contract.

Verification route:

```powershell
Get-AppxPackage *Widget* |
  Select-Object Name, PackageFamilyName, InstallLocation

Select-String -Path "$manifest" -Pattern "xbox.gamebar.widget","ms-gamebarwidget","uap3:Extension"
```

Activation logging:

```cpp
void App::OnActivated(IActivatedEventArgs const& e) {
    auto protocol = e.try_as<IProtocolActivatedEventArgs>();
    auto widgetArgs = e.try_as<XboxGameBarWidgetActivatedEventArgs>();
    printf("kind=%d scheme=%ls widgetArgs=%d launch=%d\n",
           (int)e.Kind(),
           protocol ? protocol.Uri().SchemeName().c_str() : L"",
           (bool)widgetArgs,
           widgetArgs ? widgetArgs.IsLaunchActivation() : false);
}
```

Interpretation:
- Package missing or manifest lacks widget extension: the C++ widget implementation is irrelevant.
- Activation kind is not protocol or scheme is not `ms-gamebarwidget`: the app was launched through a different route.
- `widgetArgs` exists but launch flag differs: handle settings/secondary activation paths separately from initial widget creation.

## References
- <https://github.com/microsoft/XboxGameBarSamples>
