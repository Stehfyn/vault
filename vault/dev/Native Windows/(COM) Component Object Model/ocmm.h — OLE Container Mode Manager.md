# ocmm.h - OLE Container Mode Manager

`ocmm.h` belongs to the old OLE/DocObject container world: hosts that embed rich in-place objects need to negotiate UI activation, command routing, menu merging, and container mode. It is adjacent to `IOleInPlaceSite`, `IOleCommandTarget`, MSHTML hosting, and shell browser frames rather than to modern COM server registration.

The practical value is recognizing the header when spelunking legacy MFC/ATL containers or Trident-era code. If a project includes `ocmm.h`, it is probably dealing with embedded OLE UI state, not merely creating COM objects.

## References
- `ocmm.h` - Windows SDK header for legacy OLE container mode-management interfaces.
