# Windows Classic SDK Samples

The big bag of "desktop" (Win32, COM, MFC, ATL, GDI, USER, DWM, WIC, DirectShow, WIA, Bluetooth, etc.) samples that used to ship in the Windows SDK Samples Gallery. If you ever need "what's the right way to talk to API X" from MSDN's perspective, this repo is the official answer — every sample is keyed to a `Samples\` directory named after the API surface (e.g. `Samples\Win7Samples\winui\shell\appshellintegration`). Worth grep-ing before reinventing any Win32 boilerplate.

```text
# Repo layout (abridged)
Samples/
  Win7Samples/         # the bulk: shell, winui, com, gdi+, dwm, wmi, ...
    winui/
      shell/
        appshellintegration/  # context menus, jump lists, taskbar overlay
        explorerdataprovider/ # IShellFolder shell namespace extensions
        propertysystem/       # IPropertyStore, custom property handlers
    com/                       # marshalling, monikers, fusion, RT_DLG
    gdi/, gdiplus/             # blits, paths, GDI+ effects
    dwm/                       # extended frames, thumbnail tooltips
```

## References
- <https://github.com/microsoft/Windows-classic-samples>
