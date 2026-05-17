# DirectComposition + DirectX 12

Create a DirectComposition device and set a DXGI swap chain as the visual content so the DX12 render target is composed by DComp.

```cpp
#include <dcomp.h>
#pragma comment(lib, "dcomp.lib")

IDCompositionDevice* dcomp = nullptr;
DCompositionCreateDevice(dxgiDevice, IID_PPV_ARGS(&dcomp));

IDCompositionTarget* target = nullptr;
dcomp->CreateTargetForHwnd(hwnd, TRUE, &target);

IDCompositionVisual* visual = nullptr;
dcomp->CreateVisual(&visual);

visual->SetContent(swapChain);  // IDXGISwapChain1/3
target->SetRoot(visual);
dcomp->Commit();
```

## References
- https://github.com/PJayB/DirectCompositionDirectX12Sample
