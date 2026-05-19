# regbag.h — Registry-Backed IPropertyBag Header

`regbag.h` exposes a shell-oriented `IPropertyBag` implementation backed by registry storage. That sounds mundane, but it is exactly the adapter shell extensions want: COM components can consume name/value properties through `IPropertyBag` while persistence remains a normal registry key with string, DWORD, binary, and expandable-string values.

Use it as a bridge concept when reading old property sheet extensions, namespace extensions, and control-panel style configuration code. It is not the modern property system (`IPropertyStore`, `PROPERTYKEY`, `propvarutil.h`), and it should not be confused with MSI property bags or installer tables.

## Connections
- `propvarutil.h` is the newer PROPVARIANT/property-system helper layer.
- `Cpl.h` and `commdlg.h` are common neighbors in shell/control-panel extension code that still stores options in the registry.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/propsys/nn-propsys-ipropertybag>
