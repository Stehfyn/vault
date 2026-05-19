# Files (WinUI 3 Explorer Replacement)

Open-source modern (WinUI 3 / WinAppSDK) Explorer replacement. Notable because it's one of the largest production-grade WinUI 3 codebases in the wild, exercising things you don't otherwise see real-world examples of: WinUI 3 tabbed shell host, `Microsoft.UI.Xaml.Controls.NavigationView` with deep folder trees, Mica/Acrylic system backdrops, shell-namespace integration via `IShellItem`/`IShellFolder` interop, drag-drop with `IDataObject`, and per-tab preview panes via XAML islands.

```text
# Project layout (high level)
src/
  Files.App/                  # WinUI 3 host, view models, navigation
    Helpers/Interop/           # IShellItem / SHCreateItemFromParsingName wrappers
    UserControls/Widgets/      # quick-access, drives, recents widgets
    ViewModels/Properties/     # file-property sheet pages
  Files.App.Storage/           # FTP / cloud / archive storage providers
  Files.Backend/               # services: search, indexer, tags
  Files.Shared/                # cross-target helpers (Win/Mobile/Linux ports)
```

## References
- <https://github.com/files-community/Files>
