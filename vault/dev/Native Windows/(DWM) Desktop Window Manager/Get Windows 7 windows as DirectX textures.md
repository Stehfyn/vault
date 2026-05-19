# Get Windows 7 Windows as DirectX Textures

Windows 7 DWM used a D3D10-era compositor with redirected per-window surfaces, and `dwmaxx2` attacks that layer directly: it hooks DWM's draw path and exposes a shared texture handle for a target HWND. That is stronger than `DwmRegisterThumbnail`, which only asks DWM to composite a live thumbnail into another window; a shared handle lets your own D3D device sample the window as a texture.

This belongs with `DwmGetDxSharedSurface Window Capture.md`. `dwmaxx2` is the older Windows 7/hook-heavy version of the same idea: avoid `BitBlt`, `PrintWindow`, and occlusion-sensitive desktop scraping by grabbing the redirected surface DWM already owns.

```c
// Public thumbnail compositing: useful for display, not direct texture access.
HTHUMBNAIL thumb = NULL;
DwmRegisterThumbnail(hwndDest, hwndSrc, &thumb);

DWM_THUMBNAIL_PROPERTIES props = {};
props.dwFlags = DWM_TNP_RECTDESTINATION | DWM_TNP_VISIBLE | DWM_TNP_OPACITY;
props.rcDestination = { 0, 0, 200, 150 };
props.opacity = 255;
props.fVisible = TRUE;
DwmUpdateThumbnailProperties(thumb, &props);

// on cleanup:
DwmUnregisterThumbnail(thumb);

// dwmaxx2: get a shared DX10 texture handle for any HWND.
DwmaxxLoad();
HANDLE hShared = DwmaxxGetWindowSharedHandle(hwndTarget);
// open as ID3D10Resource via OpenSharedResource
```

## References
- https://github.com/steeve/dwmaxx2
