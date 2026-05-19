# Aero Theme

PresentationTheme.Aero preserves WPF resource dictionaries that recreate the Windows 7 Aero control look. The useful artifact is the XAML itself: control templates, brushes, triggers, and theme resource keys that show how WPF's styling system modeled a native Windows visual language without relying on the current OS theme renderer for every detail.

Keep this beside custom-frame and WPF theming notes. It is a better reference for "how does WPF skin a complete control family?" than for new app design; modern Windows styling has moved on, but legacy line-of-business WPF apps still need compatible Aero/Classic visual dictionaries when running across OS versions.

Code contribution: the raw XAML contributes `ControlTemplate`, `Style`, `Trigger`, `DynamicResource`, brush keys, and theme dictionary structure for WPF control skinning.

## References
- <https://github.com/gix/PresentationTheme.Aero> - WPF theme package containing Aero-style control templates and resources.
- <https://raw.githubusercontent.com/gix/PresentationTheme.Aero/master/Source/PresentationTheme.Aero.Win7/Themes/Aero.Win7.NormalColor.xaml> - raw Windows 7 normal-color resource dictionary; inspect for actual template keys and brush definitions.
