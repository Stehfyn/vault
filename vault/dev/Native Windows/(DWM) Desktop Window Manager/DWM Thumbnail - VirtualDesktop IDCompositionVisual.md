# DWM Thumbnail - VirtualDesktop IDCompositionVisual

Uses undocumented DWM private exports (`DwmpCreateSharedThumbnailVisual`, `DwmpCreateSharedMultiWindowVisual`, `DwmpUpdateSharedMultiWindowVisual`) to host live window thumbnails as `IDCompositionVisual` nodes. That is materially different from `DwmRegisterThumbnail`: the legacy API draws into a destination HWND through DWM-owned thumbnail plumbing, while this path gives the caller a visual that can be inserted into an existing DirectComposition tree, transformed, clipped, animated, or combined with other visuals.

The VirtualDesktop angle is the important part. The multi-window visual accepts include/exclude HWND lists, so callers can ask DWM for "these windows as one composed visual" instead of scraping screen pixels. It sits near `DwmGetDxSharedSurface Window Capture.md`: both exploit DWM's redirected window surfaces, but the thumbnail visual is for composition, not CPU/GPU capture.

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

## Discussion Claim To Verify

The ADeltaX blog/gist claim is that private DWM thumbnail exports can produce an `IDCompositionVisual`, not just paint a legacy thumbnail into a destination HWND. That drives very different code: the caller can insert the returned visual into its own DComp tree, apply transforms/effects/clips, and compose multi-window sets.

```cpp
auto before = qpc_now();
hr = DwmpCreateSharedThumbnailVisual(dst, src, 0, &props,
                                     dcomp_device, (void**)&visual, &thumb);
log(hr, visual != nullptr, thumb != nullptr, qpc_now() - before);

root->AddVisual(visual, TRUE, nullptr);
visual->SetOffsetX(80.0f);
dcomp_device->Commit();
```

Verification route: compare three paths against the same source HWND: public `DwmRegisterThumbnail`, private shared-thumbnail visual, and private multi-window visual. Record HRESULT, returned handle/visual presence, visual transform success, source window occlusion behavior, and output pixels via DXGI duplication. If only the private visual path moves/animates as part of the caller's DComp tree, the claim survives. If it behaves like a static bitmap or fails after a Windows build change, the note should classify it as build-sensitive reverse-engineering evidence, not a stable UI primitive.

## References
- https://gist.github.com/ADeltaX/aea6aac248604d0cb7d423a61b06e247
- https://blog.adeltax.com/dwm-thumbnails-but-with-idcompositionvisual/
