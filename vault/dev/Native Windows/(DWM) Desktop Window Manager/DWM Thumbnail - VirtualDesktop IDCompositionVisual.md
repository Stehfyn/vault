Uses undocumented DWM private APIs (`DwmpCreateSharedThumbnailVisual`, `DwmpCreateSharedMultiWindowVisual`) to host DWM thumbnails as `IDCompositionVisual` nodes. This avoids the legacy `DwmRegisterThumbnail` path and enables VirtualDesktop-aware rendering by specifying which HWNDs to include/exclude. Ordinal-based `GetProcAddress` is required since these are private exports.

```c
// Load private DWM APIs by ordinal
auto dwmapiLib = LoadLibrary(L"dwmapi.dll");

auto lDwmpCreateSharedThumbnailVisual =
    (DwmpCreateSharedThumbnailVisual)GetProcAddress(dwmapiLib, MAKEINTRESOURCEA(147));
auto lDwmpCreateSharedMultiWindowVisual =
    (DwmpCreateSharedMultiWindowVisual)GetProcAddress(dwmapiLib, MAKEINTRESOURCEA(163));
auto lDwmpUpdateSharedMultiWindowVisual =
    (DwmpUpdateSharedMultiWindowVisual)GetProcAddress(dwmapiLib, MAKEINTRESOURCEA(164));

// Create a DComp device
IDCompositionDevice* dcompDevice = nullptr;
DCompositionCreateDevice(dxgiDevice, IID_PPV_ARGS(&dcompDevice));

// Single-window thumbnail as IDCompositionVisual
IDCompositionVisual* pVisual = nullptr;
HTHUMBNAIL hThumb = nullptr;
DWM_THUMBNAIL_PROPERTIES props = {};
props.dwFlags = DWM_TNP_RECTDESTINATION | DWM_TNP_VISIBLE | DWM_TNP_OPACITY;
props.opacity = 255;
props.fVisible = TRUE;
lDwmpCreateSharedThumbnailVisual(hwndDest, hwndSrc, 0, &props,
                                 dcompDevice, (void**)&pVisual, &hThumb);

// Multi-window (VirtualDesktop-style) visual -- Windows 20xxx+
IDCompositionVisual* pMultiVisual = nullptr;
HTHUMBNAIL hMultiThumb = nullptr;
lDwmpCreateSharedMultiWindowVisual(hwndDest, dcompDevice,
                                   (void**)&pMultiVisual, &hMultiThumb);

HWND includes[] = { hwnd1, hwnd2 };
RECT rcSource = {};
SIZE destSize = {};
// dwFlags = 1 required on iron+
lDwmpUpdateSharedMultiWindowVisual(hMultiThumb,
    includes, ARRAYSIZE(includes),
    nullptr, 0,
    &rcSource, &destSize, 1);
```

## References
- https://gist.github.com/ADeltaX/aea6aac248604d0cb7d423a61b06e247
- https://blog.adeltax.com/dwm-thumbnails-but-with-idcompositionvisual/
