# cmdtree.h - Shell OLE Command Tree

`cmdtree.h` is an obscure shell/OLE header tied to command-tree publication in old DocObject, Explorer, MSHTML, and command-bar hosting scenarios. The surrounding world is `IOleCommandTarget`, command groups such as shell and browser command GUIDs, and containers that need to expose a structured menu/verb surface for an embedded object.

It belongs in the MFC folder because MFC/ATL hosts are where this kind of code usually appears: embedded WebBrowser/MSHTML controls, shell views, or Office/IE-era UI integration. Treat it as shell/OLE archaeology, not a general menu API; modern command surfaces use ribbon/command frameworks, XAML commanding, or direct app-defined menus.

## References
- `cmdtree.h` - Windows SDK header for legacy shell/OLE command-tree structures.
