<!-- generated-from-dump2 -->
# Gemini — Visual Studio Shell Clone (WPF)

WPF-based IDE shell framework — basically a stripped-down clone of the Visual Studio Shell that you can build extensions on top of, written in C#. Uses AvalonDock for the tool-window docking layout (the same library Visual Studio Code uses internally for its lighter-weight UI in earlier versions), MVVM via Caliburn.Micro (auto-wires `Button.Click` to `ButtonClick` methods on the view-model by naming convention), and MEF for plugin discovery. Tim Jones built it because back in ~2013 there was no good way to embed the actual VS Shell outside of "VS Isolated Shell" (which was free but heavyweight and licensing-restricted). It's seen non-trivial production use as the host of shader-development tools and HLSL editors.

```csharp
// Typical Gemini module — registers via MEF, provides a tool window
using Gemini.Framework;
using Gemini.Framework.Menus;
using System.ComponentModel.Composition;

[Export(typeof(IModule))]
public class MyModule : ModuleBase
{
    public override void Initialize()
    {
        MainWindow.Title = "My IDE";
    }

    public override IEnumerable<Type> DefaultTools => new[] { typeof(MyToolViewModel) };
}

public class MyToolViewModel : Tool
{
    public override PaneLocation PreferredLocation => PaneLocation.Left;
    public override string DisplayName => "My Tool";
}
```

## References
- <https://github.com/tgjones/gemini>
