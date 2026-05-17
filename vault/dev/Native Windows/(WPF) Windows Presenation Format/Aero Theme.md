# Aero Theme

## References
- https://github.com/gix/PresentationTheme.Aero
- https://raw.githubusercontent.com/gix/PresentationTheme.Aero/master/Source/PresentationTheme.Aero.Win7/Themes/Aero.Win7.NormalColor.xaml

## XAML usage (merge theme dictionary)
```xaml
<Application.Resources>
  <ResourceDictionary>
    <ResourceDictionary.MergedDictionaries>
      <ResourceDictionary Source="pack://application:,,,/PresentationTheme.Aero.Win7;component/Themes/Aero.Win7.NormalColor.xaml"/>
    </ResourceDictionary.MergedDictionaries>
  </ResourceDictionary>
</Application.Resources>
```
